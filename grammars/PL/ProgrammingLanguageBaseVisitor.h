
// Generated from ../grammars/PL/ProgrammingLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ProgrammingLanguageVisitor.h"


/**
 * This class provides an empty implementation of ProgrammingLanguageVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ProgrammingLanguageBaseVisitor : public ProgrammingLanguageVisitor {
public:

  virtual std::any visitLanguage(ProgrammingLanguageParser::LanguageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitary(ProgrammingLanguageParser::UnitaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProb(ProgrammingLanguageParser::ProbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSkip(ProgrammingLanguageParser::SkipContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassical(ProgrammingLanguageParser::ClassicalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf(ProgrammingLanguageParser::IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSeq(ProgrammingLanguageParser::SeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignZero(ProgrammingLanguageParser::AssignZeroContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignOne(ProgrammingLanguageParser::AssignOneContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignCopy(ProgrammingLanguageParser::AssignCopyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignMeasure(ProgrammingLanguageParser::AssignMeasureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQlist(ProgrammingLanguageParser::QlistContext *ctx) override {
    return visitChildren(ctx);
  }


};

