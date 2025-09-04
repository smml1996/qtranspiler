#ifndef SOLVERS_H
#define SOLVERS_H

#include "pomdp.hpp"
#include "beliefs.hpp"
#include "algorithm.hpp"
#include <functional>

using f_reward_type = std::function<MyFloat(const Belief&, const unordered_map<int, int> &)>;

class PBVISolution {
public:
    Algorithm* algorithm;
    MyFloat guarantee;
    MyFloat error;
    PBVISolution(Algorithm* alg, const MyFloat &guarantee, const MyFloat &error);
};
class SingleDistributionSolver {
    POMDP pomdp;
    f_reward_type get_reward;
    int precision;
    unordered_map<Belief, pair<Algorithm*, MyFloat>, BeliefHash> beliefs_to_rewards;
    unordered_map<int, int> embedding;
    MyFloat error;

    // PBVI methods
    bool is_belief_visited(const Belief &belief) const;
    MyFloat get_closest_L1(const Belief &belief) const;
    public:
        SingleDistributionSolver(const POMDP &pomdp, const f_reward_type &get_reward, int precision, const unordered_map<int, int> & embedding);
        pair<Algorithm*, MyFloat> get_bellman_value(const Belief &current_belief, const int &horizon);

        // PBVI
        pair<Algorithm*, MyFloat> PBVI_solve(const Belief &current_beliefs, const int &horizon);
        double get_error(const int &horizon) const;

};


class ConvexDistributionSolver {
    POMDP pomdp;
    f_reward_type get_reward;
    int precision;
    unordered_map<int, int> embedding;
    int initial_classical_state;
    void get_matrix_maximin(const vector<POMDPVertex*> &initial_states,
            Algorithm *current_algorithm,
            unordered_map<int, unordered_map<int, double>> &minimax_matrix,
            const int &max_horizon,
            unordered_map<int, Algorithm*> &mapping_index_algorithm);

    void set_minimax_values(
            Algorithm* algorithm,
            const vector<POMDPVertex*> &initial_states,
            unordered_map<int, unordered_map<int, double>> &minimax_matrix,
            unordered_map<int, Algorithm*> &mapping_index_algorithm);

    static pair<vector<double>, double> solve_lp_maximin(const unordered_map<int, unordered_map<int, double>> &maximin_matrix, const int &n_algorithms, const int &n_initial_states);
    public:
        ConvexDistributionSolver(const POMDP &pomdp, const f_reward_type &get_reward, int precision, const unordered_map<int, int> & embedding);
        pair<Algorithm*, double> solve(const vector<POMDPVertex*> &initial_states, const int &horizon);
};

#endif