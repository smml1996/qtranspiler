//
// Created by Stefanie Muroya Lei on 15.09.25.
//
#include "algorithm.hpp"
#include <gtest/gtest.h>

vector<Instruction> XSeq({Instruction(GateName::X, 0)});
vector<Instruction> HSeq({Instruction(GateName::H, 0)});
POMDPAction XAction("X", XSeq, 10, XSeq);
POMDPAction HAction("H", HSeq, 10, HSeq);

TEST(AlgorithmTest, Initialization) {
    EXPECT_TRUE(random_branch.name == "RANDOM_BRANCH");
    EXPECT_TRUE(HALT_ACTION.name == "HALT__");

    Algorithm algorithm(&XAction, 1, 10, 1);
    EXPECT_TRUE(*algorithm.action == XAction);
    EXPECT_TRUE(algorithm.action->name == "X");
    EXPECT_TRUE(algorithm.children.size() == 0);
    EXPECT_TRUE(algorithm.classical_state == 1);
    EXPECT_TRUE(algorithm.children.size() == 0);
    EXPECT_TRUE(algorithm.depth == 1);
}

TEST(AlgorithmTest, FindChildWithCState) {
    Algorithm algorithm(&XAction, 1, 10, 1);

    EXPECT_FALSE(algorithm.exist_child_with_cstate(0));
    EXPECT_FALSE(algorithm.exist_child_with_cstate(1));

    Algorithm child1(&XAction, 0, 10, 2);
    algorithm.children.push_back(&child1);
    EXPECT_TRUE(algorithm.exist_child_with_cstate(0));
    EXPECT_FALSE(algorithm.exist_child_with_cstate(1));

    Algorithm child2(&XAction, 1, 10, 2);
    algorithm.children.push_back(&child2);
    EXPECT_TRUE(algorithm.exist_child_with_cstate(0));
    EXPECT_TRUE(algorithm.exist_child_with_cstate(1));
}

TEST(AlgorithmTest, EqualAlgorithm) {
    Algorithm algorithm(&XAction, 1, 10, 1);

    EXPECT_EQ(algorithm, algorithm);

    Algorithm algorithm2(&XAction, 1, 10, 1);
    EXPECT_EQ(algorithm2, algorithm);


    Algorithm algorithm3(&XAction, 0, 10, 1);
    algorithm.children.push_back(&algorithm3);
    algorithm2.children.push_back(&algorithm3);
    EXPECT_EQ(algorithm, algorithm2);

}

TEST(AlgorithmTest, NotEqualAlgorithm) {
    {
        Algorithm algorithm(&XAction, 1, 10, 1);

        Algorithm algorithm2(&XAction, 0, 10, 1);
        EXPECT_FALSE(algorithm2 == algorithm);
    }

    {
        Algorithm algorithm(&XAction, 1, 10, 1);
        Algorithm algorithm2(&XAction, 0, 10, 2);
        EXPECT_FALSE(algorithm2 == algorithm);
    }

    {
        Algorithm algorithm(&XAction, 1, 10, 1);
        Algorithm algorithm2(&HAction, 1, 10, 1);
        EXPECT_FALSE(algorithm2 == algorithm);
    }

    Algorithm algorithm(&XAction, 1, 10, 1);
    Algorithm algorithm2(&XAction, 0, 10, 2);

    Algorithm algorithm3(&XAction, 0, 10, 1);
    Algorithm algorithm4(&HAction, 0, 10, 1);
    algorithm.children.push_back(&algorithm3);
    algorithm2.children.push_back(&algorithm4);
    EXPECT_FALSE(algorithm == algorithm2);
}


TEST(AlgorithmTest, HasMeas) {
    {
        Algorithm algorithm(&XAction, 1, 10, 1);
        EXPECT_FALSE(algorithm.has_meas());
    }

    {
        vector<Instruction> ins_seq({Instruction(GateName::H, 0), Instruction(GateName::Meas, 0, 0), Instruction(GateName::H, 0)});
        POMDPAction MeasAction("MeasAction", ins_seq, 10, ins_seq);
        Algorithm algorithm(&MeasAction, 1, 10, 1);

        EXPECT_TRUE(algorithm.has_meas());
    }

    {
        vector<Instruction> ins_seq({Instruction(GateName::P0, 0)});
        POMDPAction MeasAction("MeasAction", ins_seq, 10, ins_seq);
        Algorithm algorithm(&MeasAction, 1, 10, 1);
        EXPECT_FALSE(algorithm.has_meas());
    }
}

