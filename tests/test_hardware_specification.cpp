//
// Created by Stefanie Muroya Lei on 14.09.25.
//

#include <gtest/gtest.h>
#include "hardware_specification.hpp"
#include "instruction.hpp"
#include "quantum_gates.hpp"
#include "states.hpp"

// ---------- Enum conversion tests ----------
// TEST(QuantumHardwareTest, StringConversionRoundTrip) {
//     for (int i = 0; i < QuantumHardware::HardwareCount; i++) {
//         QuantumHardware hw = static_cast<QuantumHardware>(i);
//         std::string name = to_string(hw);
//         QuantumHardware hw_back = to_quantum_hardware(name);
//         EXPECT_EQ(hw, hw_back) << "Mismatch for hardware: " << name;
//     }
// }
//
// TEST(QuantumHardwareTest, GetHardwareStringsContainsAll) {
//     std::set<std::string> names = get_hardware_strings();
//     EXPECT_EQ(names.size(), QuantumHardware::HardwareCount);
//
//     for (int i = 0; i < QuantumHardware::HardwareCount; i++) {
//         QuantumHardware hw = static_cast<QuantumHardware>(i);
//         EXPECT_TRUE(names.count(to_string(hw)) > 0);
//     }
// }
//
// // ---------- HardwareSpecification tests (with Lima hardware) ----------
// TEST(HardwareSpecificationTest, ConstructorSetsName) {
//     HardwareSpecification spec(QuantumHardware::Lima, false, false);
//     EXPECT_EQ(spec.get_hardware_name(), "lima");
// }
//
// TEST(HardwareSpecificationTest, ConstructorSetsNumQubits) {
//     HardwareSpecification spec(QuantumHardware::Lima, false, false);
//     EXPECT_EQ(spec.num_qubits, 5);
// }
//
// TEST(HardwareSpecificationTest, ConstructorSetsBasisGatesType) {
//     HardwareSpecification spec(Lima, false, false);
//     EXPECT_EQ(spec.basis_gates_type, BasisGates::TYPE1);
// }
//
// TEST(HardwareSpecificationTest, Digraph) {
//     HardwareSpecification spec(Lima, false, false);
//
//     for (int source = 0; source < spec.digraph.size(); source ++) {
//         EXPECT_TRUE(spec.digraph.find(source) != spec.digraph.end());
//     }
//
//     unordered_map<int, unordered_set<int>> digraph;
//     digraph[0] = unordered_set<int>({1});
//     digraph[1] = unordered_set<int>({0, 2, 3});
//     digraph[2] = unordered_set<int>({1});
//     digraph[3] = unordered_set<int>({1,4});
//     digraph[4] = unordered_set<int>({3});
//
//     EXPECT_EQ(spec.digraph, digraph);
// }
//
// TEST(HardwareSpecificationTest, qubitInDegree) {
//     HardwareSpecification spec(Lima, false, false);
//
//     EXPECT_EQ(spec.get_qubit_indegree(0), 1);
//     EXPECT_EQ(spec.get_qubit_indegree(1), 3);
//     EXPECT_EQ(spec.get_qubit_indegree(2), 1);
//     EXPECT_EQ(spec.get_qubit_indegree(3), 2);
//     EXPECT_EQ(spec.get_qubit_indegree(4), 1);
// }
//
// TEST(ToBasisGatesImpl, ReturnsGateUnchangedIfAlreadyBasis) {
//     HardwareSpecification spec(Algiers, false, false);
//     spec.basis_gates.insert(GateName::Rz);
//
//     Instruction rz(GateName::Rz, 0, vector<double>({1.23}));
//     auto result = spec.to_basis_gates_impl(rz);
//
//     ASSERT_EQ(result.size(), 1);
//     EXPECT_TRUE(result[0].gate_name == GateName::Rz);
//     EXPECT_DOUBLE_EQ(result[0].params[0], 1.23);
// }


class HardwareDecompositionTest : public ::testing::TestWithParam<QuantumHardware> {
protected:
    vector<int> qubits = {0, 1};
    QuantumState init_state{qubits, 5};

    // Helper: apply decomposition returned by to_basis_gates_impl
    shared_ptr<QuantumState> apply_decomposition(HardwareSpecification &spec, const Instruction& instr) {
        auto decomposition = spec.to_basis_gates_impl(instr);
        auto state = make_shared<QuantumState>(init_state);
        for (const auto& d : decomposition) {
            state = state->apply_instruction(d);
        }
        return state;
    }
};

// TEST_P(HardwareDecompositionTest, HGateDecomposition) {
//     QuantumHardware hw_ = GetParam();
//     HardwareSpecification hw{hw_, false, false};
//     Instruction instr(GateName::H, 0);
//     auto direct = init_state.apply_instruction(instr);
//     auto decomposed = apply_decomposition(hw, instr);
//     EXPECT_EQ(*direct, *decomposed);
// }

TEST_P(HardwareDecompositionTest, CnotDecomposition) {
    QuantumHardware hw_ = GetParam();
    HardwareSpecification hw{hw_, false, false};
    cout << hw.get_hardware_name() << " " << hw.basis_gates_type << endl;
    Instruction instr(GateName::Cnot, vector<int>({0}), 1);
    auto direct = init_state.apply_instruction(instr);
    auto decomposed = apply_decomposition(hw, instr);
    EXPECT_EQ(*direct, *decomposed);
}

