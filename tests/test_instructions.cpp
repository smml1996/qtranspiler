//
// Created by Stefanie Muroya Lei on 08.09.25.
//

#include <gtest/gtest.h>
#include "instruction.hpp"
#include "quantum_gates.hpp" // For GateName
#include <nlohmann/json.hpp>
#include <vector>
#include <string>

using namespace std;
using json = nlohmann::json;

// ---------- Construction ----------
TEST(InstructionTest, SingleQubitConstructor) {
    Instruction instr(X, 0);
    EXPECT_EQ(instr.target, 0);
    EXPECT_TRUE(instr.controls.empty());
    EXPECT_EQ(instr.gate_name, X);
    EXPECT_EQ(instr.get_instruction_type(), UnitarySingleQubit);
}

TEST(InstructionTest, SingleQubitParamConstructor) {
    vector<double> params{3.14};
    Instruction instr(Rz, 1, params);
    EXPECT_EQ(instr.target, 1);
    EXPECT_EQ(instr.params, params);
    EXPECT_EQ(instr.params.size(), 1);
    EXPECT_TRUE(instr.controls.empty());
    EXPECT_EQ(instr.get_instruction_type(), UnitarySingleQubit);
}

TEST(InstructionTest, MultiQubitConstructor) {
    vector<int> controls{0,2};
    Instruction instr(Cnot, controls, 1);
    EXPECT_EQ(instr.controls, controls);
    EXPECT_EQ(instr.target, 1);
    EXPECT_EQ(instr.get_instruction_type(), UnitaryMultiQubit);
}

TEST(InstructionTest, MultiQubitParamConstructor) {
    vector<int> controls{0,2};
    vector<double> params{0.5, 1.0};
    Instruction instr(Rzx, controls, 1, params);
    EXPECT_EQ(instr.controls, controls);
    EXPECT_EQ(instr.target, 1);
    EXPECT_EQ(instr.params, params);
    EXPECT_EQ(instr.get_instruction_type(), UnitaryMultiQubit);
}

TEST(InstructionTest, MeasurementConstructor) {
    Instruction instr(Meas, 0, 1);
    EXPECT_EQ(instr.target, 0);
    EXPECT_EQ(instr.c_target, 1);
    EXPECT_EQ(instr.get_instruction_type(), Measurement);
}

TEST(InstructionTest, ClassicalConstructor) {
    Instruction instr(Write0, 1);
    EXPECT_EQ(instr.c_target, 1);
    EXPECT_EQ(instr.get_instruction_type(), Classical);

    Instruction instr2(Write1, 100);
    EXPECT_EQ(instr2.c_target, 100);
    EXPECT_EQ(instr2.get_instruction_type(), Classical);
}

TEST(InstructionTest, ProjectorConstructor) {
    Instruction instr(P0, 1);
    EXPECT_EQ(instr.target, 1);
    EXPECT_EQ(instr.get_instruction_type(), Projector);

    Instruction instr2(P1, 0);
    EXPECT_EQ(instr2.target, 0);
    EXPECT_EQ(instr2.get_instruction_type(), Projector);
}


// ---------- Equality ----------
TEST(InstructionTest, EqualityOperator) {
    Instruction a(X, 0);
    Instruction b(X, 0);
    Instruction c(Y, 0);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

// ---------- String conversion ----------
TEST(InstructionTest, ToString) {
    Instruction instr(H, 1);
    string s = to_string(instr);
    EXPECT_NE(s.find("H"), string::npos);
    EXPECT_NE(s.find("1"), string::npos);
}

// ---------- JSON constructor ----------
TEST(InstructionTest, JsonConstructor) {
    json j = {
        {"type", "instruction"},
        {"target", 0},
        {"control", -1},
        {"op", "X"},
        {"params", "[]"}
    };
    Instruction instr(j);
    EXPECT_EQ(instr.gate_name, X);
    EXPECT_EQ(instr.target, 0);
    EXPECT_EQ(instr.get_instruction_type(), UnitarySingleQubit);
}

// ---------- Hash and pointer equality ----------
TEST(InstructionTest, HashAndPointerEqual) {
    Instruction a(X, 0);
    Instruction b(X, 0);
    Instruction* pa = &a;
    Instruction* pb = &b;
    InstructionHash hasher;
    InstructionPtrEqual equal_fn;
    EXPECT_TRUE(equal_fn(pa, pb));
    EXPECT_EQ(hasher(pa), hasher(pb)); // Hash based on content
}

TEST(InstructionTest, HashAndPointerNotEqual) {
    Instruction a(X, 0);
    Instruction b(X, 10);
    Instruction* pa = &a;
    Instruction* pb = &b;
    InstructionHash hasher;
    InstructionPtrEqual equal_fn;
    EXPECT_FALSE(equal_fn(pa, pb));
    EXPECT_NE(hasher(pa), hasher(pb)); // Hash based on content
}

TEST(InstructionTest, HashAndPointerNotEqual2) {
    Instruction a(H, 0);
    Instruction b(X, 0);
    Instruction* pa = &a;
    Instruction* pb = &b;
    InstructionHash hasher;
    InstructionPtrEqual equal_fn;
    EXPECT_FALSE(equal_fn(pa, pb));
    EXPECT_NE(hasher(pa), hasher(pb)); // Hash based on content
}


// ---------- Identity check ----------
TEST(InstructionTest, IsIdentity) {
    Instruction instr1(I, 0);
    Instruction instr2(I, 1);
    Instruction instr3(X, 0);
    vector<Instruction> seq1{instr1, instr2};
    vector<Instruction> seq2{instr1, instr3};
    EXPECT_TRUE(is_identity(seq1));
    EXPECT_FALSE(is_identity(seq2));
}

// ---------- Edge cases ----------
TEST(InstructionTest, EmptyControlsAndParams) {
    vector<int> empty_controls;
    vector<double> empty_params;
    Instruction instr(Rx, empty_controls, 0, empty_params);
    EXPECT_TRUE(instr.controls.empty());
    EXPECT_TRUE(instr.params.empty());
    EXPECT_EQ(instr.get_instruction_type(), UnitaryMultiQubit);
}
