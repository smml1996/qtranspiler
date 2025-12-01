
// Generated from grammars/assertions/Assertion.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "AssertionParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AssertionParser.
 */
class  AssertionListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAssertion(AssertionParser::AssertionContext *ctx) = 0;
  virtual void exitAssertion(AssertionParser::AssertionContext *ctx) = 0;

  virtual void enterDistribution_assertion(AssertionParser::Distribution_assertionContext *ctx) = 0;
  virtual void exitDistribution_assertion(AssertionParser::Distribution_assertionContext *ctx) = 0;

  virtual void enterDis_or_expr(AssertionParser::Dis_or_exprContext *ctx) = 0;
  virtual void exitDis_or_expr(AssertionParser::Dis_or_exprContext *ctx) = 0;

  virtual void enterDis_and_expr(AssertionParser::Dis_and_exprContext *ctx) = 0;
  virtual void exitDis_and_expr(AssertionParser::Dis_and_exprContext *ctx) = 0;

  virtual void enterDis_conv_expr(AssertionParser::Dis_conv_exprContext *ctx) = 0;
  virtual void exitDis_conv_expr(AssertionParser::Dis_conv_exprContext *ctx) = 0;

  virtual void enterDis_not(AssertionParser::Dis_notContext *ctx) = 0;
  virtual void exitDis_not(AssertionParser::Dis_notContext *ctx) = 0;

  virtual void enterDis_not_atom(AssertionParser::Dis_not_atomContext *ctx) = 0;
  virtual void exitDis_not_atom(AssertionParser::Dis_not_atomContext *ctx) = 0;

  virtual void enterDis_assertion(AssertionParser::Dis_assertionContext *ctx) = 0;
  virtual void exitDis_assertion(AssertionParser::Dis_assertionContext *ctx) = 0;

  virtual void enterSymbolic_prob(AssertionParser::Symbolic_probContext *ctx) = 0;
  virtual void exitSymbolic_prob(AssertionParser::Symbolic_probContext *ctx) = 0;

  virtual void enterStates_assertion(AssertionParser::States_assertionContext *ctx) = 0;
  virtual void exitStates_assertion(AssertionParser::States_assertionContext *ctx) = 0;

  virtual void enterOr_expr(AssertionParser::Or_exprContext *ctx) = 0;
  virtual void exitOr_expr(AssertionParser::Or_exprContext *ctx) = 0;

  virtual void enterAnd_expr(AssertionParser::And_exprContext *ctx) = 0;
  virtual void exitAnd_expr(AssertionParser::And_exprContext *ctx) = 0;

  virtual void enterNot_expr(AssertionParser::Not_exprContext *ctx) = 0;
  virtual void exitNot_expr(AssertionParser::Not_exprContext *ctx) = 0;

  virtual void enterStates_atom_rule(AssertionParser::States_atom_ruleContext *ctx) = 0;
  virtual void exitStates_atom_rule(AssertionParser::States_atom_ruleContext *ctx) = 0;

  virtual void enterQterm(AssertionParser::QtermContext *ctx) = 0;
  virtual void exitQterm(AssertionParser::QtermContext *ctx) = 0;

  virtual void enterBterm(AssertionParser::BtermContext *ctx) = 0;
  virtual void exitBterm(AssertionParser::BtermContext *ctx) = 0;

  virtual void enterRow(AssertionParser::RowContext *ctx) = 0;
  virtual void exitRow(AssertionParser::RowContext *ctx) = 0;

  virtual void enterBList(AssertionParser::BListContext *ctx) = 0;
  virtual void exitBList(AssertionParser::BListContext *ctx) = 0;

  virtual void enterQList(AssertionParser::QListContext *ctx) = 0;
  virtual void exitQList(AssertionParser::QListContext *ctx) = 0;


};

