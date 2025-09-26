//
// Created by Stefanie Muroya Lei on 23.09.25.
//

#include <gtest/gtest.h>
#include "../src/experiments/bitflip.cpp"
#include "../src/experiments/discrimination.cpp"
#include "../src/experiments/ghz.cpp"
#include "../src/experiments/reset.cpp"
#include <set>

using namespace std;

int precision = 5;
bool with_thermalization = false;



set<QuantumHardware> get_hardware_list() {
    set<QuantumHardware> hw_list;
    for (int i = 0; i < HardwareCount; i++) {
        hw_list.insert(static_cast<QuantumHardware>(i));
    }
    return hw_list;
}

// TEST(ExperimentsTests, ResetTest) {
//     const int min_horizon = 2;
//     const int max_horizon = 7;
//     string custom_name = "test_reset_test";
//
//     set<MethodType> methods = {
//         SingleDistBellman,
//         SingleDistPBVI
//     };
//
//     auto hw_list = get_hardware_list();
//
//     ResetProblem reset_problem = ResetProblem(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
//     reset_problem.run();
// }

TEST(ExperimentsTests, ResetTestAlmaden) {
    const int min_horizon = 2;
    const int max_horizon = 7;
    string custom_name = "test_reset_test_almaden";

    set<MethodType> methods = {
        SingleDistBellman,
        // SingleDistPBVI
    };

    auto hw_list = {Almaden};

    ResetProblem reset_problem = ResetProblem(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
    reset_problem.run();
}

TEST(ExperimentsTests, ResetTestBrisbane) {
    const int min_horizon = 7;
    const int max_horizon = 7;
    string custom_name = "test_reset_test_Brisbane";

    set<MethodType> methods = {
        SingleDistBellman,
        // SingleDistPBVI
    };

    auto hw_list = {Brisbane};

    ResetProblem reset_problem = ResetProblem(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
    reset_problem.run();
}

// TEST(ExperimentsTests, BitflipTest) {
//     const int min_horizon = 4;
//     const int max_horizon = 6;
//     string custom_name = "test_bitflip_test";
//
//     set<MethodType> methods = {
//         SingleDistBellman,
//         SingleDistPBVI
//     };
//
//     auto hw_list = get_hardware_list();
//
//     IPMA2Bitflip bitflip_ipma2 = IPMA2Bitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
//     bitflip_ipma2.run();
// }
//
//
// TEST(ExperimentsTests, GHZTest) {
//     string custom_name = "test_ghz_test";
//
//     set<MethodType> methods = {
//         SingleDistBellman,
//         SingleDistPBVI
//     };
//
//     auto hw_list = get_hardware_list();
//     const int min_horizon = 3;
//     const int max_horizon = 3;
//
//     GHZStatePreparation3 ghz_problem(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list);
//     ghz_problem.run();
// }