//
// Created by Stefanie Muroya Lei on 02.01.26.
//

#ifndef PROBABILISTC_HOARE_TRIPLES_VERIFIER_H
#define PROBABILISTC_HOARE_TRIPLES_VERIFIER_H
#include "hardware_specification.hpp"
#include "verifier.hpp"
#include "markov_chain.hpp"
#include "ensemble.hpp"

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
    bool check_polygon(const Polygon<double> &polygon, MarkovChain &mc,
        ProgrammingLanguageParser::ProgramContext* program,
        const string &raw_postcondition);
    bool verify(const string &raw_precondition, const string &raw_program, const string &raw_postcondition);
};


#endif //PROBABILISTC_HOARE_TRIPLES_VERIFIER_H