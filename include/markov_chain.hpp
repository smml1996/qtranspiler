//
// Created by Stefanie Muroya Lei on 02.01.26.
//

#ifndef PROBABILISTC_HOARE_TRIPLES_MARKOV_CHAIN_H
#define PROBABILISTC_HOARE_TRIPLES_MARKOV_CHAIN_H
// ANTLR first
#include "ensemble.hpp"

// Boost AFTER clean-up
#include "boost_clean.hpp"
#include "pomdp.hpp"
#include "floats.hpp"
#include "hardware_specification.hpp"
#include <memory>
#include <utility>

#include "grammars/PL/ProgrammingLanguageParser.h"


class Configuration {
public:
    shared_ptr<Ensemble<double>> ensemble;
    ProgrammingLanguageParser::ProgramContext* program;
    Configuration(ProgrammingLanguageParser::ProgramContext* program, shared_ptr<Ensemble<double>> ensemble) {
        this->ensemble = std::move(ensemble);
        this->program = program;
    }

    [[nodiscard]] bool is_atomic_program() const;

    shared_ptr<Configuration> get_atomic_program_ensemble(HardwareSpecification &spec, const unordered_map<int, int> &embedding, const int &mc_precision);

};

class MarkovChain {
public:
    HardwareSpecification spec;
    unordered_map<int, int> embedding;
    int mc_precision;
    int max_depth;

    MarkovChain(const HardwareSpecification &spec_,
                const std::unordered_map<int,int> &embedding_, const int &mc_precision_)
        : spec(spec_), embedding(embedding_), mc_precision(mc_precision_), max_depth(-1)
    {};

    shared_ptr<Ensemble<MyFloat>> get_final_ensemble (const shared_ptr<Configuration> &config);
    static int get_depth(const shared_ptr<Configuration> &config);
};



#endif //PROBABILISTC_HOARE_TRIPLES_MARKOV_CHAIN_H