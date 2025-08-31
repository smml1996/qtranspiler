#ifndef SOLVERS_H
#define SOLVERS_H

#include "pomdp.hpp"
#include "beliefs.hpp"
#include "algorithm.hpp"

typedef function<MyFloat(const Belief &)> f_reward_type;

class SingleDistributionSolver {
    POMDP pomdp;
    f_reward_type get_reward;
    unordered_map<Belief, pair<Algorithm*, MyFloat>, BeliefHash> beliefs_to_rewards;
    public:
        SingleDistributionSolver(const POMDP &pomdp, f_reward_type &get_reward);
        pair<Algorithm*, MyFloat> get_bellman_value(const Belief &current_belief, const int &horizon);
};


class ConvexDistributionSolver {

};

#endif