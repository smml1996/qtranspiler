
// Generated from ../grammars/PL/ProgrammingLanguage.g4 by ANTLR 4.13.2


#include "ProgrammingLanguageLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ProgrammingLanguageLexerStaticData final {
  ProgrammingLanguageLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ProgrammingLanguageLexerStaticData(const ProgrammingLanguageLexerStaticData&) = delete;
  ProgrammingLanguageLexerStaticData(ProgrammingLanguageLexerStaticData&&) = delete;
  ProgrammingLanguageLexerStaticData& operator=(const ProgrammingLanguageLexerStaticData&) = delete;
  ProgrammingLanguageLexerStaticData& operator=(ProgrammingLanguageLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag programminglanguagelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ProgrammingLanguageLexerStaticData> programminglanguagelexerLexerStaticData = nullptr;

void programminglanguagelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (programminglanguagelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(programminglanguagelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ProgrammingLanguageLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "MEASURE", "SKIPKW", "SEMICOLON", "IF", "ELSE", "LPAREN", 
      "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "PERCENT", "WS", 
      "UNITARY", "REALNUM", "CID", "QID"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,19,119,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,0,1,1,1,1,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,
  	6,1,6,1,6,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,
  	12,1,13,1,13,1,14,4,14,83,8,14,11,14,12,14,84,1,14,1,14,1,15,1,15,1,15,
  	1,15,3,15,93,8,15,1,16,4,16,96,8,16,11,16,12,16,97,1,16,1,16,4,16,102,
  	8,16,11,16,12,16,103,3,16,106,8,16,1,17,1,17,4,17,110,8,17,11,17,12,17,
  	111,1,18,1,18,4,18,116,8,18,11,18,12,18,117,0,0,19,1,1,3,2,5,3,7,4,9,
  	5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,
  	35,18,37,19,1,0,2,3,0,9,10,13,13,32,32,1,0,48,57,126,0,1,1,0,0,0,0,3,
  	1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,
  	0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,
  	1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,
  	0,0,0,37,1,0,0,0,1,39,1,0,0,0,3,42,1,0,0,0,5,44,1,0,0,0,7,52,1,0,0,0,
  	9,57,1,0,0,0,11,59,1,0,0,0,13,62,1,0,0,0,15,67,1,0,0,0,17,69,1,0,0,0,
  	19,71,1,0,0,0,21,73,1,0,0,0,23,75,1,0,0,0,25,77,1,0,0,0,27,79,1,0,0,0,
  	29,82,1,0,0,0,31,92,1,0,0,0,33,95,1,0,0,0,35,107,1,0,0,0,37,113,1,0,0,
  	0,39,40,5,58,0,0,40,41,5,61,0,0,41,2,1,0,0,0,42,43,5,44,0,0,43,4,1,0,
  	0,0,44,45,5,109,0,0,45,46,5,101,0,0,46,47,5,97,0,0,47,48,5,115,0,0,48,
  	49,5,117,0,0,49,50,5,114,0,0,50,51,5,101,0,0,51,6,1,0,0,0,52,53,5,115,
  	0,0,53,54,5,107,0,0,54,55,5,105,0,0,55,56,5,112,0,0,56,8,1,0,0,0,57,58,
  	5,59,0,0,58,10,1,0,0,0,59,60,5,105,0,0,60,61,5,102,0,0,61,12,1,0,0,0,
  	62,63,5,101,0,0,63,64,5,108,0,0,64,65,5,115,0,0,65,66,5,101,0,0,66,14,
  	1,0,0,0,67,68,5,40,0,0,68,16,1,0,0,0,69,70,5,41,0,0,70,18,1,0,0,0,71,
  	72,5,123,0,0,72,20,1,0,0,0,73,74,5,125,0,0,74,22,1,0,0,0,75,76,5,91,0,
  	0,76,24,1,0,0,0,77,78,5,93,0,0,78,26,1,0,0,0,79,80,5,37,0,0,80,28,1,0,
  	0,0,81,83,7,0,0,0,82,81,1,0,0,0,83,84,1,0,0,0,84,82,1,0,0,0,84,85,1,0,
  	0,0,85,86,1,0,0,0,86,87,6,14,0,0,87,30,1,0,0,0,88,93,5,88,0,0,89,90,5,
  	67,0,0,90,93,5,88,0,0,91,93,5,72,0,0,92,88,1,0,0,0,92,89,1,0,0,0,92,91,
  	1,0,0,0,93,32,1,0,0,0,94,96,7,1,0,0,95,94,1,0,0,0,96,97,1,0,0,0,97,95,
  	1,0,0,0,97,98,1,0,0,0,98,105,1,0,0,0,99,101,5,46,0,0,100,102,7,1,0,0,
  	101,100,1,0,0,0,102,103,1,0,0,0,103,101,1,0,0,0,103,104,1,0,0,0,104,106,
  	1,0,0,0,105,99,1,0,0,0,105,106,1,0,0,0,106,34,1,0,0,0,107,109,5,120,0,
  	0,108,110,7,1,0,0,109,108,1,0,0,0,110,111,1,0,0,0,111,109,1,0,0,0,111,
  	112,1,0,0,0,112,36,1,0,0,0,113,115,5,113,0,0,114,116,7,1,0,0,115,114,
  	1,0,0,0,116,117,1,0,0,0,117,115,1,0,0,0,117,118,1,0,0,0,118,38,1,0,0,
  	0,8,0,84,92,97,103,105,111,117,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  programminglanguagelexerLexerStaticData = std::move(staticData);
}

}

ProgrammingLanguageLexer::ProgrammingLanguageLexer(CharStream *input) : Lexer(input) {
  ProgrammingLanguageLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *programminglanguagelexerLexerStaticData->atn, programminglanguagelexerLexerStaticData->decisionToDFA, programminglanguagelexerLexerStaticData->sharedContextCache);
}

ProgrammingLanguageLexer::~ProgrammingLanguageLexer() {
  delete _interpreter;
}

std::string ProgrammingLanguageLexer::getGrammarFileName() const {
  return "ProgrammingLanguage.g4";
}

const std::vector<std::string>& ProgrammingLanguageLexer::getRuleNames() const {
  return programminglanguagelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ProgrammingLanguageLexer::getChannelNames() const {
  return programminglanguagelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ProgrammingLanguageLexer::getModeNames() const {
  return programminglanguagelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ProgrammingLanguageLexer::getVocabulary() const {
  return programminglanguagelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ProgrammingLanguageLexer::getSerializedATN() const {
  return programminglanguagelexerLexerStaticData->serializedATN;
}

const atn::ATN& ProgrammingLanguageLexer::getATN() const {
  return *programminglanguagelexerLexerStaticData->atn;
}




void ProgrammingLanguageLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  programminglanguagelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(programminglanguagelexerLexerOnceFlag, programminglanguagelexerLexerInitialize);
#endif
}
