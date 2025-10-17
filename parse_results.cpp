//
// Created by Stefanie Muroya Lei on 02.10.25.
//
#include <fstream>
#include <iostream>


#include "instruction.hpp"
#include "algorithm.hpp"
#include <string>
#include <vector>
#include "experiments.hpp"
#include <nlohmann/json.hpp>
#include "bitflip.cpp"
#include "discrimination.cpp"
#include "ghz.cpp"
#include "reset.cpp"
#include "bellstate_reach.cpp"

using namespace std;
namespace fs = std::filesystem;

void split_str(string const &str, const char delim, vector<string> &out) {
    stringstream s(str);

    string s2;

    while(getline(s, s2, delim)){
        out.push_back(s2);
    }
}

unordered_set<shared_ptr<Instruction>, InstructionHash, InstructionPtrEqual> get_unique_instructions(const vector<shared_ptr<POMDPAction>> &actions) {
    unordered_set<shared_ptr<Instruction>, InstructionHash, InstructionPtrEqual> result;
    for (auto action : actions) {
        for (auto instruction : action->instruction_sequence) {
            result.insert(make_shared<Instruction>(instruction));
        }
    }
    return result;
}

class Setup {
public:
    string name;
    int num_batches;
    shared_ptr<Experiment> experiment;
    bool with_cnot;
    int max_horizon;
    bool with_thermalization;
    Setup(string name_, int num_batches_, shared_ptr<Experiment> exp_, bool with_cnot_, int max_horizon_, bool with_thermalization_=false) {
        this->name = name_;
        this->with_thermalization = with_thermalization_;
        this->num_batches = num_batches_;
        this->experiment = exp_;
        this->with_cnot = with_cnot_;
        this->max_horizon = max_horizon_;
    }
};

int get_algorithm_index(const Algorithm &current_algorithm,const vector<Algorithm> &unique_algorithms) {
    for (int i = 0; i < unique_algorithms.size(); i++) {
        if (unique_algorithms[i] == current_algorithm) {
            return i;
        }
    }
    return -1;
}

