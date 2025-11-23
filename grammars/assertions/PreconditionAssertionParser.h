
// Generated from ../grammars/assertions/PreconditionAssertion.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  PreconditionAssertionParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, BINARYSTRING = 9, REALNUM = 10, CID = 11, QID = 12, WS = 13
  };

  enum {
    RulePrecon_assertion = 0, RuleDistribution_assertion = 1, RuleSingle_distribution = 2, 
    RuleCanon_clause = 3, RuleCanon_state = 4, RuleRow = 5, RuleBList = 6, 
    RuleQList = 7
  };

  explicit PreconditionAssertionParser(antlr4::TokenStream *input);

  PreconditionAssertionParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~PreconditionAssertionParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Precon_assertionContext;
  class Distribution_assertionContext;
  class Single_distributionContext;
  class Canon_clauseContext;
  class Canon_stateContext;
  class RowContext;
  class BListContext;
  class QListContext; 

  class  Precon_assertionContext : public antlr4::ParserRuleContext {
  public:
    Precon_assertionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Distribution_assertionContext *distribution_assertion();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Precon_assertionContext* precon_assertion();

  class  Distribution_assertionContext : public antlr4::ParserRuleContext {
  public:
    Distribution_assertionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Single_distributionContext *> single_distribution();
    Single_distributionContext* single_distribution(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Distribution_assertionContext* distribution_assertion();

  class  Single_distributionContext : public antlr4::ParserRuleContext {
  public:
    Single_distributionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Canon_clauseContext *> canon_clause();
    Canon_clauseContext* canon_clause(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Single_distributionContext* single_distribution();

  class  Canon_clauseContext : public antlr4::ParserRuleContext {
  public:
    Canon_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Canon_stateContext *canon_state();
    antlr4::tree::TerminalNode *REALNUM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Canon_clauseContext* canon_clause();

  class  Canon_stateContext : public antlr4::ParserRuleContext {
  public:
    Canon_stateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QListContext *qList();
    RowContext *row();
    BListContext *bList();
    antlr4::tree::TerminalNode *BINARYSTRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Canon_stateContext* canon_state();

  class  RowContext : public antlr4::ParserRuleContext {
  public:
    RowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> REALNUM();
    antlr4::tree::TerminalNode* REALNUM(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RowContext* row();

  class  BListContext : public antlr4::ParserRuleContext {
  public:
    BListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CID();
    antlr4::tree::TerminalNode* CID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BListContext* bList();

  class  QListContext : public antlr4::ParserRuleContext {
  public:
    QListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QID();
    antlr4::tree::TerminalNode* QID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QListContext* qList();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

