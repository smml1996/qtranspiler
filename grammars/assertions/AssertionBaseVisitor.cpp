
// Generated from grammars/assertions/Assertion.g4 by ANTLR 4.13.2


#include "AssertionBaseVisitor.h"
#include "verification_utils.hpp"
#include <z3++.h>

class Z3AssertionVisitor : public AssertionBaseVisitor {
  public:
  z3::context &context;
  z3::solver &solver;
  std::vector<Ensemble<z3::expr>> ensemble_stack;
  shared_ptr<HybridState> current_hs;

  Z3AssertionVisitor(z3::context &_context, z3::solver &_solver) : context(_context), solver(_solver), current_hs(nullptr) {};

    antlrcpp::Any visitAssertion( AssertionParser::AssertionContext *ctx) override
    {
      assert (this->ensemble_stack.size() == 1);
      return visit(ctx->distribution_assertion());
    }

    antlrcpp::Any visitDistribution_assertion(AssertionParser::Distribution_assertionContext *ctx) override {
      assert (this->ensemble_stack.size() == 1);
      return visit(ctx->dis_or_expr());
    }

    antlrcpp::Any visitDis_or_expr(AssertionParser::Dis_or_exprContext *ctx) override {
      z3::expr result = std::any_cast<z3::expr>(visit(ctx->dis_and_expr(0)));

      for (int i = 1; i < ctx->dis_and_expr().size(); i++) {
        z3::expr rhs = std::any_cast<z3::expr>(visit(ctx->dis_and_expr(i)));
        result = result || rhs;
      }
      return result;
    }

  antlrcpp::Any visitDis_and_expr(AssertionParser::Dis_and_exprContext *ctx) override {
      z3::expr result = std::any_cast<z3::expr>(visit(ctx->dis_conv_expr(0)));
      for (int i = 1; i < ctx->dis_conv_expr().size(); i++) {
        z3::expr rhs = std::any_cast<z3::expr>(visit(ctx->dis_conv_expr(i)));
        result = result && rhs;
      }
      return result;
  }

  antlrcpp::Any visitDis_conv_expr(AssertionParser::Dis_conv_exprContext *ctx) override {

      if (auto simple = dynamic_cast<AssertionParser::Conv_simple_caseContext*>(ctx)) {
        // Case: dis_not_expr
        z3::expr e = std::any_cast<z3::expr>(visit(simple->dis_not_expr()));
        return e;
      }

      if (auto complex = dynamic_cast<AssertionParser::Conv_complex_caseContext*>(ctx)) {



        auto current_ensemble = ensemble_stack.back();
        z3::sort R = context.real_sort();
        z3::expr_vector bound_vars(context); // bounded variables to existentially quantify the existence of
        z3::expr sum1 = context.real_val("0");
        z3::expr sum2 = context.real_val("0");
        z3::expr body = context.bool_val(true);

        Ensemble<z3::expr> ensemble1(current_ensemble.precision);
        Ensemble<z3::expr> ensemble2(current_ensemble.precision);

        for (int i = 0; i < current_ensemble.probs.size(); i++) {
          Z3_ast b1 = Z3_mk_bound(context, 2*i, R);  // raw AST for bound variable
          bound_vars.push_back(z3::expr(context, b1));
          sum1 = sum1 + bound_vars.back();
          body = body && (bound_vars.back() >= 0);
          auto temp = bound_vars.back();
          ensemble1.insert_prob(current_ensemble.probs[i].first, temp);

          Z3_ast b2 = Z3_mk_bound(context, 2*i+1, R);  // raw AST for bound variable
          bound_vars.push_back(z3::expr(context, b2));
          sum2 = sum2 + bound_vars.back();
          body = body && (bound_vars.back() >= 0);
          temp = bound_vars.back();
          ensemble2.insert_prob(current_ensemble.probs[i].first, temp);
        }


        body = body && (sum1 ==1) && (sum2 == 1);
        Z3_ast p_ = Z3_mk_bound(context, current_ensemble.probs.size()*2, R);  // raw AST for bound variable
        auto p = z3::expr(context, p_);

        z3::expr body0 = context.bool_val(true);
        z3::expr body1 = context.bool_val(true);
        z3::expr mix_body = context.bool_val(true);
        for (int i = 0; i < current_ensemble.probs.size(); i++) {
            body0 = body0 && (ensemble1.probs[i].second == current_ensemble.probs[i].second);
            body1 = body1 && (ensemble2.probs[i].second == current_ensemble.probs[i].second);
            mix_body = mix_body && ((1-p) *ensemble1.probs[i].second + p * ensemble2.probs[i].second == current_ensemble.probs[i].second);
        }

        body = body && (sum1 ==1) && (sum2 == 1) && (p >= 0) && (p <= 0) && z3::implies(p == 0, body0) &&
          z3::implies(p == 1, body1), z3::implies( p > 0 && p < 1, mix_body);

        ensemble_stack.push_back(ensemble1);
        z3::expr left = std::any_cast<z3::expr>(visit(complex->dis_not_expr(0)));
        ensemble_stack.pop_back();

        ensemble_stack.push_back(ensemble2);
        z3::expr right = std::any_cast<z3::expr>(visit(complex->dis_not_expr(1)));
        ensemble_stack.pop_back();

        body = body && left && right;

        bound_vars.push_back(p);
        return z3::exists(bound_vars, body);
      }

      throw std::runtime_error("Unknown alternative in dis_conv_expr");
  }

