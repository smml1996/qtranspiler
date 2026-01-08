
// Generated from grammars/PL/ProgrammingLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  ProgrammingLanguageLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, MEASURE = 3, SKIPKW = 4, SEMICOLON = 5, IF = 6, 
    ELSE = 7, LPAREN = 8, RPAREN = 9, LBRACE = 10, RBRACE = 11, LBRACKET = 12, 
    RBRACKET = 13, PERCENT = 14, WS = 15, UNITARY = 16, REALNUM = 17, CID = 18, 
    QID = 19
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

