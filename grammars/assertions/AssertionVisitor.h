
// Generated from ./grammars/assertions/Assertion.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "AssertionParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by AssertionParser.
 */
class  AssertionVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by AssertionParser.
   */
    virtual std::any visitAssertion(AssertionParser::AssertionContext *context) = 0;

    virtual std::any visitDistribution_assertion(AssertionParser::Distribution_assertionContext *context) = 0;

    virtual std::any visitDis_or_expr(AssertionParser::Dis_or_exprContext *context) = 0;

    virtual std::any visitDis_and_expr(AssertionParser::Dis_and_exprContext *context) = 0;

    virtual std::any visitDis_conv_expr(AssertionParser::Dis_conv_exprContext *context) = 0;

    virtual std::any visitDis_not_expr(AssertionParser::Dis_not_exprContext *context) = 0;

    virtual std::any visitProbability_term(AssertionParser::Probability_termContext *context) = 0;

    virtual std::any visitStates_assertion(AssertionParser::States_assertionContext *context) = 0;

    virtual std::any visitOr_expr(AssertionParser::Or_exprContext *context) = 0;

    virtual std::any visitAnd_expr(AssertionParser::And_exprContext *context) = 0;

    virtual std::any visitNot_expr(AssertionParser::Not_exprContext *context) = 0;

    virtual std::any visitQCompare(AssertionParser::QCompareContext *context) = 0;

    virtual std::any visitBCompare(AssertionParser::BCompareContext *context) = 0;

    virtual std::any visitParens(AssertionParser::ParensContext *context) = 0;

    virtual std::any visitBinary_term(AssertionParser::Binary_termContext *context) = 0;

    virtual std::any visitQuantum_term(AssertionParser::Quantum_termContext *context) = 0;

    virtual std::any visitMatrix(AssertionParser::MatrixContext *context) = 0;


};