// TEST_P(HardwareDecompositionTest, ZGateDecomposition) {
//     QuantumHardware hw_ = GetParam();
//     HardwareSpecification hw{hw_, false, false};
//     Instruction instr(GateName::Z, 0);
//     auto direct = init_state.apply_instruction(instr);
//     auto decomposed = apply_decomposition(hw, instr);
//     EXPECT_EQ(*direct, *decomposed);
// }
//
// TEST_P(HardwareDecompositionTest, SGateDecomposition) {
//     QuantumHardware hw_ = GetParam();
//     HardwareSpecification hw{hw_, false, false};
//     Instruction instr(GateName::S, 0);
//     shared_ptr<QuantumState> direct = init_state.apply_instruction(instr);
//     shared_ptr<QuantumState> decomposed = apply_decomposition(hw, instr);
//     EXPECT_EQ(*direct, *decomposed);
// }
//
// // TEST_P(HardwareDecompositionTest, TGateDecomposition) {
// //     Instruction instr(GateName::T, 0);
// //     shared_ptr<QuantumState> direct = init_state.apply_instruction(instr);
// //     shared_ptr<QuantumState> decomposed = apply_decomposition(instr);
// //     EXPECT_EQ(*direct, *decomposed);
// //     delete direct;
// //     delete decomposed;
// // }
//
// TEST_P(HardwareDecompositionTest, RyGateDecomposition) {
//     QuantumHardware hw_ = GetParam();
//     HardwareSpecification hw{hw_, false, false};
//     vector<double> test_angles = {0.0, M_PI/2, M_PI, 2*M_PI, 0.321};
//     for (double theta : test_angles) {
//         Instruction instr(GateName::Ry, 0, vector<double>({theta}));
//         shared_ptr<QuantumState> direct = init_state.apply_instruction(instr);
//         shared_ptr<QuantumState> decomposed = apply_decomposition(hw, instr);
//         EXPECT_EQ(*direct, *decomposed) << "Failed for theta = " << theta;
//     }
// }
//
// TEST_P(HardwareDecompositionTest, RxGateDecomposition) {
//     QuantumHardware hw_ = GetParam();
//     HardwareSpecification hw{hw_, false, false};
//     vector<double> test_angles = {0.0, M_PI/2, M_PI, 2*M_PI, -0.123};
//     for (double theta : test_angles) {
//         Instruction instr(GateName::Rx, 0, vector<double>({theta}));
//         shared_ptr<QuantumState> direct = init_state.apply_instruction(instr);
//         shared_ptr<QuantumState> decomposed = apply_decomposition(hw, instr);
//         EXPECT_EQ(*direct, *decomposed) << "Failed for theta = " << theta;
//     }
// }
//
// TEST_P(HardwareDecompositionTest, U3GateDecomposition) {
//     QuantumHardware hw_ = GetParam();
//     HardwareSpecification hw{hw_, false, false};
//     vector<array<double,3>> test_params = {
//         {M_PI/3, M_PI/7, M_PI/5},
//         {0, 0, 0},
//         {M_PI, M_PI/2, M_PI/4}
//     };
//     for (auto params : test_params) {
//         Instruction instr(GateName::U3, 0, {params[0], params[1], params[2]});
//         shared_ptr<QuantumState> direct = init_state.apply_instruction(instr);
//         shared_ptr<QuantumState> decomposed = apply_decomposition(hw, instr);
//         EXPECT_EQ(*direct, *decomposed)
//             << "Failed for params (" << params[0] << "," << params[1] << "," << params[2] << ")";
//     }
// }

INSTANTIATE_TEST_SUITE_P(
    AllHardware,
    HardwareDecompositionTest,
    ::testing::Values(
        QuantumHardware::Algiers,
        QuantumHardware::Almaden,
        QuantumHardware::Athens,
        QuantumHardware::Auckland,
        QuantumHardware::Belem,
        QuantumHardware::Boeblingen,
        QuantumHardware::Bogota,
        QuantumHardware::Brisbane,
        QuantumHardware::Brooklyn,
        QuantumHardware::Burlington,
        QuantumHardware::Cairo,
        QuantumHardware::Cambridge,
        QuantumHardware::Casablanca,
        QuantumHardware::Cusco,
        QuantumHardware::Essex,
        QuantumHardware::Fez,
        QuantumHardware::Geneva,
        QuantumHardware::Guadalupe,
        QuantumHardware::Hanoi,
        QuantumHardware::Jakarta,
        QuantumHardware::Johannesburg,
        QuantumHardware::Kawasaki,
        QuantumHardware::Kolkata,
        QuantumHardware::Kyiv,
        QuantumHardware::Kyoto,
        QuantumHardware::Lagos,
        QuantumHardware::Lima,
        QuantumHardware::London,
        QuantumHardware::Makarresh,
        QuantumHardware::Melbourne,
        QuantumHardware::Manhattan,
        QuantumHardware::Manila,
        QuantumHardware::Montreal,
        QuantumHardware::Mumbai,
        QuantumHardware::Nairobi,
        QuantumHardware::Osaka,
        QuantumHardware::Oslo,
        QuantumHardware::Ourense,
        QuantumHardware::Paris,
        QuantumHardware::Perth,
        QuantumHardware::Poughkeepsie,
        QuantumHardware::Prague,
        QuantumHardware::Quito,
        QuantumHardware::Rochester,
        QuantumHardware::Rome,
        QuantumHardware::Santiago,
        QuantumHardware::Singapore,
        QuantumHardware::Sydney,
        QuantumHardware::Torino,
        QuantumHardware::Toronto,
        QuantumHardware::Valencia,
        QuantumHardware::Vigo,
        QuantumHardware::Washington,
        QuantumHardware::Yorktown
    )
);


// You can expand with more tests depending on how you implement digraph, basis gates, etc.