  antlrcpp::Any visitDis_not_expr(AssertionParser::Dis_not_exprContext *ctx) override {

      if (auto negated = dynamic_cast<AssertionParser::Dis_notContext*>(ctx)) {
        return !std::any_cast<z3::expr>(visit(negated->dis_not_expr()));
      }

      if (auto non_negated = dynamic_cast<AssertionParser::Dis_assertionContext*>(ctx)) {
        return std::any_cast<z3::expr>(visit(non_negated->distribution_assertion()));
      }

      if (auto prob_assertion = dynamic_cast<AssertionParser::Dis_prob_assertionContext*>(ctx)) {
        string prob_ = prob_assertion->REALNUM()->getText();
        auto prob = this->context.real_val(prob_.c_str());
        return std::any_cast<z3::expr>(visit(prob_assertion->probability_term())) >= prob;
      }

      throw std::runtime_error("Unknown alternative in dis_conv_expr");
  }

  antlrcpp::Any visitProbability_term(AssertionParser::Probability_termContext *ctx) override {
    if (auto symbolic = dynamic_cast<AssertionParser::Symbolic_probContext*>(ctx)) {
        z3::expr result = this->context.real_val("0");
        for (auto e : this->ensemble_stack.back().probs) {
          this->current_hs = e.first;
          if (std::any_cast<bool>(visit(symbolic->states_assertion()))) {
            result = result + e.second;
          }
        }
      return result;
    }

    if (auto concrete = dynamic_cast<AssertionParser::Concrete_probContext*>(ctx)) {
      return std::any_cast<z3::expr>(concrete->REALNUM());
    }

      throw std::runtime_error("Unknown alternative in Probability_term");
  }

  antlrcpp::Any visitStates_assertion(AssertionParser::States_assertionContext *ctx) override {
        return visit(ctx->states_or_expr());
  }


  antlrcpp::Any visitOr_expr(AssertionParser::Or_exprContext *ctx) override {
      for (auto e : ctx->states_and_expr()) {
        if (std::any_cast<bool>(visit(e))) {
          return true;
        }
      }
      return false;
  }

  antlrcpp::Any visitAnd_expr(AssertionParser::And_exprContext *ctx) override {
      for (auto e : ctx->states_not_expr()) {
        if (!std::any_cast<bool>(visit(e))) {
          return false;
        }
      }
      return true;
  }

