
// Generated from grammars/assertions/Assertion.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  AssertionParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, BINARYSTRING = 13, 
    REALNUM = 14, CID = 15, QID = 16, WS = 17
  };

  enum {
    RuleAssertion = 0, RuleDistribution_assertion = 1, RuleDis_or_expr = 2, 
    RuleDis_and_expr = 3, RuleDis_conv_expr = 4, RuleDis_not_expr = 5, RuleDis_atom = 6, 
    RuleStates_assertion = 7, RuleStates_or_expr = 8, RuleStates_and_expr = 9, 
    RuleStates_not_expr = 10, RuleStates_atom = 11, RuleRow = 12, RuleBList = 13, 
    RuleQList = 14
  };

  explicit AssertionParser(antlr4::TokenStream *input);

  AssertionParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~AssertionParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class AssertionContext;
  class Distribution_assertionContext;
  class Dis_or_exprContext;
  class Dis_and_exprContext;
  class Dis_conv_exprContext;
  class Dis_not_exprContext;
  class Dis_atomContext;
  class States_assertionContext;
  class States_or_exprContext;
  class States_and_exprContext;
  class States_not_exprContext;
  class States_atomContext;
  class RowContext;
  class BListContext;
  class QListContext; 

  class  AssertionContext : public antlr4::ParserRuleContext {
  public:
    AssertionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Distribution_assertionContext *distribution_assertion();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssertionContext* assertion();

  class  Distribution_assertionContext : public antlr4::ParserRuleContext {
  public:
    Distribution_assertionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Dis_or_exprContext *dis_or_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Distribution_assertionContext* distribution_assertion();

  class  Dis_or_exprContext : public antlr4::ParserRuleContext {
  public:
    Dis_or_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Dis_and_exprContext *> dis_and_expr();
    Dis_and_exprContext* dis_and_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dis_or_exprContext* dis_or_expr();

  class  Dis_and_exprContext : public antlr4::ParserRuleContext {
  public:
    Dis_and_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Dis_conv_exprContext *> dis_conv_expr();
    Dis_conv_exprContext* dis_conv_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dis_and_exprContext* dis_and_expr();

  class  Dis_conv_exprContext : public antlr4::ParserRuleContext {
  public:
    Dis_conv_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Dis_not_exprContext *> dis_not_expr();
    Dis_not_exprContext* dis_not_expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dis_conv_exprContext* dis_conv_expr();

  class  Dis_not_exprContext : public antlr4::ParserRuleContext {
  public:
    Dis_not_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Dis_not_exprContext() = default;
    void copyFrom(Dis_not_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Dis_not_atomContext : public Dis_not_exprContext {
  public:
    Dis_not_atomContext(Dis_not_exprContext *ctx);

    Dis_atomContext *dis_atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Dis_notContext : public Dis_not_exprContext {
  public:
    Dis_notContext(Dis_not_exprContext *ctx);

    Dis_not_exprContext *dis_not_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Dis_not_exprContext* dis_not_expr();

  class  Dis_atomContext : public antlr4::ParserRuleContext {
  public:
    Dis_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Dis_atomContext() = default;
    void copyFrom(Dis_atomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Dis_assertionContext : public Dis_atomContext {
  public:
    Dis_assertionContext(Dis_atomContext *ctx);

    Distribution_assertionContext *distribution_assertion();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Symbolic_probContext : public Dis_atomContext {
  public:
    Symbolic_probContext(Dis_atomContext *ctx);

    States_assertionContext *states_assertion();
    antlr4::tree::TerminalNode *REALNUM();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Dis_atomContext* dis_atom();

  class  States_assertionContext : public antlr4::ParserRuleContext {
  public:
    States_assertionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    States_or_exprContext *states_or_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  States_assertionContext* states_assertion();

  class  States_or_exprContext : public antlr4::ParserRuleContext {
  public:
    States_or_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    States_or_exprContext() = default;
    void copyFrom(States_or_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Or_exprContext : public States_or_exprContext {
  public:
    Or_exprContext(States_or_exprContext *ctx);

    std::vector<States_and_exprContext *> states_and_expr();
    States_and_exprContext* states_and_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  States_or_exprContext* states_or_expr();

  class  States_and_exprContext : public antlr4::ParserRuleContext {
  public:
    States_and_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    States_and_exprContext() = default;
    void copyFrom(States_and_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  And_exprContext : public States_and_exprContext {
  public:
    And_exprContext(States_and_exprContext *ctx);

    std::vector<States_not_exprContext *> states_not_expr();
    States_not_exprContext* states_not_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  States_and_exprContext* states_and_expr();

  class  States_not_exprContext : public antlr4::ParserRuleContext {
  public:
    States_not_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    States_not_exprContext() = default;
    void copyFrom(States_not_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Not_exprContext : public States_not_exprContext {
  public:
    Not_exprContext(States_not_exprContext *ctx);

    States_not_exprContext *states_not_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  States_atom_ruleContext : public States_not_exprContext {
  public:
    States_atom_ruleContext(States_not_exprContext *ctx);

    States_atomContext *states_atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  States_not_exprContext* states_not_expr();

  class  States_atomContext : public antlr4::ParserRuleContext {
  public:
    States_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    States_atomContext() = default;
    void copyFrom(States_atomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  QtermContext : public States_atomContext {
  public:
    QtermContext(States_atomContext *ctx);

    QListContext *qList();
    RowContext *row();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BtermContext : public States_atomContext {
  public:
    BtermContext(States_atomContext *ctx);

    BListContext *bList();
    antlr4::tree::TerminalNode *BINARYSTRING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  States_atomContext* states_atom();

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

