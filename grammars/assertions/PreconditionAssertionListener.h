
// Generated from grammars/assertions/PreconditionAssertion.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PreconditionAssertionParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by PreconditionAssertionParser.
 */
class  PreconditionAssertionListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterPrecon_assertion(PreconditionAssertionParser::Precon_assertionContext *ctx) = 0;
  virtual void exitPrecon_assertion(PreconditionAssertionParser::Precon_assertionContext *ctx) = 0;

  virtual void enterDistribution_assertion(PreconditionAssertionParser::Distribution_assertionContext *ctx) = 0;
  virtual void exitDistribution_assertion(PreconditionAssertionParser::Distribution_assertionContext *ctx) = 0;

  virtual void enterPolygon_assertion(PreconditionAssertionParser::Polygon_assertionContext *ctx) = 0;
  virtual void exitPolygon_assertion(PreconditionAssertionParser::Polygon_assertionContext *ctx) = 0;

  virtual void enterSingle_distribution(PreconditionAssertionParser::Single_distributionContext *ctx) = 0;
  virtual void exitSingle_distribution(PreconditionAssertionParser::Single_distributionContext *ctx) = 0;

  virtual void enterCanon_clause(PreconditionAssertionParser::Canon_clauseContext *ctx) = 0;
  virtual void exitCanon_clause(PreconditionAssertionParser::Canon_clauseContext *ctx) = 0;

  virtual void enterCanon_state(PreconditionAssertionParser::Canon_stateContext *ctx) = 0;
  virtual void exitCanon_state(PreconditionAssertionParser::Canon_stateContext *ctx) = 0;

  virtual void enterRow(PreconditionAssertionParser::RowContext *ctx) = 0;
  virtual void exitRow(PreconditionAssertionParser::RowContext *ctx) = 0;

  virtual void enterBList(PreconditionAssertionParser::BListContext *ctx) = 0;
  virtual void exitBList(PreconditionAssertionParser::BListContext *ctx) = 0;

  virtual void enterQList(PreconditionAssertionParser::QListContext *ctx) = 0;
  virtual void exitQList(PreconditionAssertionParser::QListContext *ctx) = 0;


};

