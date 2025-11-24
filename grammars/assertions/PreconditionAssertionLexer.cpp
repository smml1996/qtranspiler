
// Generated from ../grammars/assertions/PreconditionAssertion.g4 by ANTLR 4.13.2


#include "PreconditionAssertionLexer.h"


using namespace antlr4;


namespace {

struct PreconditionAssertionLexerStaticData final {
  PreconditionAssertionLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PreconditionAssertionLexerStaticData(const PreconditionAssertionLexerStaticData&) = delete;
  PreconditionAssertionLexerStaticData(PreconditionAssertionLexerStaticData&&) = delete;
  PreconditionAssertionLexerStaticData& operator=(const PreconditionAssertionLexerStaticData&) = delete;
  PreconditionAssertionLexerStaticData& operator=(PreconditionAssertionLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag preconditionassertionlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PreconditionAssertionLexerStaticData> preconditionassertionlexerLexerStaticData = nullptr;

void preconditionassertionlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (preconditionassertionlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(preconditionassertionlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PreconditionAssertionLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "BINARYSTRING", 
      "REALNUM", "CID", "QID", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,13,85,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,1,0,1,1,1,
  	1,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,4,8,
  	48,8,8,11,8,12,8,49,1,9,4,9,53,8,9,11,9,12,9,54,1,9,1,9,4,9,59,8,9,11,
  	9,12,9,60,3,9,63,8,9,1,10,1,10,5,10,67,8,10,10,10,12,10,70,9,10,1,11,
  	1,11,5,11,74,8,11,10,11,12,11,77,9,11,1,12,4,12,80,8,12,11,12,12,12,81,
  	1,12,1,12,0,0,13,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,
  	23,12,25,13,1,0,2,1,0,48,57,3,0,9,10,13,13,32,32,91,0,1,1,0,0,0,0,3,1,
  	0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,
  	15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,
  	0,0,0,1,27,1,0,0,0,3,29,1,0,0,0,5,33,1,0,0,0,7,36,1,0,0,0,9,38,1,0,0,
  	0,11,40,1,0,0,0,13,42,1,0,0,0,15,44,1,0,0,0,17,47,1,0,0,0,19,52,1,0,0,
  	0,21,64,1,0,0,0,23,71,1,0,0,0,25,79,1,0,0,0,27,28,5,43,0,0,28,2,1,0,0,
  	0,29,30,5,97,0,0,30,31,5,110,0,0,31,32,5,100,0,0,32,4,1,0,0,0,33,34,5,
  	80,0,0,34,35,5,40,0,0,35,6,1,0,0,0,36,37,5,41,0,0,37,8,1,0,0,0,38,39,
  	5,61,0,0,39,10,1,0,0,0,40,41,5,91,0,0,41,12,1,0,0,0,42,43,5,93,0,0,43,
  	14,1,0,0,0,44,45,5,44,0,0,45,16,1,0,0,0,46,48,2,48,49,0,47,46,1,0,0,0,
  	48,49,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,18,1,0,0,0,51,53,7,0,0,0,
  	52,51,1,0,0,0,53,54,1,0,0,0,54,52,1,0,0,0,54,55,1,0,0,0,55,62,1,0,0,0,
  	56,58,5,46,0,0,57,59,7,0,0,0,58,57,1,0,0,0,59,60,1,0,0,0,60,58,1,0,0,
  	0,60,61,1,0,0,0,61,63,1,0,0,0,62,56,1,0,0,0,62,63,1,0,0,0,63,20,1,0,0,
  	0,64,68,5,120,0,0,65,67,7,0,0,0,66,65,1,0,0,0,67,70,1,0,0,0,68,66,1,0,
  	0,0,68,69,1,0,0,0,69,22,1,0,0,0,70,68,1,0,0,0,71,75,5,113,0,0,72,74,7,
  	0,0,0,73,72,1,0,0,0,74,77,1,0,0,0,75,73,1,0,0,0,75,76,1,0,0,0,76,24,1,
  	0,0,0,77,75,1,0,0,0,78,80,7,1,0,0,79,78,1,0,0,0,80,81,1,0,0,0,81,79,1,
  	0,0,0,81,82,1,0,0,0,82,83,1,0,0,0,83,84,6,12,0,0,84,26,1,0,0,0,8,0,49,
  	54,60,62,68,75,81,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  preconditionassertionlexerLexerStaticData = std::move(staticData);
}

}

PreconditionAssertionLexer::PreconditionAssertionLexer(CharStream *input) : Lexer(input) {
  PreconditionAssertionLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *preconditionassertionlexerLexerStaticData->atn, preconditionassertionlexerLexerStaticData->decisionToDFA, preconditionassertionlexerLexerStaticData->sharedContextCache);
}

PreconditionAssertionLexer::~PreconditionAssertionLexer() {
  delete _interpreter;
}

std::string PreconditionAssertionLexer::getGrammarFileName() const {
  return "PreconditionAssertion.g4";
}

const std::vector<std::string>& PreconditionAssertionLexer::getRuleNames() const {
  return preconditionassertionlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& PreconditionAssertionLexer::getChannelNames() const {
  return preconditionassertionlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& PreconditionAssertionLexer::getModeNames() const {
  return preconditionassertionlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& PreconditionAssertionLexer::getVocabulary() const {
  return preconditionassertionlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PreconditionAssertionLexer::getSerializedATN() const {
  return preconditionassertionlexerLexerStaticData->serializedATN;
}

const atn::ATN& PreconditionAssertionLexer::getATN() const {
  return *preconditionassertionlexerLexerStaticData->atn;
}




void PreconditionAssertionLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  preconditionassertionlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(preconditionassertionlexerLexerOnceFlag, preconditionassertionlexerLexerInitialize);
#endif
}