bool are_actions_valid(const HardwareSpecification &hardware_spec, vector<shared_ptr<POMDPAction>> &actions) {
    for (auto action : actions) {
        for (auto instruction : action->instruction_sequence) {
            if (hardware_spec.instructions_to_channels.find(make_shared<Instruction>(instruction)) == hardware_spec.instructions_to_channels.end()) {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    // load all hardware specs
    cout << "started loading hardware specs" << endl;
    map<bool, vector<HardwareSpecification>> all_specs;
    all_specs[false] = vector<HardwareSpecification>({});
    all_specs[true] = vector<HardwareSpecification>({});
    for (auto index = 0; index < QuantumHardware::HardwareCount; index++) {
        all_specs[false].push_back(HardwareSpecification(static_cast<QuantumHardware>(index), false, true));
        all_specs[true].push_back(HardwareSpecification(static_cast<QuantumHardware>(index), true, true));
    }
    cout << "end loading hardware specs" << endl << endl;

    filesystem::path parsed_results_path = fs::path("..") /"parsed_results";

    if (!fs::exists(parsed_results_path)) {
        fs::create_directory(parsed_results_path);
    }

    vector<Setup> setups({
        Setup("basic_zero_plus_discr", 1, make_shared<BasicZeroPlusDiscrimination>(), false, 3),
        // Setup("basic_zero_plus_discr", 1, make_shared<BasicZeroPlusDiscrimination>(), false, 3, true),
        Setup("bell_state_reach", 1, make_shared<BellStateReach>(), true, 3),
        // Setup("reset", 20, make_shared<ResetProblem>(), false, 5, true),
        Setup("reset", 22, make_shared<ResetProblem>(), false, 8, false),
        Setup("ghz3", 5, make_shared<GHZStatePreparation3>(), true, 3),
        Setup("bitflip_ipma2", 50, make_shared<IPMA2Bitflip>(), true, 8, false),
        Setup("bitflip_cxh", 20, make_shared<CXHBitflip>(), true, 7),
        Setup("bitflip_ipma", 20, make_shared<IPMABitflip>(), true, 7),
    });

    for (auto setup : setups) {
        string therm_str;
        if (setup.with_thermalization) {
            therm_str = "_therm";
        }
        cout << "parsing experiment " << setup.experiment->name << endl;
        fs::path exp_dir = parsed_results_path / (setup.name + therm_str);
        fs::create_directories(exp_dir);

        fs::path parsed_algorithms_path = exp_dir / "raw_algorithms";
        fs::create_directories(parsed_algorithms_path);

        vector<Algorithm> unique_algorithms;
        vector<int> is_algorithm_convex;

        // fs::path parsed_stats_path = exp_dir / "stats.csv";
        // ofstream parsed_stats_file(parsed_stats_path);
        // parsed_stats_file << join(vector<string>({"hardware",
        // "embedding_index",
        // "horizon",
        // "pomdp_build_time",
        // "probability",
        // "method",
        // "method_time",
        // "algorithm_index"})
        // , ",") << "\n";
        //
        // for (int batch = 0; batch < setup.num_batches; batch++) {
        //     fs::path raw_exp_path = fs::path("..") / "results" / (setup.name + "_" + to_string(batch) + therm_str);
        //     ifstream f(raw_exp_path / "stats.csv");
        //
        //     string line;
        //     getline(f, line);
        //
        //     while (getline(f, line)) {
        //         vector<string> tokens;
        //         split_str(line, ',', tokens);
        //         string quantum_hardware = tokens[0];
        //         string embedding_index = tokens[1];
        //         string horizon = tokens[2];
        //         string pomdp_build_time = tokens[3];
        //         string probability = tokens[4];
        //         string method = tokens[5];
        //         string method_time = tokens[6];
        //         int algorithm_index = stoi(tokens[7]);
        //
        //         std::ifstream curr_alg_file(raw_exp_path / "raw_algorithms" / ("R_" + to_string(algorithm_index+1) + ".txt"));
        //         if (!curr_alg_file.is_open()) {
        //             std::cerr << "Error opening file\n";
        //             return 1;
        //         }
        //
        //         json current_algorithm;
        //         curr_alg_file >> current_algorithm;
        //         curr_alg_file.close();
        //         Algorithm alg_object(current_algorithm);
        //         int real_index = get_algorithm_index(alg_object, unique_algorithms);
        //         if (real_index == -1) {
        //             real_index = unique_algorithms.size();
        //             unique_algorithms.push_back(alg_object);
        //             // dump algorithm
        //             dump_raw_algorithm(parsed_algorithms_path / ("R_" + to_string(real_index) + ".txt"), make_shared<Algorithm>(alg_object));
        //             dump_to_file(parsed_algorithms_path / ("A_" + to_string(real_index) + ".txt"), make_shared<Algorithm>(alg_object));
        //
        //             if (method == "convex") {
        //                 is_algorithm_convex.push_back(true);
        //             } else {
        //                 assert(method == "bellman");
        //                 is_algorithm_convex.push_back(false);
        //             }
        //         }
        //         algorithm_index = real_index;
        //
        //         parsed_stats_file << join(vector<string>({quantum_hardware,
        //         embedding_index,
        //         horizon,
        //         pomdp_build_time,
        //         probability,
        //         method,
        //         method_time,
        //         to_string(algorithm_index)})
        //         , ",") << "\n";
        //     }
        //
        // }
        // parsed_stats_file.close();

        // // test all algorithms in all hardware specifications
        // fs::path verification_path = exp_dir / "verification.csv";
        // ofstream verification_file(verification_path);
        // verification_file << join(vector<string>({"hardware",
        // "embedding_index",
        // "algorithm_index",
        // "probability",
        // "method"})
        // , ",") << "\n";
        //
        // if (!verification_file.is_open()) {
        //     std::cerr << "Error opening verification file " << verification_path << endl;
        //     return 1;
        // }
        // for (auto &hardware_spec : all_specs[setup.with_thermalization]) {
        //     if ((setup.with_cnot && hardware_spec.basis_gates_type != BasisGates::TYPE5 && hardware_spec.basis_gates_type != BasisGates::TYPE2) or !setup.with_cnot) {
        //         auto embeddings = setup.experiment->get_hardware_scenarios(hardware_spec);
        //         for (int embedding_index = 0; embedding_index < embeddings.size(); ++embedding_index) {
        //             cout << "testing hardware spec " << hardware_spec.get_hardware_name() << ", embedding " << (embedding_index+1) << "/ " << embeddings.size() << endl;
        //             auto embedding = embeddings[embedding_index];
        //             POMDP pomdp(setup.experiment->precision);
        //             auto actions = setup.experiment->get_actions(hardware_spec, embedding);
        //             auto initial_distribution = setup.experiment->get_initial_distribution(embedding);
        //             auto qubits_used = setup.experiment->get_qubits_used(embedding);
        //             auto guard = [&setup](const shared_ptr<POMDPVertex>& v, const std::unordered_map<int,int>& m, const shared_ptr<POMDPAction>& a) {
        //                 return setup.experiment->guard(v, m, a);
        //             };
        //             pomdp.build_pomdp(actions, hardware_spec, setup.max_horizon, embedding, nullptr, initial_distribution, qubits_used, guard, setup.experiment->set_hidden_index);
        //             for (int algorithm_index = 0; algorithm_index < unique_algorithms.size(); ++algorithm_index) {
        //
        //                 auto unique_algorithm = unique_algorithms[algorithm_index];
        //
        //                 double probability = 0.0;
        //
        //                 probability = verify_algorithm(pomdp, *setup.experiment, unique_algorithm, hardware_spec, embeddings[embedding_index], is_algorithm_convex[algorithm_index], setup.max_horizon);
        //                 string method = "bellman";
        //                 if (is_algorithm_convex[algorithm_index]) {
        //                     method = "convex";
        //                 }
        //                 verification_file << join(vector<string>({hardware_spec.get_hardware_name(),
        //                     to_string(embedding_index),
        //                     to_string(algorithm_index),
        //                     to_string(round_to(probability, 5)),
        //                     method})
        //                     , ",") << "\n";
        //             }
        //             verification_file.flush();
        //         }
        //     }
        // }
        // verification_file.close();

        // dump hardware specifications
        fs::path unitary_specs = exp_dir / "unitary_specs.csv";
        ofstream unitary_specs_file(unitary_specs);
        unitary_specs_file << join(vector<string>({"hardware",
        "embedding_index",
        "gate_name",
        "probability"})
        , ",") << "\n";

        fs::path measurement_specs = exp_dir / "measurement_specs.csv";
        ofstream measurement_specs_file(measurement_specs);
        measurement_specs_file << join(vector<string>({"hardware",
        "embedding_index",
        "meas0_sucess",
        "meas1_sucess"})
        , ",") << "\n";

        for (auto &hardware_spec : all_specs[setup.with_thermalization]) {
            if ((setup.with_cnot && hardware_spec.basis_gates_type != BasisGates::TYPE5 && hardware_spec.basis_gates_type != BasisGates::TYPE2) or !setup.with_cnot) {
                auto embeddings = setup.experiment->get_hardware_scenarios(hardware_spec);
                for (int embedding_index = 0; embedding_index < embeddings.size(); ++embedding_index) {
                    auto embedding = embeddings[embedding_index];
                    auto actions = setup.experiment->get_actions(hardware_spec, embedding);
                    auto unique_instructions = get_unique_instructions(actions);
                    for (auto instruction : unique_instructions) {
                        if (instruction->instruction_type == InstructionType::Measurement) {
                            shared_ptr<MeasurementChannel> meas_channel = static_pointer_cast<MeasurementChannel>(hardware_spec.get_channel(instruction));
                            measurement_specs_file << join(vector<string>({hardware_spec.get_hardware_name(),
                                to_string(embedding_index),
                                to_string(meas_channel->get_ind_probability(0,0)),
                                to_string(meas_channel->get_ind_probability(1,1)),})
                                , ",") << "\n";
                        } else if (instruction->instruction_type == InstructionType::UnitaryMultiQubit || instruction->instruction_type == InstructionType::UnitarySingleQubit) {
                            shared_ptr<QuantumChannel> quantum_channel = static_pointer_cast<QuantumChannel>(hardware_spec.get_channel(instruction));
                            unitary_specs_file << join(vector<string>({hardware_spec.get_hardware_name(),
                        to_string(embedding_index),
                        gate_to_string(instruction->gate_name),
                        to_string(quantum_channel->estimated_success_prob)})
                        , ",") << "\n";
                        }
                    }
                }
            }
        }

        unitary_specs_file.close();
        measurement_specs_file.close();

    }

    return 0;
}
