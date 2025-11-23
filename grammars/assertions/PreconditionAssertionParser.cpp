
// Generated from ../grammars/assertions/PreconditionAssertion.g4 by ANTLR 4.13.2


#include "PreconditionAssertionListener.h"
#include "PreconditionAssertionVisitor.h"

#include "PreconditionAssertionParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PreconditionAssertionParserStaticData final {
  PreconditionAssertionParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PreconditionAssertionParserStaticData(const PreconditionAssertionParserStaticData&) = delete;
  PreconditionAssertionParserStaticData(PreconditionAssertionParserStaticData&&) = delete;
  PreconditionAssertionParserStaticData& operator=(const PreconditionAssertionParserStaticData&) = delete;
  PreconditionAssertionParserStaticData& operator=(PreconditionAssertionParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag preconditionassertionParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PreconditionAssertionParserStaticData> preconditionassertionParserStaticData = nullptr;

void preconditionassertionParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (preconditionassertionParserStaticData != nullptr) {
    return;
  }
#else
  assert(preconditionassertionParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PreconditionAssertionParserStaticData>(
    std::vector<std::string>{
      "precon_assertion", "distribution_assertion", "single_distribution", 
      "canon_clause", "canon_state", "row", "bList", "qList"
    },
    std::vector<std::string>{
      "", "'+'", "'and'", "'P('", "')'", "'='", "'['", "']'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "BINARYSTRING", "REALNUM", "CID", 
      "QID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,13,81,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,1,0,1,0,1,0,1,1,1,1,1,1,5,1,23,8,1,10,1,12,1,26,9,1,1,2,1,2,1,2,5,
  	2,31,8,2,10,2,12,2,34,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,5,5,58,8,5,10,5,12,5,61,9,
  	5,1,5,1,5,1,6,1,6,1,6,5,6,68,8,6,10,6,12,6,71,9,6,1,7,1,7,1,7,5,7,76,
  	8,7,10,7,12,7,79,9,7,1,7,0,0,8,0,2,4,6,8,10,12,14,0,0,77,0,16,1,0,0,0,
  	2,19,1,0,0,0,4,27,1,0,0,0,6,35,1,0,0,0,8,41,1,0,0,0,10,53,1,0,0,0,12,
  	64,1,0,0,0,14,72,1,0,0,0,16,17,3,2,1,0,17,18,5,0,0,1,18,1,1,0,0,0,19,
  	24,3,4,2,0,20,21,5,1,0,0,21,23,3,4,2,0,22,20,1,0,0,0,23,26,1,0,0,0,24,
  	22,1,0,0,0,24,25,1,0,0,0,25,3,1,0,0,0,26,24,1,0,0,0,27,32,3,6,3,0,28,
  	29,5,2,0,0,29,31,3,6,3,0,30,28,1,0,0,0,31,34,1,0,0,0,32,30,1,0,0,0,32,
  	33,1,0,0,0,33,5,1,0,0,0,34,32,1,0,0,0,35,36,5,3,0,0,36,37,3,8,4,0,37,
  	38,5,4,0,0,38,39,5,5,0,0,39,40,5,10,0,0,40,7,1,0,0,0,41,42,5,6,0,0,42,
  	43,3,14,7,0,43,44,5,7,0,0,44,45,5,5,0,0,45,46,3,10,5,0,46,47,5,2,0,0,
  	47,48,5,6,0,0,48,49,3,12,6,0,49,50,5,7,0,0,50,51,5,5,0,0,51,52,5,9,0,
  	0,52,9,1,0,0,0,53,54,5,6,0,0,54,59,5,10,0,0,55,56,5,8,0,0,56,58,5,10,
  	0,0,57,55,1,0,0,0,58,61,1,0,0,0,59,57,1,0,0,0,59,60,1,0,0,0,60,62,1,0,
  	0,0,61,59,1,0,0,0,62,63,5,7,0,0,63,11,1,0,0,0,64,69,5,11,0,0,65,66,5,
  	8,0,0,66,68,5,11,0,0,67,65,1,0,0,0,68,71,1,0,0,0,69,67,1,0,0,0,69,70,
  	1,0,0,0,70,13,1,0,0,0,71,69,1,0,0,0,72,77,5,12,0,0,73,74,5,8,0,0,74,76,
  	5,12,0,0,75,73,1,0,0,0,76,79,1,0,0,0,77,75,1,0,0,0,77,78,1,0,0,0,78,15,
  	1,0,0,0,79,77,1,0,0,0,5,24,32,59,69,77
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  preconditionassertionParserStaticData = std::move(staticData);
}

}

PreconditionAssertionParser::PreconditionAssertionParser(TokenStream *input) : PreconditionAssertionParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PreconditionAssertionParser::PreconditionAssertionParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PreconditionAssertionParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *preconditionassertionParserStaticData->atn, preconditionassertionParserStaticData->decisionToDFA, preconditionassertionParserStaticData->sharedContextCache, options);
}

