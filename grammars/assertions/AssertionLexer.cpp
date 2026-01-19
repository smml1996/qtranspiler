
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
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "MUL", 
      "RELOP", "SIGN", "REALNUM", "BINARYSTRING", "CID", "QID", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'or'", "'and'", "'+'", "'!'", "'('", "')'", "'Tr'", "'P'", "'='", 
      "'['", "','", "']'", "'i'", "'[['", "';'", "']]'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "MUL", "RELOP", "SIGN", "REALNUM", "BINARYSTRING", "CID", "QID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,24,136,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,
  	1,4,1,4,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,
  	11,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,17,1,
  	17,1,17,1,17,1,17,3,17,95,8,17,1,18,1,18,1,19,4,19,100,8,19,11,19,12,
  	19,101,1,19,1,19,4,19,106,8,19,11,19,12,19,107,3,19,110,8,19,1,20,1,20,
  	4,20,114,8,20,11,20,12,20,115,1,21,1,21,4,21,120,8,21,11,21,12,21,121,
  	1,22,1,22,4,22,126,8,22,11,22,12,22,127,1,23,4,23,131,8,23,11,23,12,23,
  	132,1,23,1,23,0,0,24,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,
  	11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,
  	45,23,47,24,1,0,4,2,0,42,42,183,183,2,0,43,43,45,45,1,0,48,57,3,0,9,10,
  	13,13,32,32,144,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,
  	0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,
  	0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,
  	31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,
  	0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,1,49,1,0,0,0,3,52,1,0,0,
  	0,5,56,1,0,0,0,7,58,1,0,0,0,9,60,1,0,0,0,11,62,1,0,0,0,13,64,1,0,0,0,
  	15,67,1,0,0,0,17,69,1,0,0,0,19,71,1,0,0,0,21,73,1,0,0,0,23,75,1,0,0,0,
  	25,77,1,0,0,0,27,79,1,0,0,0,29,82,1,0,0,0,31,84,1,0,0,0,33,87,1,0,0,0,
  	35,94,1,0,0,0,37,96,1,0,0,0,39,99,1,0,0,0,41,111,1,0,0,0,43,117,1,0,0,
  	0,45,123,1,0,0,0,47,130,1,0,0,0,49,50,5,111,0,0,50,51,5,114,0,0,51,2,
  	1,0,0,0,52,53,5,97,0,0,53,54,5,110,0,0,54,55,5,100,0,0,55,4,1,0,0,0,56,
  	57,5,43,0,0,57,6,1,0,0,0,58,59,5,33,0,0,59,8,1,0,0,0,60,61,5,40,0,0,61,
  	10,1,0,0,0,62,63,5,41,0,0,63,12,1,0,0,0,64,65,5,84,0,0,65,66,5,114,0,
  	0,66,14,1,0,0,0,67,68,5,80,0,0,68,16,1,0,0,0,69,70,5,61,0,0,70,18,1,0,
  	0,0,71,72,5,91,0,0,72,20,1,0,0,0,73,74,5,44,0,0,74,22,1,0,0,0,75,76,5,
  	93,0,0,76,24,1,0,0,0,77,78,5,105,0,0,78,26,1,0,0,0,79,80,5,91,0,0,80,
  	81,5,91,0,0,81,28,1,0,0,0,82,83,5,59,0,0,83,30,1,0,0,0,84,85,5,93,0,0,
  	85,86,5,93,0,0,86,32,1,0,0,0,87,88,7,0,0,0,88,34,1,0,0,0,89,90,5,62,0,
  	0,90,95,5,61,0,0,91,92,5,60,0,0,92,95,5,61,0,0,93,95,2,60,62,0,94,89,
  	1,0,0,0,94,91,1,0,0,0,94,93,1,0,0,0,95,36,1,0,0,0,96,97,7,1,0,0,97,38,
  	1,0,0,0,98,100,7,2,0,0,99,98,1,0,0,0,100,101,1,0,0,0,101,99,1,0,0,0,101,
  	102,1,0,0,0,102,109,1,0,0,0,103,105,5,46,0,0,104,106,7,2,0,0,105,104,
  	1,0,0,0,106,107,1,0,0,0,107,105,1,0,0,0,107,108,1,0,0,0,108,110,1,0,0,
  	0,109,103,1,0,0,0,109,110,1,0,0,0,110,40,1,0,0,0,111,113,5,98,0,0,112,
  	114,2,48,49,0,113,112,1,0,0,0,114,115,1,0,0,0,115,113,1,0,0,0,115,116,
  	1,0,0,0,116,42,1,0,0,0,117,119,5,120,0,0,118,120,7,2,0,0,119,118,1,0,
  	0,0,120,121,1,0,0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,44,1,0,0,0,123,
  	125,5,113,0,0,124,126,7,2,0,0,125,124,1,0,0,0,126,127,1,0,0,0,127,125,
  	1,0,0,0,127,128,1,0,0,0,128,46,1,0,0,0,129,131,7,3,0,0,130,129,1,0,0,
  	0,131,132,1,0,0,0,132,130,1,0,0,0,132,133,1,0,0,0,133,134,1,0,0,0,134,
  	135,6,23,0,0,135,48,1,0,0,0,9,0,94,101,107,109,115,121,127,132,1,6,0,
  	0
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
