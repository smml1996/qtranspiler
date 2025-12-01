
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

  virtual std::any visitSymbolic_prob(AssertionParser::Symbolic_probContext *ctx) override {
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

  virtual std::any visitRow(AssertionParser::RowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBList(AssertionParser::BListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQList(AssertionParser::QListContext *ctx) override {
    return visitChildren(ctx);
  }


};

