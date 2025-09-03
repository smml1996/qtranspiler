#include "../include/solvers.hpp"
#include <cassert>

SingleDistributionSolver::SingleDistributionSolver(const POMDP &pomdp, const f_reward_type &get_reward, int precision) {
    this->pomdp = pomdp;
    this->get_reward = get_reward;
    this->precision = precision;
}

pair<Algorithm*, MyFloat> SingleDistributionSolver::get_bellman_value(const Belief &current_belief, const int &horizon){
    auto temp_it = this->beliefs_to_rewards.find(current_belief);
    if (temp_it != this->beliefs_to_rewards.end()) {
        return temp_it->second;
    }

    MyFloat curr_belief_val;
    if (this->get_reward(current_belief)) {
        curr_belief_val = MyFloat("1");
    } else {
        curr_belief_val = MyFloat("0");
    }
    
    int current_classical_state = -1;
    for(auto & prob : current_belief.probs) {
        if (current_classical_state == -1) {
            current_classical_state = prob.first->hybrid_state->classical_state->get_memory_val();
        } else {
            assert(prob.first->hybrid_state->classical_state->get_memory_val() == current_classical_state);
        }
    }
    assert(current_classical_state >= 0);
    POMDPAction * HALT_ACTION = new POMDPAction("HALT__", {}, -1, {});
    auto halt_algorithm = new Algorithm(HALT_ACTION, current_classical_state, 0);
    if (horizon == 0) {
        return make_pair(halt_algorithm, curr_belief_val);
    }

    vector< pair< Algorithm*, MyFloat > > bellman_values;

    bellman_values.emplace_back(halt_algorithm, curr_belief_val);
    
    for(auto it = pomdp.actions.begin(); it != pomdp.actions.end(); it++) {
        POMDPAction * action = &(*it);

        // build next_beliefs, separate them by different observables
        map<int, Belief> obs_to_next_beliefs;

        MyFloat zero;
        for(auto & prob : current_belief.probs) {
            auto current_v = prob.first;
            if(prob.second > zero) {
                for (const auto &it_next_v: pomdp.transition_matrix[current_v][action]) {
                    if (it_next_v.second > zero) {
                        auto successor = it_next_v.first;
                        obs_to_next_beliefs[it_next_v.first->hybrid_state->classical_state->get_memory_val()].add_val(successor,
                                                                                  prob.second * it_next_v.second);
                    }
                }
            }
        }
        
        if (!obs_to_next_beliefs.empty()) {
            Algorithm *new_alg_node = new Algorithm(action, current_classical_state, this->precision);
            MyFloat bellman_val;

            int max_depth = 0;
            for(auto & obs_to_next_belief : obs_to_next_beliefs) {
                auto temp = get_bellman_value(obs_to_next_belief.second, horizon-1);
                new_alg_node->children.push_back(temp.first);
                max_depth = max(temp.first->depth, max_depth);
                bellman_val = bellman_val + temp.second;
            }

            new_alg_node->depth = max_depth + 1;
            bellman_values.emplace_back(new_alg_node, bellman_val);
        }
    }

    MyFloat max_val; // this is initialized as zero
    for(auto & bellman_value : bellman_values) {
        max_val = min(max_val, bellman_value.second);
    }

    int shortest_alg_with_max_val = -1;
    for(auto & bellman_value : bellman_values) {
        if (bellman_value.second == max_val) {
            if (shortest_alg_with_max_val == -1) {
                shortest_alg_with_max_val = bellman_value.first->depth;
            } else {
                shortest_alg_with_max_val = min(shortest_alg_with_max_val, bellman_value.first->depth);
            }
        }
    }

    for(auto & bellman_value : bellman_values) {
        if (bellman_value.second == max_val and bellman_value.first->depth == shortest_alg_with_max_val) {
            this->beliefs_to_rewards.insert({current_belief, bellman_value});
            return bellman_value;
        }
    }
    assert(false);
}