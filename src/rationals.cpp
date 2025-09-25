//
// Created by Stefanie Muroya Lei on 05.09.25.
//

#include "rationals.hpp"

#include <cassert>
#include <iostream>
#include <string>
#include <ostream>

using namespace std;

Rational::Rational(const string &numerator, const string &denominator, int custom_precision) {
    if (custom_precision == -1) {

    }
    this->precision = custom_precision;
    this->numerator = MyFloat(numerator, custom_precision);
    if (this->numerator == MyFloat("0", this->precision)) {
        this->denominator = MyFloat("1", this->precision);
    } else {
        this->denominator = MyFloat(denominator, custom_precision);
    }

    if (this->denominator.is_negative) {
        this->denominator.is_negative = false;
        this->numerator.is_negative = !this->numerator.is_negative;
    }
    if (this->denominator == MyFloat("0")) {
        throw invalid_argument("denominator cannot be zero");
    }
}

Rational::Rational(const MyFloat &numerator, const MyFloat &denominator) {
    assert(numerator.precision != -1);
    assert (numerator.precision == denominator.precision);
    this->precision = numerator.precision;
    this->numerator = numerator;
    if (this->numerator == MyFloat("0", this->precision)) {
        this->denominator = MyFloat("1", this->precision);
    } else {
        this->denominator = denominator;
    }

    if (denominator == MyFloat("0")) {
        throw invalid_argument("denominator cannot be zero");
    }
    if (this->denominator.is_negative) {
        this->denominator.is_negative = false;
        this->numerator.is_negative = !this->numerator.is_negative;
    }
}

Rational Rational::operator+(Rational const &rhs) const {
    MyFloat new_num = numerator * rhs.denominator + rhs.numerator * denominator;
    MyFloat new_den = denominator * rhs.denominator;

    if (new_den == MyFloat("0", this->precision)) {
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
    const auto ZERO = MyFloat("0", this->precision);

    // If exactly one is zero, they are not equal
    if (this->numerator == ZERO) {
        if (rhs.numerator == ZERO) {
            return true;
        }
        return false;
    }

    if (rhs.numerator == ZERO) {
        return false;
    }
    auto temp = *this / rhs;
    auto one = MyFloat("1", this->precision);
    return (temp.numerator == temp.denominator) || (temp.numerator == one && temp.denominator == one);
}

bool Rational::operator!=(const Rational &rhs) const {
    return !(*this == rhs);
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
    double numerator = stod(gate_to_string(rational.numerator));
    double denominator = stod(gate_to_string(rational.denominator));
    return numerator / denominator;
}

ostream & operator<<(ostream &os, const Rational &rational) {
    os << rational.numerator << "/" << rational.denominator;
    return os;
}

int Rational::LOCAL_PRECISION = -1;