PreconditionAssertionParser::~PreconditionAssertionParser() {
  delete _interpreter;
}

const atn::ATN& PreconditionAssertionParser::getATN() const {
  return *preconditionassertionParserStaticData->atn;
}

std::string PreconditionAssertionParser::getGrammarFileName() const {
  return "PreconditionAssertion.g4";
}

const std::vector<std::string>& PreconditionAssertionParser::getRuleNames() const {
  return preconditionassertionParserStaticData->ruleNames;
}

const dfa::Vocabulary& PreconditionAssertionParser::getVocabulary() const {
  return preconditionassertionParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PreconditionAssertionParser::getSerializedATN() const {
  return preconditionassertionParserStaticData->serializedATN;
}


//----------------- Precon_assertionContext ------------------------------------------------------------------

PreconditionAssertionParser::Precon_assertionContext::Precon_assertionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PreconditionAssertionParser::Distribution_assertionContext* PreconditionAssertionParser::Precon_assertionContext::distribution_assertion() {
  return getRuleContext<PreconditionAssertionParser::Distribution_assertionContext>(0);
}

tree::TerminalNode* PreconditionAssertionParser::Precon_assertionContext::EOF() {
  return getToken(PreconditionAssertionParser::EOF, 0);
}


size_t PreconditionAssertionParser::Precon_assertionContext::getRuleIndex() const {
  return PreconditionAssertionParser::RulePrecon_assertion;
}

void PreconditionAssertionParser::Precon_assertionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrecon_assertion(this);
}

void PreconditionAssertionParser::Precon_assertionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrecon_assertion(this);
}


std::any PreconditionAssertionParser::Precon_assertionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PreconditionAssertionVisitor*>(visitor))
    return parserVisitor->visitPrecon_assertion(this);
  else
    return visitor->visitChildren(this);
}

PreconditionAssertionParser::Precon_assertionContext* PreconditionAssertionParser::precon_assertion() {
  Precon_assertionContext *_localctx = _tracker.createInstance<Precon_assertionContext>(_ctx, getState());
  enterRule(_localctx, 0, PreconditionAssertionParser::RulePrecon_assertion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    distribution_assertion();
    setState(17);
    match(PreconditionAssertionParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Distribution_assertionContext ------------------------------------------------------------------

PreconditionAssertionParser::Distribution_assertionContext::Distribution_assertionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PreconditionAssertionParser::Single_distributionContext *> PreconditionAssertionParser::Distribution_assertionContext::single_distribution() {
  return getRuleContexts<PreconditionAssertionParser::Single_distributionContext>();
}

PreconditionAssertionParser::Single_distributionContext* PreconditionAssertionParser::Distribution_assertionContext::single_distribution(size_t i) {
  return getRuleContext<PreconditionAssertionParser::Single_distributionContext>(i);
}


size_t PreconditionAssertionParser::Distribution_assertionContext::getRuleIndex() const {
  return PreconditionAssertionParser::RuleDistribution_assertion;
}

void PreconditionAssertionParser::Distribution_assertionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDistribution_assertion(this);
}

void PreconditionAssertionParser::Distribution_assertionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDistribution_assertion(this);
}


std::any PreconditionAssertionParser::Distribution_assertionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PreconditionAssertionVisitor*>(visitor))
    return parserVisitor->visitDistribution_assertion(this);
  else
    return visitor->visitChildren(this);
}

PreconditionAssertionParser::Distribution_assertionContext* PreconditionAssertionParser::distribution_assertion() {
  Distribution_assertionContext *_localctx = _tracker.createInstance<Distribution_assertionContext>(_ctx, getState());
  enterRule(_localctx, 2, PreconditionAssertionParser::RuleDistribution_assertion);
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
    setState(19);
    single_distribution();
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PreconditionAssertionParser::T__0) {
      setState(20);
      match(PreconditionAssertionParser::T__0);
      setState(21);
      single_distribution();
      setState(26);
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

//----------------- Single_distributionContext ------------------------------------------------------------------

PreconditionAssertionParser::Single_distributionContext::Single_distributionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PreconditionAssertionParser::Canon_clauseContext *> PreconditionAssertionParser::Single_distributionContext::canon_clause() {
  return getRuleContexts<PreconditionAssertionParser::Canon_clauseContext>();
}

PreconditionAssertionParser::Canon_clauseContext* PreconditionAssertionParser::Single_distributionContext::canon_clause(size_t i) {
  return getRuleContext<PreconditionAssertionParser::Canon_clauseContext>(i);
}


size_t PreconditionAssertionParser::Single_distributionContext::getRuleIndex() const {
  return PreconditionAssertionParser::RuleSingle_distribution;
}

void PreconditionAssertionParser::Single_distributionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_distribution(this);
}

