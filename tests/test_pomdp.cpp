//
// Created by Stefanie Muroya Lei on 14.09.25.
//
#include <gtest/gtest.h>
#include "pomdp.hpp"

int precision = 10;

// POMDP vertex tests
TEST(POMDVertexTest, VertexConstructor) {
    const auto cs = make_shared<ClassicalState>();
    auto s = make_shared<HybridState>(make_shared<QuantumState>(vector<int>({0}), precision), cs);
    const auto vertex1 = make_shared<POMDPVertex>(s);

    EXPECT_EQ(*vertex1->hybrid_state, *s);
    EXPECT_EQ(vertex1->hidden_index, -1);
    EXPECT_EQ(vertex1->id, 1);
    EXPECT_EQ(*vertex1->get_obs(), *cs);
    EXPECT_EQ(vertex1, vertex1);

    const auto vertex2 = make_shared<POMDPVertex>(s, 1);
    EXPECT_TRUE(*vertex2 == *vertex2);
    EXPECT_EQ(vertex2->id, 2);
    EXPECT_EQ(vertex2->hidden_index, 1);
}

// POMDP Action tests
class POMDPActionTest : public ::testing::Test {
protected:
    int precision = 10;

    shared_ptr<QuantumState> qs = make_shared<QuantumState>(vector<int>({0}), precision );
    shared_ptr<ClassicalState> cs = make_shared<ClassicalState>();
    shared_ptr<HybridState> hybrid_state = make_shared<HybridState>( qs, cs );
    shared_ptr<POMDPVertex> vertex = make_shared<POMDPVertex>(hybrid_state, 0);

    HardwareSpecification hardware{ QuantumHardware::Algiers, false };

    Instruction meas_ins{ GateName::Meas, 0 , 0};
    Instruction x_ins{ GateName::X, 0 };
    Instruction reset_ins{ GateName::Reset, 0 };

    std::unique_ptr<POMDPAction> action;

    void SetUp() override {
        action = std::make_unique<POMDPAction>(
            "test_action",
            std::vector<Instruction>{ x_ins },
            precision,
            std::vector<Instruction>{}
        );
    }
};

TEST_F(POMDPActionTest, EqualityOperator) {
    const POMDPAction a1("action1", {x_ins}, precision, {});
    const POMDPAction a2("action1", {x_ins}, precision, {});
    const POMDPAction a3("action2", {meas_ins}, precision, {});

    EXPECT_TRUE(a1 == a2);
    EXPECT_FALSE(a1 == a3);
}

TEST_F(POMDPActionTest, HashAndPtrEqual) {
    const POMDPAction a1("action1", {x_ins}, precision, {x_ins});
    const POMDPAction a2("action1", {x_ins}, precision, {x_ins});

    constexpr POMDPActionHash hasher;
    constexpr POMDPActionPtrEqual eq;

    EXPECT_TRUE(eq(make_shared<POMDPAction>(a1), make_shared<POMDPAction>(a2)));
    EXPECT_EQ(hasher(make_shared<POMDPAction>(a1)), hasher(make_shared<POMDPAction>(a2)));
}

TEST_F(POMDPActionTest, ToStringWorks) {
    const POMDPAction a1("action1", {x_ins}, precision, {x_ins});
    std::string str1 = to_string(a1);
    std::string str2 = to_string(make_shared<POMDPAction>(a1));

    EXPECT_NE(str1.find("X([q0]); "), std::string::npos);
    EXPECT_NE(str2.find("X([q0]); "), std::string::npos);
}

TEST_F(POMDPActionTest, GetSuccessorStatesUnitary) {
    // Action applies an X gate
    const POMDPAction x_action("x_action", {x_ins}, precision, {x_ins});
    const vertex_dict result = x_action.get_successor_states(hardware, vertex);

    double prob_sum = 0.0;
    for (auto &kv : result) {
        prob_sum += kv.second;
        EXPECT_NE(kv.first, nullptr);
    }

    EXPECT_NEAR(prob_sum, 1.0, 1e-9);
}

TEST_F(POMDPActionTest, GetSuccessorStatesMeasurement) {
    // Action applies a measurement
    POMDPAction m_action("m_action", {meas_ins}, precision, {meas_ins});
    vertex_dict result = m_action.get_successor_states(hardware, vertex);
    double prob_sum = 0.0;
    for (auto &kv : result) {
        prob_sum += kv.second;
        EXPECT_NE(kv.first, nullptr);
    }

    EXPECT_NEAR(prob_sum, 1.0, 1e-9);
    EXPECT_GE(result.size(), 2);  // typically two outcomes for measurement
}

TEST_F(POMDPActionTest, GetSuccessorStatesReset) {
    // Action applies a reset
    POMDPAction r_action("r_action", {reset_ins}, precision, {reset_ins});
    vertex_dict result = r_action.get_successor_states(hardware, vertex);

    double prob_sum = 0.0;
    for (auto &kv : result) {
        prob_sum += kv.second;
        EXPECT_NE(kv.first, nullptr);
    }

    EXPECT_NEAR(prob_sum, 1.0, 1e-9);
}

// POMDP tests

TEST(POMDPTest, VertexHandlingTest) {
    QuantumState qs({0}, 10);
    ClassicalState cs;
    ClassicalState cs2 = *cs.apply_instruction(Instruction(GateName::Write1, 0));
    HybridState hs1(make_shared<QuantumState>(qs), make_shared<ClassicalState>(cs));
    HybridState hs2(make_shared<QuantumState>(qs), make_shared<ClassicalState>(cs2));
    POMDP pomdp(10);

    POMDPVertexHash hasher;
    POMDPVertexPtrEqual eq;

    auto v1 = pomdp.create_new_vertex(make_shared<HybridState>(hs1), 0);
    EXPECT_EQ(v1->hidden_index, 0);

    // Equal objects
    EXPECT_TRUE(eq(v1, v1));
    EXPECT_EQ(hasher(v1), hasher(v1));

    auto v2 = pomdp.create_new_vertex(make_shared<HybridState>(hs1), 1);
    EXPECT_TRUE(v2 != v1);
    EXPECT_FALSE(*v2 == *v1);
    // Equal objects
    EXPECT_FALSE(eq(v1, v2));
    EXPECT_FALSE(hasher(v1) == hasher(v2));


    auto v3 = pomdp.create_new_vertex(make_shared<HybridState>(hs1), 0);
    EXPECT_TRUE(v1 != v3);
    EXPECT_EQ(*v3, *v1);
    // Equal objects
    EXPECT_TRUE(eq(v1, v3));
    EXPECT_EQ(hasher(v1), hasher(v3));

    auto v4 = pomdp.create_new_vertex(make_shared<HybridState>(hs2), 0);
    EXPECT_TRUE(v4 != v1);
    EXPECT_FALSE(*v4 == *v1);
    // Equal objects
    EXPECT_FALSE(eq(v4, v1));
    EXPECT_FALSE(hasher(v1) == hasher(v4));
}