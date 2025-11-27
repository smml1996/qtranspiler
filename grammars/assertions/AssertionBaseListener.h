
// Generated from grammars/assertions/Assertion.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "AssertionListener.h"


/**
 * This class provides an empty implementation of AssertionListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AssertionBaseListener : public AssertionListener {
public:

  virtual void enterAssertion(AssertionParser::AssertionContext * /*ctx*/) override { }
  virtual void exitAssertion(AssertionParser::AssertionContext * /*ctx*/) override { }

  virtual void enterDistribution_assertion(AssertionParser::Distribution_assertionContext * /*ctx*/) override { }
  virtual void exitDistribution_assertion(AssertionParser::Distribution_assertionContext * /*ctx*/) override { }

  virtual void enterDis_or_expr(AssertionParser::Dis_or_exprContext * /*ctx*/) override { }
  virtual void exitDis_or_expr(AssertionParser::Dis_or_exprContext * /*ctx*/) override { }

  virtual void enterDis_and_expr(AssertionParser::Dis_and_exprContext * /*ctx*/) override { }
  virtual void exitDis_and_expr(AssertionParser::Dis_and_exprContext * /*ctx*/) override { }

  virtual void enterConv_simple_case(AssertionParser::Conv_simple_caseContext * /*ctx*/) override { }
  virtual void exitConv_simple_case(AssertionParser::Conv_simple_caseContext * /*ctx*/) override { }

  virtual void enterConv_complex_case(AssertionParser::Conv_complex_caseContext * /*ctx*/) override { }
  virtual void exitConv_complex_case(AssertionParser::Conv_complex_caseContext * /*ctx*/) override { }

  virtual void enterDis_not(AssertionParser::Dis_notContext * /*ctx*/) override { }
  virtual void exitDis_not(AssertionParser::Dis_notContext * /*ctx*/) override { }

  virtual void enterDis_assertion(AssertionParser::Dis_assertionContext * /*ctx*/) override { }
  virtual void exitDis_assertion(AssertionParser::Dis_assertionContext * /*ctx*/) override { }

  virtual void enterDis_prob_assertion(AssertionParser::Dis_prob_assertionContext * /*ctx*/) override { }
  virtual void exitDis_prob_assertion(AssertionParser::Dis_prob_assertionContext * /*ctx*/) override { }

  virtual void enterSymbolic_prob(AssertionParser::Symbolic_probContext * /*ctx*/) override { }
  virtual void exitSymbolic_prob(AssertionParser::Symbolic_probContext * /*ctx*/) override { }

  virtual void enterConcrete_prob(AssertionParser::Concrete_probContext * /*ctx*/) override { }
  virtual void exitConcrete_prob(AssertionParser::Concrete_probContext * /*ctx*/) override { }

  virtual void enterStates_assertion(AssertionParser::States_assertionContext * /*ctx*/) override { }
  virtual void exitStates_assertion(AssertionParser::States_assertionContext * /*ctx*/) override { }

  virtual void enterOr_expr(AssertionParser::Or_exprContext * /*ctx*/) override { }
  virtual void exitOr_expr(AssertionParser::Or_exprContext * /*ctx*/) override { }

  virtual void enterAnd_expr(AssertionParser::And_exprContext * /*ctx*/) override { }
  virtual void exitAnd_expr(AssertionParser::And_exprContext * /*ctx*/) override { }

  virtual void enterNot_expr(AssertionParser::Not_exprContext * /*ctx*/) override { }
  virtual void exitNot_expr(AssertionParser::Not_exprContext * /*ctx*/) override { }

  virtual void enterQCompare(AssertionParser::QCompareContext * /*ctx*/) override { }
  virtual void exitQCompare(AssertionParser::QCompareContext * /*ctx*/) override { }

  virtual void enterBCompare(AssertionParser::BCompareContext * /*ctx*/) override { }
  virtual void exitBCompare(AssertionParser::BCompareContext * /*ctx*/) override { }

  virtual void enterParens(AssertionParser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(AssertionParser::ParensContext * /*ctx*/) override { }

  virtual void enterList_b_vars(AssertionParser::List_b_varsContext * /*ctx*/) override { }
  virtual void exitList_b_vars(AssertionParser::List_b_varsContext * /*ctx*/) override { }

  virtual void enterBin_str(AssertionParser::Bin_strContext * /*ctx*/) override { }
  virtual void exitBin_str(AssertionParser::Bin_strContext * /*ctx*/) override { }

  virtual void enterList_q_vars(AssertionParser::List_q_varsContext * /*ctx*/) override { }
  virtual void exitList_q_vars(AssertionParser::List_q_varsContext * /*ctx*/) override { }

  virtual void enterQuantum_state(AssertionParser::Quantum_stateContext * /*ctx*/) override { }
  virtual void exitQuantum_state(AssertionParser::Quantum_stateContext * /*ctx*/) override { }

  virtual void enterRow(AssertionParser::RowContext * /*ctx*/) override { }
  virtual void exitRow(AssertionParser::RowContext * /*ctx*/) override { }

  virtual void enterBList(AssertionParser::BListContext * /*ctx*/) override { }
  virtual void exitBList(AssertionParser::BListContext * /*ctx*/) override { }

  virtual void enterQList(AssertionParser::QListContext * /*ctx*/) override { }
  virtual void exitQList(AssertionParser::QListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

