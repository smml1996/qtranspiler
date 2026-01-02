
// Generated from grammars/PL/ProgrammingLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  ProgrammingLanguageLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, MEASURE = 5, SKIPKW = 6, SEMICOLON = 7, 
    IF = 8, ELSE = 9, LPAREN = 10, RPAREN = 11, LBRACE = 12, RBRACE = 13, 
    LBRACKET = 14, RBRACKET = 15, PERCENT = 16, WS = 17, UNITARY = 18, REALNUM = 19, 
    INTEGER = 20, CID = 21, QID = 22
  };

  explicit ProgrammingLanguageLexer(antlr4::CharStream *input);

  ~ProgrammingLanguageLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

