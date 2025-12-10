
// Generated from grammars/assertions/Assertion.g4 by ANTLR 4.13.2

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

    virtual std::any visitDis_not(AssertionParser::Dis_notContext *context) = 0;

    virtual std::any visitDis_not_atom(AssertionParser::Dis_not_atomContext *context) = 0;

    virtual std::any visitDis_assertion(AssertionParser::Dis_assertionContext *context) = 0;

    virtual std::any visitSymbolic_prob(AssertionParser::Symbolic_probContext *context) = 0;

    virtual std::any visitStates_assertion(AssertionParser::States_assertionContext *context) = 0;

    virtual std::any visitOr_expr(AssertionParser::Or_exprContext *context) = 0;

    virtual std::any visitAnd_expr(AssertionParser::And_exprContext *context) = 0;

    virtual std::any visitNot_expr(AssertionParser::Not_exprContext *context) = 0;

    virtual std::any visitStates_atom_rule(AssertionParser::States_atom_ruleContext *context) = 0;

    virtual std::any visitQterm(AssertionParser::QtermContext *context) = 0;

    virtual std::any visitBterm(AssertionParser::BtermContext *context) = 0;

    virtual std::any visitVectorTerm(AssertionParser::VectorTermContext *context) = 0;

    virtual std::any visitMatrixVectorTerm(AssertionParser::MatrixVectorTermContext *context) = 0;

    virtual std::any visitQVarVector(AssertionParser::QVarVectorContext *context) = 0;

    virtual std::any visitNumericVector(AssertionParser::NumericVectorContext *context) = 0;

    virtual std::any visitRow(AssertionParser::RowContext *context) = 0;

    virtual std::any visitComplexRealImag(AssertionParser::ComplexRealImagContext *context) = 0;

    virtual std::any visitRealPart(AssertionParser::RealPartContext *context) = 0;

    virtual std::any visitImagPart(AssertionParser::ImagPartContext *context) = 0;

    virtual std::any visitMatrix(AssertionParser::MatrixContext *context) = 0;

    virtual std::any visitBList(AssertionParser::BListContext *context) = 0;

    virtual std::any visitQList(AssertionParser::QListContext *context) = 0;


};

