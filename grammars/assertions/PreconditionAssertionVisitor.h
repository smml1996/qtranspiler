
// Generated from ../grammars/assertions/PreconditionAssertion.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PreconditionAssertionParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PreconditionAssertionParser.
 */
class  PreconditionAssertionVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PreconditionAssertionParser.
   */
    virtual std::any visitPrecon_assertion(PreconditionAssertionParser::Precon_assertionContext *context) = 0;

    virtual std::any visitDistribution_assertion(PreconditionAssertionParser::Distribution_assertionContext *context) = 0;

    virtual std::any visitSingle_distribution(PreconditionAssertionParser::Single_distributionContext *context) = 0;

    virtual std::any visitCanon_clause(PreconditionAssertionParser::Canon_clauseContext *context) = 0;

    virtual std::any visitCanon_state(PreconditionAssertionParser::Canon_stateContext *context) = 0;

    virtual std::any visitRow(PreconditionAssertionParser::RowContext *context) = 0;

    virtual std::any visitBList(PreconditionAssertionParser::BListContext *context) = 0;

    virtual std::any visitQList(PreconditionAssertionParser::QListContext *context) = 0;


};

