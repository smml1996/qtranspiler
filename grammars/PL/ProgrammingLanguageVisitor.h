
// Generated from grammars/PL/ProgrammingLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ProgrammingLanguageParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ProgrammingLanguageParser.
 */
class  ProgrammingLanguageVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ProgrammingLanguageParser.
   */
    virtual std::any visitLanguage(ProgrammingLanguageParser::LanguageContext *context) = 0;

    virtual std::any visitUnitary(ProgrammingLanguageParser::UnitaryContext *context) = 0;

    virtual std::any visitProb(ProgrammingLanguageParser::ProbContext *context) = 0;

    virtual std::any visitSkip(ProgrammingLanguageParser::SkipContext *context) = 0;

    virtual std::any visitClassical(ProgrammingLanguageParser::ClassicalContext *context) = 0;

    virtual std::any visitIf(ProgrammingLanguageParser::IfContext *context) = 0;

    virtual std::any visitSeq(ProgrammingLanguageParser::SeqContext *context) = 0;

    virtual std::any visitConstAssign(ProgrammingLanguageParser::ConstAssignContext *context) = 0;

    virtual std::any visitAssignCopy(ProgrammingLanguageParser::AssignCopyContext *context) = 0;

    virtual std::any visitAssignMeasure(ProgrammingLanguageParser::AssignMeasureContext *context) = 0;

    virtual std::any visitQlist(ProgrammingLanguageParser::QlistContext *context) = 0;


};

