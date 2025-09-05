//
// Created by Stefanie Muroya Lei on 05.09.25.
//

#ifndef PROBABILISTC_HOARE_TRIPLES_RATIONALS_H
#define PROBABILISTC_HOARE_TRIPLES_RATIONALS_H
#include "floats.hpp"

class Rational {
public:
    MyFloat numerator;
    MyFloat denominator;
    int precision;
    Rational(const string &numerator="0", const string &denominator = "1", int custom_precision=-1);
    Rational(const MyFloat & numerator, const MyFloat & denominator = MyFloat("1"));
    friend std::ostream &operator<<(ostream& os, const Rational& rational);
    Rational operator+(Rational const &rhs) const;
    Rational operator*(Rational const &rhs) const;
    Rational operator/(Rational const &rhs) const;
    bool operator==(Rational const &rhs) const;
    bool operator!=(Rational const &rhs) const;
    bool operator<(Rational const &rhs) const;
    bool operator>(Rational const &rhs) const;
 };

Rational abs(const Rational &rational);
Rational max(Rational const &rational1, Rational const &rational2);
Rational min(Rational const &rational1, Rational const &rational2);

double to_double(const Rational &rational);

#endif //PROBABILISTC_HOARE_TRIPLES_RATIONALS_H