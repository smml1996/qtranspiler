
// Generated from ../grammars/PL/ProgrammingLanguage.g4 by ANTLR 4.13.2


#include "ProgrammingLanguageListener.h"
#include "ProgrammingLanguageVisitor.h"

#include "ProgrammingLanguageParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ProgrammingLanguageParserStaticData final {
  ProgrammingLanguageParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ProgrammingLanguageParserStaticData(const ProgrammingLanguageParserStaticData&) = delete;
  ProgrammingLanguageParserStaticData(ProgrammingLanguageParserStaticData&&) = delete;
  ProgrammingLanguageParserStaticData& operator=(const ProgrammingLanguageParserStaticData&) = delete;
  ProgrammingLanguageParserStaticData& operator=(ProgrammingLanguageParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag programminglanguageParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ProgrammingLanguageParserStaticData> programminglanguageParserStaticData = nullptr;

void programminglanguageParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (programminglanguageParserStaticData != nullptr) {
    return;
  }
#else
  assert(programminglanguageParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ProgrammingLanguageParserStaticData>(
    std::vector<std::string>{
      "language", "program", "classical_statement", "qlist"
    },
    std::vector<std::string>{
      "", "':='", "','", "'measure'", "'skip'", "';'", "'if'", "'else'", 
      "'('", "')'", "'{'", "'}'", "'['", "']'", "'%'"
    },
    std::vector<std::string>{
      "", "", "", "MEASURE", "SKIPKW", "SEMICOLON", "IF", "ELSE", "LPAREN", 
      "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "PERCENT", "WS", 
      "UNITARY", "REALNUM", "CID", "QID"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,19,76,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,0,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,44,8,1,1,1,1,1,1,1,5,1,
  	49,8,1,10,1,12,1,52,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,3,2,66,8,2,1,3,1,3,1,3,5,3,71,8,3,10,3,12,3,74,9,3,1,3,0,1,2,4,0,2,
  	4,6,0,0,79,0,8,1,0,0,0,2,43,1,0,0,0,4,65,1,0,0,0,6,67,1,0,0,0,8,9,3,2,
  	1,0,9,10,5,0,0,1,10,1,1,0,0,0,11,12,6,1,-1,0,12,44,5,4,0,0,13,44,3,4,
  	2,0,14,15,5,16,0,0,15,16,5,8,0,0,16,17,5,12,0,0,17,18,3,6,3,0,18,19,5,
  	13,0,0,19,20,5,9,0,0,20,44,1,0,0,0,21,22,5,6,0,0,22,23,5,8,0,0,23,24,
  	5,17,0,0,24,25,5,9,0,0,25,26,5,10,0,0,26,27,3,2,1,0,27,28,5,11,0,0,28,
  	29,5,7,0,0,29,30,5,10,0,0,30,31,3,2,1,0,31,32,5,11,0,0,32,44,1,0,0,0,
  	33,34,5,10,0,0,34,35,3,2,1,0,35,36,5,11,0,0,36,37,5,14,0,0,37,38,5,17,
  	0,0,38,39,5,14,0,0,39,40,5,10,0,0,40,41,3,2,1,0,41,42,5,11,0,0,42,44,
  	1,0,0,0,43,11,1,0,0,0,43,13,1,0,0,0,43,14,1,0,0,0,43,21,1,0,0,0,43,33,
  	1,0,0,0,44,50,1,0,0,0,45,46,10,3,0,0,46,47,5,5,0,0,47,49,3,2,1,4,48,45,
  	1,0,0,0,49,52,1,0,0,0,50,48,1,0,0,0,50,51,1,0,0,0,51,3,1,0,0,0,52,50,
  	1,0,0,0,53,54,5,18,0,0,54,55,5,1,0,0,55,66,5,17,0,0,56,57,5,18,0,0,57,
  	58,5,1,0,0,58,66,5,18,0,0,59,60,5,18,0,0,60,61,5,1,0,0,61,62,5,3,0,0,
  	62,63,5,8,0,0,63,64,5,19,0,0,64,66,5,9,0,0,65,53,1,0,0,0,65,56,1,0,0,
  	0,65,59,1,0,0,0,66,5,1,0,0,0,67,72,5,19,0,0,68,69,5,2,0,0,69,71,5,19,
  	0,0,70,68,1,0,0,0,71,74,1,0,0,0,72,70,1,0,0,0,72,73,1,0,0,0,73,7,1,0,
  	0,0,74,72,1,0,0,0,4,43,50,65,72
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  programminglanguageParserStaticData = std::move(staticData);
}

}

ProgrammingLanguageParser::ProgrammingLanguageParser(TokenStream *input) : ProgrammingLanguageParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ProgrammingLanguageParser::ProgrammingLanguageParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ProgrammingLanguageParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *programminglanguageParserStaticData->atn, programminglanguageParserStaticData->decisionToDFA, programminglanguageParserStaticData->sharedContextCache, options);
}

