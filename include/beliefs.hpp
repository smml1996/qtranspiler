#ifndef BELIEFS_H
#define BELIEFS_H
#include "rationals.hpp"
#include "pomdp.hpp"


class Belief {
    Rational get_sum() const;
public:
    unordered_map<POMDPVertex *, Rational, POMDPVertexHash, POMDPVertexPtrEqual> probs;

    Rational get(POMDPVertex *v);

    void set_val(POMDPVertex* v, const Rational &prob);

    void add_val(POMDPVertex* v, const Rational &val);

    bool is_normalized(int precision) const;

    bool operator==(const Belief& other) const;
};

struct BeliefHash {
    std::size_t operator()(const Belief &instruction) const;
};

Rational l1_norm(const Belief &b1, const Belief &b2);

Belief normalize_belief(const Belief &belief);

#endif