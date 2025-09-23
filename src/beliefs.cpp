#include "beliefs.hpp"

#include <iostream>

#include "utils.hpp"

Rational Belief::get_sum(int precision) const {
    Rational result("0", "1", precision);

    for (auto & prob : this->probs) {
        result = result + prob.second;
    }

    return result;
}

Rational Belief::get(POMDPVertex *v) {
    if(this->probs.find(v) == this->probs.end()){
        return Rational();
    }
    return this->probs[v];
}

void Belief::set_val(POMDPVertex *v, const Rational &prob) {
    if (prob.numerator == MyFloat("0", prob.precision)) return;
    this->probs.insert_or_assign(v, prob);
}

void Belief::add_val(POMDPVertex *v, const Rational &val) {
    this->probs[v] = this->get(v) + val;

    if (this->probs[v].numerator == MyFloat("0", val.precision)) {
        this->probs.erase(v);
    }
}

bool Belief::is_normalized(int precision) const {
    auto my_sum = to_double(this->get_sum(precision));
    if (is_close(my_sum, 1.0, precision)) {
        return true;
    }

    return false;
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
        std::size_t h2 = float_hasher(gate_to_string(kv.second.numerator) + gate_to_string(kv.second.denominator));

        // combine (boost::hash_combine style)
        seed ^= h1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}

Rational l1_norm(const Belief &b1, const Belief &b2, int precision) {
    Rational result("0", "1", precision);
    for (auto it = b1.probs.begin(); it != b1.probs.end(); it++) {
        auto it2 = b2.probs.find(it->first);
        if (it2 != b2.probs.end()) {
            auto temp = Rational("-1", "1", precision) * it2->second ;
            result = result + abs(it->second + temp);
        }
    }
    return result;
}

Belief normalize_belief(const Belief &belief, int precision) {
    Belief result;
    Rational total("0", "1", precision);
    for (auto it : belief.probs) {
        total = total + it.second;
    }

    for (auto it : belief.probs) {
        Rational value = it.second / total;
        result.set_val(it.first, value);
    }

    return result;
}
