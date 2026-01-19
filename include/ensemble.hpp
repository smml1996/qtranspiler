//
// Created by Stefanie Muroya Lei on 02.01.26.
//

#ifndef PROBABILISTC_HOARE_TRIPLES_ENSEMBLE_H
#define PROBABILISTC_HOARE_TRIPLES_ENSEMBLE_H
#include <cassert>
#include "states.hpp"
#include "floats.hpp"
#include <z3++.h>

template <typename FloatT>
class Ensemble {
    int does_hybrid_state_exists(shared_ptr<HybridState> &state) const;
public:
    vector<pair<shared_ptr<HybridState>, FloatT>> probs;
    int precision;

    explicit Ensemble(int precision) : precision(precision) {};
    Ensemble(){this->precision=-1;};
    bool insert_prob(shared_ptr<HybridState> &hs, FloatT &value){
        assert(this->precision != -1);
        if (this->does_hybrid_state_exists(hs) == -1) return false;
        this->probs.push_back(make_pair(hs, value));
        return true;
    }
    void add_prob(shared_ptr<HybridState> &hs, FloatT value);
    FloatT get_weight();
    void normalize();
    bool operator==(const Ensemble<FloatT> &other) const;
};

template <typename FloatT>
class Polygon {
public:
    vector<shared_ptr<Ensemble<FloatT>>> corners;
};

Ensemble<z3::expr> get_symbolic_ensemble(const std::vector<shared_ptr<Ensemble<MyFloat>>> &ensembles, const z3::expr_vector &weights, z3::context &ctx, const int &mc_precision);
shared_ptr<Ensemble<MyFloat>> to_myfloat(const shared_ptr<Ensemble<double>> &ensemble, const int &mc_precision, const int &max_depth);
shared_ptr<Ensemble<double>> to_double(const shared_ptr<Ensemble<MyFloat>> &ensemble, const int &mc_precision);
template <typename FloatT>
bool is_new_ensemble(const vector<shared_ptr<Ensemble<FloatT>>> &all_ensembles, const shared_ptr<Ensemble<FloatT>> &new_ensemble) {
    for (auto e : all_ensembles) {
        if (*e == *new_ensemble ) {
            return false;
        }
    }
    return true;
}

#endif //PROBABILISTC_HOARE_TRIPLES_ENSEMBLE_H