ProgrammingLanguageParser::~ProgrammingLanguageParser() {
  delete _interpreter;
}

const atn::ATN& ProgrammingLanguageParser::getATN() const {
  return *programminglanguageParserStaticData->atn;
}

std::string ProgrammingLanguageParser::getGrammarFileName() const {
  return "ProgrammingLanguage.g4";
}

const std::vector<std::string>& ProgrammingLanguageParser::getRuleNames() const {
  return programminglanguageParserStaticData->ruleNames;
}

const dfa::Vocabulary& ProgrammingLanguageParser::getVocabulary() const {
  return programminglanguageParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ProgrammingLanguageParser::getSerializedATN() const {
  return programminglanguageParserStaticData->serializedATN;
}


//----------------- LanguageContext ------------------------------------------------------------------

ProgrammingLanguageParser::LanguageContext::LanguageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProgrammingLanguageParser::ProgramContext* ProgrammingLanguageParser::LanguageContext::program() {
  return getRuleContext<ProgrammingLanguageParser::ProgramContext>(0);
}

tree::TerminalNode* ProgrammingLanguageParser::LanguageContext::EOF() {
  return getToken(ProgrammingLanguageParser::EOF, 0);
}


size_t ProgrammingLanguageParser::LanguageContext::getRuleIndex() const {
  return ProgrammingLanguageParser::RuleLanguage;
}

void ProgrammingLanguageParser::LanguageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLanguage(this);
}

void ProgrammingLanguageParser::LanguageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLanguage(this);
}


std::any ProgrammingLanguageParser::LanguageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitLanguage(this);
  else
    return visitor->visitChildren(this);
}

