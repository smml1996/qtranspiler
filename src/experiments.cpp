#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>
#include "experiments.hpp"

#include <cassert>

#include "solvers.hpp"
#include "utils.hpp"
using namespace  std;

std::string join(const std::vector<std::string>& parts, const std::string& delimiter) {
    std::ostringstream oss;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) oss << delimiter;
        oss << parts[i];
    }
    return oss.str();
}

string get_method_string(MethodType method) {
    if (method == MethodType::ConvexDist) {
        return "convex";
    }

    if (method == MethodType::SingleDistBellman) {
        return "exact_bellman";
    }

    if (method == MethodType::SingleDistPBVI) {
        return "pbvi";
    }

    throw invalid_argument("Method type not recognized");
}

string gate_to_string(const set<MethodType> &methods) {
    string result;
    for (auto m : methods) {
        if (!result.empty()) {
            result += ", ";
        }
        result += gate_to_string(m);
    }
    return result;
}

set<string> get_solver_methods_strings() {
    set<string> solver_methods;
    for (int i = 0; i < MethodType::MethodCount; i++) {
        solver_methods.insert(gate_to_string(static_cast<MethodType>(i)));
    }

    return solver_methods;
}

string gate_to_string(const MethodType &method) {
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

MethodType str_to_method_type(const string &method) {
    for (int i = 0; i < MethodType::MethodCount; i++) {
        string m_str = gate_to_string(static_cast<MethodType>(i));
        if (m_str == method) {
            return static_cast<MethodType>(i);
        }
    }
    throw invalid_argument("Method type not recognized: " + method);
}

bool Experiment::guard(const POMDPVertex&, const unordered_map<int, int>&, const POMDPAction&) const {
    return true;
}

void Experiment::make_setup_file() const {
    // write a text file that contains the setup of this experiment
    fs::path setup_path =  this->get_wd() / "setup.txt";
    ofstream setup_file(setup_path);
    if (!setup_file.is_open()) {
        std::cerr << "Failed to open file: " << setup_path << "\n";
        return;
    }

    setup_file << "name: " << this->name << "\n";
    setup_file << "precision: " << this->precision << "\n";
    setup_file << "thermalization: " << with_thermalization << "\n";
    setup_file << "min. horizon: " << this->min_horizon << "\n";
    setup_file << "max. horizon: " << this->max_horizon << "\n";
    setup_file << "hidden index: " << this->set_hidden_index << "\n";
    setup_file << "methods: " << gate_to_string(this->method_types) << endl;
    setup_file << "quantum hardware: " << to_string(this->hw_list) << endl;
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

set<QuantumHardware> Experiment::get_allowed_hardware() const {
    if (!this->hw_list.empty()) return this->hw_list;
    set<QuantumHardware> hardware_specs;

    for(int i = 0; i < QuantumHardware::HardwareCount; i++)  {
        hardware_specs.insert(static_cast<QuantumHardware>(i));
    }

    return hardware_specs;
}

vector<HardwareSpecification> Experiment::get_hardware_specs() const {
    auto  quantum_hardwares = this->get_allowed_hardware();
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
    POMDPAction INIT_CHANNEL =  POMDPAction("INIT__", {}, this->precision, {});

    if (pomdp.transition_matrix.at(pomdp.initial_state).find(&INIT_CHANNEL) !=  pomdp.transition_matrix.at(pomdp.initial_state).end()) {
        for(auto it : pomdp.transition_matrix.at(pomdp.initial_state).at(&INIT_CHANNEL)) {
            initial_belief.add_val(it.first, it.second);
        }
    } else {
        initial_belief.set_val(pomdp.initial_state, Rational("1", "1", this->precision *(this->max_horizon+1)));
    }

    return initial_belief;

}

vector<POMDPVertex*> Experiment::get_initial_states(const POMDP &pomdp) const {
    vector<POMDPVertex*> initial_states;

    POMDPAction* INIT_CHANNEL = new POMDPAction("INIT__", {}, this->precision, {});

    if (pomdp.transition_matrix.at(pomdp.initial_state).find(INIT_CHANNEL) !=  pomdp.transition_matrix.at(pomdp.initial_state).end()) {
        for(auto it : pomdp.transition_matrix.at(pomdp.initial_state).at(INIT_CHANNEL)) {
            initial_states.push_back(it.first);
        }
    } else {
        initial_states.push_back(pomdp.initial_state);
    }

    return initial_states;
}

Experiment::Experiment(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
    bool set_hidden_index, const set<MethodType> &method_types, const set<QuantumHardware> &hw_list) {
    this->name = name;
    this->precision = precision;
    this->with_thermalization = with_thermalization;
    this->min_horizon = min_horizon;
    this->max_horizon = max_horizon;
    this->set_hidden_index = set_hidden_index;
    this->method_types = method_types;
    this->hw_list = hw_list;
}

void Experiment::run() const {
    if (!setup_working_dir()) {
        return;
    }

    this->make_setup_file();


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
        "horizon",
        "pomdp_build_time",
        "probability",
        "method",
        "method_time",
        "algorithm_index",
        "error"})
        , ",") << "\n";


    vector<HardwareSpecification> hardware_specs = this->get_hardware_specs();

    auto actual_guard = [this](const POMDPVertex& v, const std::unordered_map<int,int>& m, const POMDPAction& a) {
        return this->guard(v, m, a);
    };

    auto actual_reward_f = [this](const Belief &b, const unordered_map<int, int> &embedding) -> Rational {
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
            auto pomdp_build_time = chrono::duration<double>(end_pomdp_build - start_pomdp_build).count();
            cout << pomdp_build_time << endl;
            // pomdp.print_pomdp();
            // initial belief
            auto initial_belief = this->get_initial_belief(pomdp);
            auto initial_states = this->get_initial_states(pomdp);

            auto HALT_ALGORITHM = new Algorithm(&HALT_ACTION, get_belief_cs(initial_belief), 0);
            for (int horizon = this->min_horizon; horizon <= this->max_horizon; horizon++) {
                cout << horizon << endl;
                for (auto method : this->method_types) {
                    long long method_time;
                    pair<Algorithm *, double> result;
                    double error = 0.0;
                    if (method == MethodType::SingleDistBellman) {
                        SingleDistributionSolver solver(pomdp, actual_reward_f, this->precision * (max_horizon+1), embedding);
                        solver.beliefs_to_rewards.insert({initial_belief, {}});
                        assert(solver.beliefs_to_rewards.size() == 1);
                        assert(solver.beliefs_to_rewards.find(initial_belief) != solver.beliefs_to_rewards.end());
                        solver.beliefs_to_rewards.at(initial_belief).insert({0, {HALT_ALGORITHM, actual_reward_f(initial_belief, embedding)}});

                        auto start_method = chrono::high_resolution_clock::now();
                        auto result_temp = solver.get_bellman_value(initial_belief, horizon);
                        auto end_method = chrono::high_resolution_clock::now();
                        result = make_pair(new Algorithm(*result_temp.first), to_double(result_temp.second));
                        method_time = chrono::duration<double>(end_method - start_method).count();
                    } else if (method == MethodType::SingleDistPBVI) {
                        SingleDistributionSolver solver(pomdp, actual_reward_f, this->precision * (max_horizon+1), embedding);
                        solver.beliefs_to_rewards.insert({initial_belief, {}});
                        assert(solver.beliefs_to_rewards.size() == 1);
                        assert(solver.beliefs_to_rewards.find(initial_belief) != solver.beliefs_to_rewards.end());
                        solver.beliefs_to_rewards.at(initial_belief).insert({0, {HALT_ALGORITHM, actual_reward_f(initial_belief, embedding)}});

                        auto start_method = chrono::high_resolution_clock::now();
                        auto result_temp = solver.PBVI_solve(initial_belief, horizon);
                        auto end_method = chrono::high_resolution_clock::now();
                        result = make_pair(new Algorithm(*result_temp.first), to_double(result_temp.second));
                        method_time = chrono::duration<double>(end_method - start_method).count();
                        error = solver.get_error(horizon);
                    } else {
                        ConvexDistributionSolver solver (pomdp, actual_reward_f, this->precision * (max_horizon+1), embedding);
                        auto start_method = chrono::high_resolution_clock::now();
                        auto result_temp = solver.solve(initial_states, horizon);
                        result = make_pair(new Algorithm(*result_temp.first), result_temp.second);
                        auto end_method = chrono::high_resolution_clock::now();
                        method_time = chrono::duration<double>(end_method - start_method).count();
                    }

                    int algorithm_index = get_algorithm_from_list(unique_algorithms, result.first);
                    if (algorithm_index == -1) {
                        algorithm_index = unique_algorithms.size();
                        unique_algorithms.push_back(result.first);
                    }

                    results_file << join(vector<string>({hardware_name, 
                                                    to_string(embedding_index),
                                                    to_string(horizon),
                                                    to_string(round_to(pomdp_build_time, Experiment::round_in_file)),
                                                    to_string(round_to(result.second, Experiment::round_in_file)),
                                                    gate_to_string(method),
                                                    to_string(round_to(method_time, Experiment::round_in_file)),
                                                    to_string(algorithm_index),
                                                    to_string(round_to(error, Experiment::round_in_file))})
                                                    , ",") << "\n";
                }
            }
            embedding_index++;
        }
    }

    results_file.close();

    // dump algorithms
    fs::path algorithms_folder = this->get_wd() / "algorithms";
    int algo_index = 0;
    for (auto algorithm : unique_algorithms) {
        algo_index += 1;
        fs::path algorithm_path = algorithms_folder / ("A_" + to_string(algo_index) + ".txt");
        dump_to_file(algorithm_path, algorithm);
    }
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
        if (hardware_spec.get_qubit_indegree(qubit) > 1) {
            Instruction *instruction = new Instruction(GateName::Meas, qubit, qubit);
            MeasurementChannel* noise_data = static_cast<MeasurementChannel*>(hardware_spec.instructions_to_channels.at(instruction));
            auto success0 = noise_data->correct_0;
            auto success1 = noise_data->correct_1;
            noises.push_back(ReadoutNoise(qubit, success0, success1));
        }
    }
    assert(noises.size() > 0);

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

int Experiment::round_in_file = 5;