//
// Created by Stefanie Muroya Lei on 08.09.25.
//

#include <gtest/gtest.h>
#include <unordered_set>
#include <string>
#include "quantum_gates.hpp" // adjust include path

using namespace std;

// ---------- get_value ----------
TEST(GateEnumTest, GetValueBasic) {
    auto s1 = get_value(TYPE1);
    EXPECT_FALSE(s1.empty());
    for (auto g : s1) {
        EXPECT_GE(g, I);
        EXPECT_LE(g, GateName::count);
    }

    auto s2 = get_value(TYPE2);
    EXPECT_FALSE(s2.empty());
    EXPECT_NE(s1, s2);

    auto s_last = get_value(TYPE6);
    EXPECT_FALSE(s_last.empty());
}

// ---------- Round-trip consistency ----------
TEST(GateEnumTest, GetBasisGatesTypeRoundTrip) {
    for (int i = TYPE1; i < BasisGatesCount; i++) {
        auto basis = static_cast<BasisGates>(i);
        auto set_val = get_value(basis);
        auto back = get_basis_gates_type(set_val);
        EXPECT_EQ(back, basis);
    }
}

// ---------- Get enum object from string ----------
TEST(GateEnumTest, GetEnumObjValid) {
    EXPECT_EQ(get_enum_obj("X"), X);
    EXPECT_EQ(get_enum_obj("H"), H);
    EXPECT_EQ(get_enum_obj("CNOT"), Cnot);
    EXPECT_EQ(get_enum_obj("RX"), Rx);
    EXPECT_EQ(get_enum_obj("MEAS"), Meas);
    EXPECT_EQ(get_enum_obj("CUSTOM"), Custom);
}

TEST(GateEnumTest, GetEnumObjInvalid) {
    EXPECT_THROW(get_enum_obj("INVALID_GATE"), invalid_argument);
    EXPECT_THROW(get_enum_obj(""), invalid_argument);
}

// ---------- Edge cases ----------
TEST(GateEnumTest, EnumCountSanity) {
    EXPECT_GT(GateName::count, 0);
    EXPECT_LT(I, GateName::count);
    EXPECT_LT(Toffoli, GateName::count);
}

TEST(GateEnumTest, BasisGatesCountSanity) {
    EXPECT_GT(BasisGatesCount, 0);
    EXPECT_LT(TYPE1, BasisGatesCount);
    EXPECT_LT(TYPE6, BasisGatesCount);
}

TEST(GateEnumTest, GetBasisGatesTypeEmptyThrows) {
    unordered_set<GateName> empty_set;
    EXPECT_THROW(get_basis_gates_type(empty_set), invalid_argument);
}