TEST(AlgorithmTest, HasCInstruction) {
    {
        Algorithm algorithm(&XAction, 1, 10, 1);
        EXPECT_FALSE(algorithm.has_classical_instruction());
    }

    {
        vector<Instruction> ins_seq({Instruction(GateName::H, 0), Instruction(GateName::Write0, 0), Instruction(GateName::H, 0)});
        POMDPAction WriteAction("Write", ins_seq, 10, ins_seq);
        Algorithm algorithm(&WriteAction, 1, 10, 1);

        EXPECT_TRUE(algorithm.has_classical_instruction());
    }

    {
        vector<Instruction> ins_seq({Instruction(GateName::H, 0), Instruction(GateName::Write1, 0), Instruction(GateName::H, 0)});
        POMDPAction WriteAction("Write", ins_seq, 10, ins_seq);
        Algorithm algorithm(&WriteAction, 1, 10, 1);

        EXPECT_TRUE(algorithm.has_classical_instruction());
    }

    {
        vector<Instruction> ins_seq({Instruction(GateName::H, 0), Instruction(GateName::Meas, 0, 0), Instruction(GateName::H, 0)});
        POMDPAction MeasAction("MeasAction", ins_seq, 10, ins_seq);
        Algorithm algorithm(&MeasAction, 1, 10, 1);

        EXPECT_FALSE(algorithm.has_classical_instruction());
    }

    {
        vector<Instruction> ins_seq({Instruction(GateName::P0, 0)});
        POMDPAction MeasAction("MeasAction", ins_seq, 10, ins_seq);
        Algorithm algorithm(&MeasAction, 1, 10, 1);
        EXPECT_FALSE(algorithm.has_meas());
    }
}

TEST(AlgorithmTest, IsUnitary) {
    {
        Algorithm algorithm(&XAction, 1, 10, 1);
        EXPECT_TRUE(algorithm.is_unitary());
    }

    {
        vector<Instruction> ins_seq({Instruction(GateName::H, 0), Instruction(GateName::Write0, 0), Instruction(GateName::H, 0)});
        POMDPAction WriteAction("Write", ins_seq, 10, ins_seq);
        Algorithm algorithm(&WriteAction, 1, 10, 1);

        EXPECT_FALSE(algorithm.is_unitary());
    }

    {
        vector<Instruction> ins_seq({Instruction(GateName::H, 0), Instruction(GateName::Write1, 0), Instruction(GateName::H, 0)});
        POMDPAction WriteAction("Write", ins_seq, 10, ins_seq);
        Algorithm algorithm(&WriteAction, 1, 10, 1);

        EXPECT_FALSE(algorithm.is_unitary());
    }

    {
        vector<Instruction> ins_seq({Instruction(GateName::H, 0), Instruction(GateName::Meas, 0, 0), Instruction(GateName::H, 0)});
        POMDPAction MeasAction("MeasAction", ins_seq, 10, ins_seq);
        Algorithm algorithm(&MeasAction, 1, 10, 1);

        EXPECT_FALSE(algorithm.is_unitary());
    }

    {
        vector<Instruction> ins_seq({Instruction(GateName::P0, 0)});
        POMDPAction MeasAction("MeasAction", ins_seq, 10, ins_seq);
        Algorithm algorithm(&MeasAction, 1, 10, 1);
        EXPECT_FALSE(algorithm.is_unitary());
    }
}


TEST(AlgorithmTest, SuccessorWithCState) {

    {
        vector<Instruction> ins_seq({Instruction(GateName::P0, 0)});
        POMDPAction meas_action("m1", ins_seq, 10, ins_seq);
        Algorithm algorithm(&meas_action, 0, 10, 1);

        unordered_set<int> successors;
        algorithm.get_successor_classical_states(0, successors);
        EXPECT_EQ(successors.size(), 1);
        EXPECT_TRUE(successors.find(0) != successors.end());
        EXPECT_TRUE(successors.find(1) == successors.end());
    }



    {
        vector<Instruction> ins_seq({Instruction(GateName::Meas, 0, 0)});
        POMDPAction meas_action("m1", ins_seq, 10, ins_seq);
        Algorithm algorithm(&meas_action, 0, 10, 1);
        unordered_set<int> successors;
        algorithm.get_successor_classical_states(0, successors);
        EXPECT_EQ(successors.size(), 2);

        for (int i = 0; i < 2; i++) {
            EXPECT_TRUE(successors.find(i) != successors.end());
        }
    }

    // {
    //     vector<Instruction> ins_seq({Instruction(GateName::Write1, 0)});
    //     POMDPAction write_action("w1", ins_seq, 10, ins_seq);
    //     Algorithm algorithm(&write_action, 0, 10, 1);
    //     unordered_set<int> successors;
    //     algorithm.get_successor_classical_states(0, successors);
    //     EXPECT_EQ(successors.size(), 1);
    //     EXPECT_TRUE(successors.find(1) != successors.end());
    // }
}

