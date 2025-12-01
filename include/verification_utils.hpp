//
// Created by Stefanie Muroya Lei on 21.11.25.
//
#include "cxxopts.hpp"
#include <fstream>
// ANTLR first
#include "antlr4-runtime.h"
#include "grammars/PL/ProgrammingLanguageParser.h"
#include <memory>

// Boost AFTER clean-up
#include "boost_clean.hpp"
#include "floats.hpp"
#include "hardware_specification.hpp"
#include "pomdp.hpp"
#include "states.hpp"
#include <z3++.h>

#ifndef PROBABILISTC_HOARE_TRIPLES_MARKOV_CHAIN_H
#define PROBABILISTC_HOARE_TRIPLES_MARKOV_CHAIN_H

inline int mc_precision;
inline int max_depth;

template <typename FloatT>
class Ensemble {
    int does_hybrid_state_exists(shared_ptr<HybridState> &state) const;
public:
    vector<pair<shared_ptr<HybridState>, FloatT>> probs;
    int precision;

    explicit Ensemble(int precision) : precision(precision) {};
    Ensemble(){this->precision=-1;};
    bool insert_prob(shared_ptr<HybridState> &hs, FloatT &value);
    void add_prob(shared_ptr<HybridState> &hs, FloatT value);
    FloatT get_weight();
    void normalize();
    bool operator==(const Ensemble<FloatT> &other) const;
};

template <typename FloatT>
bool Ensemble<FloatT>::insert_prob(shared_ptr<HybridState> &hs, FloatT &value) {
    assert(this->precision != -1);
    if (this->does_hybrid_state_exists(hs) == -1) return false;
    this->probs.push_back(make_pair(hs, value));
    return true;
}

template <typename FloatT>
bool is_new_ensemble(const vector<shared_ptr<Ensemble<FloatT>>> &all_ensembles, const shared_ptr<Ensemble<FloatT>> &new_ensemble) {
    for (auto e : all_ensembles) {
        if (*e == *new_ensemble ) {
            return false;
        }
    }
    return true;
}

shared_ptr<Ensemble<MyFloat>> to_myfloat(const shared_ptr<Ensemble<double>> &ensemble);

shared_ptr<Ensemble<double>> to_double(const shared_ptr<Ensemble<MyFloat>> &ensemble);

Ensemble<z3::expr> get_symbolic_ensemble(const std::vector<shared_ptr<Ensemble<MyFloat>>> &ensembles,
    const z3::expr_vector &weights,
    z3::context &ctx);

class Configuration {
    public:
    shared_ptr<Ensemble<double>> ensemble;
    ProgrammingLanguageParser::ProgramContext* program;
    Configuration(ProgrammingLanguageParser::ProgramContext* program, shared_ptr<Ensemble<double>> ensemble) {
        this->ensemble = std::move(ensemble);
        this->program = program;
    }

    [[nodiscard]] bool is_atomic_program() const;

    shared_ptr<Configuration> get_atomic_program_ensemble(HardwareSpecification &spec, const unordered_map<int, int> &embedding);

};

class MarkovChain {
public:
    HardwareSpecification spec;
    unordered_map<int, int> embedding;

    MarkovChain(const HardwareSpecification &spec_,
                const std::unordered_map<int,int> &embedding_)
        : spec(spec_), embedding(embedding_)  // <-- Initialization happens here
    {};

    shared_ptr<Ensemble<MyFloat>> get_final_ensemble (const shared_ptr<Configuration> &config);


    int get_depth(const shared_ptr<Configuration> &config);
};

#endif //PROBABILISTC_HOARE_TRIPLES_MARKOV_CHAIN_H


