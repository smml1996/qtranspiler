cmake_minimum_required(VERSION 3.18)
project(probabilistc_hoare_triples)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/experiments
)
# Add Boost headers (header-only for multiprecision)
find_package(Boost REQUIRED)

# Tell CMake where to find OR-Tools
find_package(ortools REQUIRED)

# json files
find_package(nlohmann_json REQUIRED)

# Source files (your code + generated code)
set(SOURCES
    main.cpp
        src/algorithm.cpp
        src/beliefs.cpp
        src/channels.cpp
        src/experiments.cpp
        src/floats.cpp
        src/hardware_specification.cpp
        src/instruction.cpp
        src/quantum_gates.cpp
        src/solvers.cpp
        src/states.cpp
        src/utils.cpp
        src/pomdp.cpp
        src/experiments/bitflip.cpp
        src/experiments/ghz.cpp
        src/experiments/reset.cpp
        src/rationals.cpp
        src/experiments/discrimination.cpp
        src/experiments/bellstate_reach.cpp
)

add_executable(main ${SOURCES})

target_link_libraries(main PRIVATE
        ortools::ortools
        nlohmann_json::nlohmann_json
        c++      # libc++
)

# testing

# Download and build GoogleTest automatically
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows/MSVC only: avoid overriding parent project's compiler settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# test floats
add_executable(test_floats tests/test_floats.cpp src/floats.cpp)
target_link_libraries(test_floats GTest::gtest_main)
gtest_discover_tests(test_floats)

# test rationals
add_executable(test_rationals tests/test_rationals.cpp src/rationals.cpp src/floats.cpp)
target_link_libraries(test_rationals GTest::gtest_main)
gtest_discover_tests(test_rationals)

# test utils
add_executable(test_utils tests/test_utils.cpp src/utils.cpp)
target_link_libraries(test_utils GTest::gtest_main ortools::ortools
        nlohmann_json::nlohmann_json
        c++ )
gtest_discover_tests(test_utils)

# test quantum gates
add_executable(test_quantum_gates tests/test_quantum_gates.cpp src/quantum_gates.cpp)
target_link_libraries(test_quantum_gates GTest::gtest_main)
gtest_discover_tests(test_quantum_gates)

# test instructions
add_executable(test_instructions tests/test_instructions.cpp src/instruction.cpp src/quantum_gates.cpp src/utils.cpp)
target_link_libraries(test_instructions GTest::gtest_main nlohmann_json::nlohmann_json)
gtest_discover_tests(test_instructions)

# test states
add_executable(test_states tests/test_states.cpp src/states.cpp src/instruction.cpp src/quantum_gates.cpp src/utils.cpp)
target_link_libraries(test_states GTest::gtest_main nlohmann_json::nlohmann_json)
gtest_discover_tests(test_states)

# test channels
add_executable(test_channels tests/test_channels.cpp src/channels.cpp src/instruction.cpp src/quantum_gates.cpp src/utils.cpp)
target_link_libraries(test_channels GTest::gtest_main nlohmann_json::nlohmann_json)
gtest_discover_tests(test_channels)

# test hardware specifications
add_executable(test_specs tests/test_hardware_specification.cpp
        src/hardware_specification.cpp
        src/channels.cpp
        src/states.cpp
        src/quantum_gates.cpp
        src/instruction.cpp
        src/utils.cpp)
target_link_libraries(test_specs GTest::gtest_main nlohmann_json::nlohmann_json)
gtest_discover_tests(test_specs)

# test POMDPs
add_executable(test_pomdp tests/test_pomdp.cpp
        src/pomdp.cpp
        src/beliefs.cpp
        src/hardware_specification.cpp
        src/channels.cpp
        src/states.cpp
        src/quantum_gates.cpp
        src/instruction.cpp
        src/floats.cpp
        src/rationals.cpp
        src/utils.cpp)
target_link_libraries(test_pomdp GTest::gtest_main nlohmann_json::nlohmann_json)
gtest_discover_tests(test_pomdp)

# test beliefs
add_executable(test_beliefs tests/test_beliefs.cpp
        src/pomdp.cpp
        src/beliefs.cpp
        src/hardware_specification.cpp
        src/channels.cpp
        src/states.cpp
        src/quantum_gates.cpp
        src/instruction.cpp
        src/floats.cpp
        src/rationals.cpp
        src/utils.cpp)
target_link_libraries(test_beliefs GTest::gtest_main nlohmann_json::nlohmann_json)
gtest_discover_tests(test_beliefs)


# test algorithms
add_executable(test_algorithms tests/test_algorithms.cpp
        src/algorithm.cpp
        src/pomdp.cpp
        src/beliefs.cpp
        src/hardware_specification.cpp
        src/channels.cpp
        src/states.cpp
        src/quantum_gates.cpp
        src/instruction.cpp
        src/floats.cpp
        src/rationals.cpp
        src/utils.cpp)
target_link_libraries(test_algorithms GTest::gtest_main nlohmann_json::nlohmann_json)
gtest_discover_tests(test_algorithms)


# test experiments
add_executable(test_experiments tests/test_experiments.cpp
        src/solvers.cpp
        src/experiments.cpp
        src/experiments/bitflip.cpp
        src/experiments/discrimination.cpp
        src/experiments/ghz.cpp
        src/experiments/reset.cpp
        src/experiments/bellstate_reach.cpp
        src/algorithm.cpp
        src/pomdp.cpp
        src/beliefs.cpp
        src/hardware_specification.cpp
        src/channels.cpp
        src/states.cpp
        src/quantum_gates.cpp
        src/instruction.cpp
        src/floats.cpp
        src/rationals.cpp
        src/utils.cpp)
target_link_libraries(test_experiments GTest::gtest_main ortools::ortools nlohmann_json::nlohmann_json)
gtest_discover_tests(test_experiments)

# all tests in one file

