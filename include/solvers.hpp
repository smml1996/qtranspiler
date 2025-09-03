#ifndef SOLVERS_H
#define SOLVERS_H

#include "pomdp.hpp"
#include "beliefs.hpp"
#include "algorithm.hpp"

using f_reward_type = std::function<MyFloat(const Belief&, const unordered_map<int, int> &)>;

class SingleDistributionSolver {
    POMDP pomdp;
    f_reward_type get_reward;
    int precision;
    unordered_map<Belief, pair<Algorithm*, MyFloat>, BeliefHash> beliefs_to_rewards;
    public:
        SingleDistributionSolver(const POMDP &pomdp, const f_reward_type &get_reward, int precision);
        pair<Algorithm*, MyFloat> get_bellman_value(const Belief &current_belief, const int &horizon);
};


class ConvexDistributionSolver {

};

#endif