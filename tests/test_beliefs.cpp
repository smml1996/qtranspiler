//
// Created by Stefanie Muroya Lei on 14.09.25.
//
#include "beliefs.hpp"
#include <gtest/gtest.h>

class BeliefTest : public ::testing::Test {
protected:
    QuantumState qs{ {0}, 10 }; // small precision for example
    ClassicalState cs;
    HybridState hs{ &qs, &cs };

    POMDPVertex v1{ &hs, 0 };
    POMDPVertex v2{ &hs, 1 };

    Belief b;

    void SetUp() override {
        auto val = Rational("1", "2", 10);
        b.set_val(&v1, val);  // 0.5
        b.set_val(&v2, Rational("1", "2", 10));  // 0.5
    }
};

TEST_F(BeliefTest, GetAndSet) {
    EXPECT_EQ(b.get(&v1, 10), Rational("1", "2", 10));
    EXPECT_EQ(b.get(&v2, 10), Rational("1", "2", 10));
    b.set_val(&v1, Rational("3", "4", 10));
    EXPECT_EQ(b.get(&v1, 10), Rational("3", "4", 10));
}

TEST_F(BeliefTest, AddVal) {
    b.add_val(&v1, Rational("1", "4", 10));  // 0.5 + 0.25 = 0.75
    EXPECT_EQ(b.get(&v1, 10), Rational("3", "4", 10));
}

TEST_F(BeliefTest, SumIsCorrect) {
    EXPECT_EQ(b.get_sum(10), Rational("1", "1", 10));  // 0.5 + 0.5 = 1
}

TEST_F(BeliefTest, NormalizationCheck) {
    EXPECT_TRUE(b.is_normalized(10));  // already normalized
    b.set_val(&v1, Rational("2", "1", 10));       // total = 2.5
    EXPECT_FALSE(b.is_normalized(10));
}

TEST_F(BeliefTest, EqualityOperator) {
    Belief b2;
    b2.set_val(&v1, Rational("1", "2", 10));
    b2.set_val(&v2, Rational("1", "2", 10));
    EXPECT_TRUE(b == b2);

    b2.set_val(&v2, Rational("3", "4", 10));
    EXPECT_FALSE(b == b2);
}

TEST_F(BeliefTest, NormalizeBelief) {
    Belief b2;
    b2.set_val(&v1, Rational("2", "1", 10));   // not normalized
    b2.set_val(&v2, Rational("2", "1", 10));
    auto b_norm = normalize_belief(b2, 10);

    EXPECT_TRUE(b_norm.is_normalized(10));
    EXPECT_EQ(b_norm.get(&v1, 10), Rational("1", "2", 10));
    EXPECT_EQ(b_norm.get(&v2, 10), Rational("1", "2", 10));
}

TEST_F(BeliefTest, L1Norm) {
    Belief b2;
    b2.set_val(&v1, Rational("3", "4", 10)); // 0.75
    b2.set_val(&v2, Rational("1", "4", 10)); // 0.25

    Rational dist = l1_norm(b, b2, 10); // |0.5-0.75| + |0.5-0.25| = 0.5
    EXPECT_EQ(dist, Rational("1", "2", 10));
}

TEST_F(BeliefTest, BeliefHasher) {
    Belief belief;

    belief.set_val(&v1, Rational("3", "4", 10)); // 0.75
    belief.set_val(&v2, Rational("1", "4", 10)); // 0.25

    BeliefHash bh;

    EXPECT_EQ(bh(belief), bh(belief));

    Belief belief2;
    belief2.set_val(&v1, Rational("1", "2", 10)); // 0.75
    belief2.set_val(&v2, Rational("1", "2", 10)); // 0.25
    EXPECT_FALSE(bh(belief) == bh(belief2));

}