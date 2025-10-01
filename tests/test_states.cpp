//
// Created by Stefanie Muroya Lei on 08.09.25.
//

#include "gtest/gtest.h"
#include "states.hpp"
#include "instruction.hpp"
#include "quantum_gates.hpp"
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

// ---------- QuantumState basic ----------
TEST(QuantumStateTest, Initialization) {
    QuantumState qs({0,1}, 10);
    EXPECT_EQ(qs.qubits_used.size(), 2);
    EXPECT_TRUE(qs.sparse_vector.size() == 1);
    EXPECT_TRUE(qs.sparse_vector.find(0) != qs.sparse_vector.end());
    EXPECT_EQ(qs.sparse_vector[0], complex<double>(1, 0));
    EXPECT_TRUE(qs.is_qubit_0());
    EXPECT_TRUE(qs.is_qubit()); // general check
}

TEST(QuantumStateTest, AmplitudeInsertionAndRetrieval) {
    QuantumState qs({0}, 10);
    EXPECT_EQ(qs.get_amplitude(0), complex<double>(1.0,0.0));
    qs.add_amplitude(0, complex<double>(0.5,0.5));
    EXPECT_EQ(qs.get_amplitude(0), complex<double>(1.5,0.5));
}

// ---------- Normalization ----------
TEST(QuantumStateTest, Normalize) {
    QuantumState qs({0,1}, 10);
    qs.insert_amplitude(0, complex<double>(3.0, 4.0));
    qs.insert_amplitude(1, complex<double>(0.0, 0.0));
    qs.normalize();
    EXPECT_NEAR(abs(qs.get_amplitude(0)), 1.0, 1e-10);
}

// ---------- Single-qubit gate ----------
TEST(QuantumStateTest, EvalSingleQubitGate) {
    QuantumState qs({0}, 10);
    Instruction instr(H, 0); // Hadamard
    auto new_qs = qs.eval_single_qubit_gate(instr);
    EXPECT_NEAR(abs(new_qs->get_amplitude(0)), 1/std::sqrt(2), 1e-10);
    EXPECT_NEAR(abs(new_qs->get_amplitude(1)), 1/std::sqrt(2), 1e-10);
}

TEST(QuantumStateTest, EqHGate) {
    QuantumState qs({0}, 10);
    Instruction instr(H, 0); // Hadamard
    auto new_qs1 = qs.eval_single_qubit_gate(instr);
    auto new_qs2 = qs.eval_single_qubit_gate(instr);

    EXPECT_TRUE(*new_qs1 == *new_qs2);
}

TEST(QuantumStateTest, EqHDecomposition) {
    QuantumState qs({0}, 10);
    Instruction HGate(H, 0); // Hadamard
    Instruction RzGate(Rz,0 ,vector<double>({my_pi/2}));
    Instruction SXGate(Sx, 0);

    auto direct = qs.apply_instruction(HGate);
    auto temp = qs.apply_instruction(RzGate);
    auto current = temp->apply_instruction(SXGate);
    temp = current;
    current = temp->apply_instruction(RzGate);
    EXPECT_TRUE(*direct == *current);
}
// ---------- Multi-qubit gate ----------
TEST(QuantumStateTest, EvalMultiQubitGate) {
    QuantumState qs({0,1}, 10);
    Instruction instr(Cnot, vector<int>{0}, 1);
    auto new_qs = qs.eval_multiqubit_gate(instr);
    EXPECT_TRUE(new_qs->get_amplitude(0) != complex<double>(0,0));
}

// ---------- Apply instruction ----------
TEST(QuantumStateTest, ApplyInstruction) {
    QuantumState qs({0}, 10);
    Instruction instr(X, 0);
    auto new_qs = qs.apply_instruction(instr);
    EXPECT_EQ(new_qs->get_amplitude(1), complex<double>(1.0,0.0));
}

// ---------- Controls ----------
TEST(QuantumStateTest, AreControlsTrue) {
    int basis = 0b101; // qubits 0 and 2 are 1
    vector<int> controls1{0,2};
    vector<int> controls2{1};
    EXPECT_TRUE(QuantumState::are_controls_true(basis, controls1));
    EXPECT_FALSE(QuantumState::are_controls_true(basis, controls2));
}

// ---------- Inner product and fidelity ----------
TEST(QuantumStateTest, InnerProductAndFidelity) {
    QuantumState qs1({0}, 10);
    QuantumState qs2({0}, 10);
    auto ip = get_inner_product(qs1, qs2);
    EXPECT_EQ(ip, complex<double>(1.0,0.0));
    EXPECT_NEAR(get_fidelity(qs1, qs2), 1.0, 1e-10);
}

// ---------- ClassicalState ----------
TEST(ClassicalStateTest, ReadWrite) {
    ClassicalState cs;
    auto cs2 = cs.write(0, true);
    EXPECT_TRUE(cs2->read(0));
    EXPECT_FALSE(cs2->read(100));
    auto cs3 = cs2->write(1, false);
    EXPECT_FALSE(cs3->read(1));
}

TEST(ClassicalStateTest, Equality) {
    ClassicalState cs1;
    ClassicalState cs2;
    EXPECT_TRUE(cs1 == cs2);
    auto cs3 = cs1.write(0, true);
    EXPECT_FALSE(*cs3 == (cs2));
}

// ---------- HybridState ----------
TEST(HybridStateTest, ApplyInstruction) {
    QuantumState qs({0}, 10);
    ClassicalState cs;
    HybridState hs(make_shared<QuantumState>(qs), make_shared<ClassicalState>(cs));
    Instruction instr(X, 0);
    auto new_hs = hs.apply_instruction(instr);
    EXPECT_EQ(new_hs->quantum_state->get_amplitude(1), complex<double>(1.0,0.0));
}

// ---------- Multi partial trace ----------
TEST(QuantumStateTest, MultiPartialTrace) {
    QuantumState qs({0,1}, 10);
    auto pt = qs.multi_partial_trace({1});
    EXPECT_EQ(pt.size(), 2);
    EXPECT_EQ(pt[0].size(), 2);
}
