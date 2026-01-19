
// Generated from grammars/assertions/PreconditionAssertion.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PreconditionAssertionListener.h"


/**
 * This class provides an empty implementation of PreconditionAssertionListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PreconditionAssertionBaseListener : public PreconditionAssertionListener {
public:

  virtual void enterPrecon_assertion(PreconditionAssertionParser::Precon_assertionContext * /*ctx*/) override { }
  virtual void exitPrecon_assertion(PreconditionAssertionParser::Precon_assertionContext * /*ctx*/) override { }

  virtual void enterDistribution_assertion(PreconditionAssertionParser::Distribution_assertionContext * /*ctx*/) override { }
  virtual void exitDistribution_assertion(PreconditionAssertionParser::Distribution_assertionContext * /*ctx*/) override { }

  virtual void enterPolygon_assertion(PreconditionAssertionParser::Polygon_assertionContext * /*ctx*/) override { }
  virtual void exitPolygon_assertion(PreconditionAssertionParser::Polygon_assertionContext * /*ctx*/) override { }

  virtual void enterSingle_distribution(PreconditionAssertionParser::Single_distributionContext * /*ctx*/) override { }
  virtual void exitSingle_distribution(PreconditionAssertionParser::Single_distributionContext * /*ctx*/) override { }

  virtual void enterCanon_clause(PreconditionAssertionParser::Canon_clauseContext * /*ctx*/) override { }
  virtual void exitCanon_clause(PreconditionAssertionParser::Canon_clauseContext * /*ctx*/) override { }

  virtual void enterCanon_state(PreconditionAssertionParser::Canon_stateContext * /*ctx*/) override { }
  virtual void exitCanon_state(PreconditionAssertionParser::Canon_stateContext * /*ctx*/) override { }

  virtual void enterRow(PreconditionAssertionParser::RowContext * /*ctx*/) override { }
  virtual void exitRow(PreconditionAssertionParser::RowContext * /*ctx*/) override { }

  virtual void enterBList(PreconditionAssertionParser::BListContext * /*ctx*/) override { }
  virtual void exitBList(PreconditionAssertionParser::BListContext * /*ctx*/) override { }

  virtual void enterQList(PreconditionAssertionParser::QListContext * /*ctx*/) override { }
  virtual void exitQList(PreconditionAssertionParser::QListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

