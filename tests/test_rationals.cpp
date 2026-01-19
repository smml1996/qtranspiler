//
// Created by Stefanie Muroya Lei on 08.09.25.
//
#include <gtest/gtest.h>
#include "floats.hpp"
#include "rationals.hpp"  // adjust include path

// ---------- Construction ----------
TEST(RationalTest, ConstructFromStrings) {
    Rational r1("3", "4", 10);   // 3/4
    Rational r2("0", "5", 10);   // 0/5
    Rational r3("-7", "2", 10);  // -7/2

    EXPECT_NO_THROW(Rational("42", "7", 10));
}

TEST(RationalTest, ConstructFromMyFloat) {
    MyFloat num("5", 10);
    MyFloat den("2", 10);
    Rational r(num, den);
    EXPECT_NEAR(to_double(r), 2.5, 1e-10);
}

// ---------- Arithmetic ----------
TEST(RationalTest, Addition) {
    Rational r1("1", "2", 10);  // 1/2
    Rational r2("1", "3", 10);  // 1/3
    Rational result = r1 + r2;  // 5/6
    EXPECT_NEAR(to_double(result), 5.0 / 6.0, 1e-10);
}

TEST(RationalTest, Multiplication) {
    Rational r1("2", "3", 10);  // 2/3
    Rational r2("3", "4", 10);  // 3/4
    Rational result = r1 * r2;  // 6/12 = 1/2
    EXPECT_NEAR(to_double(result), 0.5, 1e-10);
}

TEST(RationalTest, Division) {
    Rational r1("5", "6", 10);  // 5/6
    Rational r2("5", "3", 10);  // 5/3
    Rational result = r1 / r2;  // (5/6) ÷ (5/3) = 3/6 = 1/2
    EXPECT_NEAR(to_double(result), 0.5, 1e-10);
}

// ---------- Comparisons ----------
TEST(RationalTest, ComparisonOperators) {
    Rational r1("1", "2", 10);  // 1/2
    Rational r2("2", "4", 10);  // 2/4
    Rational r3("3", "4", 10);  // 3/4

    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 != r2);
    EXPECT_TRUE(r3 > r1);
    EXPECT_TRUE(r1 < r3);
}

// ---------- Abs / Min / Max ----------
TEST(RationalTest, AbsValue) {
    Rational r1("-5", "2", 10);
    Rational r2("5", "2", 10);
    EXPECT_TRUE(abs(r1) == r2);
}

TEST(RationalTest, MinMax) {
    Rational r1("1", "2", 10);
    Rational r2("3", "4", 10);
    EXPECT_TRUE(min(r1, r2) == r1);
    EXPECT_TRUE(max(r1, r2) == r2);
}

// ---------- To double ----------
TEST(RationalTest, ToDoubleConversion) {
    Rational r("7", "8", 10);
    double d = to_double(r);
    EXPECT_NEAR(d, 0.875, 1e-10);
}


// ---------- Edge Cases ----------

TEST(RationalTest, ZeroDenominatorThrows) {
    // Construction with denominator = 0 should throw
    EXPECT_THROW(Rational("1", "0", 10), std::invalid_argument);
    EXPECT_THROW(Rational(MyFloat("5"), MyFloat("0")), std::invalid_argument);
}

TEST(RationalTest, ZeroNumerator) {
    Rational r("0", "7", 10);
    EXPECT_NEAR(to_double(r), 0.0, 1e-10);

    Rational other("5", "3", 10);
    EXPECT_TRUE((r * other) == r);  // 0 * anything = 0
}

TEST(RationalTest, NegativeDenominatorNormalizes) {
    Rational r1("1", "-2", 10);   // 1 / -2
    Rational r2("-1", "2", 10);   // -1 / 2

    EXPECT_TRUE(r1 == r2);
}

TEST(RationalTest, LargeNumbers) {
    Rational r1("123456789", "987654321", 20);
    Rational r2("246913578", "1975308642", 20);  // double numerator and denominator
    EXPECT_TRUE(r1 == r2);  // reduced fraction equivalence
    EXPECT_NEAR(to_double(r1), 123456789.0 / 987654321.0, 1e-15);
}

TEST(RationalTest, PrecisionEffects) {
    Rational r1("1", "3", 5);   // with precision 5
    Rational r2("1", "3", 15);  // with precision 15
    double d1 = to_double(r1);
    double d2 = to_double(r2);
    EXPECT_NEAR(d1, d2, 1e-5);   // less precise
    EXPECT_NEAR(d2, 1.0 / 3.0, 1e-15); // more precise
}

TEST(RationalTest, DivisionBySelf) {
    Rational r("17", "5", 10);
    Rational result = r / r;
    EXPECT_NEAR(to_double(result), 1.0, 1e-10);
}

TEST(RationalTest, NegativeComparisons) {
    Rational r1("-3", "4", 10);  // -0.75
    Rational r2("1", "2", 10);   // 0.5
    EXPECT_TRUE(r1 < r2);
    EXPECT_TRUE(r2 > r1);
}