void PreconditionAssertionParser::Single_distributionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_distribution(this);
}


std::any PreconditionAssertionParser::Single_distributionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PreconditionAssertionVisitor*>(visitor))
    return parserVisitor->visitSingle_distribution(this);
  else
    return visitor->visitChildren(this);
}

PreconditionAssertionParser::Single_distributionContext* PreconditionAssertionParser::single_distribution() {
  Single_distributionContext *_localctx = _tracker.createInstance<Single_distributionContext>(_ctx, getState());
  enterRule(_localctx, 4, PreconditionAssertionParser::RuleSingle_distribution);
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
    setState(27);
    canon_clause();
    setState(32);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PreconditionAssertionParser::T__1) {
      setState(28);
      match(PreconditionAssertionParser::T__1);
      setState(29);
      canon_clause();
      setState(34);
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

//----------------- Canon_clauseContext ------------------------------------------------------------------

PreconditionAssertionParser::Canon_clauseContext::Canon_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PreconditionAssertionParser::Canon_stateContext* PreconditionAssertionParser::Canon_clauseContext::canon_state() {
  return getRuleContext<PreconditionAssertionParser::Canon_stateContext>(0);
}

tree::TerminalNode* PreconditionAssertionParser::Canon_clauseContext::REALNUM() {
  return getToken(PreconditionAssertionParser::REALNUM, 0);
}


size_t PreconditionAssertionParser::Canon_clauseContext::getRuleIndex() const {
  return PreconditionAssertionParser::RuleCanon_clause;
}

void PreconditionAssertionParser::Canon_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCanon_clause(this);
}

void PreconditionAssertionParser::Canon_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCanon_clause(this);
}


std::any PreconditionAssertionParser::Canon_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PreconditionAssertionVisitor*>(visitor))
    return parserVisitor->visitCanon_clause(this);
  else
    return visitor->visitChildren(this);
}

PreconditionAssertionParser::Canon_clauseContext* PreconditionAssertionParser::canon_clause() {
  Canon_clauseContext *_localctx = _tracker.createInstance<Canon_clauseContext>(_ctx, getState());
  enterRule(_localctx, 6, PreconditionAssertionParser::RuleCanon_clause);

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
    match(PreconditionAssertionParser::T__2);
    setState(36);
    canon_state();
    setState(37);
    match(PreconditionAssertionParser::T__3);
    setState(38);
    match(PreconditionAssertionParser::T__4);
    setState(39);
    match(PreconditionAssertionParser::REALNUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Canon_stateContext ------------------------------------------------------------------

PreconditionAssertionParser::Canon_stateContext::Canon_stateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PreconditionAssertionParser::QListContext* PreconditionAssertionParser::Canon_stateContext::qList() {
  return getRuleContext<PreconditionAssertionParser::QListContext>(0);
}

PreconditionAssertionParser::RowContext* PreconditionAssertionParser::Canon_stateContext::row() {
  return getRuleContext<PreconditionAssertionParser::RowContext>(0);
}

PreconditionAssertionParser::BListContext* PreconditionAssertionParser::Canon_stateContext::bList() {
  return getRuleContext<PreconditionAssertionParser::BListContext>(0);
}

tree::TerminalNode* PreconditionAssertionParser::Canon_stateContext::BINARYSTRING() {
  return getToken(PreconditionAssertionParser::BINARYSTRING, 0);
}


size_t PreconditionAssertionParser::Canon_stateContext::getRuleIndex() const {
  return PreconditionAssertionParser::RuleCanon_state;
}

void PreconditionAssertionParser::Canon_stateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCanon_state(this);
}

void PreconditionAssertionParser::Canon_stateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCanon_state(this);
}


std::any PreconditionAssertionParser::Canon_stateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PreconditionAssertionVisitor*>(visitor))
    return parserVisitor->visitCanon_state(this);
  else
    return visitor->visitChildren(this);
}

