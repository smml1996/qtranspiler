cmake_minimum_required(VERSION 3.10)
project(probabilistc_hoare_triples)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Homebrew nlohmann-json path
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/nlohmann-json/include")

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
)

add_executable(main ${SOURCES})

target_link_libraries(main PRIVATE
        ortools::ortools
        nlohmann_json::nlohmann_json
        c++      # libc++
)
