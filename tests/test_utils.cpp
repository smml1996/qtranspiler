//
// Created by Stefanie Muroya Lei on 08.09.25.
//

#include <gtest/gtest.h>
#include <complex>
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>
#include "utils.hpp"

using namespace std;

// ---------- Tolerance helpers ----------
TEST(UtilsTest, AbsTol) {
    EXPECT_GT(get_abs_tol(5), 0.0);
    EXPECT_LT(get_abs_tol(10), get_abs_tol(2));  // higher precision → smaller tol
}

TEST(UtilsTest, RelTol) {
    EXPECT_GT(get_rel_tol(5), 0.0);
    EXPECT_LT(get_rel_tol(10), get_rel_tol(2));
}

TEST(UtilsTest, IsCloseBasic) {
    EXPECT_TRUE(is_close(1.0, 1.0, 5));
    EXPECT_TRUE(is_close(1.0, 1.000001, 6));
    EXPECT_FALSE(is_close(1.0, 1.1, 6));
}

TEST(UtilsTest, IsCloseNegative) {
    EXPECT_TRUE(is_close(-2.5, -2.5, 5));
    EXPECT_TRUE(is_close(-2.5, -2.5000001, 6));
    EXPECT_FALSE(is_close(-2.5, -3.0, 6));
}

// ---------- Weighted choice ----------
TEST(UtilsTest, WeightedChoiceValid) {
    vector<int> elems{1, 2, 3};
    vector<double> weights{0.1, 0.3, 0.6};

    // Run multiple times to ensure only valid elements are returned
    for (int i = 0; i < 50; ++i) {
        int val = weighted_choice(elems, weights);
        EXPECT_TRUE(val == 1 || val == 2 || val == 3);
    }
}

TEST(UtilsTest, WeightedChoiceThrows) {
    vector<int> elems{1, 2};
    vector<double> weights{0.5};
    EXPECT_THROW(weighted_choice(elems, weights), invalid_argument);

    vector<int> empty_elems{};
    vector<double> empty_weights{};
    EXPECT_THROW(weighted_choice(empty_elems, empty_weights), invalid_argument);
}

// ---------- Rounding ----------
TEST(UtilsTest, RoundToBasic) {
    EXPECT_DOUBLE_EQ(round_to(3.14159, 2), 3.14);
    EXPECT_DOUBLE_EQ(round_to(3.14159, 3), 3.142);
    EXPECT_DOUBLE_EQ(round_to(-1.2345, 2), -1.23);
}

TEST(UtilsTest, RoundToZeroDecimals) {
    EXPECT_DOUBLE_EQ(round_to(3.7, 0), 4.0);
    EXPECT_DOUBLE_EQ(round_to(3.4, 0), 3.0);
}

TEST(UtilsTest, RoundToLargeDecimals) {
    EXPECT_DOUBLE_EQ(round_to(1.23456789, 8), 1.23456789);
}

// ---------- Binary conversion ----------
TEST(UtilsTest, ToBinaryBasic) {
    EXPECT_EQ(to_binary(0), "0");
    EXPECT_EQ(to_binary(5), "101");
    EXPECT_EQ(to_binary(16), "00001");
}

TEST(UtilsTest, ToBinaryNegative) {
    // Depending on your implementation, this might throw or handle differently
    EXPECT_THROW(to_binary(-3), invalid_argument);
}

// ---------- Matrix equality ----------
TEST(UtilsTest, AreMatricesEqualBasic) {
    vector<vector<complex<double>>> m1{{1.0, 2.0}, {3.0, 4.0}};
    vector<vector<complex<double>>> m2{{1.0, 2.0}, {3.0, 4.0}};
    EXPECT_TRUE(are_matrices_equal(m1, m2, 10));
}

TEST(UtilsTest, AreMatricesEqualTolerance) {
    vector<vector<complex<double>>> m1{{1.0, 2.0}, {3.0, 4.0}};
    vector<vector<complex<double>>> m2{{1.0, 2.0000001}, {3.0, 4.0}};
    EXPECT_TRUE(are_matrices_equal(m1, m2, 6));
    EXPECT_FALSE(are_matrices_equal(m1, m2, 12));
}

TEST(UtilsTest, AreMatricesEqualDifferentShapes) {
    vector<vector<complex<double>>> m1{{1.0, 2.0}};
    vector<vector<complex<double>>> m2{{1.0, 2.0}, {3.0, 4.0}};
    EXPECT_FALSE(are_matrices_equal(m1, m2, 5));
}

// ---------- Matrix list ----------
TEST(UtilsTest, IsMatrixInList) {
    vector<vector<complex<double>>> m1{{1.0, 0.0}, {0.0, 1.0}};
    vector<vector<complex<double>>> m2{{0.0, 1.0}, {1.0, 0.0}};
    vector<vector<vector<complex<double>>>> list{m1, m2};

    EXPECT_TRUE(is_matrix_in_list(m1, list, 10));
    EXPECT_TRUE(is_matrix_in_list(m2, list, 10));

    vector<vector<complex<double>>> m3{{1.0, 1.0}, {0.0, 1.0}};
    EXPECT_FALSE(is_matrix_in_list(m3, list, 10));
}
