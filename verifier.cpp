//
// Created by Stefanie Muroya Lei on 18.11.25.
//

#include <string>
#include <iostream>
#include <fstream>
// ANTLR first
#include "antlr4-runtime.h"
#include "grammars/PL/ProgrammingLanguageLexer.h"
#include "grammars/PL/ProgrammingLanguageParser.h"
#include "grammars/assertions/PreconditionAssertionLexer.h"
#include "grammars/assertions/PreconditionAssertionParser.h"

#include "grammars/assertions/AssertionLexer.h"
#include "grammars/assertions/AssertionParser.h"
#include "verification_utils.hpp"
#include <memory>

// Boost AFTER clean-up
#include "boost_clean.hpp"
#include "floats.hpp"
#include "hardware_specification.hpp"
#include "pomdp.hpp"
#include "cxxopts.hpp"
#include "grammars/assertions/PreconditionAssertionBaseVisitor.cpp"


using namespace std;


int main(int argc, char* argv[]) {
    HardwareSpecification hardware_specification(QuantumHardware::PerfectHardware, false, true);
    unordered_map<int, int> embedding{
            {0, 0},
            {1, 1},
            {2, 2}
    };

    cxxopts::Options options("verifier", "verify hoare triple is valid");
    options.add_options()
        ("triple_path", "path to the triple file", cxxopts::value<std::string>())
        ("nqvars", "number of quantum variables", cxxopts::value<int>())
        ("ncvars", "number of classical variables", cxxopts::value<int>())
        ("precision", "Markov chain precision", cxxopts::value<int>()->default_value("8"))
        ("h,help", "print usage");

    auto result = options.parse(argc, argv);
    if (result.count("help")) {
        cout << options.help() << endl;
        return 0;
    }

    string triple_path = result["triple_path"].as<std::string>();
    mc_precision = result["precision"].as<int>();
    int nqvars = result["nqvars"].as<int>();
    int ncvars = result["ncvars"].as<int>();
    std::ifstream input_file(triple_path);
    if (!input_file.is_open()) {
        cout << "Failed to open file " << triple_path << endl;
    }

    string raw_precondition;
    string raw_program;
    string raw_postcondition;
    if (getline(input_file, raw_precondition)) {
        if (getline(input_file, raw_program)) {
            if (!getline(input_file, raw_postcondition)) throw runtime_error("couldn't get postcondition line");
        } else {
            throw runtime_error("couldn't get program line");
        }
    } else {
        throw runtime_error("couldn't get precondition line");
    }
    input_file.close();

    // parse precondition
    antlr4::ANTLRInputStream prec_input(raw_precondition);
    PreconditionAssertionLexer prec_lexer(&prec_input);
    antlr4::CommonTokenStream prec_tokens(&prec_lexer);
    PreconditionAssertionParser prec_parser(&prec_tokens);
    antlr4::tree::ParseTree *raw_prec = prec_parser.precon_assertion();

    // std::cout << precondition->toStringTree(&prec_parser) << std::endl;

    // program parsing
    antlr4::ANTLRInputStream input(raw_program);
    ProgrammingLanguageLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    ProgrammingLanguageParser parser(&tokens);
    antlr4::tree::ParseTree *raw = parser.program();
    std::shared_ptr<antlr4::tree::ParseTree> tree(raw, [](auto*){ /* do nothing */ });
    auto *program = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(tree.get());

    // postcondition parsing
    // antlr4::ANTLRInputStream post_input(raw_postcondition);
    // AssertionLexer post_lexer(&post_input);
    // antlr4::CommonTokenStream post_tokens(&post_lexer);
    // AssertionParser post_parser(&prec_tokens);
    // antlr4::tree::ParseTree *raw_post = prec_parser.precon_assertion();
    // std::shared_ptr<antlr4::tree::ParseTree> post_tree(raw_post, [](auto*){ /* do nothing */ });
    // auto *postcondition = dynamic_cast<AssertionParser::AssertionContext*>(post_tree.get());

    // initial ensembles
    PreconVisitor visitor(nqvars, ncvars, mc_precision);
    visitor.visit(raw_prec);
    vector<shared_ptr<Ensemble<double>>> initial_ensembles = visitor.ensembles;
    for (auto ensemble : initial_ensembles) {
        cout << "****** ensemble ******" << endl;
        for (auto e : ensemble->probs) {
            cout << *e.first << " " << e.second << endl;
        }
        cout << endl;
    }


    // MarkovChain mc(hardware_specification, embedding);
    // max_depth = mc.get_depth(make_shared<Configuration>(program, initial_ensembles[0]));
    // the depth is independent of the initial ensemble (FIX this!)
    //
    // vector<shared_ptr<Ensemble<MyFloat>>> final_ensembles;
    // for (auto initial_ensemble : initial_ensembles) {
    //     auto final_ensemble = mc.get_final_ensemble(make_shared<Configuration>(program, initial_ensemble));
    // }
    //
    // // TODO: build FOL formula
    // cout << is_sat(final_ensembles, postcondition) << endl;
    return 0;
}