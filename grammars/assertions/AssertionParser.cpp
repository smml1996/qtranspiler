
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
      "dis_conv_expr", "dis_not_expr", "probability_term", "states_assertion", 
      "states_or_expr", "states_and_expr", "states_not_expr", "binary_term", 
      "quantum_term", "row", "bList", "qList"
    },
    std::vector<std::string>{
      "", "'or'", "'and'", "'+'", "'!'", "'('", "')'", "'>='", "'P'", "'='", 
      "'['", "']'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "BINARYSTRING", 
      "REALNUM", "CID", "QID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,17,157,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,5,2,41,8,2,10,2,12,2,44,
  	9,2,1,3,1,3,1,3,5,3,49,8,3,10,3,12,3,52,9,3,1,4,1,4,1,4,5,4,57,8,4,10,
  	4,12,4,60,9,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,72,8,5,1,6,
  	1,6,1,6,1,6,1,6,1,6,3,6,80,8,6,1,7,1,7,1,8,1,8,1,8,5,8,87,8,8,10,8,12,
  	8,90,9,8,1,9,1,9,1,9,5,9,95,8,9,10,9,12,9,98,9,9,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,114,8,10,1,11,
  	1,11,1,11,1,11,1,11,3,11,121,8,11,1,12,1,12,1,12,1,12,1,12,3,12,128,8,
  	12,1,13,1,13,1,13,1,13,5,13,134,8,13,10,13,12,13,137,9,13,1,13,1,13,1,
  	14,1,14,1,14,5,14,144,8,14,10,14,12,14,147,9,14,1,15,1,15,1,15,5,15,152,
  	8,15,10,15,12,15,155,9,15,1,15,0,0,16,0,2,4,6,8,10,12,14,16,18,20,22,
  	24,26,28,30,0,0,156,0,32,1,0,0,0,2,35,1,0,0,0,4,37,1,0,0,0,6,45,1,0,0,
  	0,8,53,1,0,0,0,10,71,1,0,0,0,12,79,1,0,0,0,14,81,1,0,0,0,16,83,1,0,0,
  	0,18,91,1,0,0,0,20,113,1,0,0,0,22,120,1,0,0,0,24,127,1,0,0,0,26,129,1,
  	0,0,0,28,140,1,0,0,0,30,148,1,0,0,0,32,33,3,2,1,0,33,34,5,0,0,1,34,1,
  	1,0,0,0,35,36,3,4,2,0,36,3,1,0,0,0,37,42,3,6,3,0,38,39,5,1,0,0,39,41,
  	3,6,3,0,40,38,1,0,0,0,41,44,1,0,0,0,42,40,1,0,0,0,42,43,1,0,0,0,43,5,
  	1,0,0,0,44,42,1,0,0,0,45,50,3,8,4,0,46,47,5,2,0,0,47,49,3,8,4,0,48,46,
  	1,0,0,0,49,52,1,0,0,0,50,48,1,0,0,0,50,51,1,0,0,0,51,7,1,0,0,0,52,50,
  	1,0,0,0,53,58,3,10,5,0,54,55,5,3,0,0,55,57,3,10,5,0,56,54,1,0,0,0,57,
  	60,1,0,0,0,58,56,1,0,0,0,58,59,1,0,0,0,59,9,1,0,0,0,60,58,1,0,0,0,61,
  	62,5,4,0,0,62,72,3,10,5,0,63,64,5,5,0,0,64,65,3,2,1,0,65,66,5,6,0,0,66,
  	72,1,0,0,0,67,68,3,12,6,0,68,69,5,7,0,0,69,70,5,14,0,0,70,72,1,0,0,0,
  	71,61,1,0,0,0,71,63,1,0,0,0,71,67,1,0,0,0,72,11,1,0,0,0,73,74,5,8,0,0,
  	74,75,5,5,0,0,75,76,3,14,7,0,76,77,5,6,0,0,77,80,1,0,0,0,78,80,5,14,0,
  	0,79,73,1,0,0,0,79,78,1,0,0,0,80,13,1,0,0,0,81,82,3,16,8,0,82,15,1,0,
  	0,0,83,88,3,18,9,0,84,85,5,1,0,0,85,87,3,18,9,0,86,84,1,0,0,0,87,90,1,
  	0,0,0,88,86,1,0,0,0,88,89,1,0,0,0,89,17,1,0,0,0,90,88,1,0,0,0,91,96,3,
  	20,10,0,92,93,5,2,0,0,93,95,3,20,10,0,94,92,1,0,0,0,95,98,1,0,0,0,96,
  	94,1,0,0,0,96,97,1,0,0,0,97,19,1,0,0,0,98,96,1,0,0,0,99,100,5,4,0,0,100,
  	114,3,20,10,0,101,102,3,24,12,0,102,103,5,9,0,0,103,104,3,24,12,0,104,
  	114,1,0,0,0,105,106,3,22,11,0,106,107,5,9,0,0,107,108,3,22,11,0,108,114,
  	1,0,0,0,109,110,5,5,0,0,110,111,3,14,7,0,111,112,5,6,0,0,112,114,1,0,
  	0,0,113,99,1,0,0,0,113,101,1,0,0,0,113,105,1,0,0,0,113,109,1,0,0,0,114,
  	21,1,0,0,0,115,116,5,10,0,0,116,117,3,28,14,0,117,118,5,11,0,0,118,121,
  	1,0,0,0,119,121,5,13,0,0,120,115,1,0,0,0,120,119,1,0,0,0,121,23,1,0,0,
  	0,122,123,5,10,0,0,123,124,3,30,15,0,124,125,5,11,0,0,125,128,1,0,0,0,
  	126,128,3,26,13,0,127,122,1,0,0,0,127,126,1,0,0,0,128,25,1,0,0,0,129,
  	130,5,10,0,0,130,135,5,14,0,0,131,132,5,12,0,0,132,134,5,14,0,0,133,131,
  	1,0,0,0,134,137,1,0,0,0,135,133,1,0,0,0,135,136,1,0,0,0,136,138,1,0,0,
  	0,137,135,1,0,0,0,138,139,5,11,0,0,139,27,1,0,0,0,140,145,5,15,0,0,141,
  	142,5,12,0,0,142,144,5,15,0,0,143,141,1,0,0,0,144,147,1,0,0,0,145,143,
  	1,0,0,0,145,146,1,0,0,0,146,29,1,0,0,0,147,145,1,0,0,0,148,153,5,16,0,
  	0,149,150,5,12,0,0,150,152,5,16,0,0,151,149,1,0,0,0,152,155,1,0,0,0,153,
  	151,1,0,0,0,153,154,1,0,0,0,154,31,1,0,0,0,155,153,1,0,0,0,13,42,50,58,
  	71,79,88,96,113,120,127,135,145,153
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
    setState(32);
    distribution_assertion();
    setState(33);
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
    setState(35);
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
    setState(37);
    dis_and_expr();
    setState(42);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__0) {
      setState(38);
      match(AssertionParser::T__0);
      setState(39);
      dis_and_expr();
      setState(44);
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
    setState(45);
    dis_conv_expr();
    setState(50);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__1) {
      setState(46);
      match(AssertionParser::T__1);
      setState(47);
      dis_conv_expr();
      setState(52);
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
    setState(53);
    dis_not_expr();
    setState(58);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__2) {
      setState(54);
      match(AssertionParser::T__2);
      setState(55);
      dis_not_expr();
      setState(60);
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

AssertionParser::Dis_not_exprContext* AssertionParser::Dis_not_exprContext::dis_not_expr() {
  return getRuleContext<AssertionParser::Dis_not_exprContext>(0);
}

AssertionParser::Distribution_assertionContext* AssertionParser::Dis_not_exprContext::distribution_assertion() {
  return getRuleContext<AssertionParser::Distribution_assertionContext>(0);
}

AssertionParser::Probability_termContext* AssertionParser::Dis_not_exprContext::probability_term() {
  return getRuleContext<AssertionParser::Probability_termContext>(0);
}

tree::TerminalNode* AssertionParser::Dis_not_exprContext::REALNUM() {
  return getToken(AssertionParser::REALNUM, 0);
}


size_t AssertionParser::Dis_not_exprContext::getRuleIndex() const {
  return AssertionParser::RuleDis_not_expr;
}

void AssertionParser::Dis_not_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDis_not_expr(this);
}

