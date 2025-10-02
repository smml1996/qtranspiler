//
// Created by Stefanie Muroya Lei on 23.09.25.
//

#include <gtest/gtest.h>
#include "../src/experiments/bitflip.cpp"
#include "../src/experiments/discrimination.cpp"
#include "../src/experiments/ghz.cpp"
#include "../src/experiments/bellstate_reach.cpp"
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
//     const int max_horizon = 4;
//     string custom_name = "test_reset_test";
//
//     set<MethodType> methods = {
//         SingleDistBellman
//     };
//
//     auto hw_list = get_hardware_list();
//
//     ResetProblem reset_problem = ResetProblem(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list, false);
//     reset_problem.run();
// }
//
//
// TEST(ExperimentsTests, BitflipTest) {
//     const int min_horizon = 4;
//     const int max_horizon = 5;
//     string custom_name = "test_bitflip_test";
//
//     set<MethodType> methods = {
//         SingleDistBellman
//     };
//
//     auto hw_list = {PerfectHardware, Athens, Almaden};
//
//     IPMA2Bitflip bitflip_ipma2 = IPMA2Bitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list, false);
//     bitflip_ipma2.run();
// }
//
//
// TEST(GHZTest, GHZNumEmbeddings) {
//     /*
//     algiers 37
//     almaden 36
//     athens 3
//     auckland 37
//     belem 4
//     boeblingen 36
//     bogota 3
//     brisbane 139
//     brooklyn 95
//     burlington 4
//     cairo 17
//     cambridge 36
//     casablanca 7
//     cusco 141
//     essex 4
//     fez 244
//     geneva 37
//     guadalupe 20
//     hanoi 37
//     jakarta 7
//     Johannesburg 32
//     kawasaki 141
//     kolkata 37
//     kyiv 131
//     kyoto 140
//     lagos 7
//     lima 4
//     london 4
//     makarresh 244
//     melbourne 36
//     manhattan 95
//     manila 3
//     montreal 37
//     mumbai 37
//     nairobi 7
//     osaka 142
//     oslo 7
//     ourense 4
//     paris 37
//     perth 7
//     poughkeepsie 32
//     prague 45
//     quito 4
//     rochester 75
//     rome 3
//     santiago 3
//     singapore 36
//     sydney 37
//     torino 206
//     toronto 37
//     valencia 4
//     vigo 4
//     washington 191
//     yorktown 6
//     perfect_hardware 1
//      */
//     string custom_name = "test_ghz3_test";
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
//     GHZStatePreparation3 ghz_problem(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list, false);
//     int total_embeddings = 0;
//     for (auto hw : hw_list) {
//         HardwareSpecification spec(hw, false, false);
//         auto e = ghz_problem.get_hardware_scenarios(spec);
//         cout << spec.get_hardware_name() << " " << e.size() << endl;
//         total_embeddings += e.size();
//     }
//
//     EXPECT_EQ(total_embeddings, 2780);
// }

// TEST(GHZTest, GHZ4NumEmbeddings) {
//     string custom_name = "test_ghz3_test";
//
//     set<MethodType> methods = {
//         SingleDistBellman,
//         // SingleDistPBVI
//     };
//
//     auto hw_list = {Brisbane};//get_hardware_list();
//     const int min_horizon = 4;
//     const int max_horizon = 4;
//
//     GHZStatePreparation4 ghz_problem(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list, false);
//     int total_embeddings = 0;
//     for (auto hw : hw_list) {
//         HardwareSpecification spec(hw, false, false);
//         cout << spec.get_hardware_name() << " " << spec.num_qubits << endl;
//         auto e = ghz_problem.get_hardware_scenarios(spec);
//         cout << spec.get_hardware_name() << " " << e.size() << endl;
//         total_embeddings += e.size();
//     }
//
//     EXPECT_EQ(total_embeddings, 2780);
// }

