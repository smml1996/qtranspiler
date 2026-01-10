#pragma once

// 1. Include system definitions FIRST
#include <cstddef>
#include <cstdint>
#include <cstdio>   // defines the real macro EOF

// 2. Remove any ANTLR pollution
#ifdef EOF
#undef EOF
#endif

// 3. Recreate the expected C macro explicitly
#define EOF (-1)

// 4. Now include Boost safely
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>



