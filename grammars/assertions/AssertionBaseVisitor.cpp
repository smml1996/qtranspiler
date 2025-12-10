
// Generated from grammars/assertions/Assertion.g4 by ANTLR 4.13.2


#include "AssertionBaseVisitor.h"



// Generated from grammars/assertions/Assertion.g4 by ANTLR 4.13.2

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
    auto result = std::any_cast<z3::expr>(visit(ctx->dis_and_expr(0)));

    for (int i = 1; i < ctx->dis_and_expr().size(); i++) {
      auto rhs = std::any_cast<z3::expr>(visit(ctx->dis_and_expr(i)));
      result = result || rhs;
    }
    return result;
  }

  antlrcpp::Any visitDis_and_expr(AssertionParser::Dis_and_exprContext *ctx) override {
    auto result = std::any_cast<z3::expr>(visit(ctx->dis_conv_expr(0)));
    for (int i = 1; i < ctx->dis_conv_expr().size(); i++) {
      auto rhs = std::any_cast<z3::expr>(visit(ctx->dis_conv_expr(i)));
      result = result && rhs;
    }
    return result;
  }

  antlrcpp::Any visitDis_conv_expr(AssertionParser::Dis_conv_exprContext *ctx) override {
    assert(!ctx->dis_not_expr().empty());
    if (ctx->dis_not_expr().size()  == 1) {
      // Case: dis_not_expr
      auto e = std::any_cast<z3::expr>(visit(ctx->dis_not_expr(0)));
      return e;
    }

    if (ctx->dis_not_expr().size() != 2) {
      throw runtime_error("Invalid dis_conv_expr size. Convex expression not implemented for size larger than 2 ");
    }
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
    auto left = std::any_cast<z3::expr>(visit(ctx->dis_not_expr(0)));
    ensemble_stack.pop_back();

    ensemble_stack.push_back(ensemble2);
    auto right = std::any_cast<z3::expr>(visit(ctx->dis_not_expr(1)));
    ensemble_stack.pop_back();

    body = body && left && right;

    bound_vars.push_back(p);
    return z3::exists(bound_vars, body);

  }

  antlrcpp::Any visitDis_not(AssertionParser::Dis_notContext *ctx) override {
    if (auto non_negated = dynamic_cast<AssertionParser::Dis_atomContext*>(ctx)) {
      return std::any_cast<z3::expr>(visit(non_negated));
    }
    return !std::any_cast<z3::expr>(visit(ctx->dis_not_expr()));
  }


  antlrcpp::Any visitSymbolic_prob(AssertionParser::Symbolic_probContext *ctx) override {
    z3::expr result = this->context.real_val("0");
    for (const auto& e : this->ensemble_stack.back().probs) {
      this->current_hs = e.first;
      if (std::any_cast<bool>(visit(ctx->states_assertion()))) {
        result = result + e.second;
      }
    }

    z3::expr const_ = this->context.real_val(ctx->REALNUM()->getText().c_str());
    return result >= const_;
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
      return !std::any_cast<bool>(visit(ctx->states_not_expr()));

  }

  antlrcpp::Any visitStates_atom_rule(AssertionParser::States_atom_ruleContext *ctx) override {
    // handle visiting the atomic states
    return visit(ctx->states_atom());
  }

  antlrcpp::Any visitBterm(AssertionParser::BtermContext *ctx) override {
        vector<int> vars = Z3AssertionVisitor::get_cvars_list(ctx->bList());

        string result;

        for (auto v : vars) {
          if (current_hs->classical_state->read(v)) {
            result += "1";
          } else {
            result += "0";
          }
        }
      return result == ctx->BINARYSTRING()->getText();


    }

  antlrcpp::Any visitQterm(AssertionParser::QtermContext *ctx) override {
        auto result = std::any_cast<vector<vector<complex<double>>>>(visit(ctx->qTerm2()));
        auto pt = get_density_matrix(ctx->qList());
        return pt == result; // FIX ME: this might cause trouble
  }


  static vector<int> get_cvars_list(AssertionParser::BListContext *ctx) {
        vector<int> result;
      for (auto cid : ctx->CID()) {
        int index = std::stoi(cid->getText().substr(1));
        result.push_back(index);
      }

      return result;
    }

  static set<int> get_qvars_list(AssertionParser::QListContext *ctx) {
      set<int> result;
      for (auto cid : ctx->QID()) {
        int index = std::stoi(cid->getText().substr(1));
        result.insert(index);
      }

      return result;
  }

  vector<vector<complex<double>>> get_density_matrix(AssertionParser::QListContext *ctx) const {
    auto vars = get_qvars_list(ctx);

    vector<int> remove_indices;

    for (auto q : this->current_hs->quantum_state->qubits_used) {
      if (vars.find(q) == vars.end()) {
        remove_indices.push_back(q);
      }
    }
    return current_hs->quantum_state->multi_partial_trace(remove_indices);

  }

  antlrcpp::Any visitRow(AssertionParser::RowContext *ctx) override {
    std::vector<complex<double>> values;
    for (auto *c : ctx->complexNumber()) {
      auto val = std::any_cast<complex<double>>(visit(c));
      values.push_back(val);
    }
    return values;
  }

  antlrcpp::Any visitMatrix(AssertionParser::MatrixContext *ctx) override {
    std::vector<std::vector<complex<double>>> M;
    for (auto *rowCtx : ctx->row()) {
      auto row = std::any_cast<vector<complex<double>>>(visit(rowCtx));
      M.push_back(row);
    }
    return M;
  }

  antlrcpp::Any visitQVarVector(AssertionParser::QVarVectorContext *ctx) override {
    return get_density_matrix(ctx->qList());
  }

  antlrcpp::Any visitNumericVector(AssertionParser::NumericVectorContext *ctx) override {
    auto state = std::any_cast<vector<complex<double>>>(visit(ctx->row()));
    vector<vector<complex<double>>> result; // returns a density matrix
    for (int i = 0; i < state.size(); i++) {
      vector<complex<double>> current_row;
      current_row.reserve(state.size());
      for (int j = 0; j < state.size(); j++) {
        current_row.push_back(state[i] * conj(state[j]));
      }
      result.push_back(current_row);
    }
    return result;
  }

  antlrcpp::Any visitVectorTerm(AssertionParser::VectorTermContext *ctx) override {
    return visit(ctx->vector());
  }

  antlrcpp::Any visitMatrixVectorTerm(AssertionParser::MatrixVectorTermContext *ctx) override {
    // TODO: fix this (should handle multiplication with and without normalization)
      auto A = std::any_cast<std::vector<std::vector<std::complex<double>>>>(visit(ctx->matrix()));
      auto B = std::any_cast<std::vector<std::vector<std::complex<double>>>>(visit(ctx->vector()));

      // Dimensions
      size_t A_rows = A.size();
      size_t A_cols = A[0].size();
      size_t B_rows = B.size();
      size_t B_cols = B[0].size();

      // Check compatibility: A_cols must match B_rows
      if (A_cols != B_rows)
        throw std::runtime_error("Dimension mismatch: A columns != B rows");

      // Result matrix: A_rows × B_cols
      std::vector<std::vector<std::complex<double>>> C(
          A_rows,
          std::vector<std::complex<double>>(B_cols, {0.0, 0.0})
      );

      // Standard triple-loop matmul
      for (size_t i = 0; i < A_rows; ++i) {
        for (size_t k = 0; k < A_cols; ++k) {
          for (size_t j = 0; j < B_cols; ++j) {
            C[i][j] += A[i][k] * B[k][j];
          }
        }
      }

      return C;
  }



  antlrcpp::Any visitComplexRealImag(AssertionParser::ComplexRealImagContext *ctx) override {
    auto real = std::any_cast<double>(visitRealPart(ctx->realPart()));
    double imag = 0.0;

    if (ctx->imagPart() != nullptr) {
      imag = std::any_cast<double>(visitImagPart(ctx->imagPart()));
    }
    return complex<double>(real, imag);
  }

  antlrcpp::Any visitRealPart(AssertionParser::RealPartContext* ctx) override
  {
    std::string sign;
    if (ctx->SIGN())
      sign = ctx->SIGN()->getText();

    std::string num = ctx->REALNUM()->getText();
    return std::stod(sign + num);
  }

  antlrcpp::Any visitImagPart(AssertionParser::ImagPartContext* ctx) override
  {
    // sign
    std::string sign;
    if (ctx->SIGN())
      sign = ctx->SIGN()->getText();

    // number (might be null if the user wrote "i" or "-i")
    double magnitude = 1.0;
    if (ctx->REALNUM())
      magnitude = std::stod(ctx->REALNUM()->getText());

    // apply sign
    if (sign == "-")
      magnitude = -magnitude;

    return magnitude;
  }

};