#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>
#include "experiments.hpp"
#include "solvers.hpp"

std::string join(const std::vector<std::string>& parts, const std::string& delimiter) {
    std::ostringstream oss;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) oss << delimiter;
        oss << parts[i];
    }
    return oss.str();
}

string to_string(const MethodType &method) {
    switch(method) {
        case MethodType::SingleDistBellman:
            return "bellman";
        case MethodType::SingleDistPBVI:
            return "PBVI";
        case MethodType::ConvexDist:
            return "convex";
        default:
            assert(false);
    }
}

bool Experiment::guard(const POMDPVertex&, const unordered_map<int, int>&, const POMDPAction&) const {
    return true;
}

fs::path Experiment::get_wd() const {
    return  fs::path("..") / "results" / this->name;
}

bool Experiment::setup_working_dir() const {

    fs::path dir_path = this->get_wd();
    
    if (!fs::exists(dir_path)) {
        if (fs::create_directories(dir_path)) {
            std::cout << "main experiments directory created successfully.\n";
        } else {
            std::cerr << "Failed to create main experiments directory.\n";
            return false;
        }
    }

    dir_path = fs::path("..") / "results" / this->name / "algorithms";
    
    if (!fs::exists(dir_path)) {
        if (fs::create_directories(dir_path)) {
            std::cout << "Algorithms directory created successfully.\n";
        } else {
            std::cerr << "Failed to create directory for storing algorithms.\n";
            return false;
        }
    }
    return true;
}

vector<QuantumHardware> Experiment::get_allowed_hardware() const {
    vector<QuantumHardware> hardware_specs;

    for(int i = 0; i < QuantumHardware::HardwareCount; i++)  {
        hardware_specs.push_back(static_cast<QuantumHardware>(i));
    }

    return hardware_specs;
}

vector<HardwareSpecification> Experiment::get_hardware_specs() const {
    vector<QuantumHardware>  quantum_hardwares = this->get_allowed_hardware();
    vector<HardwareSpecification> result;
    
    for (QuantumHardware qw : quantum_hardwares) {
        result.emplace_back(qw, this->with_thermalization);
    }

    return result;
}

vector<int> Experiment::get_qubits_used(const unordered_map<int, int> &embedding) {
    vector<int> result;
    for (auto it : embedding) {
        result.push_back(it.second);
    }
    return result;
}

Belief Experiment::get_initial_belief(const POMDP &pomdp) const {
    Belief initial_belief;

    POMDPAction* INIT_CHANNEL = new POMDPAction("INIT__", {}, this->precision, {});

    if (pomdp.transition_matrix.at(pomdp.initial_state).find(INIT_CHANNEL) ==  pomdp.transition_matrix.at(pomdp.initial_state).end()) {
        for(auto it : pomdp.transition_matrix.at(pomdp.initial_state).at(INIT_CHANNEL)) {
            initial_belief.add_val(it.first, it.second);
        }
    } else {
        initial_belief.set_val(pomdp.initial_state, MyFloat("1"));
    }
    return initial_belief;
}

vector<POMDPVertex*> Experiment::get_initial_states(const POMDP &pomdp) const {
    vector<POMDPVertex*> initial_states;

    POMDPAction* INIT_CHANNEL = new POMDPAction("INIT__", {}, this->precision, {});

    if (pomdp.transition_matrix.at(pomdp.initial_state).find(INIT_CHANNEL) ==  pomdp.transition_matrix.at(pomdp.initial_state).end()) {
        for(auto it : pomdp.transition_matrix.at(pomdp.initial_state).at(INIT_CHANNEL)) {
            initial_states.push_back(it.first);
        }
    } else {
        initial_states.push_back(pomdp.initial_state);
    }

    return initial_states;
}