  antlrcpp::Any visitNot_expr(AssertionParser::Not_exprContext *ctx) override {
      if (auto negated = dynamic_cast<AssertionParser::Not_exprContext*>(ctx)) {
         return !std::any_cast<bool>(visit(negated->states_not_expr()));
      }

      if (auto parens = dynamic_cast<AssertionParser::ParensContext*>(ctx)) {
        return std::any_cast<bool>(visit(parens->states_assertion()));
      }

      if (auto qexpr = dynamic_cast<AssertionParser::QCompareContext*>(ctx)) {
          assert (qexpr->quantum_term().size() == 2);
          vector<vector<double>> left = std::any_cast<vector<vector<double>>>(qexpr->quantum_term()[0]);
          vector<vector<double>> right = std::any_cast<vector<vector<double>>>(qexpr->quantum_term()[1]);
          return left == right; // FIX: This might give trouble
      }

      if (auto bexpr = dynamic_cast<AssertionParser::BCompareContext*>(ctx)) {
        assert (bexpr->binary_term().size() == 2);

        string left = std::any_cast<string>(bexpr->binary_term()[0]);
        string right = std::any_cast<string>(bexpr->binary_term()[1]);

        return left == right;
      }

      throw std::runtime_error("Unknown alternative in Not_expr");
  }

  antlrcpp::Any visitBinary_term(AssertionParser::Binary_termContext *ctx) override {
      if (auto const_str = dynamic_cast<AssertionParser::Bin_strContext*>(ctx)) {
        return const_str->getText();
      }

      if (auto b_vars_list = dynamic_cast<AssertionParser::List_b_varsContext*>(ctx)) {
          vector<int> vars = std::any_cast<vector<int>>(visit(b_vars_list->bList()));

          string result = "";

          for (auto v : vars) {
            if (current_hs->classical_state->read(v)) {
              result += "1";
            } else {
              result += "0";
            }
          }
        return result;
      }

      throw std::runtime_error("Unknown alternative in Binary_term");
    }

  antlrcpp::Any visitQuantum_term(AssertionParser::Quantum_termContext *ctx) override {
      if (auto const_qs = dynamic_cast<AssertionParser::Quantum_stateContext*>(ctx)) {
        vector<double> state = std::any_cast<vector<double>>(const_qs->row());

        vector<vector<double>> result;
        for (int i = 0; i < state.size(); i++) {
          vector<double> current_row;
          for (int j = 0; j < state.size(); j++) {
            current_row.push_back(state[i] * state[j]);
          }
          result.push_back(current_row);
        }
        return result;
      }

      if (auto q_vars_list = dynamic_cast<AssertionParser::List_q_varsContext*>(ctx)) {
        set<int> vars = std::any_cast<set<int>>(visit(q_vars_list->qList()));

        vector<int> remove_indices;

        for (auto q : this->current_hs->quantum_state->qubits_used) {
          if (vars.find(q) == vars.end()) {
            remove_indices.push_back(q);
          }
        }
        return current_hs->quantum_state->multi_partial_trace(remove_indices);
      }

      throw std::runtime_error("Unknown alternative in Quantum_term");
  }

  antlrcpp::Any visitBList(AssertionParser::BListContext *ctx) override {
        vector<int> result;
      for (auto cid : ctx->CID()) {
        int index = std::stoi(cid->toString().substr(1));
        result.push_back(index);
      }

      return result;
    }

  antlrcpp::Any visitQList(AssertionParser::QListContext *ctx) override {
      set<int> result;
      for (auto cid : ctx->QID()) {
        int index = std::stoi(cid->toString().substr(1));
        result.insert(index);
      }

      return result;
    }

  antlrcpp::Any visitRow(AssertionParser::RowContext *ctx) override {
      vector<double> result;

      for (auto e : ctx->REALNUM()) {
        result.push_back(std::any_cast<double>(e));
      }

      return result;

  }
};