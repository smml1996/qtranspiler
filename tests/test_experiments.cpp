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

TEST(ExperimentsTests, ResetTest) {
    const int min_horizon = 2;
    const int max_horizon = 4;
    string custom_name = "test_reset_test";

    set<MethodType> methods = {
        SingleDistBellman
    };

    auto hw_list = get_hardware_list();

    ResetProblem reset_problem = ResetProblem(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
    reset_problem.run();
}


TEST(ExperimentsTests, BitflipTest) {
    const int min_horizon = 4;
    const int max_horizon = 5;
    string custom_name = "test_bitflip_test";

    set<MethodType> methods = {
        SingleDistBellman
    };

    auto hw_list = {PerfectHardware, Athens, Almaden};

    IPMA2Bitflip bitflip_ipma2 = IPMA2Bitflip(custom_name, precision, with_thermalization,min_horizon, max_horizon, methods, hw_list);
    bitflip_ipma2.run();
}


TEST(GHZTest, GHZNumEmbeddings) {
    /*
    algiers 37
    almaden 36
    athens 3
    auckland 37
    belem 4
    boeblingen 36
    bogota 3
    brisbane 139
    brooklyn 95
    burlington 4
    cairo 17
    cambridge 36
    casablanca 7
    cusco 141
    essex 4
    fez 244
    geneva 37
    guadalupe 20
    hanoi 37
    jakarta 7
    Johannesburg 32
    kawasaki 141
    kolkata 37
    kyiv 131
    kyoto 140
    lagos 7
    lima 4
    london 4
    makarresh 244
    melbourne 36
    manhattan 95
    manila 3
    montreal 37
    mumbai 37
    nairobi 7
    osaka 142
    oslo 7
    ourense 4
    paris 37
    perth 7
    poughkeepsie 32
    prague 45
    quito 4
    rochester 75
    rome 3
    santiago 3
    singapore 36
    sydney 37
    torino 206
    toronto 37
    valencia 4
    vigo 4
    washington 191
    yorktown 6
    perfect_hardware 1
     */
    string custom_name = "test_ghz3_test";

    set<MethodType> methods = {
        SingleDistBellman,
        SingleDistPBVI
    };

    auto hw_list = get_hardware_list();
    const int min_horizon = 3;
    const int max_horizon = 3;

    GHZStatePreparation3 ghz_problem(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list);
    int total_embeddings = 0;
    for (auto hw : hw_list) {
        HardwareSpecification spec(hw, false);
        auto e = ghz_problem.get_hardware_scenarios(spec);
        cout << spec.get_hardware_name() << " " << e.size() << endl;
        total_embeddings += e.size();
    }

    EXPECT_EQ(total_embeddings, 2780);
}

TEST(GHZTest, GHZ4NumEmbeddings) {
    string custom_name = "test_ghz3_test";

    set<MethodType> methods = {
        SingleDistBellman,
        // SingleDistPBVI
    };

    auto hw_list = {Brisbane};//get_hardware_list();
    const int min_horizon = 4;
    const int max_horizon = 4;

    GHZStatePreparation4 ghz_problem(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list);
    int total_embeddings = 0;
    for (auto hw : hw_list) {
        HardwareSpecification spec(hw, false);
        cout << spec.get_hardware_name() << " " << spec.num_qubits << endl;
        auto e = ghz_problem.get_hardware_scenarios(spec);
        cout << spec.get_hardware_name() << " " << e.size() << endl;
        total_embeddings += e.size();
    }

    EXPECT_EQ(total_embeddings, 2780);
}

TEST(ExperimentsTests, GHZ3Test) {
    string custom_name = "test_ghz3_test";

    set<MethodType> methods = {
        SingleDistBellman,
        // SingleDistPBVI
    };

    auto hw_list = {PerfectHardware, Athens};
    const int min_horizon = 3;
    const int max_horizon = 3;

    GHZStatePreparation3 ghz_problem(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list);
    ghz_problem.run();
}




TEST(ConvexSolver, ZeroPlusDiscrimination) {

    const int min_horizon = 3;
    const int max_horizon = 3;
    string custom_name = "test_zero_plus_discr_test";

    set<MethodType> methods = {
        ConvexDist
    };

    auto hw_list = {PerfectHardware, Almaden};

    auto zero_plus_problem = BasicZeroPlusDiscrimination(custom_name, precision, with_thermalization, min_horizon, max_horizon, methods, hw_list);
    zero_plus_problem.run();

}