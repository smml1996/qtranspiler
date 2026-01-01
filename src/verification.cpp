//
// Created by Stefanie Muroya Lei on 21.11.25.
//
// ANTLR first
#include "antlr4-runtime.h"
#include "grammars/PL/ProgrammingLanguageLexer.h"
#include "grammars/PL/ProgrammingLanguageParser.h"
#include "grammars/assertions/PreconditionAssertionLexer.h"
#include "grammars/assertions/PreconditionAssertionParser.h"

#include "grammars/assertions/AssertionLexer.h"
#include "grammars/assertions/AssertionParser.h"
#include <memory>
#include <utility>

// Boost AFTER clean-up

#include "boost_clean.hpp"
#include "utils.hpp"
#include "floats.hpp"
#include "hardware_specification.hpp"
#include "pomdp.hpp"
#include "states.hpp"
#include "cxxopts.hpp"
#include "grammars/assertions/PreconditionAssertionBaseVisitor.cpp"
#include "grammars/assertions/AssertionBaseVisitor.cpp"

inline int mc_precision;
inline int max_depth;

class Configuration {
public:
    shared_ptr<Ensemble<double>> ensemble;
    ProgrammingLanguageParser::ProgramContext* program;
    Configuration(ProgrammingLanguageParser::ProgramContext* program_, shared_ptr<Ensemble<double>> ensemble_) {
        this->ensemble = std::move(ensemble_);
        this->program = program_;
    }

    [[nodiscard]] bool is_atomic_program() const;

    shared_ptr<Configuration> get_atomic_program_ensemble(HardwareSpecification &spec, const unordered_map<int, int> &embedding);

};

class MarkovChain {
public:
    HardwareSpecification spec;
    unordered_map<int, int> embedding;

    MarkovChain(HardwareSpecification spec_,
                const std::unordered_map<int,int> &embedding_)
        : spec(std::move(spec_)), embedding(embedding_)  // <-- Initialization happens here
    {};

    shared_ptr<Ensemble<MyFloat>> get_final_ensemble (const shared_ptr<Configuration> &config);


    static int get_depth(const shared_ptr<Configuration> &config);
};

class Verifier {
public:
    HardwareSpecification spec;
    unordered_map<int, int> embedding;
    Experiment *experiment;
    int nqvars, ncvars;

    Verifier(HardwareSpecification spec_, const unordered_map<int, int> &embedding_,
             Experiment *experiment, const int &nqvars_, const int &ncvars_) : spec(std::move(spec_)),embedding(embedding_),  experiment(experiment), nqvars(nqvars_), ncvars(ncvars_) {
    };
    [[nodiscard]] bool verify(const string &raw_precondition, const string &raw_program, const string &raw_postcondition) const;
};


Ensemble<z3::expr> get_symbolic_ensemble(const std::vector<shared_ptr<Ensemble<MyFloat>>> &ensembles, const z3::expr_vector &weights, z3::context &ctx) {
    Ensemble<z3::expr> result(mc_precision);

    assert( weights.size() == ensembles.size());
    for (int i = 0; i <ensembles.size(); i++) {
        for (auto e : ensembles[i]->probs) {
            result.add_prob(e.first, weights[i] * ctx.real_val(to_string(e.second).c_str()));
        }
    }
    return result;
}

shared_ptr<Ensemble<MyFloat>> to_myfloat(const shared_ptr<Ensemble<double>> &ensemble) {
    shared_ptr<Ensemble<MyFloat>> result = make_shared<Ensemble<MyFloat>>(mc_precision * (max_depth + 1));

    for (auto p : ensemble->probs) {
        result->add_prob(p.first, MyFloat(to_string(p.second), mc_precision* (max_depth + 1)));
    }

    return result;
}

shared_ptr<Ensemble<double>> to_double(const shared_ptr<Ensemble<MyFloat>> &ensemble) {
    shared_ptr<Ensemble<double>> result = make_shared<Ensemble<double>>(mc_precision);

    for (auto p : ensemble->probs) {
        result->add_prob(p.first, round_to(to_double(p.second), mc_precision));
    }

    return result;
}

