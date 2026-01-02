
// Generated from grammars/PL/ProgrammingLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ProgrammingLanguageListener.h"


/**
 * This class provides an empty implementation of ProgrammingLanguageListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ProgrammingLanguageBaseListener : public ProgrammingLanguageListener {
public:

  virtual void enterLanguage(ProgrammingLanguageParser::LanguageContext * /*ctx*/) override { }
  virtual void exitLanguage(ProgrammingLanguageParser::LanguageContext * /*ctx*/) override { }

  virtual void enterUnitary(ProgrammingLanguageParser::UnitaryContext * /*ctx*/) override { }
  virtual void exitUnitary(ProgrammingLanguageParser::UnitaryContext * /*ctx*/) override { }

  virtual void enterProb(ProgrammingLanguageParser::ProbContext * /*ctx*/) override { }
  virtual void exitProb(ProgrammingLanguageParser::ProbContext * /*ctx*/) override { }

  virtual void enterSkip(ProgrammingLanguageParser::SkipContext * /*ctx*/) override { }
  virtual void exitSkip(ProgrammingLanguageParser::SkipContext * /*ctx*/) override { }

  virtual void enterClassical(ProgrammingLanguageParser::ClassicalContext * /*ctx*/) override { }
  virtual void exitClassical(ProgrammingLanguageParser::ClassicalContext * /*ctx*/) override { }

  virtual void enterIf(ProgrammingLanguageParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(ProgrammingLanguageParser::IfContext * /*ctx*/) override { }

  virtual void enterSeq(ProgrammingLanguageParser::SeqContext * /*ctx*/) override { }
  virtual void exitSeq(ProgrammingLanguageParser::SeqContext * /*ctx*/) override { }

  virtual void enterAssignZero(ProgrammingLanguageParser::AssignZeroContext * /*ctx*/) override { }
  virtual void exitAssignZero(ProgrammingLanguageParser::AssignZeroContext * /*ctx*/) override { }

  virtual void enterAssignOne(ProgrammingLanguageParser::AssignOneContext * /*ctx*/) override { }
  virtual void exitAssignOne(ProgrammingLanguageParser::AssignOneContext * /*ctx*/) override { }

  virtual void enterAssignCopy(ProgrammingLanguageParser::AssignCopyContext * /*ctx*/) override { }
  virtual void exitAssignCopy(ProgrammingLanguageParser::AssignCopyContext * /*ctx*/) override { }

  virtual void enterAssignMeasure(ProgrammingLanguageParser::AssignMeasureContext * /*ctx*/) override { }
  virtual void exitAssignMeasure(ProgrammingLanguageParser::AssignMeasureContext * /*ctx*/) override { }

  virtual void enterQlist(ProgrammingLanguageParser::QlistContext * /*ctx*/) override { }
  virtual void exitQlist(ProgrammingLanguageParser::QlistContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

