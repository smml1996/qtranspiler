//
// Created by Stefanie Muroya Lei on 07.09.25.
//

#include <gtest/gtest.h>
#include "floats.hpp"

// ---------- Construction ----------
TEST(MyFloatTest, ConstructFromDouble) {
    MyFloat f1(3.14159, 10);
    EXPECT_NO_THROW(MyFloat(2.71828, 5));
    EXPECT_NO_THROW(MyFloat(0.0, 3));
}

TEST(MyFloatTest, ConstructFromString) {
    MyFloat f1("123.456", 10);
    MyFloat f2("0", 5);
    MyFloat f3("-987.65", 15);
    EXPECT_NO_THROW(MyFloat("42", 4));
}

// ---------- Utility checks ----------
TEST(MyFloatTest, CheckDigitValid) {
    EXPECT_NO_THROW(MyFloat::check_digit(0));
    EXPECT_NO_THROW(MyFloat::check_digit(9));
}

TEST(MyFloatTest, CheckDigitInvalid) {
    EXPECT_THROW(MyFloat::check_digit(-1), std::invalid_argument);
    EXPECT_THROW(MyFloat::check_digit(10), std::invalid_argument);
}

TEST(MyFloatTest, RemoveInitialZeros) {
    EXPECT_EQ(MyFloat::remove_initial_zeros("000123"), "123");
    EXPECT_EQ(MyFloat::remove_initial_zeros("0000"), "0");
    EXPECT_EQ(MyFloat::remove_initial_zeros("004560"), "4560");
}

TEST(MyFloatTest, IntegerAddition) {
    std::vector<short> v1{1, 2, 3}; // 123
    std::vector<short> v2{4, 5, 6}; // 456
    auto result = MyFloat::integer_addition(v1, v2);
    std::vector<short> expected{5, 7, 9}; // 579
    EXPECT_TRUE(MyFloat::are_vectors_equal(result, expected));
}

TEST(MyFloatTest, DigitSubtraction) {
    auto [res1, carry1] = MyFloat::digit_substraction(5, 3, 0);
    EXPECT_EQ(res1, 2);
    EXPECT_EQ(carry1, 0);

    auto [res2, carry2] = MyFloat::digit_substraction(3, 5, 0);
    EXPECT_EQ(res2, 8);  // assuming borrow from next digit
    EXPECT_EQ(carry2, 1);
}

// ---------- Comparisons ----------
TEST(MyFloatTest, ComparisonOperators) {
    MyFloat a("123", 10);
    MyFloat b("123", 10);
    MyFloat c("456", 10);

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
    EXPECT_TRUE(c > a);
    EXPECT_TRUE(a < c);
}

// ---------- Arithmetic ----------
TEST(MyFloatTest, Addition) {
    MyFloat a("123", 10);
    MyFloat b("77", 10);
    MyFloat c = a + b;
    EXPECT_EQ(to_string(c), "200.0000000000");  // assuming decimal-style addition
}

TEST(MyFloatTest, Multiplication) {
    MyFloat a("12", 10);
    MyFloat b("10", 10);
    MyFloat c = a * b;
    EXPECT_EQ(to_string(c), "120.0000000000");
}

// ---------- Static Algorithms ----------
TEST(MyFloatTest, VectorEqual) {
    std::vector<short> v1{1,2,3};
    std::vector<short> v2{1,2,3};
    std::vector<short> v3{3,2,1};
    EXPECT_TRUE(MyFloat::are_vectors_equal(v1, v2));
    EXPECT_FALSE(MyFloat::are_vectors_equal(v1, v3));
}

TEST(MyFloatTest, VectorGreater) {
    std::vector<short> v1{9,9};
    std::vector<short> v2{1,0,0};
    EXPECT_FALSE(MyFloat::is_vector_greater(v2, v1));
    EXPECT_TRUE(MyFloat::is_vector_greater(v1, v2));
}

// ---------- Abs / Min / Max ----------
TEST(MyFloatTest, AbsValue) {
    MyFloat a("-123", 10);
    MyFloat b("123", 10);
    EXPECT_TRUE(MyFloat::abs(a) == b);
}

TEST(MyFloatTest, MinMax) {
    MyFloat a("10", 10);
    MyFloat b("20", 10);
    EXPECT_EQ(to_string(min(a,b)), "10.0000000000");
    EXPECT_EQ(to_string(max(a,b)), "20.0000000000");
}

// ---------- To double ----------
TEST(MyFloatTest, ToDoubleConversion) {
    MyFloat a("3.14", 10);
    double d = to_double(a);
    EXPECT_NEAR(d, 3.14, 1e-10);
}
