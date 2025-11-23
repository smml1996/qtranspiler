
// Generated from ../grammars/assertions/PreconditionAssertion.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PreconditionAssertionVisitor.h"


/**
 * This class provides an empty implementation of PreconditionAssertionVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PreconditionAssertionBaseVisitor : public PreconditionAssertionVisitor {
public:

  virtual std::any visitPrecon_assertion(PreconditionAssertionParser::Precon_assertionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDistribution_assertion(PreconditionAssertionParser::Distribution_assertionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingle_distribution(PreconditionAssertionParser::Single_distributionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCanon_clause(PreconditionAssertionParser::Canon_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCanon_state(PreconditionAssertionParser::Canon_stateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRow(PreconditionAssertionParser::RowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBList(PreconditionAssertionParser::BListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQList(PreconditionAssertionParser::QListContext *ctx) override {
    return visitChildren(ctx);
  }


};

