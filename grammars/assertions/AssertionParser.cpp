
// Generated from grammars/assertions/Assertion.g4 by ANTLR 4.13.2


#include "AssertionListener.h"
#include "AssertionVisitor.h"

#include "AssertionParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct AssertionParserStaticData final {
  AssertionParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AssertionParserStaticData(const AssertionParserStaticData&) = delete;
  AssertionParserStaticData(AssertionParserStaticData&&) = delete;
  AssertionParserStaticData& operator=(const AssertionParserStaticData&) = delete;
  AssertionParserStaticData& operator=(AssertionParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag assertionParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<AssertionParserStaticData> assertionParserStaticData = nullptr;

void assertionParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (assertionParserStaticData != nullptr) {
    return;
  }
#else
  assert(assertionParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AssertionParserStaticData>(
    std::vector<std::string>{
      "assertion", "distribution_assertion", "dis_or_expr", "dis_and_expr", 
      "dis_conv_expr", "dis_not_expr", "dis_atom", "states_assertion", "states_or_expr", 
      "states_and_expr", "states_not_expr", "states_atom", "row", "bList", 
      "qList"
    },
    std::vector<std::string>{
      "", "'or'", "'and'", "'+'", "'!'", "'('", "')'", "'P'", "'>='", "'='", 
      "'['", "','", "']'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "BINARYSTRING", 
      "REALNUM", "CID", "QID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,17,138,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,5,2,39,8,2,10,2,12,2,42,9,2,1,3,1,
  	3,1,3,5,3,47,8,3,10,3,12,3,50,9,3,1,4,1,4,1,4,5,4,55,8,4,10,4,12,4,58,
  	9,4,1,5,1,5,1,5,3,5,63,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,3,6,76,8,6,1,7,1,7,1,8,1,8,1,8,5,8,83,8,8,10,8,12,8,86,9,8,1,9,1,9,
  	1,9,5,9,91,8,9,10,9,12,9,94,9,9,1,10,1,10,1,10,3,10,99,8,10,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,3,11,109,8,11,1,12,1,12,1,12,1,12,5,12,
  	115,8,12,10,12,12,12,118,9,12,1,12,1,12,1,13,1,13,1,13,5,13,125,8,13,
  	10,13,12,13,128,9,13,1,14,1,14,1,14,5,14,133,8,14,10,14,12,14,136,9,14,
  	1,14,0,0,15,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,0,0,134,0,30,1,0,
  	0,0,2,33,1,0,0,0,4,35,1,0,0,0,6,43,1,0,0,0,8,51,1,0,0,0,10,62,1,0,0,0,
  	12,75,1,0,0,0,14,77,1,0,0,0,16,79,1,0,0,0,18,87,1,0,0,0,20,98,1,0,0,0,
  	22,108,1,0,0,0,24,110,1,0,0,0,26,121,1,0,0,0,28,129,1,0,0,0,30,31,3,2,
  	1,0,31,32,5,0,0,1,32,1,1,0,0,0,33,34,3,4,2,0,34,3,1,0,0,0,35,40,3,6,3,
  	0,36,37,5,1,0,0,37,39,3,6,3,0,38,36,1,0,0,0,39,42,1,0,0,0,40,38,1,0,0,
  	0,40,41,1,0,0,0,41,5,1,0,0,0,42,40,1,0,0,0,43,48,3,8,4,0,44,45,5,2,0,
  	0,45,47,3,8,4,0,46,44,1,0,0,0,47,50,1,0,0,0,48,46,1,0,0,0,48,49,1,0,0,
  	0,49,7,1,0,0,0,50,48,1,0,0,0,51,56,3,10,5,0,52,53,5,3,0,0,53,55,3,10,
  	5,0,54,52,1,0,0,0,55,58,1,0,0,0,56,54,1,0,0,0,56,57,1,0,0,0,57,9,1,0,
  	0,0,58,56,1,0,0,0,59,60,5,4,0,0,60,63,3,10,5,0,61,63,3,12,6,0,62,59,1,
  	0,0,0,62,61,1,0,0,0,63,11,1,0,0,0,64,65,5,5,0,0,65,66,3,2,1,0,66,67,5,
  	6,0,0,67,76,1,0,0,0,68,69,5,7,0,0,69,70,5,5,0,0,70,71,3,14,7,0,71,72,
  	5,6,0,0,72,73,5,8,0,0,73,74,5,14,0,0,74,76,1,0,0,0,75,64,1,0,0,0,75,68,
  	1,0,0,0,76,13,1,0,0,0,77,78,3,16,8,0,78,15,1,0,0,0,79,84,3,18,9,0,80,
  	81,5,1,0,0,81,83,3,18,9,0,82,80,1,0,0,0,83,86,1,0,0,0,84,82,1,0,0,0,84,
  	85,1,0,0,0,85,17,1,0,0,0,86,84,1,0,0,0,87,92,3,20,10,0,88,89,5,2,0,0,
  	89,91,3,20,10,0,90,88,1,0,0,0,91,94,1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,
  	0,93,19,1,0,0,0,94,92,1,0,0,0,95,96,5,4,0,0,96,99,3,20,10,0,97,99,3,22,
  	11,0,98,95,1,0,0,0,98,97,1,0,0,0,99,21,1,0,0,0,100,101,3,28,14,0,101,
  	102,5,9,0,0,102,103,3,24,12,0,103,109,1,0,0,0,104,105,3,26,13,0,105,106,
  	5,9,0,0,106,107,5,13,0,0,107,109,1,0,0,0,108,100,1,0,0,0,108,104,1,0,
  	0,0,109,23,1,0,0,0,110,111,5,10,0,0,111,116,5,14,0,0,112,113,5,11,0,0,
  	113,115,5,14,0,0,114,112,1,0,0,0,115,118,1,0,0,0,116,114,1,0,0,0,116,
  	117,1,0,0,0,117,119,1,0,0,0,118,116,1,0,0,0,119,120,5,12,0,0,120,25,1,
  	0,0,0,121,126,5,15,0,0,122,123,5,11,0,0,123,125,5,15,0,0,124,122,1,0,
  	0,0,125,128,1,0,0,0,126,124,1,0,0,0,126,127,1,0,0,0,127,27,1,0,0,0,128,
  	126,1,0,0,0,129,134,5,16,0,0,130,131,5,11,0,0,131,133,5,16,0,0,132,130,
  	1,0,0,0,133,136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,29,1,0,0,
  	0,136,134,1,0,0,0,12,40,48,56,62,75,84,92,98,108,116,126,134
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  assertionParserStaticData = std::move(staticData);
}

}

AssertionParser::AssertionParser(TokenStream *input) : AssertionParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

AssertionParser::AssertionParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  AssertionParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *assertionParserStaticData->atn, assertionParserStaticData->decisionToDFA, assertionParserStaticData->sharedContextCache, options);
}

