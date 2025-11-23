
// Generated from ../grammars/PL/ProgrammingLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ProgrammingLanguageParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ProgrammingLanguageParser.
 */
class  ProgrammingLanguageListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterLanguage(ProgrammingLanguageParser::LanguageContext *ctx) = 0;
  virtual void exitLanguage(ProgrammingLanguageParser::LanguageContext *ctx) = 0;

  virtual void enterUnitary(ProgrammingLanguageParser::UnitaryContext *ctx) = 0;
  virtual void exitUnitary(ProgrammingLanguageParser::UnitaryContext *ctx) = 0;

  virtual void enterProb(ProgrammingLanguageParser::ProbContext *ctx) = 0;
  virtual void exitProb(ProgrammingLanguageParser::ProbContext *ctx) = 0;

  virtual void enterSkip(ProgrammingLanguageParser::SkipContext *ctx) = 0;
  virtual void exitSkip(ProgrammingLanguageParser::SkipContext *ctx) = 0;

  virtual void enterClassical(ProgrammingLanguageParser::ClassicalContext *ctx) = 0;
  virtual void exitClassical(ProgrammingLanguageParser::ClassicalContext *ctx) = 0;

  virtual void enterIf(ProgrammingLanguageParser::IfContext *ctx) = 0;
  virtual void exitIf(ProgrammingLanguageParser::IfContext *ctx) = 0;

  virtual void enterSeq(ProgrammingLanguageParser::SeqContext *ctx) = 0;
  virtual void exitSeq(ProgrammingLanguageParser::SeqContext *ctx) = 0;

  virtual void enterAssignZero(ProgrammingLanguageParser::AssignZeroContext *ctx) = 0;
  virtual void exitAssignZero(ProgrammingLanguageParser::AssignZeroContext *ctx) = 0;

  virtual void enterAssignOne(ProgrammingLanguageParser::AssignOneContext *ctx) = 0;
  virtual void exitAssignOne(ProgrammingLanguageParser::AssignOneContext *ctx) = 0;

  virtual void enterAssignCopy(ProgrammingLanguageParser::AssignCopyContext *ctx) = 0;
  virtual void exitAssignCopy(ProgrammingLanguageParser::AssignCopyContext *ctx) = 0;

  virtual void enterAssignMeasure(ProgrammingLanguageParser::AssignMeasureContext *ctx) = 0;
  virtual void exitAssignMeasure(ProgrammingLanguageParser::AssignMeasureContext *ctx) = 0;

  virtual void enterQlist(ProgrammingLanguageParser::QlistContext *ctx) = 0;
  virtual void exitQlist(ProgrammingLanguageParser::QlistContext *ctx) = 0;


};

