
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
      "dis_conv_expr", "dis_not_expr", "dis_atom", "prob_term", "states_assertion", 
      "states_or_expr", "states_and_expr", "states_not_expr", "states_atom", 
      "qTerm2", "vector", "row", "complexNumber", "realPart", "imagPart", 
      "matrix", "bList", "qList"
    },
    std::vector<std::string>{
      "", "'or'", "'and'", "'+'", "'!'", "'('", "')'", "'Tr'", "'P'", "'='", 
      "'['", "','", "']'", "'i'", "'[['", "';'", "']]'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "MUL", "RELOP", "SIGN", "BINARYSTRING", "REALNUM", "CID", "QID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,24,203,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,5,2,53,8,2,10,2,12,2,56,9,2,1,3,1,
  	3,1,3,5,3,61,8,3,10,3,12,3,64,9,3,1,4,1,4,1,4,5,4,69,8,4,10,4,12,4,72,
  	9,4,1,5,1,5,1,5,3,5,77,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,87,8,6,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,100,8,7,1,8,1,8,1,9,1,
  	9,1,9,5,9,107,8,9,10,9,12,9,110,9,9,1,10,1,10,1,10,5,10,115,8,10,10,10,
  	12,10,118,9,10,1,11,1,11,1,11,3,11,123,8,11,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,3,12,133,8,12,1,13,1,13,1,13,1,13,1,13,3,13,140,8,13,1,
  	14,1,14,3,14,144,8,14,1,15,1,15,1,15,1,15,5,15,150,8,15,10,15,12,15,153,
  	9,15,1,15,1,15,1,16,1,16,3,16,159,8,16,1,17,3,17,162,8,17,1,17,1,17,1,
  	18,3,18,167,8,18,1,18,3,18,170,8,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,
  	1,19,5,19,180,8,19,10,19,12,19,183,9,19,1,19,1,19,1,20,1,20,1,20,5,20,
  	190,8,20,10,20,12,20,193,9,20,1,21,1,21,1,21,5,21,198,8,21,10,21,12,21,
  	201,9,21,1,21,0,0,22,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,
  	36,38,40,42,0,0,201,0,44,1,0,0,0,2,47,1,0,0,0,4,49,1,0,0,0,6,57,1,0,0,
  	0,8,65,1,0,0,0,10,76,1,0,0,0,12,86,1,0,0,0,14,99,1,0,0,0,16,101,1,0,0,
  	0,18,103,1,0,0,0,20,111,1,0,0,0,22,122,1,0,0,0,24,132,1,0,0,0,26,139,
  	1,0,0,0,28,143,1,0,0,0,30,145,1,0,0,0,32,156,1,0,0,0,34,161,1,0,0,0,36,
  	166,1,0,0,0,38,173,1,0,0,0,40,186,1,0,0,0,42,194,1,0,0,0,44,45,3,2,1,
  	0,45,46,5,0,0,1,46,1,1,0,0,0,47,48,3,4,2,0,48,3,1,0,0,0,49,54,3,6,3,0,
  	50,51,5,1,0,0,51,53,3,6,3,0,52,50,1,0,0,0,53,56,1,0,0,0,54,52,1,0,0,0,
  	54,55,1,0,0,0,55,5,1,0,0,0,56,54,1,0,0,0,57,62,3,8,4,0,58,59,5,2,0,0,
  	59,61,3,8,4,0,60,58,1,0,0,0,61,64,1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,
  	63,7,1,0,0,0,64,62,1,0,0,0,65,70,3,10,5,0,66,67,5,3,0,0,67,69,3,10,5,
  	0,68,66,1,0,0,0,69,72,1,0,0,0,70,68,1,0,0,0,70,71,1,0,0,0,71,9,1,0,0,
  	0,72,70,1,0,0,0,73,74,5,4,0,0,74,77,3,10,5,0,75,77,3,12,6,0,76,73,1,0,
  	0,0,76,75,1,0,0,0,77,11,1,0,0,0,78,79,5,5,0,0,79,80,3,2,1,0,80,81,5,6,
  	0,0,81,87,1,0,0,0,82,83,3,14,7,0,83,84,5,18,0,0,84,85,3,14,7,0,85,87,
  	1,0,0,0,86,78,1,0,0,0,86,82,1,0,0,0,87,13,1,0,0,0,88,89,5,7,0,0,89,90,
  	5,5,0,0,90,91,3,26,13,0,91,92,5,6,0,0,92,100,1,0,0,0,93,94,5,8,0,0,94,
  	95,5,5,0,0,95,96,3,16,8,0,96,97,5,6,0,0,97,100,1,0,0,0,98,100,5,21,0,
  	0,99,88,1,0,0,0,99,93,1,0,0,0,99,98,1,0,0,0,100,15,1,0,0,0,101,102,3,
  	18,9,0,102,17,1,0,0,0,103,108,3,20,10,0,104,105,5,1,0,0,105,107,3,20,
  	10,0,106,104,1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,
  	109,19,1,0,0,0,110,108,1,0,0,0,111,116,3,22,11,0,112,113,5,2,0,0,113,
  	115,3,22,11,0,114,112,1,0,0,0,115,118,1,0,0,0,116,114,1,0,0,0,116,117,
  	1,0,0,0,117,21,1,0,0,0,118,116,1,0,0,0,119,120,5,4,0,0,120,123,3,22,11,
  	0,121,123,3,24,12,0,122,119,1,0,0,0,122,121,1,0,0,0,123,23,1,0,0,0,124,
  	125,3,42,21,0,125,126,5,9,0,0,126,127,3,26,13,0,127,133,1,0,0,0,128,129,
  	3,40,20,0,129,130,5,9,0,0,130,131,5,20,0,0,131,133,1,0,0,0,132,124,1,
  	0,0,0,132,128,1,0,0,0,133,25,1,0,0,0,134,140,3,28,14,0,135,136,3,38,19,
  	0,136,137,5,17,0,0,137,138,3,28,14,0,138,140,1,0,0,0,139,134,1,0,0,0,
  	139,135,1,0,0,0,140,27,1,0,0,0,141,144,3,42,21,0,142,144,3,30,15,0,143,
  	141,1,0,0,0,143,142,1,0,0,0,144,29,1,0,0,0,145,146,5,10,0,0,146,151,3,
  	32,16,0,147,148,5,11,0,0,148,150,3,32,16,0,149,147,1,0,0,0,150,153,1,
  	0,0,0,151,149,1,0,0,0,151,152,1,0,0,0,152,154,1,0,0,0,153,151,1,0,0,0,
  	154,155,5,12,0,0,155,31,1,0,0,0,156,158,3,34,17,0,157,159,3,36,18,0,158,
  	157,1,0,0,0,158,159,1,0,0,0,159,33,1,0,0,0,160,162,5,19,0,0,161,160,1,
  	0,0,0,161,162,1,0,0,0,162,163,1,0,0,0,163,164,5,21,0,0,164,35,1,0,0,0,
  	165,167,5,19,0,0,166,165,1,0,0,0,166,167,1,0,0,0,167,169,1,0,0,0,168,
  	170,5,21,0,0,169,168,1,0,0,0,169,170,1,0,0,0,170,171,1,0,0,0,171,172,
  	5,13,0,0,172,37,1,0,0,0,173,174,5,14,0,0,174,175,3,30,15,0,175,176,5,
  	15,0,0,176,181,3,30,15,0,177,178,5,15,0,0,178,180,3,30,15,0,179,177,1,
  	0,0,0,180,183,1,0,0,0,181,179,1,0,0,0,181,182,1,0,0,0,182,184,1,0,0,0,
  	183,181,1,0,0,0,184,185,5,16,0,0,185,39,1,0,0,0,186,191,5,22,0,0,187,
  	188,5,11,0,0,188,190,5,22,0,0,189,187,1,0,0,0,190,193,1,0,0,0,191,189,
  	1,0,0,0,191,192,1,0,0,0,192,41,1,0,0,0,193,191,1,0,0,0,194,199,5,23,0,
  	0,195,196,5,11,0,0,196,198,5,23,0,0,197,195,1,0,0,0,198,201,1,0,0,0,199,
  	197,1,0,0,0,199,200,1,0,0,0,200,43,1,0,0,0,201,199,1,0,0,0,20,54,62,70,
  	76,86,99,108,116,122,132,139,143,151,158,161,166,169,181,191,199
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
    setState(44);
    distribution_assertion();
    setState(45);
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
    setState(47);
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
    setState(49);
    dis_and_expr();
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__0) {
      setState(50);
      match(AssertionParser::T__0);
      setState(51);
      dis_and_expr();
      setState(56);
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
    setState(57);
    dis_conv_expr();
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__1) {
      setState(58);
      match(AssertionParser::T__1);
      setState(59);
      dis_conv_expr();
      setState(64);
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
    setState(65);
    dis_not_expr();
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__2) {
      setState(66);
      match(AssertionParser::T__2);
      setState(67);
      dis_not_expr();
      setState(72);
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
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__3: {
        _localctx = _tracker.createInstance<AssertionParser::Dis_notContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(73);
        match(AssertionParser::T__3);
        setState(74);
        dis_not_expr();
        break;
      }

      case AssertionParser::T__4:
      case AssertionParser::T__6:
      case AssertionParser::T__7:
      case AssertionParser::REALNUM: {
        _localctx = _tracker.createInstance<AssertionParser::Dis_not_atomContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(75);
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
//----------------- Atom_terminalContext ------------------------------------------------------------------

std::vector<AssertionParser::Prob_termContext *> AssertionParser::Atom_terminalContext::prob_term() {
  return getRuleContexts<AssertionParser::Prob_termContext>();
}

AssertionParser::Prob_termContext* AssertionParser::Atom_terminalContext::prob_term(size_t i) {
  return getRuleContext<AssertionParser::Prob_termContext>(i);
}

tree::TerminalNode* AssertionParser::Atom_terminalContext::RELOP() {
  return getToken(AssertionParser::RELOP, 0);
}

AssertionParser::Atom_terminalContext::Atom_terminalContext(Dis_atomContext *ctx) { copyFrom(ctx); }

void AssertionParser::Atom_terminalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_terminal(this);
}
void AssertionParser::Atom_terminalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_terminal(this);
}