TEST(AlgorithmTest, GetAlgFromList) {

    Algorithm algorithm(&XAction, 1, 10, 1);
    Algorithm algorithm2(&HAction, 1, 10, 1);

    vector<Algorithm *> algorithms = {&algorithm, &algorithm2};

    EXPECT_EQ(get_algorithm_from_list(algorithms, &algorithm), 0);
    EXPECT_EQ(get_algorithm_from_list(algorithms, &algorithm2), 1);

    Algorithm algorithm3(&HAction, 2, 10, 1);
    EXPECT_EQ(get_algorithm_from_list(algorithms, &algorithm3), -1);
}

TEST(AlgorithmTest, DeepCopy) {
    Algorithm algorithm(&XAction, 1, 10, 1);
    auto algorithm2 = deep_copy_algorithm(&algorithm);

    EXPECT_EQ(algorithm, *algorithm2);
    algorithm2->classical_state +=1;
    EXPECT_EQ(algorithm.classical_state+1, algorithm2->classical_state);
    delete algorithm2;
}

TEST(AlgorithmTest, EndNodes) {
    Algorithm algorithm(&XAction, 1, 10, 1);

    {
        vector<Algorithm *> end_nodes;
        get_algorithm_end_nodes(&algorithm, end_nodes);
        EXPECT_EQ(end_nodes.size(), 1);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &algorithm), 0);
    }

    Algorithm child1(&XAction, 0, 10, 2);
    algorithm.children.push_back(&child1);

    {
        vector<Algorithm *> end_nodes;
        get_algorithm_end_nodes(&algorithm, end_nodes);
        EXPECT_EQ(end_nodes.size(), 1);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &algorithm), -1);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &child1), 0);
    }

    Algorithm child2(&HAction, 1, 10, 2);
    algorithm.children.push_back(&child2);
    {
        vector<Algorithm *> end_nodes;
        get_algorithm_end_nodes(&algorithm, end_nodes);
        EXPECT_EQ(end_nodes.size(), 2);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &algorithm), -1);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &child1), 0);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &child2), 1);
    }

    vector<Instruction> ins_seq({Instruction(GateName::Meas, 0, 0)});
    POMDPAction measAction("m1", ins_seq, 10, ins_seq);
    Algorithm meas_alg(&measAction, 0, 10, 1);
    Algorithm algorithm_(&XAction, 0, 10, 1);
    meas_alg.children.push_back(&algorithm_);
    {
        vector<Algorithm *> end_nodes;
        get_algorithm_end_nodes(&meas_alg, end_nodes);
        EXPECT_EQ(end_nodes.size(), 2);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &meas_alg), 0);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &algorithm_), 1);
    }

    Algorithm meas_alg2(&measAction, 1, 10, 1);
    Algorithm algorithm__(&XAction, 1, 10, 1);
    meas_alg2.children.push_back(&algorithm__);
    {
        vector<Algorithm *> end_nodes;
        get_algorithm_end_nodes(&meas_alg2, end_nodes);
        EXPECT_EQ(end_nodes.size(), 1);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &meas_alg2), -1);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &algorithm__), 0);
    }

    meas_alg.children.push_back(&child2);
    {
        vector<Algorithm *> end_nodes;
        get_algorithm_end_nodes(&meas_alg, end_nodes);
        EXPECT_EQ(end_nodes.size(), 2);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &algorithm_), 0);
        EXPECT_EQ(get_algorithm_from_list(end_nodes, &child2), 1);
    }
}

TEST(AlgorithmTest, MixedAlgorithm) {

    Algorithm algorithm(&XAction, 1, 10, 1);
    Algorithm algorithm2(&HAction, 1, 10, 1);

    unordered_map<int, Algorithm *> mapping_index_algorithm;
    mapping_index_algorithm[0] = &algorithm;
    mapping_index_algorithm[1] = &algorithm2;

    int initial_classical_state = 0;

    vector<double> x({0.3, 0.7});

    auto mixed_algorithm = get_mixed_algorithm(x, mapping_index_algorithm, initial_classical_state);

    Algorithm * new_head = new Algorithm(&random_branch, initial_classical_state, -1);
    new_head->children_probs[0] = 0.3;
    new_head->children_probs[1] = 0.7;
    new_head->children.push_back(&algorithm);
    new_head->children.push_back(&algorithm2);

    EXPECT_EQ(*new_head, *mixed_algorithm);
    delete new_head;
    delete mixed_algorithm;
}



