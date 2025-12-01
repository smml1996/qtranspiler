
// Generated from grammars/assertions/Assertion.g4 by ANTLR 4.13.2


#include "AssertionLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct AssertionLexerStaticData final {
  AssertionLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AssertionLexerStaticData(const AssertionLexerStaticData&) = delete;
  AssertionLexerStaticData(AssertionLexerStaticData&&) = delete;
  AssertionLexerStaticData& operator=(const AssertionLexerStaticData&) = delete;
  AssertionLexerStaticData& operator=(AssertionLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag assertionlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<AssertionLexerStaticData> assertionlexerLexerStaticData = nullptr;

void assertionlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (assertionlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(assertionlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AssertionLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "BINARYSTRING", "REALNUM", "CID", "QID", 
      "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,17,100,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,
  	1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,
  	11,1,12,4,12,65,8,12,11,12,12,12,66,1,13,4,13,70,8,13,11,13,12,13,71,
  	1,13,1,13,4,13,76,8,13,11,13,12,13,77,3,13,80,8,13,1,14,1,14,4,14,84,
  	8,14,11,14,12,14,85,1,15,1,15,4,15,90,8,15,11,15,12,15,91,1,16,4,16,95,
  	8,16,11,16,12,16,96,1,16,1,16,0,0,17,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,
  	8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,1,0,2,1,0,48,57,
  	3,0,9,10,13,13,32,32,106,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,
  	0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,
  	19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,
  	0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,1,35,1,0,0,0,3,38,1,0,0,0,5,42,1,0,0,
  	0,7,44,1,0,0,0,9,46,1,0,0,0,11,48,1,0,0,0,13,50,1,0,0,0,15,52,1,0,0,0,
  	17,55,1,0,0,0,19,57,1,0,0,0,21,59,1,0,0,0,23,61,1,0,0,0,25,64,1,0,0,0,
  	27,69,1,0,0,0,29,81,1,0,0,0,31,87,1,0,0,0,33,94,1,0,0,0,35,36,5,111,0,
  	0,36,37,5,114,0,0,37,2,1,0,0,0,38,39,5,97,0,0,39,40,5,110,0,0,40,41,5,
  	100,0,0,41,4,1,0,0,0,42,43,5,43,0,0,43,6,1,0,0,0,44,45,5,33,0,0,45,8,
  	1,0,0,0,46,47,5,40,0,0,47,10,1,0,0,0,48,49,5,41,0,0,49,12,1,0,0,0,50,
  	51,5,80,0,0,51,14,1,0,0,0,52,53,5,62,0,0,53,54,5,61,0,0,54,16,1,0,0,0,
  	55,56,5,61,0,0,56,18,1,0,0,0,57,58,5,91,0,0,58,20,1,0,0,0,59,60,5,44,
  	0,0,60,22,1,0,0,0,61,62,5,93,0,0,62,24,1,0,0,0,63,65,2,48,49,0,64,63,
  	1,0,0,0,65,66,1,0,0,0,66,64,1,0,0,0,66,67,1,0,0,0,67,26,1,0,0,0,68,70,
  	7,0,0,0,69,68,1,0,0,0,70,71,1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,72,79,
  	1,0,0,0,73,75,5,46,0,0,74,76,7,0,0,0,75,74,1,0,0,0,76,77,1,0,0,0,77,75,
  	1,0,0,0,77,78,1,0,0,0,78,80,1,0,0,0,79,73,1,0,0,0,79,80,1,0,0,0,80,28,
  	1,0,0,0,81,83,5,120,0,0,82,84,7,0,0,0,83,82,1,0,0,0,84,85,1,0,0,0,85,
  	83,1,0,0,0,85,86,1,0,0,0,86,30,1,0,0,0,87,89,5,113,0,0,88,90,7,0,0,0,
  	89,88,1,0,0,0,90,91,1,0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,32,1,0,0,0,
  	93,95,7,1,0,0,94,93,1,0,0,0,95,96,1,0,0,0,96,94,1,0,0,0,96,97,1,0,0,0,
  	97,98,1,0,0,0,98,99,6,16,0,0,99,34,1,0,0,0,8,0,66,71,77,79,85,91,96,1,
  	6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  assertionlexerLexerStaticData = std::move(staticData);
}

}

AssertionLexer::AssertionLexer(CharStream *input) : Lexer(input) {
  AssertionLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *assertionlexerLexerStaticData->atn, assertionlexerLexerStaticData->decisionToDFA, assertionlexerLexerStaticData->sharedContextCache);
}

AssertionLexer::~AssertionLexer() {
  delete _interpreter;
}

std::string AssertionLexer::getGrammarFileName() const {
  return "Assertion.g4";
}

const std::vector<std::string>& AssertionLexer::getRuleNames() const {
  return assertionlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& AssertionLexer::getChannelNames() const {
  return assertionlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& AssertionLexer::getModeNames() const {
  return assertionlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& AssertionLexer::getVocabulary() const {
  return assertionlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AssertionLexer::getSerializedATN() const {
  return assertionlexerLexerStaticData->serializedATN;
}

const atn::ATN& AssertionLexer::getATN() const {
  return *assertionlexerLexerStaticData->atn;
}




void AssertionLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  assertionlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(assertionlexerLexerOnceFlag, assertionlexerLexerInitialize);
#endif
}