void Experiment::run() const {
    if (!setup_working_dir()) {
        return;
    }

    fs::path results_path = this->get_wd() / "stats.csv";

    // Open file for writing (this overwrites the file if it exists)
    std::ofstream results_file(results_path);

    if (!results_file.is_open()) {
        std::cerr << "Failed to open file: " << results_path << "\n";
        return;
    }

    // write header in results file
    results_file << join(vector<string>({"hardware", 
        "embedding_index", 
        "pomdp_build_time",
        "probability",
        "method",
        "method_time",
        "algorithm_index"})
        , ",") << "\n";


    vector<HardwareSpecification> hardware_specs = this->get_hardware_specs();

    auto actual_guard = [this](const POMDPVertex& v, const std::unordered_map<int,int>& m, const POMDPAction& a) {
        return this->guard(v, m, a);
    };

    auto actual_reward_f = [this](const Belief &b, const unordered_map<int, int> &embedding) -> MyFloat {
        return this->postcondition(b, embedding);
    };

    // we store all unique algorithms
    vector<Algorithm *> unique_algorithms;

    for (HardwareSpecification hardware_spec : hardware_specs) {
        string hardware_name = hardware_spec.get_hardware_name();
        auto embeddings = this->get_hardware_scenarios(hardware_spec);
        int embedding_index = 0;
        for (auto embedding : embeddings) {
            // initial distribution
            auto initial_distribution = this->get_initial_distribution(embedding);

            // actions
            auto actions = this->get_actions(hardware_spec, embedding);

            // POMDP build
            POMDP pomdp = POMDP(this->precision);
            auto qubits_used = get_qubits_used(embedding);
            
            auto start_pomdp_build = chrono::high_resolution_clock::now();
            pomdp.build_pomdp(actions, hardware_spec, this->max_horizon, embedding, nullptr, initial_distribution, qubits_used, actual_guard, this->set_hidden_index);
            auto end_pomdp_build = chrono::high_resolution_clock::now();    // end time

            auto pomdp_build_time = (end_pomdp_build - start_pomdp_build).count();

            // initial belief
            auto initial_belief = this->get_initial_belief(pomdp);
            auto initial_states = this->get_initial_states(pomdp);

            for (int horizon = this->min_horizon; horizon <= this->max_horizon; horizon++) {
                for (auto method : this->method_types) {
                    long long method_time;
                    pair<Algorithm *, double> result = make_pair(nullptr, 0);
                    if (method == MethodType::SingleDistBellman) {
                        SingleDistributionSolver solver(pomdp, actual_reward_f, this->precision, embedding);

                        auto start_method = chrono::high_resolution_clock::now();
                        auto result_temp = solver.get_bellman_value(initial_belief, horizon);
                        auto end_method = chrono::high_resolution_clock::now();
                        result = make_pair(result_temp.first, to_double(result_temp.second));


                        method_time = (end_method - start_method).count();
                    } else if (method == MethodType::SingleDistPBVI) {
                        SingleDistributionSolver solver(pomdp, actual_reward_f, this->precision, embedding);
                        // TODO

                    } else {
                        ConvexDistributionSolver solver (pomdp, actual_reward_f, this->precision, embedding);
                        auto start_method = chrono::high_resolution_clock::now();
                        result = solver.solve(initial_states, horizon);
                        auto end_method = chrono::high_resolution_clock::now();
                        method_time = (end_method - start_method).count();
                    }

                    int algorithm_index = get_algorithm_from_list(unique_algorithms, result.first);
                    if (algorithm_index == -1) {
                        algorithm_index = unique_algorithms.size();
                        unique_algorithms.push_back(result.first);
                    }
                    results_file << join(vector<string>({hardware_name, 
                                                    to_string(embedding_index), 
                                                    to_string(pomdp_build_time),
                                                    to_string(result.second),
                                                    to_string(method),
                                                    to_string(method_time),
                                                    to_string(algorithm_index)})
                                                    , ",") << "\n";
                }
            }

            embedding_index++;
        }
    }
    
    results_file.close();
}

ReadoutNoise::ReadoutNoise(int target, double success0, double success1) {
    this->target = target;
    this->success0 = success0;
    this->success1 = success1;
    this->diff = success0 - success1;
    this->acc_err = 1-success0 + 1-success1;
    this->abs_diff = abs(success0-success1);
}

unordered_set<int> get_meas_pivot_qubits(const HardwareSpecification &hardware_spec) {
    unordered_set<int> result;
    vector<ReadoutNoise> noises;

    for (int qubit = 0; qubit < hardware_spec.num_qubits; qubit++) {
        if ((hardware_spec.get_qubit_indegree(qubit) > 1)) {
            Instruction *instruction = new Instruction(GateName::Meas, qubit, qubit);
            MeasurementChannel* noise_data = static_cast<MeasurementChannel*>(hardware_spec.instructions_to_channels.at(instruction));
            auto success0 = noise_data->correct_0;
            auto success1 = noise_data->correct_1;
            noises.push_back(ReadoutNoise(qubit, success0, success1));
        }
    }

    // success0
    sort(noises.begin(), noises.end(), [](const ReadoutNoise &a, const ReadoutNoise &b) {
        return a.success0 < b.success0;
    });
    result.insert(noises.front().target);
    result.insert(noises.back().target);

    // success1
    sort(noises.begin(), noises.end(), [](const ReadoutNoise &a, const ReadoutNoise &b) {
        return a.success1 < b.success1;
    });
    result.insert(noises.front().target);
    result.insert(noises.back().target);

    // accumulated error
    sort(noises.begin(), noises.end(), [](const ReadoutNoise &a, const ReadoutNoise &b) {
        return a.acc_err < b.acc_err;
    });
    result.insert(noises.front().target);
    result.insert(noises.back().target);

    // diff
    sort(noises.begin(), noises.end(), [](const ReadoutNoise &a, const ReadoutNoise &b) {
        return a.diff < b.diff;
    });
    if (noises.front().diff != noises.back().diff) {
        result.insert(noises.front().target);
        result.insert(noises.back().target);
    }

    // abs_diff
    sort(noises.begin(), noises.end(), [](const ReadoutNoise &a, const ReadoutNoise &b) {
        return a.abs_diff < b.abs_diff;
    });
    if (noises.front().abs_diff != noises.back().abs_diff) {
        result.insert(noises.front().target);
        result.insert(noises.back().target);
        assert(noises.front().abs_diff < noises.back().abs_diff);
    }
    return result;
}