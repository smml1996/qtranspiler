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
#include "grammars/assertions/AssertionBaseVisitor.cpp"


using namespace std;


// Helper: check if expr 'var' appears in expr 'e'
bool expr_contains_var(const z3::expr &e, const z3::expr &var) {
    if (e.is_const() && e.hash() == var.hash()) return true;
    for (unsigned i = 0; i < e.num_args(); ++i) {
        if (expr_contains_var(e.arg(i), var)) return true;
    }
    return false;
}

// Filter bound_vars to keep only the ones that appear in 'body'
z3::expr_vector filter_used_vars(const z3::expr_vector &bound_vars, const z3::expr &body) {
    z3::expr_vector used_vars(body.ctx());
    for (unsigned i = 0; i < bound_vars.size(); ++i) {
        if (expr_contains_var(body, bound_vars[i])) {
            used_vars.push_back(bound_vars[i]);
        }
    }
    return used_vars;
}

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
    cout << "raw precondition line: " << raw_precondition << endl;
    cout << "raw program: " << raw_program << endl;
    cout << "raw postcondition line: " << raw_postcondition << endl;
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
    antlr4::tree::ParseTree *tree = parser.program();
    auto *program = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(tree);

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


    MarkovChain mc(hardware_specification, embedding);
    max_depth = mc.get_depth(make_shared<Configuration>(program, initial_ensembles[0]));
    cout << "max depth: " << max_depth << endl;
    // the depth is independent of the initial ensemble (FIX this!)
    //
    vector<shared_ptr<Ensemble<MyFloat>>> final_ensembles;
    for (auto initial_ensemble : initial_ensembles) {
        auto final_ensemble = mc.get_final_ensemble(make_shared<Configuration>(program, initial_ensemble));
        if (is_new_ensemble(final_ensembles, final_ensemble)) {
            final_ensembles.push_back(final_ensemble);
        }
    }

    cout << "final ensembles:" << endl;
    for (auto ensemble : final_ensembles) {
        cout << "****** ensemble ******" << endl;
        for (auto e : ensemble->probs) {
            cout << *e.first << " " << e.second << endl;
        }
        cout << endl;
    }

    // Determine if there exists a convex combination of final ensembles

    z3::context ctx;
    z3::solver solver(ctx);

    // create bounded variables
    z3::expr body = ctx.bool_val(true);
    z3::expr sum = ctx.real_val("0");
    z3::sort R = ctx.real_sort();

    z3::expr_vector bound_vars(ctx);
    for (int i = 0; i < final_ensembles.size(); i++) {
        Z3_ast b = Z3_mk_bound(ctx, i, R);  // raw AST for bound variable
        bound_vars.push_back(ctx.real_const(("w" + std::to_string(i)).c_str()));
    }


    for (auto v : bound_vars) assert(&v.ctx() == &ctx);

    for (int i = 0; i < final_ensembles.size(); i++) {
        body = body && (bound_vars[i] >= 0);
        sum = sum + bound_vars[i];
    }

    cout << "num bounded vars:" << bound_vars.size() << endl;
    cout << "sum expr" << sum << endl;


    body = body && (sum == 1);
    cout << " body with sum" << body << endl;

    // postcondition parsing
    antlr4::ANTLRInputStream post_input(raw_postcondition);
    AssertionLexer post_lexer(&post_input);
    antlr4::CommonTokenStream post_tokens(&post_lexer);
    AssertionParser post_parser(&post_tokens);
    antlr4::tree::ParseTree *raw_post = post_parser.assertion();



    Z3AssertionVisitor post_visitor(ctx, solver);
    post_visitor.ensemble_stack.push_back(get_symbolic_ensemble(final_ensembles, bound_vars, ctx));
    auto post_expr = std::any_cast<z3::expr>(post_visitor.visit(raw_post));
    body = z3::implies(body, post_expr);
    body = body.simplify();

    // Only wrap in forall if body is non-constant
    if (!body.is_true() && !body.is_false() && !body.is_quantifier()) {
        z3::expr forall_weights = z3::forall(bound_vars, body);
        solver.add(forall_weights);
    } else {
        // If body is trivial, just add it directly
        solver.add(body);
    }

    cout << solver.check() << endl;
    return 0;
}