ProgrammingLanguageParser::LanguageContext* ProgrammingLanguageParser::language() {
  LanguageContext *_localctx = _tracker.createInstance<LanguageContext>(_ctx, getState());
  enterRule(_localctx, 0, ProgrammingLanguageParser::RuleLanguage);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    program(0);
    setState(9);
    match(ProgrammingLanguageParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

ProgrammingLanguageParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ProgrammingLanguageParser::ProgramContext::getRuleIndex() const {
  return ProgrammingLanguageParser::RuleProgram;
}

void ProgrammingLanguageParser::ProgramContext::copyFrom(ProgramContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnitaryContext ------------------------------------------------------------------

tree::TerminalNode* ProgrammingLanguageParser::UnitaryContext::UNITARY() {
  return getToken(ProgrammingLanguageParser::UNITARY, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::UnitaryContext::LPAREN() {
  return getToken(ProgrammingLanguageParser::LPAREN, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::UnitaryContext::LBRACKET() {
  return getToken(ProgrammingLanguageParser::LBRACKET, 0);
}

ProgrammingLanguageParser::QlistContext* ProgrammingLanguageParser::UnitaryContext::qlist() {
  return getRuleContext<ProgrammingLanguageParser::QlistContext>(0);
}

tree::TerminalNode* ProgrammingLanguageParser::UnitaryContext::RBRACKET() {
  return getToken(ProgrammingLanguageParser::RBRACKET, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::UnitaryContext::RPAREN() {
  return getToken(ProgrammingLanguageParser::RPAREN, 0);
}

ProgrammingLanguageParser::UnitaryContext::UnitaryContext(ProgramContext *ctx) { copyFrom(ctx); }

void ProgrammingLanguageParser::UnitaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnitary(this);
}
void ProgrammingLanguageParser::UnitaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnitary(this);
}

std::any ProgrammingLanguageParser::UnitaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitUnitary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProbContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> ProgrammingLanguageParser::ProbContext::LBRACE() {
  return getTokens(ProgrammingLanguageParser::LBRACE);
}

tree::TerminalNode* ProgrammingLanguageParser::ProbContext::LBRACE(size_t i) {
  return getToken(ProgrammingLanguageParser::LBRACE, i);
}

std::vector<ProgrammingLanguageParser::ProgramContext *> ProgrammingLanguageParser::ProbContext::program() {
  return getRuleContexts<ProgrammingLanguageParser::ProgramContext>();
}

ProgrammingLanguageParser::ProgramContext* ProgrammingLanguageParser::ProbContext::program(size_t i) {
  return getRuleContext<ProgrammingLanguageParser::ProgramContext>(i);
}

std::vector<tree::TerminalNode *> ProgrammingLanguageParser::ProbContext::RBRACE() {
  return getTokens(ProgrammingLanguageParser::RBRACE);
}

tree::TerminalNode* ProgrammingLanguageParser::ProbContext::RBRACE(size_t i) {
  return getToken(ProgrammingLanguageParser::RBRACE, i);
}

std::vector<tree::TerminalNode *> ProgrammingLanguageParser::ProbContext::PERCENT() {
  return getTokens(ProgrammingLanguageParser::PERCENT);
}

tree::TerminalNode* ProgrammingLanguageParser::ProbContext::PERCENT(size_t i) {
  return getToken(ProgrammingLanguageParser::PERCENT, i);
}

tree::TerminalNode* ProgrammingLanguageParser::ProbContext::REALNUM() {
  return getToken(ProgrammingLanguageParser::REALNUM, 0);
}

ProgrammingLanguageParser::ProbContext::ProbContext(ProgramContext *ctx) { copyFrom(ctx); }

void ProgrammingLanguageParser::ProbContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProb(this);
}
void ProgrammingLanguageParser::ProbContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProb(this);
}

std::any ProgrammingLanguageParser::ProbContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitProb(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SkipContext ------------------------------------------------------------------

tree::TerminalNode* ProgrammingLanguageParser::SkipContext::SKIPKW() {
  return getToken(ProgrammingLanguageParser::SKIPKW, 0);
}

ProgrammingLanguageParser::SkipContext::SkipContext(ProgramContext *ctx) { copyFrom(ctx); }

void ProgrammingLanguageParser::SkipContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSkip(this);
}
void ProgrammingLanguageParser::SkipContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSkip(this);
}

std::any ProgrammingLanguageParser::SkipContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitSkip(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassicalContext ------------------------------------------------------------------

ProgrammingLanguageParser::Classical_statementContext* ProgrammingLanguageParser::ClassicalContext::classical_statement() {
  return getRuleContext<ProgrammingLanguageParser::Classical_statementContext>(0);
}

ProgrammingLanguageParser::ClassicalContext::ClassicalContext(ProgramContext *ctx) { copyFrom(ctx); }

void ProgrammingLanguageParser::ClassicalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassical(this);
}
void ProgrammingLanguageParser::ClassicalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassical(this);
}

std::any ProgrammingLanguageParser::ClassicalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitClassical(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfContext ------------------------------------------------------------------

tree::TerminalNode* ProgrammingLanguageParser::IfContext::IF() {
  return getToken(ProgrammingLanguageParser::IF, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::IfContext::LPAREN() {
  return getToken(ProgrammingLanguageParser::LPAREN, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::IfContext::REALNUM() {
  return getToken(ProgrammingLanguageParser::REALNUM, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::IfContext::RPAREN() {
  return getToken(ProgrammingLanguageParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> ProgrammingLanguageParser::IfContext::LBRACE() {
  return getTokens(ProgrammingLanguageParser::LBRACE);
}

tree::TerminalNode* ProgrammingLanguageParser::IfContext::LBRACE(size_t i) {
  return getToken(ProgrammingLanguageParser::LBRACE, i);
}

std::vector<ProgrammingLanguageParser::ProgramContext *> ProgrammingLanguageParser::IfContext::program() {
  return getRuleContexts<ProgrammingLanguageParser::ProgramContext>();
}

ProgrammingLanguageParser::ProgramContext* ProgrammingLanguageParser::IfContext::program(size_t i) {
  return getRuleContext<ProgrammingLanguageParser::ProgramContext>(i);
}

std::vector<tree::TerminalNode *> ProgrammingLanguageParser::IfContext::RBRACE() {
  return getTokens(ProgrammingLanguageParser::RBRACE);
}

tree::TerminalNode* ProgrammingLanguageParser::IfContext::RBRACE(size_t i) {
  return getToken(ProgrammingLanguageParser::RBRACE, i);
}

tree::TerminalNode* ProgrammingLanguageParser::IfContext::ELSE() {
  return getToken(ProgrammingLanguageParser::ELSE, 0);
}

ProgrammingLanguageParser::IfContext::IfContext(ProgramContext *ctx) { copyFrom(ctx); }

void ProgrammingLanguageParser::IfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf(this);
}
void ProgrammingLanguageParser::IfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf(this);
}

std::any ProgrammingLanguageParser::IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitIf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SeqContext ------------------------------------------------------------------

std::vector<ProgrammingLanguageParser::ProgramContext *> ProgrammingLanguageParser::SeqContext::program() {
  return getRuleContexts<ProgrammingLanguageParser::ProgramContext>();
}

ProgrammingLanguageParser::ProgramContext* ProgrammingLanguageParser::SeqContext::program(size_t i) {
  return getRuleContext<ProgrammingLanguageParser::ProgramContext>(i);
}

tree::TerminalNode* ProgrammingLanguageParser::SeqContext::SEMICOLON() {
  return getToken(ProgrammingLanguageParser::SEMICOLON, 0);
}

ProgrammingLanguageParser::SeqContext::SeqContext(ProgramContext *ctx) { copyFrom(ctx); }

void ProgrammingLanguageParser::SeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSeq(this);
}
void ProgrammingLanguageParser::SeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSeq(this);
}

std::any ProgrammingLanguageParser::SeqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitSeq(this);
  else
    return visitor->visitChildren(this);
}

ProgrammingLanguageParser::ProgramContext* ProgrammingLanguageParser::program() {
   return program(0);
}

ProgrammingLanguageParser::ProgramContext* ProgrammingLanguageParser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ProgrammingLanguageParser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  ProgrammingLanguageParser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ProgrammingLanguageParser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(43);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ProgrammingLanguageParser::SKIPKW: {
        _localctx = _tracker.createInstance<SkipContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(12);
        match(ProgrammingLanguageParser::SKIPKW);
        break;
      }

      case ProgrammingLanguageParser::CID: {
        _localctx = _tracker.createInstance<ClassicalContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(13);
        classical_statement();
        break;
      }

      case ProgrammingLanguageParser::UNITARY: {
        _localctx = _tracker.createInstance<UnitaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(14);
        match(ProgrammingLanguageParser::UNITARY);
        setState(15);
        match(ProgrammingLanguageParser::LPAREN);
        setState(16);
        match(ProgrammingLanguageParser::LBRACKET);
        setState(17);
        qlist();
        setState(18);
        match(ProgrammingLanguageParser::RBRACKET);
        setState(19);
        match(ProgrammingLanguageParser::RPAREN);
        break;
      }

      case ProgrammingLanguageParser::IF: {
        _localctx = _tracker.createInstance<IfContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(21);
        match(ProgrammingLanguageParser::IF);
        setState(22);
        match(ProgrammingLanguageParser::LPAREN);
        setState(23);
        match(ProgrammingLanguageParser::REALNUM);
        setState(24);
        match(ProgrammingLanguageParser::RPAREN);
        setState(25);
        match(ProgrammingLanguageParser::LBRACE);
        setState(26);
        program(0);
        setState(27);
        match(ProgrammingLanguageParser::RBRACE);
        setState(28);
        match(ProgrammingLanguageParser::ELSE);
        setState(29);
        match(ProgrammingLanguageParser::LBRACE);
        setState(30);
        program(0);
        setState(31);
        match(ProgrammingLanguageParser::RBRACE);
        break;
      }

      case ProgrammingLanguageParser::LBRACE: {
        _localctx = _tracker.createInstance<ProbContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(33);
        match(ProgrammingLanguageParser::LBRACE);
        setState(34);
        program(0);
        setState(35);
        match(ProgrammingLanguageParser::RBRACE);
        setState(36);
        match(ProgrammingLanguageParser::PERCENT);
        setState(37);
        match(ProgrammingLanguageParser::REALNUM);
        setState(38);
        match(ProgrammingLanguageParser::PERCENT);
        setState(39);
        match(ProgrammingLanguageParser::LBRACE);
        setState(40);
        program(0);
        setState(41);
        match(ProgrammingLanguageParser::RBRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(50);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<SeqContext>(_tracker.createInstance<ProgramContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleProgram);
        setState(45);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(46);
        match(ProgrammingLanguageParser::SEMICOLON);
        setState(47);
        program(4); 
      }
      setState(52);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Classical_statementContext ------------------------------------------------------------------

ProgrammingLanguageParser::Classical_statementContext::Classical_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ProgrammingLanguageParser::Classical_statementContext::getRuleIndex() const {
  return ProgrammingLanguageParser::RuleClassical_statement;
}

void ProgrammingLanguageParser::Classical_statementContext::copyFrom(Classical_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AssignMeasureContext ------------------------------------------------------------------

tree::TerminalNode* ProgrammingLanguageParser::AssignMeasureContext::CID() {
  return getToken(ProgrammingLanguageParser::CID, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::AssignMeasureContext::MEASURE() {
  return getToken(ProgrammingLanguageParser::MEASURE, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::AssignMeasureContext::LPAREN() {
  return getToken(ProgrammingLanguageParser::LPAREN, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::AssignMeasureContext::QID() {
  return getToken(ProgrammingLanguageParser::QID, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::AssignMeasureContext::RPAREN() {
  return getToken(ProgrammingLanguageParser::RPAREN, 0);
}

ProgrammingLanguageParser::AssignMeasureContext::AssignMeasureContext(Classical_statementContext *ctx) { copyFrom(ctx); }

void ProgrammingLanguageParser::AssignMeasureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignMeasure(this);
}
void ProgrammingLanguageParser::AssignMeasureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignMeasure(this);
}

std::any ProgrammingLanguageParser::AssignMeasureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitAssignMeasure(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstAssignContext ------------------------------------------------------------------

tree::TerminalNode* ProgrammingLanguageParser::ConstAssignContext::CID() {
  return getToken(ProgrammingLanguageParser::CID, 0);
}

tree::TerminalNode* ProgrammingLanguageParser::ConstAssignContext::REALNUM() {
  return getToken(ProgrammingLanguageParser::REALNUM, 0);
}

ProgrammingLanguageParser::ConstAssignContext::ConstAssignContext(Classical_statementContext *ctx) { copyFrom(ctx); }

void ProgrammingLanguageParser::ConstAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstAssign(this);
}
void ProgrammingLanguageParser::ConstAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstAssign(this);
}

std::any ProgrammingLanguageParser::ConstAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitConstAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignCopyContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> ProgrammingLanguageParser::AssignCopyContext::CID() {
  return getTokens(ProgrammingLanguageParser::CID);
}

tree::TerminalNode* ProgrammingLanguageParser::AssignCopyContext::CID(size_t i) {
  return getToken(ProgrammingLanguageParser::CID, i);
}

ProgrammingLanguageParser::AssignCopyContext::AssignCopyContext(Classical_statementContext *ctx) { copyFrom(ctx); }

void ProgrammingLanguageParser::AssignCopyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignCopy(this);
}
void ProgrammingLanguageParser::AssignCopyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignCopy(this);
}

std::any ProgrammingLanguageParser::AssignCopyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitAssignCopy(this);
  else
    return visitor->visitChildren(this);
}
ProgrammingLanguageParser::Classical_statementContext* ProgrammingLanguageParser::classical_statement() {
  Classical_statementContext *_localctx = _tracker.createInstance<Classical_statementContext>(_ctx, getState());
  enterRule(_localctx, 4, ProgrammingLanguageParser::RuleClassical_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(65);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ProgrammingLanguageParser::ConstAssignContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(53);
      match(ProgrammingLanguageParser::CID);
      setState(54);
      match(ProgrammingLanguageParser::T__0);
      setState(55);
      match(ProgrammingLanguageParser::REALNUM);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ProgrammingLanguageParser::AssignCopyContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(56);
      match(ProgrammingLanguageParser::CID);
      setState(57);
      match(ProgrammingLanguageParser::T__0);
      setState(58);
      match(ProgrammingLanguageParser::CID);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ProgrammingLanguageParser::AssignMeasureContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(59);
      match(ProgrammingLanguageParser::CID);
      setState(60);
      match(ProgrammingLanguageParser::T__0);
      setState(61);
      match(ProgrammingLanguageParser::MEASURE);
      setState(62);
      match(ProgrammingLanguageParser::LPAREN);
      setState(63);
      match(ProgrammingLanguageParser::QID);
      setState(64);
      match(ProgrammingLanguageParser::RPAREN);
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

//----------------- QlistContext ------------------------------------------------------------------

ProgrammingLanguageParser::QlistContext::QlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ProgrammingLanguageParser::QlistContext::QID() {
  return getTokens(ProgrammingLanguageParser::QID);
}

tree::TerminalNode* ProgrammingLanguageParser::QlistContext::QID(size_t i) {
  return getToken(ProgrammingLanguageParser::QID, i);
}


size_t ProgrammingLanguageParser::QlistContext::getRuleIndex() const {
  return ProgrammingLanguageParser::RuleQlist;
}

void ProgrammingLanguageParser::QlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQlist(this);
}

void ProgrammingLanguageParser::QlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProgrammingLanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQlist(this);
}


std::any ProgrammingLanguageParser::QlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ProgrammingLanguageVisitor*>(visitor))
    return parserVisitor->visitQlist(this);
  else
    return visitor->visitChildren(this);
}

ProgrammingLanguageParser::QlistContext* ProgrammingLanguageParser::qlist() {
  QlistContext *_localctx = _tracker.createInstance<QlistContext>(_ctx, getState());
  enterRule(_localctx, 6, ProgrammingLanguageParser::RuleQlist);
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
    setState(67);
    match(ProgrammingLanguageParser::QID);
    setState(72);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProgrammingLanguageParser::T__1) {
      setState(68);
      match(ProgrammingLanguageParser::T__1);
      setState(69);
      match(ProgrammingLanguageParser::QID);
      setState(74);
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

bool ProgrammingLanguageParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ProgrammingLanguageParser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void ProgrammingLanguageParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  programminglanguageParserInitialize();
#else
  ::antlr4::internal::call_once(programminglanguageParserOnceFlag, programminglanguageParserInitialize);
#endif
}