void AssertionParser::Dis_not_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDis_not_expr(this);
}


std::any AssertionParser::Dis_not_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitDis_not_expr(this);
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
    setState(71);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(61);
        match(AssertionParser::T__3);
        setState(62);
        dis_not_expr();
        break;
      }

      case AssertionParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(63);
        match(AssertionParser::T__4);
        setState(64);
        distribution_assertion();
        setState(65);
        match(AssertionParser::T__5);
        break;
      }

      case AssertionParser::T__7:
      case AssertionParser::REALNUM: {
        enterOuterAlt(_localctx, 3);
        setState(67);
        probability_term();
        setState(68);
        match(AssertionParser::T__6);
        setState(69);
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

//----------------- Probability_termContext ------------------------------------------------------------------

AssertionParser::Probability_termContext::Probability_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssertionParser::States_assertionContext* AssertionParser::Probability_termContext::states_assertion() {
  return getRuleContext<AssertionParser::States_assertionContext>(0);
}

tree::TerminalNode* AssertionParser::Probability_termContext::REALNUM() {
  return getToken(AssertionParser::REALNUM, 0);
}


size_t AssertionParser::Probability_termContext::getRuleIndex() const {
  return AssertionParser::RuleProbability_term;
}

void AssertionParser::Probability_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProbability_term(this);
}