TEST(ExperimentsTests, GHZ3Test) {
    string custom_name = "test_ghz3_test";

    set<MethodType> methods = {
        SingleDistBellman,
        // SingleDistPBVI
    };

    auto hw_list = get_hardware_list();
    const int min_horizon = 3;
    const int max_horizon = 3;

    GHZStatePreparation3 ghz_problem(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list, false);
    ghz_problem.run();
}
//
//
//
//
// TEST(ConvexSolver, ZeroPlusDiscrimination) {
//
//     const int min_horizon = 3;
//     const int max_horizon = 3;
//     string custom_name = "test_zero_plus_discr_test2";
//
//     set<MethodType> methods = {
//         ConvexDist
//     };
//
//     auto hw_list = {PerfectHardware, Almaden};
//
//     auto zero_plus_problem = BasicZeroPlusDiscrimination(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list, false);
//     zero_plus_problem.run();
//
// }
//
// TEST(OptimizedModels, ResetOptimized) {
//     const int min_horizon = 2;
//     const int max_horizon = 4;
//     string custom_name = "test_reset_test_opt";
//
//     set<MethodType> methods = {
//         SingleDistBellman
//     };
//
//     auto hw_list = get_hardware_list();
//
//     ResetProblem reset_problem = ResetProblem(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list, true);
//     reset_problem.run();
//
// }
//
// TEST(OptimizedModels, BitflipTestOptimized) {
//     const int min_horizon = 4;
//     const int max_horizon = 5;
//     string custom_name = "test_bitflip_test_opt";
//
//     set<MethodType> methods = {
//         SingleDistBellman
//     };
//
//     auto hw_list = {PerfectHardware, Athens, Almaden};
//
//     IPMA2Bitflip bitflip_ipma2 = IPMA2Bitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list, true);
//     bitflip_ipma2.run();
// }
//
// TEST(OptimizedModels, GHZ3TestOptimized) {
//     string custom_name = "test_ghz3_test_opt";
//
//     set<MethodType> methods = {
//         SingleDistBellman,
//         // SingleDistPBVI
//     };
//
//     auto hw_list = {PerfectHardware, Athens};
//     const int min_horizon = 3;
//     const int max_horizon = 3;
//
//     GHZStatePreparation3 ghz_problem(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list, true);
//     ghz_problem.run();
// }
//
// TEST(OptimizedModels, ZeroPlusDiscriminationOptimized) {
//
//     const int min_horizon = 3;
//     const int max_horizon = 3;
//     string custom_name = "test_zero_plus_discr_test_opt";
//
//     set<MethodType> methods = {
//         ConvexDist
//     };
//
//     auto hw_list = {PerfectHardware, Almaden};
//
//     auto zero_plus_problem = BasicZeroPlusDiscrimination(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list, true);
//     zero_plus_problem.run();
//
// }

// TEST(OptimizedModels, CXHOptimized) {
//
//     const int min_horizon = 3;
//     const int max_horizon = 3;
//     string custom_name = "test_cxh_test_opt";
//
//     set<MethodType> methods = {
//         SingleDistBellman
//     };
//
//     auto hw_list = {PerfectHardware, Almaden};
//
//     auto cxh_problem = CXHBitflip(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list, true);
//     cxh_problem.run();
//
// }


// TEST(ThermalizationModels, ThermalReset) {
//     const int min_horizon = 2;
//     const int max_horizon = 4;
//     string custom_name = "test_reset_test_therm";
//
//     set<MethodType> methods = {
//         SingleDistBellman
//     };
//
//     auto hw_list = {PerfectHardware, Athens, Almaden};
//
//     ResetProblem reset_problem = ResetProblem(custom_name, precision, true, min_horizon, max_horizon, methods, hw_list, true);
//     reset_problem.run();
//
// }

