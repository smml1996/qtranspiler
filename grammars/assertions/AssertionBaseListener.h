
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

  virtual void enterDis_conv_expr(AssertionParser::Dis_conv_exprContext * /*ctx*/) override { }
  virtual void exitDis_conv_expr(AssertionParser::Dis_conv_exprContext * /*ctx*/) override { }

  virtual void enterDis_not(AssertionParser::Dis_notContext * /*ctx*/) override { }
  virtual void exitDis_not(AssertionParser::Dis_notContext * /*ctx*/) override { }

  virtual void enterDis_not_atom(AssertionParser::Dis_not_atomContext * /*ctx*/) override { }
  virtual void exitDis_not_atom(AssertionParser::Dis_not_atomContext * /*ctx*/) override { }

  virtual void enterDis_assertion(AssertionParser::Dis_assertionContext * /*ctx*/) override { }
  virtual void exitDis_assertion(AssertionParser::Dis_assertionContext * /*ctx*/) override { }

  virtual void enterSymbolic_prob(AssertionParser::Symbolic_probContext * /*ctx*/) override { }
  virtual void exitSymbolic_prob(AssertionParser::Symbolic_probContext * /*ctx*/) override { }

  virtual void enterStates_assertion(AssertionParser::States_assertionContext * /*ctx*/) override { }
  virtual void exitStates_assertion(AssertionParser::States_assertionContext * /*ctx*/) override { }

  virtual void enterOr_expr(AssertionParser::Or_exprContext * /*ctx*/) override { }
  virtual void exitOr_expr(AssertionParser::Or_exprContext * /*ctx*/) override { }

  virtual void enterAnd_expr(AssertionParser::And_exprContext * /*ctx*/) override { }
  virtual void exitAnd_expr(AssertionParser::And_exprContext * /*ctx*/) override { }

  virtual void enterNot_expr(AssertionParser::Not_exprContext * /*ctx*/) override { }
  virtual void exitNot_expr(AssertionParser::Not_exprContext * /*ctx*/) override { }

  virtual void enterStates_atom_rule(AssertionParser::States_atom_ruleContext * /*ctx*/) override { }
  virtual void exitStates_atom_rule(AssertionParser::States_atom_ruleContext * /*ctx*/) override { }

  virtual void enterQterm(AssertionParser::QtermContext * /*ctx*/) override { }
  virtual void exitQterm(AssertionParser::QtermContext * /*ctx*/) override { }

  virtual void enterBterm(AssertionParser::BtermContext * /*ctx*/) override { }
  virtual void exitBterm(AssertionParser::BtermContext * /*ctx*/) override { }

  virtual void enterVectorTerm(AssertionParser::VectorTermContext * /*ctx*/) override { }
  virtual void exitVectorTerm(AssertionParser::VectorTermContext * /*ctx*/) override { }

  virtual void enterMatrixVectorTerm(AssertionParser::MatrixVectorTermContext * /*ctx*/) override { }
  virtual void exitMatrixVectorTerm(AssertionParser::MatrixVectorTermContext * /*ctx*/) override { }

  virtual void enterQVarVector(AssertionParser::QVarVectorContext * /*ctx*/) override { }
  virtual void exitQVarVector(AssertionParser::QVarVectorContext * /*ctx*/) override { }

  virtual void enterNumericVector(AssertionParser::NumericVectorContext * /*ctx*/) override { }
  virtual void exitNumericVector(AssertionParser::NumericVectorContext * /*ctx*/) override { }

  virtual void enterRow(AssertionParser::RowContext * /*ctx*/) override { }
  virtual void exitRow(AssertionParser::RowContext * /*ctx*/) override { }

  virtual void enterComplexRealImag(AssertionParser::ComplexRealImagContext * /*ctx*/) override { }
  virtual void exitComplexRealImag(AssertionParser::ComplexRealImagContext * /*ctx*/) override { }

  virtual void enterRealPart(AssertionParser::RealPartContext * /*ctx*/) override { }
  virtual void exitRealPart(AssertionParser::RealPartContext * /*ctx*/) override { }

  virtual void enterImagPart(AssertionParser::ImagPartContext * /*ctx*/) override { }
  virtual void exitImagPart(AssertionParser::ImagPartContext * /*ctx*/) override { }

  virtual void enterMatrix(AssertionParser::MatrixContext * /*ctx*/) override { }
  virtual void exitMatrix(AssertionParser::MatrixContext * /*ctx*/) override { }

  virtual void enterBList(AssertionParser::BListContext * /*ctx*/) override { }
  virtual void exitBList(AssertionParser::BListContext * /*ctx*/) override { }

  virtual void enterQList(AssertionParser::QListContext * /*ctx*/) override { }
  virtual void exitQList(AssertionParser::QListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

