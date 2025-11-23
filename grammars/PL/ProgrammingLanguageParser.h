
// Generated from ../grammars/PL/ProgrammingLanguage.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  ProgrammingLanguageParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, MEASURE = 5, SKIPKW = 6, SEMICOLON = 7, 
    IF = 8, ELSE = 9, LPAREN = 10, RPAREN = 11, LBRACE = 12, RBRACE = 13, 
    LBRACKET = 14, RBRACKET = 15, PERCENT = 16, WS = 17, UNITARY = 18, REALNUM = 19, 
    CID = 20, QID = 21
  };

  enum {
    RuleLanguage = 0, RuleProgram = 1, RuleClassical_statement = 2, RuleQlist = 3
  };

  explicit ProgrammingLanguageParser(antlr4::TokenStream *input);

  ProgrammingLanguageParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ProgrammingLanguageParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class LanguageContext;
  class ProgramContext;
  class Classical_statementContext;
  class QlistContext; 

  class  LanguageContext : public antlr4::ParserRuleContext {
  public:
    LanguageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LanguageContext* language();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ProgramContext() = default;
    void copyFrom(ProgramContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnitaryContext : public ProgramContext {
  public:
    UnitaryContext(ProgramContext *ctx);

    antlr4::tree::TerminalNode *UNITARY();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *LBRACKET();
    QlistContext *qlist();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *RPAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ProbContext : public ProgramContext {
  public:
    ProbContext(ProgramContext *ctx);

    std::vector<ProgramContext *> program();
    ProgramContext* program(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PERCENT();
    antlr4::tree::TerminalNode* PERCENT(size_t i);
    antlr4::tree::TerminalNode *REALNUM();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SkipContext : public ProgramContext {
  public:
    SkipContext(ProgramContext *ctx);

    antlr4::tree::TerminalNode *SKIPKW();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ClassicalContext : public ProgramContext {
  public:
    ClassicalContext(ProgramContext *ctx);

    Classical_statementContext *classical_statement();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfContext : public ProgramContext {
  public:
    IfContext(ProgramContext *ctx);

    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *CID();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> LBRACE();
    antlr4::tree::TerminalNode* LBRACE(size_t i);
    std::vector<ProgramContext *> program();
    ProgramContext* program(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACE();
    antlr4::tree::TerminalNode* RBRACE(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SeqContext : public ProgramContext {
  public:
    SeqContext(ProgramContext *ctx);

    std::vector<ProgramContext *> program();
    ProgramContext* program(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  Classical_statementContext : public antlr4::ParserRuleContext {
  public:
    Classical_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Classical_statementContext() = default;
    void copyFrom(Classical_statementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AssignMeasureContext : public Classical_statementContext {
  public:
    AssignMeasureContext(Classical_statementContext *ctx);

    antlr4::tree::TerminalNode *CID();
    antlr4::tree::TerminalNode *MEASURE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *QID();
    antlr4::tree::TerminalNode *RPAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignZeroContext : public Classical_statementContext {
  public:
    AssignZeroContext(Classical_statementContext *ctx);

    antlr4::tree::TerminalNode *CID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignOneContext : public Classical_statementContext {
  public:
    AssignOneContext(Classical_statementContext *ctx);

    antlr4::tree::TerminalNode *CID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignCopyContext : public Classical_statementContext {
  public:
    AssignCopyContext(Classical_statementContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> CID();
    antlr4::tree::TerminalNode* CID(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Classical_statementContext* classical_statement();

  class  QlistContext : public antlr4::ParserRuleContext {
  public:
    QlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QID();
    antlr4::tree::TerminalNode* QID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    std::vector<int> getQList() {
      std::vector<int> result;

      for (antlr4::tree::TerminalNode* qid : this->QID()) {
        std::string text = qid->getText();    // "q0", "q1", "q23", ...
        int index = std::stoi(text.substr(1)); // drop leading 'q'
        result.push_back(index);
      }

      return result;
    }
  };

  QlistContext* qlist();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

