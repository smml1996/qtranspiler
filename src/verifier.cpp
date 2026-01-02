//
// Created by Stefanie Muroya Lei on 02.01.26.
//

#include "antlr4-runtime.h"
#include "grammars/PL/ProgrammingLanguageLexer.h"
#include "grammars/PL/ProgrammingLanguageParser.h"
#include "grammars/assertions/PreconditionAssertionLexer.h"
#include "grammars/assertions/PreconditionAssertionParser.h"
#include "grammars/assertions/AssertionLexer.h"
#include "grammars/assertions/AssertionParser.h"
#include "boost_clean.hpp"
#include "verifier.hpp"
#include "markov_chain.hpp"
#include "ensemble.hpp"

#include "grammars/assertions/PreconditionAssertionBaseVisitor.cpp"
#include "grammars/assertions/AssertionBaseVisitor.cpp"

bool Verifier::verify(const string &raw_precondition, const string &raw_program, const string &raw_postcondition) const {
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

    MarkovChain mc(this->spec, this->embedding, this->precision);

    // initial ensembles
    PreconVisitor visitor(nqvars, ncvars, mc.mc_precision);
    auto polygons = std::any_cast<vector<Polygon<double>>>(visitor.visit(raw_prec));
    auto first_polygon = polygons[0];
    auto some_ensemble = first_polygon.corners[0];

    mc.max_depth = MarkovChain::get_depth(make_shared<Configuration>(program, some_ensemble));
    // the depth is independent of the initial ensemble (FIX this!)
    //
    vector<shared_ptr<Ensemble<MyFloat>>> final_ensembles;
    for (const auto& [corners] : polygons) {
        for (const auto& initial_ensemble : corners) {
            auto final_ensemble = mc.get_final_ensemble(make_shared<Configuration>(program, initial_ensemble));
            if (is_new_ensemble(final_ensembles, final_ensemble)) {
                final_ensembles.push_back(final_ensemble);
            }
        }
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
        Z3_mk_bound(ctx, i, R);  // raw AST for bound variable
        bound_vars.push_back(ctx.real_const(("w" + std::to_string(i)).c_str()));
    }


    for (auto v : bound_vars) assert(&v.ctx() == &ctx);

    for (int i = 0; i < final_ensembles.size(); i++) {
        body = body && (bound_vars[i] >= 0);
        sum = sum + bound_vars[i];
    }


    body = body && (sum == 1);

    // postcondition parsing
    antlr4::ANTLRInputStream post_input(raw_postcondition);
    AssertionLexer post_lexer(&post_input);
    antlr4::CommonTokenStream post_tokens(&post_lexer);
    AssertionParser post_parser(&post_tokens);
    antlr4::tree::ParseTree *raw_post = post_parser.assertion();



    Z3AssertionVisitor post_visitor(ctx, solver);
    post_visitor.ensemble_stack.push_back(get_symbolic_ensemble(final_ensembles, bound_vars, ctx, mc.mc_precision));
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

    return solver.check() == z3::sat;
}