
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
      "states_and_expr", "states_not_expr", "states_atom", "qTerm2", "vector", 
      "row", "complexNumber", "realPart", "imagPart", "matrix", "bList", 
      "qList"
    },
    std::vector<std::string>{
      "", "'or'", "'and'", "'+'", "'!'", "'('", "')'", "'P'", "'='", "'['", 
      "','", "']'", "'i'", "'[['", "';'", "']]'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "MUL", 
      "RELOP", "SIGN", "BINARYSTRING", "REALNUM", "CID", "QID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,23,191,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,1,
  	0,1,0,1,1,1,1,1,2,1,2,1,2,5,2,51,8,2,10,2,12,2,54,9,2,1,3,1,3,1,3,5,3,
  	59,8,3,10,3,12,3,62,9,3,1,4,1,4,1,4,5,4,67,8,4,10,4,12,4,70,9,4,1,5,1,
  	5,1,5,3,5,75,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,88,8,
  	6,1,7,1,7,1,8,1,8,1,8,5,8,95,8,8,10,8,12,8,98,9,8,1,9,1,9,1,9,5,9,103,
  	8,9,10,9,12,9,106,9,9,1,10,1,10,1,10,3,10,111,8,10,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,3,11,121,8,11,1,12,1,12,1,12,1,12,1,12,3,12,128,8,
  	12,1,13,1,13,3,13,132,8,13,1,14,1,14,1,14,1,14,5,14,138,8,14,10,14,12,
  	14,141,9,14,1,14,1,14,1,15,1,15,3,15,147,8,15,1,16,3,16,150,8,16,1,16,
  	1,16,1,17,3,17,155,8,17,1,17,3,17,158,8,17,1,17,1,17,1,18,1,18,1,18,1,
  	18,1,18,1,18,5,18,168,8,18,10,18,12,18,171,9,18,1,18,1,18,1,19,1,19,1,
  	19,5,19,178,8,19,10,19,12,19,181,9,19,1,20,1,20,1,20,5,20,186,8,20,10,
  	20,12,20,189,9,20,1,20,0,0,21,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,0,0,188,0,42,1,0,0,0,2,45,1,0,0,0,4,47,1,0,0,0,6,55,
  	1,0,0,0,8,63,1,0,0,0,10,74,1,0,0,0,12,87,1,0,0,0,14,89,1,0,0,0,16,91,
  	1,0,0,0,18,99,1,0,0,0,20,110,1,0,0,0,22,120,1,0,0,0,24,127,1,0,0,0,26,
  	131,1,0,0,0,28,133,1,0,0,0,30,144,1,0,0,0,32,149,1,0,0,0,34,154,1,0,0,
  	0,36,161,1,0,0,0,38,174,1,0,0,0,40,182,1,0,0,0,42,43,3,2,1,0,43,44,5,
  	0,0,1,44,1,1,0,0,0,45,46,3,4,2,0,46,3,1,0,0,0,47,52,3,6,3,0,48,49,5,1,
  	0,0,49,51,3,6,3,0,50,48,1,0,0,0,51,54,1,0,0,0,52,50,1,0,0,0,52,53,1,0,
  	0,0,53,5,1,0,0,0,54,52,1,0,0,0,55,60,3,8,4,0,56,57,5,2,0,0,57,59,3,8,
  	4,0,58,56,1,0,0,0,59,62,1,0,0,0,60,58,1,0,0,0,60,61,1,0,0,0,61,7,1,0,
  	0,0,62,60,1,0,0,0,63,68,3,10,5,0,64,65,5,3,0,0,65,67,3,10,5,0,66,64,1,
  	0,0,0,67,70,1,0,0,0,68,66,1,0,0,0,68,69,1,0,0,0,69,9,1,0,0,0,70,68,1,
  	0,0,0,71,72,5,4,0,0,72,75,3,10,5,0,73,75,3,12,6,0,74,71,1,0,0,0,74,73,
  	1,0,0,0,75,11,1,0,0,0,76,77,5,5,0,0,77,78,3,2,1,0,78,79,5,6,0,0,79,88,
  	1,0,0,0,80,81,5,7,0,0,81,82,5,5,0,0,82,83,3,14,7,0,83,84,5,6,0,0,84,85,
  	5,17,0,0,85,86,5,20,0,0,86,88,1,0,0,0,87,76,1,0,0,0,87,80,1,0,0,0,88,
  	13,1,0,0,0,89,90,3,16,8,0,90,15,1,0,0,0,91,96,3,18,9,0,92,93,5,1,0,0,
  	93,95,3,18,9,0,94,92,1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,96,97,1,0,0,
  	0,97,17,1,0,0,0,98,96,1,0,0,0,99,104,3,20,10,0,100,101,5,2,0,0,101,103,
  	3,20,10,0,102,100,1,0,0,0,103,106,1,0,0,0,104,102,1,0,0,0,104,105,1,0,
  	0,0,105,19,1,0,0,0,106,104,1,0,0,0,107,108,5,4,0,0,108,111,3,20,10,0,
  	109,111,3,22,11,0,110,107,1,0,0,0,110,109,1,0,0,0,111,21,1,0,0,0,112,
  	113,3,40,20,0,113,114,5,8,0,0,114,115,3,24,12,0,115,121,1,0,0,0,116,117,
  	3,38,19,0,117,118,5,8,0,0,118,119,5,19,0,0,119,121,1,0,0,0,120,112,1,
  	0,0,0,120,116,1,0,0,0,121,23,1,0,0,0,122,128,3,26,13,0,123,124,3,36,18,
  	0,124,125,5,16,0,0,125,126,3,26,13,0,126,128,1,0,0,0,127,122,1,0,0,0,
  	127,123,1,0,0,0,128,25,1,0,0,0,129,132,3,40,20,0,130,132,3,28,14,0,131,
  	129,1,0,0,0,131,130,1,0,0,0,132,27,1,0,0,0,133,134,5,9,0,0,134,139,3,
  	30,15,0,135,136,5,10,0,0,136,138,3,30,15,0,137,135,1,0,0,0,138,141,1,
  	0,0,0,139,137,1,0,0,0,139,140,1,0,0,0,140,142,1,0,0,0,141,139,1,0,0,0,
  	142,143,5,11,0,0,143,29,1,0,0,0,144,146,3,32,16,0,145,147,3,34,17,0,146,
  	145,1,0,0,0,146,147,1,0,0,0,147,31,1,0,0,0,148,150,5,18,0,0,149,148,1,
  	0,0,0,149,150,1,0,0,0,150,151,1,0,0,0,151,152,5,20,0,0,152,33,1,0,0,0,
  	153,155,5,18,0,0,154,153,1,0,0,0,154,155,1,0,0,0,155,157,1,0,0,0,156,
  	158,5,20,0,0,157,156,1,0,0,0,157,158,1,0,0,0,158,159,1,0,0,0,159,160,
  	5,12,0,0,160,35,1,0,0,0,161,162,5,13,0,0,162,163,3,28,14,0,163,164,5,
  	14,0,0,164,169,3,28,14,0,165,166,5,14,0,0,166,168,3,28,14,0,167,165,1,
  	0,0,0,168,171,1,0,0,0,169,167,1,0,0,0,169,170,1,0,0,0,170,172,1,0,0,0,
  	171,169,1,0,0,0,172,173,5,15,0,0,173,37,1,0,0,0,174,179,5,21,0,0,175,
  	176,5,10,0,0,176,178,5,21,0,0,177,175,1,0,0,0,178,181,1,0,0,0,179,177,
  	1,0,0,0,179,180,1,0,0,0,180,39,1,0,0,0,181,179,1,0,0,0,182,187,5,22,0,
  	0,183,184,5,10,0,0,184,186,5,22,0,0,185,183,1,0,0,0,186,189,1,0,0,0,187,
  	185,1,0,0,0,187,188,1,0,0,0,188,41,1,0,0,0,189,187,1,0,0,0,19,52,60,68,
  	74,87,96,104,110,120,127,131,139,146,149,154,157,169,179,187
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
    setState(42);
    distribution_assertion();
    setState(43);
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
    setState(45);
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
    setState(47);
    dis_and_expr();
    setState(52);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__0) {
      setState(48);
      match(AssertionParser::T__0);
      setState(49);
      dis_and_expr();
      setState(54);
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
    setState(55);
    dis_conv_expr();
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__1) {
      setState(56);
      match(AssertionParser::T__1);
      setState(57);
      dis_conv_expr();
      setState(62);
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
    setState(63);
    dis_not_expr();
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__2) {
      setState(64);
      match(AssertionParser::T__2);
      setState(65);
      dis_not_expr();
      setState(70);
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
    setState(74);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__3: {
        _localctx = _tracker.createInstance<AssertionParser::Dis_notContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(71);
        match(AssertionParser::T__3);
        setState(72);
        dis_not_expr();
        break;
      }

      case AssertionParser::T__4:
      case AssertionParser::T__6: {
        _localctx = _tracker.createInstance<AssertionParser::Dis_not_atomContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(73);
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

tree::TerminalNode* AssertionParser::Symbolic_probContext::RELOP() {
  return getToken(AssertionParser::RELOP, 0);
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
    setState(87);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__4: {
        _localctx = _tracker.createInstance<AssertionParser::Dis_assertionContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(76);
        match(AssertionParser::T__4);
        setState(77);
        distribution_assertion();
        setState(78);
        match(AssertionParser::T__5);
        break;
      }

      case AssertionParser::T__6: {
        _localctx = _tracker.createInstance<AssertionParser::Symbolic_probContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(80);
        match(AssertionParser::T__6);
        setState(81);
        match(AssertionParser::T__4);
        setState(82);
        states_assertion();
        setState(83);
        match(AssertionParser::T__5);
        setState(84);
        match(AssertionParser::RELOP);
        setState(85);
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
    setState(89);
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
    setState(91);
    states_and_expr();
    setState(96);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__0) {
      setState(92);
      match(AssertionParser::T__0);
      setState(93);
      states_and_expr();
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
    setState(99);
    states_not_expr();
    setState(104);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__1) {
      setState(100);
      match(AssertionParser::T__1);
      setState(101);
      states_not_expr();
      setState(106);
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
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__3: {
        _localctx = _tracker.createInstance<AssertionParser::Not_exprContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(107);
        match(AssertionParser::T__3);
        setState(108);
        states_not_expr();
        break;
      }

      case AssertionParser::CID:
      case AssertionParser::QID: {
        _localctx = _tracker.createInstance<AssertionParser::States_atom_ruleContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(109);
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

AssertionParser::QTerm2Context* AssertionParser::QtermContext::qTerm2() {
  return getRuleContext<AssertionParser::QTerm2Context>(0);
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
    setState(120);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::QID: {
        _localctx = _tracker.createInstance<AssertionParser::QtermContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(112);
        qList();
        setState(113);
        match(AssertionParser::T__7);
        setState(114);
        qTerm2();
        break;
      }

      case AssertionParser::CID: {
        _localctx = _tracker.createInstance<AssertionParser::BtermContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(116);
        bList();
        setState(117);
        match(AssertionParser::T__7);
        setState(118);
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

//----------------- QTerm2Context ------------------------------------------------------------------

AssertionParser::QTerm2Context::QTerm2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssertionParser::QTerm2Context::getRuleIndex() const {
  return AssertionParser::RuleQTerm2;
}

void AssertionParser::QTerm2Context::copyFrom(QTerm2Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MatrixVectorTermContext ------------------------------------------------------------------

AssertionParser::MatrixContext* AssertionParser::MatrixVectorTermContext::matrix() {
  return getRuleContext<AssertionParser::MatrixContext>(0);
}

tree::TerminalNode* AssertionParser::MatrixVectorTermContext::MUL() {
  return getToken(AssertionParser::MUL, 0);
}

AssertionParser::VectorContext* AssertionParser::MatrixVectorTermContext::vector() {
  return getRuleContext<AssertionParser::VectorContext>(0);
}

AssertionParser::MatrixVectorTermContext::MatrixVectorTermContext(QTerm2Context *ctx) { copyFrom(ctx); }

void AssertionParser::MatrixVectorTermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatrixVectorTerm(this);
}
void AssertionParser::MatrixVectorTermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatrixVectorTerm(this);
}

std::any AssertionParser::MatrixVectorTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitMatrixVectorTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VectorTermContext ------------------------------------------------------------------

AssertionParser::VectorContext* AssertionParser::VectorTermContext::vector() {
  return getRuleContext<AssertionParser::VectorContext>(0);
}

AssertionParser::VectorTermContext::VectorTermContext(QTerm2Context *ctx) { copyFrom(ctx); }

void AssertionParser::VectorTermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVectorTerm(this);
}
void AssertionParser::VectorTermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVectorTerm(this);
}

std::any AssertionParser::VectorTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitVectorTerm(this);
  else
    return visitor->visitChildren(this);
}
AssertionParser::QTerm2Context* AssertionParser::qTerm2() {
  QTerm2Context *_localctx = _tracker.createInstance<QTerm2Context>(_ctx, getState());
  enterRule(_localctx, 24, AssertionParser::RuleQTerm2);

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
    switch (_input->LA(1)) {
      case AssertionParser::T__8:
      case AssertionParser::QID: {
        _localctx = _tracker.createInstance<AssertionParser::VectorTermContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(122);
        vector();
        break;
      }

      case AssertionParser::T__12: {
        _localctx = _tracker.createInstance<AssertionParser::MatrixVectorTermContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(123);
        matrix();
        setState(124);
        match(AssertionParser::MUL);
        setState(125);
        vector();
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

//----------------- VectorContext ------------------------------------------------------------------

AssertionParser::VectorContext::VectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssertionParser::VectorContext::getRuleIndex() const {
  return AssertionParser::RuleVector;
}

void AssertionParser::VectorContext::copyFrom(VectorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NumericVectorContext ------------------------------------------------------------------

AssertionParser::RowContext* AssertionParser::NumericVectorContext::row() {
  return getRuleContext<AssertionParser::RowContext>(0);
}

AssertionParser::NumericVectorContext::NumericVectorContext(VectorContext *ctx) { copyFrom(ctx); }

void AssertionParser::NumericVectorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericVector(this);
}
void AssertionParser::NumericVectorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericVector(this);
}

std::any AssertionParser::NumericVectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitNumericVector(this);
  else
    return visitor->visitChildren(this);
}
//----------------- QVarVectorContext ------------------------------------------------------------------

AssertionParser::QListContext* AssertionParser::QVarVectorContext::qList() {
  return getRuleContext<AssertionParser::QListContext>(0);
}

AssertionParser::QVarVectorContext::QVarVectorContext(VectorContext *ctx) { copyFrom(ctx); }

void AssertionParser::QVarVectorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQVarVector(this);
}
void AssertionParser::QVarVectorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQVarVector(this);
}

std::any AssertionParser::QVarVectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitQVarVector(this);
  else
    return visitor->visitChildren(this);
}
AssertionParser::VectorContext* AssertionParser::vector() {
  VectorContext *_localctx = _tracker.createInstance<VectorContext>(_ctx, getState());
  enterRule(_localctx, 26, AssertionParser::RuleVector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(131);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::QID: {
        _localctx = _tracker.createInstance<AssertionParser::QVarVectorContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(129);
        qList();
        break;
      }

      case AssertionParser::T__8: {
        _localctx = _tracker.createInstance<AssertionParser::NumericVectorContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(130);
        row();
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

std::vector<AssertionParser::ComplexNumberContext *> AssertionParser::RowContext::complexNumber() {
  return getRuleContexts<AssertionParser::ComplexNumberContext>();
}

AssertionParser::ComplexNumberContext* AssertionParser::RowContext::complexNumber(size_t i) {
  return getRuleContext<AssertionParser::ComplexNumberContext>(i);
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
  enterRule(_localctx, 28, AssertionParser::RuleRow);
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
    setState(133);
    match(AssertionParser::T__8);
    setState(134);
    complexNumber();
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__9) {
      setState(135);
      match(AssertionParser::T__9);
      setState(136);
      complexNumber();
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(142);
    match(AssertionParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComplexNumberContext ------------------------------------------------------------------

AssertionParser::ComplexNumberContext::ComplexNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssertionParser::ComplexNumberContext::getRuleIndex() const {
  return AssertionParser::RuleComplexNumber;
}

void AssertionParser::ComplexNumberContext::copyFrom(ComplexNumberContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ComplexRealImagContext ------------------------------------------------------------------

AssertionParser::RealPartContext* AssertionParser::ComplexRealImagContext::realPart() {
  return getRuleContext<AssertionParser::RealPartContext>(0);
}

AssertionParser::ImagPartContext* AssertionParser::ComplexRealImagContext::imagPart() {
  return getRuleContext<AssertionParser::ImagPartContext>(0);
}

AssertionParser::ComplexRealImagContext::ComplexRealImagContext(ComplexNumberContext *ctx) { copyFrom(ctx); }

void AssertionParser::ComplexRealImagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComplexRealImag(this);
}
void AssertionParser::ComplexRealImagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComplexRealImag(this);
}

std::any AssertionParser::ComplexRealImagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitComplexRealImag(this);
  else
    return visitor->visitChildren(this);
}
AssertionParser::ComplexNumberContext* AssertionParser::complexNumber() {
  ComplexNumberContext *_localctx = _tracker.createInstance<ComplexNumberContext>(_ctx, getState());
  enterRule(_localctx, 30, AssertionParser::RuleComplexNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<AssertionParser::ComplexRealImagContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(144);
    realPart();
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1314816) != 0)) {
      setState(145);
      imagPart();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealPartContext ------------------------------------------------------------------

AssertionParser::RealPartContext::RealPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssertionParser::RealPartContext::REALNUM() {
  return getToken(AssertionParser::REALNUM, 0);
}

tree::TerminalNode* AssertionParser::RealPartContext::SIGN() {
  return getToken(AssertionParser::SIGN, 0);
}


size_t AssertionParser::RealPartContext::getRuleIndex() const {
  return AssertionParser::RuleRealPart;
}

void AssertionParser::RealPartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRealPart(this);
}

void AssertionParser::RealPartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRealPart(this);
}


std::any AssertionParser::RealPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitRealPart(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::RealPartContext* AssertionParser::realPart() {
  RealPartContext *_localctx = _tracker.createInstance<RealPartContext>(_ctx, getState());
  enterRule(_localctx, 32, AssertionParser::RuleRealPart);
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
    setState(149);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AssertionParser::SIGN) {
      setState(148);
      match(AssertionParser::SIGN);
    }
    setState(151);
    match(AssertionParser::REALNUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImagPartContext ------------------------------------------------------------------

AssertionParser::ImagPartContext::ImagPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssertionParser::ImagPartContext::SIGN() {
  return getToken(AssertionParser::SIGN, 0);
}

tree::TerminalNode* AssertionParser::ImagPartContext::REALNUM() {
  return getToken(AssertionParser::REALNUM, 0);
}


size_t AssertionParser::ImagPartContext::getRuleIndex() const {
  return AssertionParser::RuleImagPart;
}

void AssertionParser::ImagPartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImagPart(this);
}

void AssertionParser::ImagPartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImagPart(this);
}


std::any AssertionParser::ImagPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitImagPart(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::ImagPartContext* AssertionParser::imagPart() {
  ImagPartContext *_localctx = _tracker.createInstance<ImagPartContext>(_ctx, getState());
  enterRule(_localctx, 34, AssertionParser::RuleImagPart);
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
    setState(154);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AssertionParser::SIGN) {
      setState(153);
      match(AssertionParser::SIGN);
    }
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AssertionParser::REALNUM) {
      setState(156);
      match(AssertionParser::REALNUM);
    }
    setState(159);
    match(AssertionParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatrixContext ------------------------------------------------------------------

AssertionParser::MatrixContext::MatrixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AssertionParser::RowContext *> AssertionParser::MatrixContext::row() {
  return getRuleContexts<AssertionParser::RowContext>();
}

AssertionParser::RowContext* AssertionParser::MatrixContext::row(size_t i) {
  return getRuleContext<AssertionParser::RowContext>(i);
}


size_t AssertionParser::MatrixContext::getRuleIndex() const {
  return AssertionParser::RuleMatrix;
}

void AssertionParser::MatrixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatrix(this);
}

void AssertionParser::MatrixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatrix(this);
}


std::any AssertionParser::MatrixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitMatrix(this);
  else
    return visitor->visitChildren(this);
}

AssertionParser::MatrixContext* AssertionParser::matrix() {
  MatrixContext *_localctx = _tracker.createInstance<MatrixContext>(_ctx, getState());
  enterRule(_localctx, 36, AssertionParser::RuleMatrix);
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
    setState(161);
    match(AssertionParser::T__12);
    setState(162);
    row();
    setState(163);
    match(AssertionParser::T__13);
    setState(164);
    row();
    setState(169);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__13) {
      setState(165);
      match(AssertionParser::T__13);
      setState(166);
      row();
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(172);
    match(AssertionParser::T__14);
   
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
  enterRule(_localctx, 38, AssertionParser::RuleBList);
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
    setState(174);
    match(AssertionParser::CID);
    setState(179);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__9) {
      setState(175);
      match(AssertionParser::T__9);
      setState(176);
      match(AssertionParser::CID);
      setState(181);
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
  enterRule(_localctx, 40, AssertionParser::RuleQList);
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
    setState(182);
    match(AssertionParser::QID);
    setState(187);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__9) {
      setState(183);
      match(AssertionParser::T__9);
      setState(184);
      match(AssertionParser::QID);
      setState(189);
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
