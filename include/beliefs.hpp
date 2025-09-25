#ifndef BELIEFS_H
#define BELIEFS_H
#include "rationals.hpp"
#include "pomdp.hpp"


class Belief {
public:
    [[nodiscard]] Rational get_sum(int precision) const;
    unordered_map<POMDPVertex *, Rational, POMDPVertexHash, POMDPVertexPtrEqual> probs;

    Rational get(POMDPVertex *v, int precision);

    void set_val(POMDPVertex* v, const Rational &prob);

    void add_val(POMDPVertex* v, const Rational &val);

    bool is_normalized(int precision) const;

    bool operator==(const Belief& other) const;

    void print() const;
};

struct BeliefHash {
    std::size_t operator()(const Belief &) const;
};

Rational l1_norm(const Belief &b1, const Belief &b2, int precision);

Belief normalize_belief(const Belief &belief, int precision);

int get_belief_cs(const Belief &belief);



#endif