std::any AssertionParser::Atom_terminalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitAtom_terminal(this);
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
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__4: {
        _localctx = _tracker.createInstance<AssertionParser::Dis_assertionContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(78);
        match(AssertionParser::T__4);
        setState(79);
        distribution_assertion();
        setState(80);
        match(AssertionParser::T__5);
        break;
      }

      case AssertionParser::T__6:
      case AssertionParser::T__7:
      case AssertionParser::REALNUM: {
        _localctx = _tracker.createInstance<AssertionParser::Atom_terminalContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(82);
        prob_term();
        setState(83);
        match(AssertionParser::RELOP);
        setState(84);
        prob_term();
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

//----------------- Prob_termContext ------------------------------------------------------------------

AssertionParser::Prob_termContext::Prob_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssertionParser::Prob_termContext::getRuleIndex() const {
  return AssertionParser::RuleProb_term;
}

void AssertionParser::Prob_termContext::copyFrom(Prob_termContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Const_probContext ------------------------------------------------------------------

tree::TerminalNode* AssertionParser::Const_probContext::REALNUM() {
  return getToken(AssertionParser::REALNUM, 0);
}

AssertionParser::Const_probContext::Const_probContext(Prob_termContext *ctx) { copyFrom(ctx); }

void AssertionParser::Const_probContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_prob(this);
}
void AssertionParser::Const_probContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_prob(this);
}

