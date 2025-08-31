//
// Created by Stefanie Muroya Lei on 28.01.24.
//
#ifndef FLOATS_H
#define FLOATS_H
#include<vector>
#include <cassert>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class MyFloat {
    public:
    static int precision;
    static int tolerance;

    vector<short> exponent;
    vector<short> mantissa;
    bool is_negative;

    static void check_digit(const short &digit);

    static string remove_initial_zeros(const string &original);

    static vector<short> integer_addition(const vector<short> &v1, const vector<short> &v2);

    static pair<short, short> digit_substraction(const short &s1, const short &s2, const short &carry);

    static MyFloat subtraction(const MyFloat& f1, const MyFloat& f2);
    

    static bool are_vectors_equal(const vector<short> &v1, const vector<short> &v2);

    static bool is_vector_greater(vector<short> v1, vector<short> v2);


    vector<short> exponent;
    vector<short> mantissa;
    bool is_negative;

    MyFloat(const double &probability__, int custom_precision);
    explicit MyFloat(const string& probability__ = "0", int custom_precision=-1);

    static MyFloat abs(MyFloat const &n);

    friend std::ostream &operator<<(ostream& os, const MyFloat& myfloat);

    MyFloat operator+(MyFloat const &other);

    MyFloat operator*(MyFloat const &other);

    bool operator==(const MyFloat &rhs) const;

    inline bool operator!=(const MyFloat &rhs);

    inline bool operator>(const MyFloat &other) const;

    inline bool operator<(const MyFloat &other) const;
};

int MyFloat::precision = 80;
int MyFloat::tolerance = 80;

MyFloat max(MyFloat const &a, MyFloat const &b);

MyFloat min(MyFloat const &a, MyFloat const &b);


#endif