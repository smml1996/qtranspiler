//
// Created by Stefanie Muroya Lei on 05.09.25.
//

#include "rationals.hpp"

#include <cassert>
#include <string>
#include <ostream>

using namespace std;

Rational::Rational(const string &numerator, const string &denominator, int custom_precision) {
    assert(custom_precision != -1);
    this->numerator = MyFloat(numerator, custom_precision);
    this->denominator = MyFloat(denominator, custom_precision);
    this->precision = custom_precision;
}

Rational::Rational(const MyFloat &numerator, const MyFloat &denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    assert (numerator.precision == denominator.precision);
    this->precision = numerator.precision;
    if (denominator == MyFloat("0")) {
        throw invalid_argument("denominator cannot be zero");
    }
}

Rational Rational::operator+(Rational const &rhs) const {
    MyFloat new_num = numerator * rhs.denominator + rhs.numerator * denominator;
    MyFloat new_den = denominator * rhs.denominator;

    if (new_den == MyFloat("0")) {
        throw runtime_error("Rational::operator+: denominator is zero");
    }
    return Rational(new_num, new_den);
}

Rational Rational::operator*(Rational const &rhs) const {
    MyFloat new_num = numerator * rhs.numerator;
    MyFloat new_den = denominator * rhs.denominator;
    if (new_den == MyFloat("0")) {
        throw runtime_error("Rational::operator*: denominator is zero");
    }
    return Rational(new_num, new_den);
}

Rational Rational::operator/(Rational const &rhs) const {
    MyFloat new_num = numerator * rhs.denominator;
    MyFloat new_den = denominator * rhs.numerator;
    if (new_den == MyFloat("0")) {
        throw runtime_error("Rational::operator/: denominator is zero");
    }
    return Rational(new_num, new_den);
}

bool Rational::operator==(Rational const &rhs) const {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

bool Rational::operator!=(Rational const &rhs) const {
    return numerator != rhs.numerator || denominator != rhs.denominator;
}

bool Rational::operator<(Rational const &rhs) const {
    return numerator * rhs.denominator < rhs.numerator * denominator;
}

bool Rational::operator>(Rational const &rhs) const {
    return numerator * rhs.denominator > rhs.numerator * denominator;
}

Rational abs(const Rational &rational) {
    return Rational(MyFloat::abs(rational.numerator), MyFloat::abs(rational.denominator));
}

Rational max(Rational const &rational1, Rational const &rational2) {
    if (rational1 > rational2) {
        return rational1;
    }
    return rational2;
}

Rational min(Rational const &rational1, Rational const &rational2) {
    if (rational1 < rational2) {
        return rational1;
    }
    return rational2;
}

double to_double(const Rational &rational) {
    double numerator = stod(to_string(rational.numerator));
    double denominator = stod(to_string(rational.denominator));
    return numerator / denominator;
}

ostream & operator<<(ostream &os, const Rational &rational) {
    os << rational.numerator << "/" << rational.denominator;
    return os;
}