// TEST(ThermalizationModels, ThermalBitflipTest) {
//     const int min_horizon = 4;
//     const int max_horizon = 5;
//     string custom_name = "test_bitflip_test_therm";
//
//     set<MethodType> methods = {
//         SingleDistBellman
//     };
//
//     auto hw_list = {PerfectHardware, Athens, Almaden};
//
//     IPMA2Bitflip bitflip_ipma2 = IPMA2Bitflip(custom_name, precision, true, min_horizon, max_horizon, methods, hw_list, true);
//     bitflip_ipma2.run();
// }
//
// TEST(ThermalizationModels, ThermalGHZ3Test) {
//     string custom_name = "test_ghz3_test_therm";
//
//     set<MethodType> methods = {
//         SingleDistBellman,
//         // SingleDistPBVI
//     };
//
//     auto hw_list = {PerfectHardware, Athens};
//     const int min_horizon = 3;
//     const int max_horizon = 3;
//
//     GHZStatePreparation3 ghz_problem(custom_name, precision, true, min_horizon, max_horizon, methods, hw_list, true);
//     ghz_problem.run();
// }
//
// TEST(ThermalizationModels, ThermalZeroPlusDiscrimination) {
//
//     const int min_horizon = 3;
//     const int max_horizon = 3;
//     string custom_name = "test_zero_plus_discr_test_therm";
//
//     set<MethodType> methods = {
//         ConvexDist
//     };
//
//     auto hw_list = {PerfectHardware, Almaden};
//
//     auto zero_plus_problem = BasicZeroPlusDiscrimination(custom_name, precision, true, min_horizon, max_horizon, methods, hw_list, true);
//     zero_plus_problem.run();
//
// }

// TEST(BitflipTest, BitflipTestIPMA) {
//     const int min_horizon = 1;
//     const int max_horizon = 3;
//     string custom_name = "test_bitflipIPMA_all";
//
//     set<MethodType> methods = {
//         SingleDistBellman
//     };
//
//     set<QuantumHardware> hw_list;
//
//     for (int i = 0; i < HardwareCount; i++) {
//         HardwareSpecification hs = HardwareSpecification(static_cast<QuantumHardware>(i), false, false);
//         if (hs.basis_gates_type != BasisGates::TYPE5) {
//             hw_list.insert(hs.get_hardware());
//         }
//     }
//
//     IPMABitflip bitflip_ipma = IPMABitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list, false);
//     bitflip_ipma.run();
// }

// TEST(BitflipTest, BitflipTestIPMA2) {
//     const int min_horizon = 1;
//     const int max_horizon = 3;
//     string custom_name = "test_bitflipIPMA2_all";
//
//     set<MethodType> methods = {
//         SingleDistBellman
//     };
//
//     set<QuantumHardware> hw_list;
//
//     for (int i = 0; i < HardwareCount; i++) {
//         HardwareSpecification hs = HardwareSpecification(static_cast<QuantumHardware>(i), false, true);
//         if (hs.basis_gates_type != BasisGates::TYPE5 && hs.basis_gates_type != BasisGates::TYPE2) {
//             hw_list.insert(hs.get_hardware());
//         }
//     }
//
//     auto bitflip_ipma = IPMA2Bitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list, false);
//     bitflip_ipma.run();
// }

// TEST(BitflipTest, BitflipTestCXH) {
//     const int min_horizon = 3;
//     const int max_horizon = 3;
//     string custom_name = "test_bitflipCXH_all";
//
//     set<MethodType> methods = {
//         SingleDistBellman
//     };
//
//     set<QuantumHardware> hw_list;
//
//     for (int i = 0; i < HardwareCount; i++) {
//         HardwareSpecification hs = HardwareSpecification(static_cast<QuantumHardware>(i), false, false);
//         if (hs.basis_gates_type != BasisGates::TYPE5 && hs.basis_gates_type != BasisGates::TYPE2) {
//             hw_list.insert(hs.get_hardware());
//         }
//     }
//
//     auto bitflip_cxh = CXHBitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list, false);
//     bitflip_cxh.run();
// }

// TEST(BellStateReachTest, BellStateReach) {
//     const int min_horizon = 1;
//     const int max_horizon = 2;
//     string custom_name = "test_bell_state_reach";
//
//     set<MethodType> methods = {
//         SingleDistBellman,
//         ConvexDist
//     };
//
//     set<QuantumHardware> hw_list = {PerfectHardware, Algiers};
//
//     auto bell_state_reach = BellStateReach(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list, true);
//     bell_state_reach.run();
// }