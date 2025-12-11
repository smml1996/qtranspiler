
// Generated from grammars/assertions/Assertion.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "AssertionVisitor.h"


/**
 * This class provides an empty implementation of AssertionVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  AssertionBaseVisitor : public AssertionVisitor {
public:

  virtual std::any visitAssertion(AssertionParser::AssertionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDistribution_assertion(AssertionParser::Distribution_assertionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDis_or_expr(AssertionParser::Dis_or_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDis_and_expr(AssertionParser::Dis_and_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDis_conv_expr(AssertionParser::Dis_conv_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDis_not(AssertionParser::Dis_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDis_not_atom(AssertionParser::Dis_not_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDis_assertion(AssertionParser::Dis_assertionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_terminal(AssertionParser::Atom_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrace_prob(AssertionParser::Trace_probContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSymbolic_prob(AssertionParser::Symbolic_probContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_prob(AssertionParser::Const_probContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStates_assertion(AssertionParser::States_assertionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOr_expr(AssertionParser::Or_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnd_expr(AssertionParser::And_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNot_expr(AssertionParser::Not_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStates_atom_rule(AssertionParser::States_atom_ruleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQterm(AssertionParser::QtermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBterm(AssertionParser::BtermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVectorTerm(AssertionParser::VectorTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatrixVectorTerm(AssertionParser::MatrixVectorTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQVarVector(AssertionParser::QVarVectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumericVector(AssertionParser::NumericVectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRow(AssertionParser::RowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComplexRealImag(AssertionParser::ComplexRealImagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRealPart(AssertionParser::RealPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImagPart(AssertionParser::ImagPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatrix(AssertionParser::MatrixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBList(AssertionParser::BListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQList(AssertionParser::QListContext *ctx) override {
    return visitChildren(ctx);
  }


};