[[nodiscard]] bool Configuration::is_atomic_program() const {
    if (dynamic_cast<ProgrammingLanguageParser::SkipContext*>(program)) {
        return true;
    }

    if (program->children.size() == 1  && dynamic_cast<ProgrammingLanguageParser::Classical_statementContext*>(program->children[0])) {
        return true;
    }

    if (dynamic_cast<ProgrammingLanguageParser::UnitaryContext*>(program)) {
        return true;
    }

    return false;
}

shared_ptr<Configuration> Configuration::get_atomic_program_ensemble(HardwareSpecification &spec, const unordered_map<int, int> &embedding) {
        assert(!this->ensemble->probs.empty());
        shared_ptr<Ensemble<double>> result_ensemble = make_shared<Ensemble<double>>(mc_precision);
        assert(is_atomic_program());

        if (dynamic_cast<ProgrammingLanguageParser::SkipContext*>(program)) {
            return make_shared<Configuration>(nullptr, ensemble);
        }
        auto *c = dynamic_cast<ProgrammingLanguageParser::Classical_statementContext*>(program->children[0]);
        if (program->children.size() == 1  && c) {
            if (auto a = dynamic_cast<ProgrammingLanguageParser::AssignZeroContext*>(c)) {
                string cid = a->CID()->toString();
                int index = std::stoi(cid.substr(1));
                Instruction W0 = Instruction(GateName::Write0, index);
                for (int i = 0; i < this->ensemble->probs.size(); i++) {
                    auto temp = this->ensemble->probs[i].first->apply_instruction(W0);
                    result_ensemble->add_prob( temp,this->ensemble->probs[i].second);
                }
            }
            else if (auto assign_one_context = dynamic_cast<ProgrammingLanguageParser::AssignOneContext*>(c)) {
                string cid = assign_one_context->CID()->toString();
                int index = std::stoi(cid.substr(1));
                Instruction W1 = Instruction(GateName::Write1, index);
                for (int i = 0; i < this->ensemble->probs.size(); i++) {
                    auto temp = this->ensemble->probs[i].first->apply_instruction(W1);
                    result_ensemble->add_prob( temp,this->ensemble->probs[i].second);
                }
            }
            else if (auto assign_copy_context = dynamic_cast<ProgrammingLanguageParser::AssignCopyContext*>(c)) {
                string write_cid = assign_copy_context->CID()[0]->toString();
                string read_cid = assign_copy_context->CID()[1]->toString();
                int w_index = std::stoi(write_cid.substr(1));
                int r_index = std::stoi(read_cid.substr(1));
                for (int i = 0; i < this->ensemble->probs.size(); i++) {
                    int value = this->ensemble->probs[i].first->classical_state->read(r_index);
                    Instruction instruction;
                    if (value == 0) {
                        instruction = Instruction(GateName::Write0, w_index);
                    } else {
                        assert(value == 1);
                        instruction = Instruction(GateName::Write1, w_index);
                    }
                    auto temp = this->ensemble->probs[i].first->apply_instruction(instruction);
                    result_ensemble->add_prob( temp,this->ensemble->probs[i].second);
                }
            } else if (auto measure_context = dynamic_cast<ProgrammingLanguageParser::AssignMeasureContext*>(c)) {
                string cid = measure_context->CID()->toString();
                string qid = measure_context->QID()->toString();
                int c_index = std::stoi(cid.substr(1));
                int q_index = embedding.at(std::stoi(qid.substr(1)));
                Instruction meas_ins = Instruction(GateName::Meas, q_index, c_index);
                for (int i = 0; i < this->ensemble->probs.size(); i++) {
                    POMDPAction action = POMDPAction("some action", {meas_ins}, mc_precision, {});
                    shared_ptr<POMDPVertex> current_vertex = make_shared<POMDPVertex>(this->ensemble->probs[i].first);
                    auto succs = action.get_successor_states(spec, current_vertex);
                    for (const auto& [fst, snd] : succs) {
                        result_ensemble->add_prob( fst->hybrid_state,this->ensemble->probs[i].second * snd);
                    }
                }
            } else {
                throw runtime_error("Classical statement does not matches anything");
            }
        }

        if (auto *U = dynamic_cast<ProgrammingLanguageParser::UnitaryContext*>(program)) {
            string unitary = U->UNITARY()->toString();
            Instruction instruction;
            auto qlist = U->UnitaryContext::qlist()->getQList();
            for (int & i : qlist) {
                i = embedding.at(i);
            }

            if (unitary == "X") {
                assert(qlist.size() == 1);
                instruction = Instruction(GateName::X, qlist[0]);
            } else if (unitary == "CX") {
                assert(qlist.size() == 2);
                instruction = Instruction(GateName::Cnot, vector<int>({qlist[0]}), qlist[1]);
            } else if (unitary == "H") {
                assert(qlist.size() == 1);
                instruction = Instruction(GateName::H, qlist[0]);
            } else {
                throw runtime_error("invalid unitary gate:" + unitary);
            }
            for (int i = 0; i < this->ensemble->probs.size(); i++) {
                POMDPAction action = POMDPAction("some action", spec.to_basis_gates_impl(instruction), mc_precision, {});
                shared_ptr<POMDPVertex> current_vertex = make_shared<POMDPVertex>(this->ensemble->probs[i].first);
                auto succs = action.get_successor_states(spec, current_vertex);
                for (const auto& [fst, snd] : succs) {
                    result_ensemble->add_prob( fst->hybrid_state,this->ensemble->probs[i].second * snd);
                }
            }
        }

        return make_shared<Configuration>(nullptr, result_ensemble);
    }

