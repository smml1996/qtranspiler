#include <cassert>
#include <iostream>
#include <set>
#include <string>

#include "cxxopts.hpp"
#include "experiments.hpp"
#include "hardware_specification.hpp"
#include "bitflip.cpp"
#include "ghz.cpp"
#include "reset.cpp"

using namespace std;


int main(int argc, char* argv[]) {
    // Valid sets
    set<string> valid_experiments = {"ghz3", "ghz4", "bitflip_ipma",
        "bitflip_ipma2", "bitflip_ipma3","bitlfip_cxh" "reset", "bell_state_discr_ipma2", "bell_state_discr_ipma3"};
    set<string> valid_methods = get_solver_methods_strings();
    set<string> valid_hardware = get_hardware_strings();

    cxxopts::Options options("main", "Run quantum experiments with POMDPs");

    options.add_options()
        ("experiment", "Experiment name", cxxopts::value<std::string>())
        ("custom_name", "Custom name", cxxopts::value<std::string>()->default_value(""))
        ("method", "Method name", cxxopts::value<std::vector<std::string>>())
        ("hardware", "Comma-separated list of hardware specs", cxxopts::value<std::string>()->default_value(""))
        ("min_horizon", "Minimum horizon", cxxopts::value<int>())
        ("max_horizon", "Maximum horizon", cxxopts::value<int>())
        ("precision", "Precision", cxxopts::value<int>()->default_value("8"))
        ("with_thermalization", "Enable thermalization", cxxopts::value<bool>()->default_value("false"))
        ("round_in_file", "files generated will round to the given number", cxxopts::value<int>()->default_value("5"))
        ("h,help", "Print usage");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        cout << options.help() << "\n";
        return 0;
    }

    Experiment::round_in_file =  result["round_in_file"].as<int>();

    // 1. Experiment name validation
    std::string experiment = result["experiment"].as<std::string>();
    if (!valid_experiments.count(experiment)) {
        throw std::invalid_argument("Invalid experiment: " + experiment);
    }

    // 1.1 custom name
    std::string custom_name = result["custom_name"].as<std::string>();

    // 2. Method validation
    auto raw_methods = result["method"].as<std::vector<std::string>>();
    set<MethodType> methods;
    for (auto& m : raw_methods) {
        if (!valid_methods.count(m)) {
            throw std::invalid_argument("Invalid method: " + m);
        }
        methods.insert(str_to_method_type(m));
    }

    // 3. Hardware validation (split by commas)
    std::string hw_string = result["hardware"].as<std::string>();
    set<QuantumHardware> hw_list;
    std::stringstream ss(hw_string);
    std::string item;
    while (std::getline(ss, item, ',')) {
        if (!valid_hardware.count(item)) {
            throw std::invalid_argument("Invalid hardware spec: " + item);
        }
        hw_list.insert(to_quantum_hardware(item));
    }

    // 4 & 5. Horizon validation
    int min_horizon = result["min_horizon"].as<int>();
    int max_horizon = result["max_horizon"].as<int>();
    if (max_horizon < min_horizon) {
        throw std::invalid_argument("max_horizon must be >= min_horizon");
    }

    // 6. Optional arguments
    int precision = result["precision"].as<int>();
    bool with_thermalization = result["with_thermalization"].as<bool>();


    if (experiment == "bitflip_ipma") {
        IPMABitflip bitflip_ipma = IPMABitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
        bitflip_ipma.run();
    }
    else if (experiment == "bitflip_ipma2") {
        IPMA2Bitflip bitflip_ipma2 = IPMA2Bitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
        bitflip_ipma2.run();
    }
    else if (experiment == "bitflip_ipma3") {
        IPMA3Bitflip bitflip_ipma3 = IPMA3Bitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
        bitflip_ipma3.run();
    }
    else if (experiment == "bitflip_cxh") {
        CXHBitflip bitflip_cxh = CXHBitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
        bitflip_cxh.run();
    }
    else if (experiment == "reset") {
        ResetProblem reset_problem = ResetProblem(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
        reset_problem.run();
    }
    else if (experiment == "ghz3") {
        GHZStatePreparation3 ghz3_problem = GHZStatePreparation3(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
        ghz3_problem.run();
    }
    else if (experiment == "ghz4") {
        GHZStatePreparation4 ghz3_problem = GHZStatePreparation4(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
        ghz3_problem.run();

    } else if (experiment == "bell_state_discr_ipma2") {
        auto bell_state_discr_problem = BellStateDiscrimination2(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
        bell_state_discr_problem.run();
    }
    else if (experiment == "bell_state_discr_ipma3") {
        auto bell_state_discr_problem = BellStateDiscrimination3(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
        bell_state_discr_problem.run();
    }
    else {
        throw std::invalid_argument("Invalid experiment: " + experiment);
    }
}