AssertionParser::~AssertionParser() {
  delete _interpreter;
}

const atn::ATN& AssertionParser::getATN() const {
  return *assertionParserStaticData->atn;
}

std::string AssertionParser::getGrammarFileName() const {
  return "Assertion.g4";
}

const std::vector<std::string>& AssertionParser::getRuleNames() const {
  return assertionParserStaticData->ruleNames;
}

const dfa::Vocabulary& AssertionParser::getVocabulary() const {
  return assertionParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AssertionParser::getSerializedATN() const {
  return assertionParserStaticData->serializedATN;
}


//----------------- AssertionContext ------------------------------------------------------------------

AssertionParser::AssertionContext::AssertionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssertionParser::Distribution_assertionContext* AssertionParser::AssertionContext::distribution_assertion() {
  return getRuleContext<AssertionParser::Distribution_assertionContext>(0);
}

tree::TerminalNode* AssertionParser::AssertionContext::EOF() {
  return getToken(AssertionParser::EOF, 0);
}


size_t AssertionParser::AssertionContext::getRuleIndex() const {
  return AssertionParser::RuleAssertion;
}

void AssertionParser::AssertionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssertion(this);
}

void AssertionParser::AssertionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssertion(this);
}


std::any AssertionParser::AssertionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitAssertion(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::AssertionContext* AssertionParser::assertion() {
  AssertionContext *_localctx = _tracker.createInstance<AssertionContext>(_ctx, getState());
  enterRule(_localctx, 0, AssertionParser::RuleAssertion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    distribution_assertion();
    setState(31);
    match(AssertionParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Distribution_assertionContext ------------------------------------------------------------------

AssertionParser::Distribution_assertionContext::Distribution_assertionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssertionParser::Dis_or_exprContext* AssertionParser::Distribution_assertionContext::dis_or_expr() {
  return getRuleContext<AssertionParser::Dis_or_exprContext>(0);
}


size_t AssertionParser::Distribution_assertionContext::getRuleIndex() const {
  return AssertionParser::RuleDistribution_assertion;
}

void AssertionParser::Distribution_assertionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDistribution_assertion(this);
}

void AssertionParser::Distribution_assertionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDistribution_assertion(this);
}


std::any AssertionParser::Distribution_assertionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitDistribution_assertion(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::Distribution_assertionContext* AssertionParser::distribution_assertion() {
  Distribution_assertionContext *_localctx = _tracker.createInstance<Distribution_assertionContext>(_ctx, getState());
  enterRule(_localctx, 2, AssertionParser::RuleDistribution_assertion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    dis_or_expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dis_or_exprContext ------------------------------------------------------------------

AssertionParser::Dis_or_exprContext::Dis_or_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AssertionParser::Dis_and_exprContext *> AssertionParser::Dis_or_exprContext::dis_and_expr() {
  return getRuleContexts<AssertionParser::Dis_and_exprContext>();
}

AssertionParser::Dis_and_exprContext* AssertionParser::Dis_or_exprContext::dis_and_expr(size_t i) {
  return getRuleContext<AssertionParser::Dis_and_exprContext>(i);
}


size_t AssertionParser::Dis_or_exprContext::getRuleIndex() const {
  return AssertionParser::RuleDis_or_expr;
}

void AssertionParser::Dis_or_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDis_or_expr(this);
}

void AssertionParser::Dis_or_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDis_or_expr(this);
}


std::any AssertionParser::Dis_or_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitDis_or_expr(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::Dis_or_exprContext* AssertionParser::dis_or_expr() {
  Dis_or_exprContext *_localctx = _tracker.createInstance<Dis_or_exprContext>(_ctx, getState());
  enterRule(_localctx, 4, AssertionParser::RuleDis_or_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    dis_and_expr();
    setState(40);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__0) {
      setState(36);
      match(AssertionParser::T__0);
      setState(37);
      dis_and_expr();
      setState(42);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dis_and_exprContext ------------------------------------------------------------------

AssertionParser::Dis_and_exprContext::Dis_and_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AssertionParser::Dis_conv_exprContext *> AssertionParser::Dis_and_exprContext::dis_conv_expr() {
  return getRuleContexts<AssertionParser::Dis_conv_exprContext>();
}

AssertionParser::Dis_conv_exprContext* AssertionParser::Dis_and_exprContext::dis_conv_expr(size_t i) {
  return getRuleContext<AssertionParser::Dis_conv_exprContext>(i);
}


size_t AssertionParser::Dis_and_exprContext::getRuleIndex() const {
  return AssertionParser::RuleDis_and_expr;
}

void AssertionParser::Dis_and_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDis_and_expr(this);
}

void AssertionParser::Dis_and_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDis_and_expr(this);
}


std::any AssertionParser::Dis_and_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitDis_and_expr(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::Dis_and_exprContext* AssertionParser::dis_and_expr() {
  Dis_and_exprContext *_localctx = _tracker.createInstance<Dis_and_exprContext>(_ctx, getState());
  enterRule(_localctx, 6, AssertionParser::RuleDis_and_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    dis_conv_expr();
    setState(48);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__1) {
      setState(44);
      match(AssertionParser::T__1);
      setState(45);
      dis_conv_expr();
      setState(50);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dis_conv_exprContext ------------------------------------------------------------------

AssertionParser::Dis_conv_exprContext::Dis_conv_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AssertionParser::Dis_not_exprContext *> AssertionParser::Dis_conv_exprContext::dis_not_expr() {
  return getRuleContexts<AssertionParser::Dis_not_exprContext>();
}

AssertionParser::Dis_not_exprContext* AssertionParser::Dis_conv_exprContext::dis_not_expr(size_t i) {
  return getRuleContext<AssertionParser::Dis_not_exprContext>(i);
}


size_t AssertionParser::Dis_conv_exprContext::getRuleIndex() const {
  return AssertionParser::RuleDis_conv_expr;
}

void AssertionParser::Dis_conv_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDis_conv_expr(this);
}

void AssertionParser::Dis_conv_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDis_conv_expr(this);
}


std::any AssertionParser::Dis_conv_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitDis_conv_expr(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::Dis_conv_exprContext* AssertionParser::dis_conv_expr() {
  Dis_conv_exprContext *_localctx = _tracker.createInstance<Dis_conv_exprContext>(_ctx, getState());
  enterRule(_localctx, 8, AssertionParser::RuleDis_conv_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    dis_not_expr();
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__2) {
      setState(52);
      match(AssertionParser::T__2);
      setState(53);
      dis_not_expr();
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dis_not_exprContext ------------------------------------------------------------------

AssertionParser::Dis_not_exprContext::Dis_not_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssertionParser::Dis_not_exprContext::getRuleIndex() const {
  return AssertionParser::RuleDis_not_expr;
}

void AssertionParser::Dis_not_exprContext::copyFrom(Dis_not_exprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Dis_not_atomContext ------------------------------------------------------------------

AssertionParser::Dis_atomContext* AssertionParser::Dis_not_atomContext::dis_atom() {
  return getRuleContext<AssertionParser::Dis_atomContext>(0);
}

AssertionParser::Dis_not_atomContext::Dis_not_atomContext(Dis_not_exprContext *ctx) { copyFrom(ctx); }

void AssertionParser::Dis_not_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDis_not_atom(this);
}
void AssertionParser::Dis_not_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDis_not_atom(this);
}

std::any AssertionParser::Dis_not_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitDis_not_atom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Dis_notContext ------------------------------------------------------------------

AssertionParser::Dis_not_exprContext* AssertionParser::Dis_notContext::dis_not_expr() {
  return getRuleContext<AssertionParser::Dis_not_exprContext>(0);
}

AssertionParser::Dis_notContext::Dis_notContext(Dis_not_exprContext *ctx) { copyFrom(ctx); }

void AssertionParser::Dis_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDis_not(this);
}
void AssertionParser::Dis_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDis_not(this);
}

std::any AssertionParser::Dis_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitDis_not(this);
  else
    return visitor->visitChildren(this);
}
AssertionParser::Dis_not_exprContext* AssertionParser::dis_not_expr() {
  Dis_not_exprContext *_localctx = _tracker.createInstance<Dis_not_exprContext>(_ctx, getState());
  enterRule(_localctx, 10, AssertionParser::RuleDis_not_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__3: {
        _localctx = _tracker.createInstance<AssertionParser::Dis_notContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(59);
        match(AssertionParser::T__3);
        setState(60);
        dis_not_expr();
        break;
      }

      case AssertionParser::T__4:
      case AssertionParser::T__6: {
        _localctx = _tracker.createInstance<AssertionParser::Dis_not_atomContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(61);
        dis_atom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dis_atomContext ------------------------------------------------------------------

AssertionParser::Dis_atomContext::Dis_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssertionParser::Dis_atomContext::getRuleIndex() const {
  return AssertionParser::RuleDis_atom;
}

void AssertionParser::Dis_atomContext::copyFrom(Dis_atomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Dis_assertionContext ------------------------------------------------------------------

AssertionParser::Distribution_assertionContext* AssertionParser::Dis_assertionContext::distribution_assertion() {
  return getRuleContext<AssertionParser::Distribution_assertionContext>(0);
}

AssertionParser::Dis_assertionContext::Dis_assertionContext(Dis_atomContext *ctx) { copyFrom(ctx); }

void AssertionParser::Dis_assertionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDis_assertion(this);
}
void AssertionParser::Dis_assertionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDis_assertion(this);
}

std::any AssertionParser::Dis_assertionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitDis_assertion(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Symbolic_probContext ------------------------------------------------------------------

AssertionParser::States_assertionContext* AssertionParser::Symbolic_probContext::states_assertion() {
  return getRuleContext<AssertionParser::States_assertionContext>(0);
}

tree::TerminalNode* AssertionParser::Symbolic_probContext::REALNUM() {
  return getToken(AssertionParser::REALNUM, 0);
}

AssertionParser::Symbolic_probContext::Symbolic_probContext(Dis_atomContext *ctx) { copyFrom(ctx); }

void AssertionParser::Symbolic_probContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbolic_prob(this);
}
void AssertionParser::Symbolic_probContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbolic_prob(this);
}

std::any AssertionParser::Symbolic_probContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitSymbolic_prob(this);
  else
    return visitor->visitChildren(this);
}
AssertionParser::Dis_atomContext* AssertionParser::dis_atom() {
  Dis_atomContext *_localctx = _tracker.createInstance<Dis_atomContext>(_ctx, getState());
  enterRule(_localctx, 12, AssertionParser::RuleDis_atom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__4: {
        _localctx = _tracker.createInstance<AssertionParser::Dis_assertionContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(64);
        match(AssertionParser::T__4);
        setState(65);
        distribution_assertion();
        setState(66);
        match(AssertionParser::T__5);
        break;
      }

      case AssertionParser::T__6: {
        _localctx = _tracker.createInstance<AssertionParser::Symbolic_probContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(68);
        match(AssertionParser::T__6);
        setState(69);
        match(AssertionParser::T__4);
        setState(70);
        states_assertion();
        setState(71);
        match(AssertionParser::T__5);
        setState(72);
        match(AssertionParser::T__7);
        setState(73);
        match(AssertionParser::REALNUM);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- States_assertionContext ------------------------------------------------------------------

AssertionParser::States_assertionContext::States_assertionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssertionParser::States_or_exprContext* AssertionParser::States_assertionContext::states_or_expr() {
  return getRuleContext<AssertionParser::States_or_exprContext>(0);
}


size_t AssertionParser::States_assertionContext::getRuleIndex() const {
  return AssertionParser::RuleStates_assertion;
}

void AssertionParser::States_assertionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStates_assertion(this);
}

void AssertionParser::States_assertionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStates_assertion(this);
}


std::any AssertionParser::States_assertionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitStates_assertion(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::States_assertionContext* AssertionParser::states_assertion() {
  States_assertionContext *_localctx = _tracker.createInstance<States_assertionContext>(_ctx, getState());
  enterRule(_localctx, 14, AssertionParser::RuleStates_assertion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    states_or_expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- States_or_exprContext ------------------------------------------------------------------

AssertionParser::States_or_exprContext::States_or_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssertionParser::States_or_exprContext::getRuleIndex() const {
  return AssertionParser::RuleStates_or_expr;
}

void AssertionParser::States_or_exprContext::copyFrom(States_or_exprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Or_exprContext ------------------------------------------------------------------

std::vector<AssertionParser::States_and_exprContext *> AssertionParser::Or_exprContext::states_and_expr() {
  return getRuleContexts<AssertionParser::States_and_exprContext>();
}

AssertionParser::States_and_exprContext* AssertionParser::Or_exprContext::states_and_expr(size_t i) {
  return getRuleContext<AssertionParser::States_and_exprContext>(i);
}

AssertionParser::Or_exprContext::Or_exprContext(States_or_exprContext *ctx) { copyFrom(ctx); }

void AssertionParser::Or_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOr_expr(this);
}
void AssertionParser::Or_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOr_expr(this);
}

std::any AssertionParser::Or_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitOr_expr(this);
  else
    return visitor->visitChildren(this);
}
AssertionParser::States_or_exprContext* AssertionParser::states_or_expr() {
  States_or_exprContext *_localctx = _tracker.createInstance<States_or_exprContext>(_ctx, getState());
  enterRule(_localctx, 16, AssertionParser::RuleStates_or_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<AssertionParser::Or_exprContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(79);
    states_and_expr();
    setState(84);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__0) {
      setState(80);
      match(AssertionParser::T__0);
      setState(81);
      states_and_expr();
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- States_and_exprContext ------------------------------------------------------------------

AssertionParser::States_and_exprContext::States_and_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssertionParser::States_and_exprContext::getRuleIndex() const {
  return AssertionParser::RuleStates_and_expr;
}

void AssertionParser::States_and_exprContext::copyFrom(States_and_exprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- And_exprContext ------------------------------------------------------------------

std::vector<AssertionParser::States_not_exprContext *> AssertionParser::And_exprContext::states_not_expr() {
  return getRuleContexts<AssertionParser::States_not_exprContext>();
}

AssertionParser::States_not_exprContext* AssertionParser::And_exprContext::states_not_expr(size_t i) {
  return getRuleContext<AssertionParser::States_not_exprContext>(i);
}

AssertionParser::And_exprContext::And_exprContext(States_and_exprContext *ctx) { copyFrom(ctx); }

void AssertionParser::And_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnd_expr(this);
}
void AssertionParser::And_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnd_expr(this);
}

std::any AssertionParser::And_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitAnd_expr(this);
  else
    return visitor->visitChildren(this);
}
AssertionParser::States_and_exprContext* AssertionParser::states_and_expr() {
  States_and_exprContext *_localctx = _tracker.createInstance<States_and_exprContext>(_ctx, getState());
  enterRule(_localctx, 18, AssertionParser::RuleStates_and_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<AssertionParser::And_exprContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(87);
    states_not_expr();
    setState(92);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__1) {
      setState(88);
      match(AssertionParser::T__1);
      setState(89);
      states_not_expr();
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- States_not_exprContext ------------------------------------------------------------------

AssertionParser::States_not_exprContext::States_not_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssertionParser::States_not_exprContext::getRuleIndex() const {
  return AssertionParser::RuleStates_not_expr;
}

void AssertionParser::States_not_exprContext::copyFrom(States_not_exprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Not_exprContext ------------------------------------------------------------------

AssertionParser::States_not_exprContext* AssertionParser::Not_exprContext::states_not_expr() {
  return getRuleContext<AssertionParser::States_not_exprContext>(0);
}

AssertionParser::Not_exprContext::Not_exprContext(States_not_exprContext *ctx) { copyFrom(ctx); }

void AssertionParser::Not_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNot_expr(this);
}
void AssertionParser::Not_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNot_expr(this);
}

std::any AssertionParser::Not_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitNot_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- States_atom_ruleContext ------------------------------------------------------------------

AssertionParser::States_atomContext* AssertionParser::States_atom_ruleContext::states_atom() {
  return getRuleContext<AssertionParser::States_atomContext>(0);
}

AssertionParser::States_atom_ruleContext::States_atom_ruleContext(States_not_exprContext *ctx) { copyFrom(ctx); }

void AssertionParser::States_atom_ruleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStates_atom_rule(this);
}
void AssertionParser::States_atom_ruleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStates_atom_rule(this);
}

std::any AssertionParser::States_atom_ruleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitStates_atom_rule(this);
  else
    return visitor->visitChildren(this);
}
AssertionParser::States_not_exprContext* AssertionParser::states_not_expr() {
  States_not_exprContext *_localctx = _tracker.createInstance<States_not_exprContext>(_ctx, getState());
  enterRule(_localctx, 20, AssertionParser::RuleStates_not_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__3: {
        _localctx = _tracker.createInstance<AssertionParser::Not_exprContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(95);
        match(AssertionParser::T__3);
        setState(96);
        states_not_expr();
        break;
      }

      case AssertionParser::CID:
      case AssertionParser::QID: {
        _localctx = _tracker.createInstance<AssertionParser::States_atom_ruleContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(97);
        states_atom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- States_atomContext ------------------------------------------------------------------

AssertionParser::States_atomContext::States_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssertionParser::States_atomContext::getRuleIndex() const {
  return AssertionParser::RuleStates_atom;
}

void AssertionParser::States_atomContext::copyFrom(States_atomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- QtermContext ------------------------------------------------------------------

AssertionParser::QListContext* AssertionParser::QtermContext::qList() {
  return getRuleContext<AssertionParser::QListContext>(0);
}

AssertionParser::RowContext* AssertionParser::QtermContext::row() {
  return getRuleContext<AssertionParser::RowContext>(0);
}

AssertionParser::QtermContext::QtermContext(States_atomContext *ctx) { copyFrom(ctx); }

void AssertionParser::QtermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQterm(this);
}
void AssertionParser::QtermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQterm(this);
}

std::any AssertionParser::QtermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitQterm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BtermContext ------------------------------------------------------------------

AssertionParser::BListContext* AssertionParser::BtermContext::bList() {
  return getRuleContext<AssertionParser::BListContext>(0);
}

tree::TerminalNode* AssertionParser::BtermContext::BINARYSTRING() {
  return getToken(AssertionParser::BINARYSTRING, 0);
}

AssertionParser::BtermContext::BtermContext(States_atomContext *ctx) { copyFrom(ctx); }

void AssertionParser::BtermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBterm(this);
}
void AssertionParser::BtermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBterm(this);
}

std::any AssertionParser::BtermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitBterm(this);
  else
    return visitor->visitChildren(this);
}
AssertionParser::States_atomContext* AssertionParser::states_atom() {
  States_atomContext *_localctx = _tracker.createInstance<States_atomContext>(_ctx, getState());
  enterRule(_localctx, 22, AssertionParser::RuleStates_atom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::QID: {
        _localctx = _tracker.createInstance<AssertionParser::QtermContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(100);
        qList();
        setState(101);
        match(AssertionParser::T__8);
        setState(102);
        row();
        break;
      }

      case AssertionParser::CID: {
        _localctx = _tracker.createInstance<AssertionParser::BtermContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(104);
        bList();
        setState(105);
        match(AssertionParser::T__8);
        setState(106);
        match(AssertionParser::BINARYSTRING);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RowContext ------------------------------------------------------------------

AssertionParser::RowContext::RowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AssertionParser::RowContext::REALNUM() {
  return getTokens(AssertionParser::REALNUM);
}

tree::TerminalNode* AssertionParser::RowContext::REALNUM(size_t i) {
  return getToken(AssertionParser::REALNUM, i);
}


size_t AssertionParser::RowContext::getRuleIndex() const {
  return AssertionParser::RuleRow;
}

void AssertionParser::RowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRow(this);
}

void AssertionParser::RowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRow(this);
}


std::any AssertionParser::RowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitRow(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::RowContext* AssertionParser::row() {
  RowContext *_localctx = _tracker.createInstance<RowContext>(_ctx, getState());
  enterRule(_localctx, 24, AssertionParser::RuleRow);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    match(AssertionParser::T__9);
    setState(111);
    match(AssertionParser::REALNUM);
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__10) {
      setState(112);
      match(AssertionParser::T__10);
      setState(113);
      match(AssertionParser::REALNUM);
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(119);
    match(AssertionParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BListContext ------------------------------------------------------------------

AssertionParser::BListContext::BListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AssertionParser::BListContext::CID() {
  return getTokens(AssertionParser::CID);
}

tree::TerminalNode* AssertionParser::BListContext::CID(size_t i) {
  return getToken(AssertionParser::CID, i);
}


size_t AssertionParser::BListContext::getRuleIndex() const {
  return AssertionParser::RuleBList;
}

void AssertionParser::BListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBList(this);
}

void AssertionParser::BListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBList(this);
}


std::any AssertionParser::BListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitBList(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::BListContext* AssertionParser::bList() {
  BListContext *_localctx = _tracker.createInstance<BListContext>(_ctx, getState());
  enterRule(_localctx, 26, AssertionParser::RuleBList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(AssertionParser::CID);
    setState(126);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__10) {
      setState(122);
      match(AssertionParser::T__10);
      setState(123);
      match(AssertionParser::CID);
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QListContext ------------------------------------------------------------------

AssertionParser::QListContext::QListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AssertionParser::QListContext::QID() {
  return getTokens(AssertionParser::QID);
}

tree::TerminalNode* AssertionParser::QListContext::QID(size_t i) {
  return getToken(AssertionParser::QID, i);
}


size_t AssertionParser::QListContext::getRuleIndex() const {
  return AssertionParser::RuleQList;
}

void AssertionParser::QListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQList(this);
}

void AssertionParser::QListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQList(this);
}


std::any AssertionParser::QListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitQList(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::QListContext* AssertionParser::qList() {
  QListContext *_localctx = _tracker.createInstance<QListContext>(_ctx, getState());
  enterRule(_localctx, 28, AssertionParser::RuleQList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    match(AssertionParser::QID);
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__10) {
      setState(130);
      match(AssertionParser::T__10);
      setState(131);
      match(AssertionParser::QID);
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void AssertionParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  assertionParserInitialize();
#else
  ::antlr4::internal::call_once(assertionParserOnceFlag, assertionParserInitialize);
#endif
}
