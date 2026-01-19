//
// Created by Stefanie Muroya Lei on 08.09.25.
//

#include <gtest/gtest.h>
#include "channels.hpp"  // adjust include as needed

// ---------- MeasurementChannel Tests ----------

TEST(MeasurementChannelTest, ProbabilitiesFromJson) {
    json data = {
        {"0", {{"0", 0.9}, {"1", 0.1}}},
        {"1", {{"1", 0.85}, {"0", 0.15}}}
    };

    MeasurementChannel mc(data);

    EXPECT_NEAR(mc.correct_0, 0.9, 1e-12);
    EXPECT_NEAR(mc.correct_1, 0.85, 1e-12);
    EXPECT_NEAR(mc.incorrect_0, 0.1, 1e-12);
    EXPECT_NEAR(mc.incorrect_1, 0.15, 1e-12);
}

TEST(MeasurementChannelTest, GetIndProbability) {
    json data = {
        {"0", {{"0", 0.9}, {"1", 0.1}}},
        {"1", {{"1", 0.85}, {"0", 0.15}}}
    };
    MeasurementChannel mc(data);

    // ideal=0, noisy=0 → correct_0
    EXPECT_NEAR(mc.get_ind_probability(0,0), 0.9, 1e-8);
    // ideal=1, noisy=1 → correct_1
    EXPECT_NEAR(mc.get_ind_probability(1,1), 0.85, 1e-8);
    // ideal=1, noisy=0 → incorrect_0
    EXPECT_NEAR(mc.get_ind_probability(1,0), 0.15, 1e-8);
    // ideal=0, noisy=1 → incorrect_1
    EXPECT_NEAR(mc.get_ind_probability(0,1), 0.1, 1e-8);
}

// ---------- QuantumChannel Tests ----------

TEST(QuantumChannelTest, ParseErrorsFromJson) {
    json j;

    // Add probabilities
    j["probabilities"] = {
        0.999712067344145,
        9.59775519517134e-05,
        9.59775519517134e-05,
        9.59775519517134e-05
    };

    // Build error instructions
    json error_I = {
        {"type", "instruction"},
        {"target", 0},
        {"control", -1},
        {"op", "I"},
        {"params", json::array()}
    };

    json error_X = {
        {"type", "instruction"},
        {"target", 0},
        {"control", -1},
        {"op", "X"},
        {"params", json::array()}
    };

    json error_Y = {
        {"type", "instruction"},
        {"target", 0},
        {"control", -1},
        {"op", "Y"},
        {"params", json::array()}
    };

    json error_Z = {
        {"type", "instruction"},
        {"target", 0},
        {"control", -1},
        {"op", "Z"},
        {"params", json::array()}
    };

    // Add them to the "errors" field (each instruction in its own array)
    j["errors"] = json::array({
        json::array({error_I}),
        json::array({error_X}),
        json::array({error_Y}),
        json::array({error_Z})
    });


    QuantumChannel qc(j);

    ASSERT_EQ(qc.errors_to_probs.size(), 4);

    EXPECT_NEAR(qc.errors_to_probs[0].second, 0.999712067344145, 1e-10);
    EXPECT_NEAR(qc.errors_to_probs[1].second, 9.59775519517134e-05, 1e-10);
    EXPECT_NEAR(qc.errors_to_probs[2].second, 9.59775519517134e-05, 1e-10);
    EXPECT_NEAR(qc.errors_to_probs[3].second, 9.59775519517134e-05, 1e-10);

    // Check that instructions are parsed (dummy check, depends on your Instruction ctor)
    for (int i = 0; i < qc.errors_to_probs.size(); i++) {
        EXPECT_EQ(qc.errors_to_probs[i].first.size(), 1);
    }
}

// ---------- Base Class ----------

TEST(ChannelTest, EstimatedSuccessProbDefault) {
    Channel ch;
    EXPECT_EQ(ch.estimated_success_prob, 0.0);
}