shared_ptr<Ensemble<MyFloat>> MarkovChain::get_final_ensemble (const shared_ptr<Configuration> &config) {
        assert(!config->ensemble->probs.empty());
        auto program = config->program;
        if (config->is_atomic_program()) {
            return to_myfloat(config->get_atomic_program_ensemble(this->spec, this->embedding)->ensemble);
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::IfContext*>(program)) {
            assert (s->program().size() == 2);
            string cid = s->CID()->toString();
            int c_index = std::stoi(cid.substr(1));


            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);

            shared_ptr<Ensemble<double>> ensemble_true = make_shared<Ensemble<double>>(mc_precision);
            shared_ptr<Ensemble<double>> ensemble_false = make_shared<Ensemble<double>>(mc_precision);

            for (auto p : config->ensemble->probs) {
                if (p.first->classical_state->read(c_index)) {
                    ensemble_true->add_prob(p.first, p.second);
                } else {
                    ensemble_false->add_prob(p.first, p.second);
                }
            }
            // auto w_true = MyFloat(to_string(ensemble_true->get_weight()), mc_precision*(max_depth+1));
            // cout << "w_true" << w_true << endl;
            // ensemble_true->normalize();
            // auto w_false = MyFloat(to_string(ensemble_false->get_weight()), mc_precision*(max_depth+1));
            // ensemble_false->normalize();
            // cout << "w_false" << w_false << endl;

            shared_ptr<Ensemble<MyFloat>> final_ensemble = make_shared<Ensemble<MyFloat>>(mc_precision*(max_depth+1));

            if (!ensemble_true->probs.empty()) {
                auto config_left = make_shared<Configuration>(program_left, ensemble_true);
                auto temp_ensemble = get_final_ensemble(config_left);
                for (auto p : temp_ensemble->probs) {
                    final_ensemble->add_prob(p.first,  p.second);
                }
            }


            if (!ensemble_false->probs.empty()) {
                auto config_right = make_shared<Configuration>(program_right, ensemble_false);
                auto temp_ensemble = get_final_ensemble(config_right);
                for (auto p : temp_ensemble->probs) {
                    final_ensemble->add_prob(p.first, p.second);
                }
            }
            return final_ensemble;
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::ProbContext*>(program)) {
            assert (s->program().size() == 2);
            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);
            double d_prob_left = round_to(1 - stod(s->REALNUM()->toString()), mc_precision);
            double d_prob_right = round_to(stod(s->REALNUM()->toString()), mc_precision);
            MyFloat prob_left = MyFloat(to_string(d_prob_left), mc_precision * (max_depth + 1));
            MyFloat prob_right = MyFloat(to_string(d_prob_right), mc_precision * (max_depth + 1));
            assert (prob_left + prob_right == MyFloat("1", mc_precision * (max_depth + 1)));
            auto config_left = make_shared<Configuration>(program_left, config->ensemble);
            auto config_right = make_shared<Configuration>(program_right, config->ensemble);
            auto final_ensemble_left = get_final_ensemble(config_left);
            auto final_ensemble_right = get_final_ensemble(config_right);

            shared_ptr<Ensemble<MyFloat>> final_ensemble = make_shared<Ensemble<MyFloat>>(mc_precision*(max_depth+1));
            for (auto p : final_ensemble_left->probs) {
                auto prob = prob_left * p.second;
                final_ensemble->add_prob(p.first, prob);
            }

            for (auto p : final_ensemble_right->probs) {
                auto prob = prob_right * p.second;
                final_ensemble->add_prob(p.first, prob);
            }
            return final_ensemble;
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::SeqContext*>(program)) {
            assert (s->program().size() == 2);
            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);
            auto config_left = make_shared<Configuration>(program_left, config->ensemble);
            auto final_ensemble_left = get_final_ensemble(config_left);
            auto config_right = make_shared<Configuration>(program_right, to_double(final_ensemble_left));
            return get_final_ensemble(config_right);
        }

        throw runtime_error("Programming language error");
    };

