cmake_minimum_required(VERSION 3.18)
project(probabilistc_hoare_triples)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/experiments
)

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
        include/rationals.hpp
        src/rationals.cpp
        src/experiments/discrimination.cpp
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

add_executable(test_example tests/test_example.cpp)

# Link with gtest targets
target_link_libraries(test_example GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_example)


