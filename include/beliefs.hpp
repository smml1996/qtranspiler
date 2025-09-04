#ifndef BELIEFS_H
#define BELIEFS_H
#include "floats.hpp"
#include "pomdp.hpp"


class Belief {
    MyFloat get_sum() const;
public:
    unordered_map<POMDPVertex *, MyFloat, POMDPVertexHash, POMDPVertexPtrEqual> probs;

    MyFloat get(POMDPVertex *v);

    void set_val(POMDPVertex* v, const MyFloat &prob);

    void add_val(POMDPVertex* v, const MyFloat &val);

    void check() const;

    bool operator==(const Belief& other) const;
};

struct BeliefHash {
    std::size_t operator()(const Belief &instruction) const;
};

#endif