int MarkovChain::get_depth(const shared_ptr<Configuration> &config) {
        auto program = config->program;
        if (config->is_atomic_program()) {
            return 1;
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::IfContext*>(program)) {
            assert (s->program().size() == 2);
            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);
            auto config_left = make_shared<Configuration>(program_left, config->ensemble);
            auto config_right = make_shared<Configuration>(program_right, config->ensemble);
            return max(get_depth(config_left), get_depth(config_right));
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::ProbContext*>(program)) {
            assert (s->program().size() == 2);
            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);
            auto config_left = make_shared<Configuration>(program_left, config->ensemble);
            auto config_right = make_shared<Configuration>(program_right, config->ensemble);
            return max(get_depth(config_left), get_depth(config_right));
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::SeqContext*>(program)) {
            assert (s->program().size() == 2);
            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);
            auto config_left = make_shared<Configuration>(program_left, config->ensemble);
            auto config_right = make_shared<Configuration>(program_right, config->ensemble);
            return get_depth(config_left) + get_depth(config_right);
        }

        throw runtime_error("Programming language error");
    }

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


    // initial ensembles
    PreconVisitor visitor(nqvars, ncvars, mc_precision);
    auto polygons = std::any_cast<vector<Polygon<double>>>(visitor.visit(raw_prec));
    auto first_polygon = polygons[0];
    auto some_ensemble = first_polygon.corners[0];
    // for (auto polygon : polygons) {
    //     cout << "****** ensemble ******" << endl;
    //     for (auto e : ensemble->probs) {
    //         cout << *e.first << " " << e.second << endl;
    //     }
    //     cout << endl;
    // }


    MarkovChain mc(this->spec, this->embedding);
    max_depth = MarkovChain::get_depth(make_shared<Configuration>(program, some_ensemble));
    cout << "max depth: " << max_depth << endl;
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

    cout << "final ensembles:" << endl;
    for (const auto& ensemble : final_ensembles) {
        cout << "****** ensemble ******" << endl;
        for (const auto& [fst, snd] : ensemble->probs) {
            cout << *fst << " " << snd << endl;
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

    return solver.check() == z3::sat;
}


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
    for (const auto & bound_var : bound_vars) {
        if (expr_contains_var(body, bound_var)) {
            used_vars.push_back(bound_var);
        }
    }
    return used_vars;
}