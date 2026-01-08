//
// Created by Stefanie Muroya Lei on 02.01.26.
//

#include <gtest/gtest.h>
#include "verifier.hpp"
#include "grammars/assertions/AssertionLexer.h"
#include "grammars/assertions/AssertionParser.h"
#include "grammars/assertions/PreconditionAssertionLexer.h"
#include "grammars/assertions/PreconditionAssertionParser.h"
#include "grammars/PL/ProgrammingLanguageLexer.h"
#include "src/experiments/reset.cpp"
#include "src/experiments/ghz.cpp"
#include "src/experiments/bellstate_reach.cpp"
#include "src/experiments/bitflip.cpp"
#include "src/experiments/discrimination.cpp"

vector<shared_ptr<Experiment>> get_experiments () {
    ResetProblem reset_problem;
    IPMABitflip ipma_problem;
    BellStateReach bell_reach_problem;
    BasicZeroPlusDiscrimination discr_problem;
    GHZStatePreparation3 ghz_problem;

    vector<shared_ptr<Experiment>> experiments;
    experiments.push_back(make_shared<ResetProblem>(reset_problem));
    experiments.push_back(make_shared<IPMABitflip>(ipma_problem));
    experiments.push_back(make_shared<BellStateReach>(bell_reach_problem));
    experiments.push_back(make_shared<BasicZeroPlusDiscrimination>(discr_problem));
    experiments.push_back(
        make_shared<GHZStatePreparation3>(ghz_problem)
    );
    return experiments;
}

vector<MethodType> get_exp_methods(shared_ptr<Experiment> &experiment) {
    if (experiment->name == "reset" || experiment->name == "BellStateReach") {
        return {MethodType::ConvexDist, MethodType::SingleDistBellman};
    }

    if (experiment->name == "ghz_state_preparation3" || experiment->name == "bitflip_ipma") {
        return {MethodType::SingleDistBellman};
    }
    assert(experiment->name == "basic_zero_plus");
    return {MethodType::ConvexDist};
}

TEST(AllExperiments, ProgramParser) {
    vector<pair<string, int>> problems({
        make_pair("reset", 160),
        make_pair("bell_state_reach", 18),
        make_pair("bitflip_cxh", 6),
        make_pair("bitflip_ipma", 26),
        make_pair("bitflip_ipma2", 39),
        make_pair("ghz3", 11)
    });
    for (auto problem: problems) {
        for (int i = 0; i < problem.second + 1; i++) {
            std::ifstream curr_alg_file(get_final_wd(problem.first) / "raw_algorithms" / ("R_" + to_string(i) + ".txt"));
            json current_algorithm;
            curr_alg_file >> current_algorithm;
            curr_alg_file.close();
            Algorithm alg_object(current_algorithm);

            auto raw_program = v_to_string(make_shared<Algorithm>(alg_object));
            antlr4::ANTLRInputStream input(raw_program);
            ProgrammingLanguageLexer lexer(&input);
            antlr4::CommonTokenStream tokens(&lexer);
            ProgrammingLanguageParser parser(&tokens);
            EXPECT_EQ(parser.getNumberOfSyntaxErrors(), 0);
        }
    }
}

// TEST(AllExperiments, ProgramDepth) {
//     auto experiments = get_experiments();
//     for (auto experiment : experiments) {
//         auto f = StatsFile(experiment->name, *experiment);
//         unordered_set<int> processed_algs;
//         for (auto row : f.stats) {
//             if (processed_algs.find(row.algorithm_index) == processed_algs.end()) {
//                 processed_algs.insert(row.algorithm_index);
//
//                 // process algorithm
//                 auto raw_program = v_to_string(make_shared<Algorithm>(row.algorithm));
//                 antlr4::ANTLRInputStream input(raw_program);
//                 ProgrammingLanguageLexer lexer(&input);
//                 antlr4::CommonTokenStream tokens(&lexer);
//                 ProgrammingLanguageParser parser(&tokens);
//                 antlr4::tree::ParseTree *tree = parser.program();
//                 auto *program = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(tree);
//
//                 // some ensemble (it doesn't matter for computing the depth)
//                 Ensemble<double> some_ensemble;
//
//                 // Markov Chain
//                 HardwareSpecification spec(row.quantum_hardware, false, true);
//                 MarkovChain mc(spec, row.embedding, 8);
//                 int depth = MarkovChain::get_depth(make_shared<Configuration>(program, make_shared<Ensemble<double>>(some_ensemble)));
//                 EXPECT_LE(depth, row.horizon);
//             }
//         }
//     }
// }

TEST(AllExperiments, Precondition) {
    auto experiments = get_experiments();
    for (auto experiment : experiments) {
        auto methods = get_exp_methods(experiment);
        for (auto method: methods) {
            // cout << experiment->name << " " << gate_to_string(method) << endl;
            auto precondition = experiment->get_precondition(method);
            // cout << precondition << endl;
            antlr4::ANTLRInputStream prec_input(precondition);
            PreconditionAssertionLexer prec_lexer(&prec_input);
            antlr4::CommonTokenStream prec_tokens(&prec_lexer);
            PreconditionAssertionParser prec_parser(&prec_tokens);
            antlr4::tree::ParseTree* tree = prec_parser.precon_assertion();
            // std::cout << tree->toStringTree(&prec_parser) << std::endl;
            EXPECT_EQ(prec_parser.getNumberOfSyntaxErrors(), 0);
            // cout << "*******" << endl;
        }

    }
}

TEST(AllExperiments, Postcondition) {
    auto experiments = get_experiments();
    for (auto experiment : experiments) {
        auto postcondition = experiment->get_target_postcondition(0.75);
        cout << experiment->name << endl;
        cout << postcondition << endl;
        antlr4::ANTLRInputStream postcon_input(postcondition);
        AssertionLexer post_lexer(&postcon_input);
        antlr4::CommonTokenStream post_tokens(&post_lexer);
        AssertionParser post_parser(&post_tokens);
        antlr4::tree::ParseTree* tree = post_parser.assertion();
        std::cout << tree->toStringTree(&post_parser) << std::endl;
        EXPECT_EQ(post_parser.getNumberOfSyntaxErrors(), 0);
        cout << "*******" << endl;
    }
}