std::any AssertionParser::Const_probContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitConst_prob(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Symbolic_probContext ------------------------------------------------------------------

AssertionParser::States_assertionContext* AssertionParser::Symbolic_probContext::states_assertion() {
  return getRuleContext<AssertionParser::States_assertionContext>(0);
}

AssertionParser::Symbolic_probContext::Symbolic_probContext(Prob_termContext *ctx) { copyFrom(ctx); }

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
//----------------- Trace_probContext ------------------------------------------------------------------

AssertionParser::QTerm2Context* AssertionParser::Trace_probContext::qTerm2() {
  return getRuleContext<AssertionParser::QTerm2Context>(0);
}

AssertionParser::Trace_probContext::Trace_probContext(Prob_termContext *ctx) { copyFrom(ctx); }

void AssertionParser::Trace_probContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrace_prob(this);
}
void AssertionParser::Trace_probContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrace_prob(this);
}

std::any AssertionParser::Trace_probContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssertionVisitor*>(visitor))
    return parserVisitor->visitTrace_prob(this);
  else
    return visitor->visitChildren(this);
}
AssertionParser::Prob_termContext* AssertionParser::prob_term() {
  Prob_termContext *_localctx = _tracker.createInstance<Prob_termContext>(_ctx, getState());
  enterRule(_localctx, 14, AssertionParser::RuleProb_term);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__6: {
        _localctx = _tracker.createInstance<AssertionParser::Trace_probContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(88);
        match(AssertionParser::T__6);
        setState(89);
        match(AssertionParser::T__4);
        setState(90);
        qTerm2();
        setState(91);
        match(AssertionParser::T__5);
        break;
      }

      case AssertionParser::T__7: {
        _localctx = _tracker.createInstance<AssertionParser::Symbolic_probContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(93);
        match(AssertionParser::T__7);
        setState(94);
        match(AssertionParser::T__4);
        setState(95);
        states_assertion();
        setState(96);
        match(AssertionParser::T__5);
        break;
      }

      case AssertionParser::REALNUM: {
        _localctx = _tracker.createInstance<AssertionParser::Const_probContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(98);
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
  enterRule(_localctx, 16, AssertionParser::RuleStates_assertion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
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
  enterRule(_localctx, 18, AssertionParser::RuleStates_or_expr);
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
    setState(103);
    states_and_expr();
    setState(108);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__0) {
      setState(104);
      match(AssertionParser::T__0);
      setState(105);
      states_and_expr();
      setState(110);
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
  enterRule(_localctx, 20, AssertionParser::RuleStates_and_expr);
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
    setState(111);
    states_not_expr();
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__1) {
      setState(112);
      match(AssertionParser::T__1);
      setState(113);
      states_not_expr();
      setState(118);
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
  enterRule(_localctx, 22, AssertionParser::RuleStates_not_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(122);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__3: {
        _localctx = _tracker.createInstance<AssertionParser::Not_exprContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(119);
        match(AssertionParser::T__3);
        setState(120);
        states_not_expr();
        break;
      }

      case AssertionParser::CID:
      case AssertionParser::QID: {
        _localctx = _tracker.createInstance<AssertionParser::States_atom_ruleContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(121);
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
  enterRule(_localctx, 24, AssertionParser::RuleStates_atom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::QID: {
        _localctx = _tracker.createInstance<AssertionParser::QtermContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(124);
        qList();
        setState(125);
        match(AssertionParser::T__8);
        setState(126);
        qTerm2();
        break;
      }

      case AssertionParser::CID: {
        _localctx = _tracker.createInstance<AssertionParser::BtermContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(128);
        bList();
        setState(129);
        match(AssertionParser::T__8);
        setState(130);
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
  enterRule(_localctx, 26, AssertionParser::RuleQTerm2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(139);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::T__9:
      case AssertionParser::QID: {
        _localctx = _tracker.createInstance<AssertionParser::VectorTermContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(134);
        vector();
        break;
      }

      case AssertionParser::T__13: {
        _localctx = _tracker.createInstance<AssertionParser::MatrixVectorTermContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(135);
        matrix();
        setState(136);
        match(AssertionParser::MUL);
        setState(137);
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
  enterRule(_localctx, 28, AssertionParser::RuleVector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(143);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssertionParser::QID: {
        _localctx = _tracker.createInstance<AssertionParser::QVarVectorContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(141);
        qList();
        break;
      }

      case AssertionParser::T__9: {
        _localctx = _tracker.createInstance<AssertionParser::NumericVectorContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(142);
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
  enterRule(_localctx, 30, AssertionParser::RuleRow);
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
    setState(145);
    match(AssertionParser::T__9);
    setState(146);
    complexNumber();
    setState(151);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__10) {
      setState(147);
      match(AssertionParser::T__10);
      setState(148);
      complexNumber();
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(154);
    match(AssertionParser::T__11);
   
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
  enterRule(_localctx, 32, AssertionParser::RuleComplexNumber);
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
    setState(156);
    realPart();
    setState(158);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2629632) != 0)) {
      setState(157);
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
  enterRule(_localctx, 34, AssertionParser::RuleRealPart);
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
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AssertionParser::SIGN) {
      setState(160);
      match(AssertionParser::SIGN);
    }
    setState(163);
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
  enterRule(_localctx, 36, AssertionParser::RuleImagPart);
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
    setState(166);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AssertionParser::SIGN) {
      setState(165);
      match(AssertionParser::SIGN);
    }
    setState(169);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AssertionParser::REALNUM) {
      setState(168);
      match(AssertionParser::REALNUM);
    }
    setState(171);
    match(AssertionParser::T__12);
   
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
  enterRule(_localctx, 38, AssertionParser::RuleMatrix);
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
    setState(173);
    match(AssertionParser::T__13);
    setState(174);
    row();
    setState(175);
    match(AssertionParser::T__14);
    setState(176);
    row();
    setState(181);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__14) {
      setState(177);
      match(AssertionParser::T__14);
      setState(178);
      row();
      setState(183);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(184);
    match(AssertionParser::T__15);
   
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
  enterRule(_localctx, 40, AssertionParser::RuleBList);
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
    setState(186);
    match(AssertionParser::CID);
    setState(191);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__10) {
      setState(187);
      match(AssertionParser::T__10);
      setState(188);
      match(AssertionParser::CID);
      setState(193);
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
  enterRule(_localctx, 42, AssertionParser::RuleQList);
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
    setState(194);
    match(AssertionParser::QID);
    setState(199);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssertionParser::T__10) {
      setState(195);
      match(AssertionParser::T__10);
      setState(196);
      match(AssertionParser::QID);
      setState(201);
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
