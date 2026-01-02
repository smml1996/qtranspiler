//
// Created by Stefanie Muroya Lei on 02.01.26.
//

#ifndef PROBABILISTC_HOARE_TRIPLES_VERIFIER_H
#define PROBABILISTC_HOARE_TRIPLES_VERIFIER_H
#include "hardware_specification.hpp"

class Verifier {
public:
    HardwareSpecification spec;
    unordered_map<int, int> embedding;
    int precision;
    int nqvars, ncvars;

    Verifier(HardwareSpecification spec_, const unordered_map<int, int> &embedding_,
             const int &nqvars_, const int &ncvars_, const int &precision_) :
    spec(std::move(spec_)),embedding(embedding_),  nqvars(nqvars_),
    ncvars(ncvars_), precision(precision_) {};
    [[nodiscard]] bool verify(const string &raw_precondition, const string &raw_program, const string &raw_postcondition) const;
};


#endif //PROBABILISTC_HOARE_TRIPLES_VERIFIER_H