void AssertionParser::Probability_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProbability_term(this);
}


std::any AssertionParser::Probability_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitProbability_term(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::Probability_termContext* AssertionParser::probability_term() {
  Probability_termContext *_localctx = _tracker.createInstance<Probability_termContext>(_ctx, getState());
  enterRule(_localctx, 12, AssertionParser::RuleProbability_term);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(73);
        match(AssertionParser::T__7);
        setState(74);
        match(AssertionParser::T__4);
        setState(75);
        states_assertion();
        setState(76);
        match(AssertionParser::T__5);
        break;
      }

      case AssertionParser::REALNUM: {
        enterOuterAlt(_localctx, 2);
        setState(78);
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
    setState(81);
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
    setState(83);
    states_and_expr();
    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__0) {
      setState(84);
      match(AssertionParser::T__0);
      setState(85);
      states_and_expr();
      setState(90);
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
    setState(91);
    states_not_expr();
    setState(96);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__1) {
      setState(92);
      match(AssertionParser::T__1);
      setState(93);
      states_not_expr();
      setState(98);
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
//----------------- ParensContext ------------------------------------------------------------------

AssertionParser::States_assertionContext* AssertionParser::ParensContext::states_assertion() {
  return getRuleContext<AssertionParser::States_assertionContext>(0);
}

AssertionParser::ParensContext::ParensContext(States_not_exprContext *ctx) { copyFrom(ctx); }

void AssertionParser::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void AssertionParser::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}

std::any AssertionParser::ParensContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitParens(this);
  else
    return visitor->visitChildren(this);
}
//----------------- QCompareContext ------------------------------------------------------------------

std::vector<AssertionParser::Quantum_termContext *> AssertionParser::QCompareContext::quantum_term() {
  return getRuleContexts<AssertionParser::Quantum_termContext>();
}

AssertionParser::Quantum_termContext* AssertionParser::QCompareContext::quantum_term(size_t i) {
  return getRuleContext<AssertionParser::Quantum_termContext>(i);
}

AssertionParser::QCompareContext::QCompareContext(States_not_exprContext *ctx) { copyFrom(ctx); }

void AssertionParser::QCompareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQCompare(this);
}
void AssertionParser::QCompareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQCompare(this);
}

std::any AssertionParser::QCompareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitQCompare(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BCompareContext ------------------------------------------------------------------

std::vector<AssertionParser::Binary_termContext *> AssertionParser::BCompareContext::binary_term() {
  return getRuleContexts<AssertionParser::Binary_termContext>();
}

AssertionParser::Binary_termContext* AssertionParser::BCompareContext::binary_term(size_t i) {
  return getRuleContext<AssertionParser::Binary_termContext>(i);
}

AssertionParser::BCompareContext::BCompareContext(States_not_exprContext *ctx) { copyFrom(ctx); }

void AssertionParser::BCompareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBCompare(this);
}
void AssertionParser::BCompareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBCompare(this);
}

