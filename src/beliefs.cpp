#include "beliefs.hpp"

MyFloat Belief::get_sum() const {
    MyFloat result;

    for (auto & prob : this->probs) {
        result = result + prob.second;
    }

    return result;
}

MyFloat Belief::get(POMDPVertex *v) {
    if(this->probs.find(v) == this->probs.end()){
        return MyFloat();
    }
    return this->probs[v];
}

void Belief::set_val(POMDPVertex *v, const MyFloat &prob) {
    if (prob == MyFloat("0")) return;

    this->probs[v] = prob;
}

void Belief::add_val(POMDPVertex *v, const MyFloat &val) {
    this->probs[v] = this->get(v) + val;

    if (this->probs[v] == MyFloat("0")) {
        this->probs.erase(v);
    }
}


void Belief::check() const {
    if (this->get_sum() != MyFloat("1")) {
        assert(false);
    }
}

bool Belief::operator==(const Belief& other) const {
    if(this->probs.size() != other.probs.size()) return false;

    for (auto it : this->probs) {
        auto it2 = other.probs.find(it.first);

        if (it.second != it2->second) {
            return false;
        }
    }

    return true;
}


std::size_t BeliefHash::operator()(const Belief &belief) const {
    std::size_t seed = 0;

    for (const auto &kv : belief.probs) {
        std::hash<std::string> float_hasher;
        POMDPVertexHash vertex_hasher;
        std::size_t h1 = vertex_hasher(kv.first);
        std::size_t h2 = float_hasher(to_string(kv.second));

        // combine (boost::hash_combine style)
        seed ^= h1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}