PreconditionAssertionParser::Canon_stateContext* PreconditionAssertionParser::canon_state() {
  Canon_stateContext *_localctx = _tracker.createInstance<Canon_stateContext>(_ctx, getState());
  enterRule(_localctx, 8, PreconditionAssertionParser::RuleCanon_state);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    match(PreconditionAssertionParser::T__5);
    setState(42);
    qList();
    setState(43);
    match(PreconditionAssertionParser::T__6);
    setState(44);
    match(PreconditionAssertionParser::T__4);
    setState(45);
    row();
    setState(46);
    match(PreconditionAssertionParser::T__1);
    setState(47);
    match(PreconditionAssertionParser::T__5);
    setState(48);
    bList();
    setState(49);
    match(PreconditionAssertionParser::T__6);
    setState(50);
    match(PreconditionAssertionParser::T__4);
    setState(51);
    match(PreconditionAssertionParser::BINARYSTRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RowContext ------------------------------------------------------------------

PreconditionAssertionParser::RowContext::RowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PreconditionAssertionParser::RowContext::REALNUM() {
  return getTokens(PreconditionAssertionParser::REALNUM);
}

tree::TerminalNode* PreconditionAssertionParser::RowContext::REALNUM(size_t i) {
  return getToken(PreconditionAssertionParser::REALNUM, i);
}


size_t PreconditionAssertionParser::RowContext::getRuleIndex() const {
  return PreconditionAssertionParser::RuleRow;
}

void PreconditionAssertionParser::RowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRow(this);
}

void PreconditionAssertionParser::RowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRow(this);
}


std::any PreconditionAssertionParser::RowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PreconditionAssertionVisitor*>(visitor))
    return parserVisitor->visitRow(this);
  else
    return visitor->visitChildren(this);
}

PreconditionAssertionParser::RowContext* PreconditionAssertionParser::row() {
  RowContext *_localctx = _tracker.createInstance<RowContext>(_ctx, getState());
  enterRule(_localctx, 10, PreconditionAssertionParser::RuleRow);
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
    match(PreconditionAssertionParser::T__5);
    setState(54);
    match(PreconditionAssertionParser::REALNUM);
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PreconditionAssertionParser::T__7) {
      setState(55);
      match(PreconditionAssertionParser::T__7);
      setState(56);
      match(PreconditionAssertionParser::REALNUM);
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(62);
    match(PreconditionAssertionParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BListContext ------------------------------------------------------------------

PreconditionAssertionParser::BListContext::BListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PreconditionAssertionParser::BListContext::CID() {
  return getTokens(PreconditionAssertionParser::CID);
}

tree::TerminalNode* PreconditionAssertionParser::BListContext::CID(size_t i) {
  return getToken(PreconditionAssertionParser::CID, i);
}


size_t PreconditionAssertionParser::BListContext::getRuleIndex() const {
  return PreconditionAssertionParser::RuleBList;
}

void PreconditionAssertionParser::BListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBList(this);
}

void PreconditionAssertionParser::BListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBList(this);
}


std::any PreconditionAssertionParser::BListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PreconditionAssertionVisitor*>(visitor))
    return parserVisitor->visitBList(this);
  else
    return visitor->visitChildren(this);
}

PreconditionAssertionParser::BListContext* PreconditionAssertionParser::bList() {
  BListContext *_localctx = _tracker.createInstance<BListContext>(_ctx, getState());
  enterRule(_localctx, 12, PreconditionAssertionParser::RuleBList);
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
    setState(64);
    match(PreconditionAssertionParser::CID);
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PreconditionAssertionParser::T__7) {
      setState(65);
      match(PreconditionAssertionParser::T__7);
      setState(66);
      match(PreconditionAssertionParser::CID);
      setState(71);
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

PreconditionAssertionParser::QListContext::QListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PreconditionAssertionParser::QListContext::QID() {
  return getTokens(PreconditionAssertionParser::QID);
}

tree::TerminalNode* PreconditionAssertionParser::QListContext::QID(size_t i) {
  return getToken(PreconditionAssertionParser::QID, i);
}


size_t PreconditionAssertionParser::QListContext::getRuleIndex() const {
  return PreconditionAssertionParser::RuleQList;
}

void PreconditionAssertionParser::QListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQList(this);
}

void PreconditionAssertionParser::QListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PreconditionAssertionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQList(this);
}


std::any PreconditionAssertionParser::QListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PreconditionAssertionVisitor*>(visitor))
    return parserVisitor->visitQList(this);
  else
    return visitor->visitChildren(this);
}

PreconditionAssertionParser::QListContext* PreconditionAssertionParser::qList() {
  QListContext *_localctx = _tracker.createInstance<QListContext>(_ctx, getState());
  enterRule(_localctx, 14, PreconditionAssertionParser::RuleQList);
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
    setState(72);
    match(PreconditionAssertionParser::QID);
    setState(77);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PreconditionAssertionParser::T__7) {
      setState(73);
      match(PreconditionAssertionParser::T__7);
      setState(74);
      match(PreconditionAssertionParser::QID);
      setState(79);
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

void PreconditionAssertionParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  preconditionassertionParserInitialize();
#else
  ::antlr4::internal::call_once(preconditionassertionParserOnceFlag, preconditionassertionParserInitialize);
#endif
}