std::any AssertionParser::BCompareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitBCompare(this);
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
    setState(113);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AssertionParser::Not_exprContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(99);
      match(AssertionParser::T__3);
      setState(100);
      states_not_expr();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<AssertionParser::QCompareContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(101);
      quantum_term();
      setState(102);
      match(AssertionParser::T__8);
      setState(103);
      quantum_term();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<AssertionParser::BCompareContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(105);
      binary_term();
      setState(106);
      match(AssertionParser::T__8);
      setState(107);
      binary_term();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AssertionParser::ParensContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(109);
      match(AssertionParser::T__4);
      setState(110);
      states_assertion();
      setState(111);
      match(AssertionParser::T__5);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_termContext ------------------------------------------------------------------

AssertionParser::Binary_termContext::Binary_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssertionParser::BListContext* AssertionParser::Binary_termContext::bList() {
  return getRuleContext<AssertionParser::BListContext>(0);
}

tree::TerminalNode* AssertionParser::Binary_termContext::BINARYSTRING() {
  return getToken(AssertionParser::BINARYSTRING, 0);
}


size_t AssertionParser::Binary_termContext::getRuleIndex() const {
  return AssertionParser::RuleBinary_term;
}

void AssertionParser::Binary_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_term(this);
}

void AssertionParser::Binary_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_term(this);
}


std::any AssertionParser::Binary_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitBinary_term(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::Binary_termContext* AssertionParser::binary_term() {
  Binary_termContext *_localctx = _tracker.createInstance<Binary_termContext>(_ctx, getState());
  enterRule(_localctx, 22, AssertionParser::RuleBinary_term);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(120);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(115);
        match(AssertionParser::T__9);
        setState(116);
        bList();
        setState(117);
        match(AssertionParser::T__10);
        break;
      }

      case AssertionParser::BINARYSTRING: {
        enterOuterAlt(_localctx, 2);
        setState(119);
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

//----------------- Quantum_termContext ------------------------------------------------------------------

AssertionParser::Quantum_termContext::Quantum_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssertionParser::QListContext* AssertionParser::Quantum_termContext::qList() {
  return getRuleContext<AssertionParser::QListContext>(0);
}

AssertionParser::RowContext* AssertionParser::Quantum_termContext::row() {
  return getRuleContext<AssertionParser::RowContext>(0);
}


size_t AssertionParser::Quantum_termContext::getRuleIndex() const {
  return AssertionParser::RuleQuantum_term;
}

void AssertionParser::Quantum_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantum_term(this);
}

void AssertionParser::Quantum_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantum_term(this);
}


std::any AssertionParser::Quantum_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitQuantum_term(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::Quantum_termContext* AssertionParser::quantum_term() {
  Quantum_termContext *_localctx = _tracker.createInstance<Quantum_termContext>(_ctx, getState());
  enterRule(_localctx, 24, AssertionParser::RuleQuantum_term);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(122);
      match(AssertionParser::T__9);
      setState(123);
      qList();
      setState(124);
      match(AssertionParser::T__10);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(126);
      row();
      break;
    }

    default:
      break;
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
  enterRule(_localctx, 26, AssertionParser::RuleRow);
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
    match(AssertionParser::T__9);
    setState(130);
    match(AssertionParser::REALNUM);
    setState(135);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__11) {
      setState(131);
      match(AssertionParser::T__11);
      setState(132);
      match(AssertionParser::REALNUM);
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(138);
    match(AssertionParser::T__10);
   
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
  enterRule(_localctx, 28, AssertionParser::RuleBList);
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
    setState(140);
    match(AssertionParser::CID);
    setState(145);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__11) {
      setState(141);
      match(AssertionParser::T__11);
      setState(142);
      match(AssertionParser::CID);
      setState(147);
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
  enterRule(_localctx, 30, AssertionParser::RuleQList);
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
    setState(148);
    match(AssertionParser::QID);
    setState(153);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__11) {
      setState(149);
      match(AssertionParser::T__11);
      setState(150);
      match(AssertionParser::QID);
      setState(155);
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
