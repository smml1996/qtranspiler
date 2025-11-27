
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

  virtual void enterConv_simple_case(AssertionParser::Conv_simple_caseContext *ctx) = 0;
  virtual void exitConv_simple_case(AssertionParser::Conv_simple_caseContext *ctx) = 0;

  virtual void enterConv_complex_case(AssertionParser::Conv_complex_caseContext *ctx) = 0;
  virtual void exitConv_complex_case(AssertionParser::Conv_complex_caseContext *ctx) = 0;

  virtual void enterDis_not(AssertionParser::Dis_notContext *ctx) = 0;
  virtual void exitDis_not(AssertionParser::Dis_notContext *ctx) = 0;

  virtual void enterDis_assertion(AssertionParser::Dis_assertionContext *ctx) = 0;
  virtual void exitDis_assertion(AssertionParser::Dis_assertionContext *ctx) = 0;

  virtual void enterDis_prob_assertion(AssertionParser::Dis_prob_assertionContext *ctx) = 0;
  virtual void exitDis_prob_assertion(AssertionParser::Dis_prob_assertionContext *ctx) = 0;

  virtual void enterSymbolic_prob(AssertionParser::Symbolic_probContext *ctx) = 0;
  virtual void exitSymbolic_prob(AssertionParser::Symbolic_probContext *ctx) = 0;

  virtual void enterConcrete_prob(AssertionParser::Concrete_probContext *ctx) = 0;
  virtual void exitConcrete_prob(AssertionParser::Concrete_probContext *ctx) = 0;

  virtual void enterStates_assertion(AssertionParser::States_assertionContext *ctx) = 0;
  virtual void exitStates_assertion(AssertionParser::States_assertionContext *ctx) = 0;

  virtual void enterOr_expr(AssertionParser::Or_exprContext *ctx) = 0;
  virtual void exitOr_expr(AssertionParser::Or_exprContext *ctx) = 0;

  virtual void enterAnd_expr(AssertionParser::And_exprContext *ctx) = 0;
  virtual void exitAnd_expr(AssertionParser::And_exprContext *ctx) = 0;

  virtual void enterNot_expr(AssertionParser::Not_exprContext *ctx) = 0;
  virtual void exitNot_expr(AssertionParser::Not_exprContext *ctx) = 0;

  virtual void enterQCompare(AssertionParser::QCompareContext *ctx) = 0;
  virtual void exitQCompare(AssertionParser::QCompareContext *ctx) = 0;

  virtual void enterBCompare(AssertionParser::BCompareContext *ctx) = 0;
  virtual void exitBCompare(AssertionParser::BCompareContext *ctx) = 0;

  virtual void enterParens(AssertionParser::ParensContext *ctx) = 0;
  virtual void exitParens(AssertionParser::ParensContext *ctx) = 0;

  virtual void enterList_b_vars(AssertionParser::List_b_varsContext *ctx) = 0;
  virtual void exitList_b_vars(AssertionParser::List_b_varsContext *ctx) = 0;

  virtual void enterBin_str(AssertionParser::Bin_strContext *ctx) = 0;
  virtual void exitBin_str(AssertionParser::Bin_strContext *ctx) = 0;

  virtual void enterList_q_vars(AssertionParser::List_q_varsContext *ctx) = 0;
  virtual void exitList_q_vars(AssertionParser::List_q_varsContext *ctx) = 0;

  virtual void enterQuantum_state(AssertionParser::Quantum_stateContext *ctx) = 0;
  virtual void exitQuantum_state(AssertionParser::Quantum_stateContext *ctx) = 0;

  virtual void enterRow(AssertionParser::RowContext *ctx) = 0;
  virtual void exitRow(AssertionParser::RowContext *ctx) = 0;

  virtual void enterBList(AssertionParser::BListContext *ctx) = 0;
  virtual void exitBList(AssertionParser::BListContext *ctx) = 0;

  virtual void enterQList(AssertionParser::QListContext *ctx) = 0;
  virtual void exitQList(AssertionParser::QListContext *ctx) = 0;


};

