cmake_minimum_required(VERSION 3.10)
project(probabilistc_hoare_triples)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${ANTLR4_RUNTIME_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/grammars/assertions
    ${CMAKE_CURRENT_SOURCE_DIR}
    /opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/include/antlr4-runtime/
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Tell CMake where to find OR-Tools
set(ORTOOLS_DIR "/opt/homebrew/Cellar/or-tools/9.14_4")  # change to your version
include_directories(${ORTOOLS_DIR}/include)
link_directories(${ORTOOLS_DIR}/lib)

# Source files (your code + generated code)
set(SOURCES
    main.cpp
    grammars/assertions/AssertionLexer.cpp
    grammars/assertions/AssertionParser.cpp
        src/algorithm.cpp
        src/beliefs.cpp
        src/channels.cpp
        src/experiments.cpp
        src/floats.cpp
        src/hardware_specification.cpp
        src/instruction.cpp
        src/pomdp.cpp
        src/quantum_gates.cpp
        src/solvers.cpp
        src/states.cpp
        src/utils.cpp
        src/experiments/bitflip.cpp
        src/experiments/ghz.cpp
        src/experiments/reset.cpp


)

add_executable(main ${SOURCES})

target_link_libraries(main PRIVATE /opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/lib/libantlr4-runtime.a)

# Link against OR-Tools libraries
target_link_libraries(SOURCES ortools)
