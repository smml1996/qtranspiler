#include "solvers.hpp"
#include "ortools/linear_solver/linear_solver.h"
#include <iostream>

#include <cassert>

bool SingleDistributionSolver::is_belief_visited(const Belief &belief) const {
    for (auto it : this->beliefs_to_rewards) {
        auto existing_belief = it.first;
        if (existing_belief == belief) {
                return true;
        }
    }
    return false;
}

Rational SingleDistributionSolver::get_closest_L1(const Belief &belief) const {
    Rational result("-1", "1", this->precision);
    bool first = true;
    for (auto it : this->beliefs_to_rewards) {
        auto existing_belief = it.first;
        auto current_l1_norm = l1_norm(existing_belief, belief, this->precision);
        if (first || result > current_l1_norm) {
            first = false;
            result = current_l1_norm;
        }
    }

    if (first) {
        assert (this->beliefs_to_rewards.size() == 0);
        return Rational("0", "1", this->precision);
    }

    return result;
}

SingleDistributionSolver::SingleDistributionSolver(const POMDP &pomdp, const f_reward_type &get_reward, int precision, const unordered_map<int, int> & embedding) {
    this->pomdp = pomdp;
    this->get_reward = get_reward;
    this->precision = precision;
    this->embedding = embedding;
    assert(precision != -1);
    this->error = Rational("0", "1", this->precision);
}

pair<Algorithm*, Rational> SingleDistributionSolver::get_bellman_value(const Belief &current_belief, const int &horizon){
    Belief curr_belief_normalized = normalize_belief(current_belief, this->precision);
    auto temp_it = this->beliefs_to_rewards.find(curr_belief_normalized);
    if (temp_it != this->beliefs_to_rewards.end()) {
        return temp_it->second;
    }

    Rational curr_belief_val = this->get_reward(current_belief, this->embedding);
    
    int current_classical_state = -1;
    for(auto & prob : current_belief.probs) {
        if (current_classical_state == -1) {
            current_classical_state = prob.first->hybrid_state->classical_state->get_memory_val();
        } else {
            assert(prob.first->hybrid_state->classical_state->get_memory_val() == current_classical_state);
        }
    }
    assert(current_classical_state >= 0);
    auto halt_algorithm = new Algorithm(&HALT_ACTION, current_classical_state, 0);
    if (horizon == 0) {
        return make_pair(halt_algorithm, curr_belief_val);
    }

    vector< pair< Algorithm*, Rational > > bellman_values;

    bellman_values.emplace_back(halt_algorithm, curr_belief_val);
    
    for (auto & it : pomdp.actions) {
        POMDPAction * action = &it;

        // build next_beliefs, separate them by different observables
        map<int, Belief> obs_to_next_beliefs;

        for(auto & prob : current_belief.probs) {
            Rational zero("0", "1", this->precision);
            auto current_v = prob.first;
            assert(prob.second > zero);
            for (const auto &it_next_v: pomdp.transition_matrix[current_v][action]) {
                if (it_next_v.second > zero) {

                    auto successor = it_next_v.first;
                    assert(prob.first->hybrid_state != nullptr);
                    assert(successor != nullptr);
                    assert(successor->hybrid_state != nullptr);
                    assert (it_next_v.first->hybrid_state != nullptr);
                    assert (it_next_v.first->hybrid_state->classical_state != nullptr);
                    obs_to_next_beliefs[it_next_v.first->hybrid_state->classical_state->get_memory_val()].add_val(successor,
                                                                              prob.second * it_next_v.second);
                }
            }
        }
        
        if (!obs_to_next_beliefs.empty()) {
            auto new_alg_node = new Algorithm(action, current_classical_state, this->precision);
            Rational bellman_val("0", "1", this->precision);

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

    Rational max_val("0", "1", this->precision); // this is initialized as zero
    for(auto & bellman_value : bellman_values) {
        max_val = max(max_val, bellman_value.second);
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
        if (bellman_value.second == max_val && bellman_value.first->depth == shortest_alg_with_max_val) {
            this->beliefs_to_rewards.insert({curr_belief_normalized, bellman_value});
            return bellman_value;
        }
    }
    assert(false);
}



pair<Algorithm*, Rational> SingleDistributionSolver::PBVI_solve(const Belief &current_belief, const int &horizon) {
    Belief curr_belief_normalized = normalize_belief(current_belief, this->precision);

    auto temp_it = this->beliefs_to_rewards.find(curr_belief_normalized);
    if (temp_it != this->beliefs_to_rewards.end()) {
        return temp_it->second;
    }

    Rational curr_belief_val = this->get_reward(current_belief, this->embedding);

    int current_classical_state = -1;
    for(auto & prob : current_belief.probs) {
        if (current_classical_state == -1) {
            current_classical_state = prob.first->hybrid_state->classical_state->get_memory_val();
        } else {
            assert(prob.first->hybrid_state->classical_state->get_memory_val() == current_classical_state);
        }
    }
    assert(current_classical_state >= 0);
    auto halt_algorithm = new Algorithm(&HALT_ACTION, current_classical_state, 0);
    if (horizon == 0) {
        return make_pair(halt_algorithm, curr_belief_val);
    }

    vector<pair<Belief, map<int, Belief>>> candidate_beliefs;

    // for picking candidate belief that has the highest distance
    unordered_map<int, Belief> temp;
    temp[current_classical_state] = current_belief;
    pair<Belief, unordered_map<int, Belief>> best_candidate = make_pair(curr_belief_normalized, temp);
    Rational furthest_value("0", "1", this->precision);
    POMDPAction* best_action = &HALT_ACTION;

    for (auto & it : pomdp.actions) {
        POMDPAction * action = &it;

        unordered_map<int, Belief> obs_to_next_beliefs; // for each belief we compute the sub-distributions to which it leads
        Belief next_belief; // we also compute the real belief which should be normalized

        for(auto & prob : current_belief.probs) {
            Rational zero("0", "1", this->precision);
            auto current_v = prob.first;

            assert(prob.second > zero);
            if (pomdp.transition_matrix.find(current_v) != pomdp.transition_matrix.end()) {
                if (pomdp.transition_matrix.at(current_v).find(action) != pomdp.transition_matrix.at(current_v).end()) {
                    for (const auto &it_next_v: pomdp.transition_matrix.at(current_v).at(action)) {
                        if (it_next_v.second > zero) {
                            auto successor = it_next_v.first;
                            obs_to_next_beliefs[it_next_v.first->hybrid_state->classical_state->get_memory_val()].add_val(successor,
                                                                                  prob.second * it_next_v.second);
                            next_belief.add_val(successor,prob.second * it_next_v.second);
                        }
                    }
                }
            }
        }

        next_belief = normalize_belief(next_belief, this->precision);
        if (!this->is_belief_visited(next_belief)) {
            Rational closest_value = this->get_closest_L1(next_belief);
            if (furthest_value == Rational("-1", "1", this->precision) || furthest_value < closest_value) {
                furthest_value = closest_value;
                best_candidate = make_pair(next_belief, obs_to_next_beliefs);
                best_action = action;
            }
        }
    }

    auto new_alg_node = new Algorithm(best_action, current_classical_state, this->precision);
    Rational bellman_val("0", "1", this->precision);

    int max_depth = 0;
    for(auto & obs_to_next_belief : best_candidate.second) {
        auto temp2 = get_bellman_value(obs_to_next_belief.second, horizon-1);
        new_alg_node->children.push_back(temp2.first);
        max_depth = max(temp2.first->depth, max_depth);
        bellman_val = bellman_val + temp2.second;
    }

    new_alg_node->depth = max_depth + 1;
    pair<Algorithm*, Rational> result = make_pair(new_alg_node, bellman_val);
    this->beliefs_to_rewards.insert({curr_belief_normalized, result});
    this->error = max(this->error, furthest_value);
    return result;
}

double SingleDistributionSolver::get_error(const int &horizon) const {
    return to_double(this->error) * horizon;
}


ConvexDistributionSolver::ConvexDistributionSolver(const POMDP &pomdp, const f_reward_type &get_reward, int precision, const unordered_map<int, int> &embedding) {
    this->pomdp = pomdp;
    this->get_reward = get_reward;
    this->precision = precision;
    this->embedding = embedding;
    this->initial_classical_state = -1;
}

Rational get_algorithm_acc(POMDP &pomdp, Algorithm*& algorithm, const Belief &current_belief, const f_reward_type &get_reward, const unordered_map<int, int> &embedding, int precision) {
    Rational curr_belief_val = get_reward(current_belief, embedding);

    if (algorithm == nullptr) {
        return curr_belief_val;
    }
    POMDPAction* action = algorithm->action;
    if (*action == HALT_ACTION) {
        return curr_belief_val;
    }

    // build next_beliefs, separate them by different observables
    unordered_map<int, Belief> obs_to_next_beliefs;

    Rational zero("0", "1", precision);
    for(auto & prob : current_belief.probs) {
        POMDPVertex* current_v = prob.first;
        if(prob.second > zero) {
            for (auto &it_next_v: pomdp.transition_matrix[current_v][action]) {
                if (it_next_v.second > zero) {
                    obs_to_next_beliefs[it_next_v.first->hybrid_state->classical_state->get_memory_val()].add_val(it_next_v.first,
                                                                              prob.second * it_next_v.second);
                }else {
                    assert(it_next_v.second == zero);
                }
            }
        }
    }
    assert(algorithm->children.size() == obs_to_next_beliefs.size());

    if (!obs_to_next_beliefs.empty()) {
        Rational bellman_val("0", "1", precision);
        
        for (int i = 0; i < algorithm->children.size(); i++) {
            assert(obs_to_next_beliefs.find(algorithm->children[i]->classical_state) != obs_to_next_beliefs.end());
            bellman_val = bellman_val + get_algorithm_acc(pomdp, algorithm->children[i], obs_to_next_beliefs[algorithm->children[i]->classical_state], get_reward, embedding, precision);
        }
        return bellman_val;
    } else {
        return curr_belief_val;
    }
}

void ConvexDistributionSolver::set_minimax_values( 
    Algorithm* algorithm, 
    const vector<POMDPVertex*> &initial_states,
    unordered_map<int, unordered_map<int, double>> &minimax_matrix,
    unordered_map<int, Algorithm*> &mapping_index_algorithm) {
    
    // Algorithm *old_algorithm = algorithm_exists(mapping_index_algorithm, algorithm);
    // if(old_algorithm != nullptr) {
    //     write_algorithm_file(old_algorithm, "temp_old.json");
    //     write_algorithm_file(algorithm, "temp_new.json");
    //     assert(false);
    // }

    int current_alg_index = minimax_matrix.size();
    mapping_index_algorithm[current_alg_index] = deep_copy_algorithm(algorithm);
    
    // the current algorithm index should not exist
    assert(minimax_matrix.find(current_alg_index) == minimax_matrix.end());
    minimax_matrix[current_alg_index] = unordered_map<int, double>();

    for (int index = 0; index < initial_states.size(); index++) {
        assert(minimax_matrix[current_alg_index].find(index) == minimax_matrix[current_alg_index].end());

        Belief initial_belief;
        initial_belief.set_val(initial_states[index], Rational("1", "1", this->precision));

        minimax_matrix[current_alg_index][index] = to_double(get_algorithm_acc(pomdp,algorithm, initial_belief, this->get_reward, this->embedding, precision));
    }
    // write_algorithm_file(algorithm, "alg_" +to_string(current_alg_index) + ".json");
}



int get_succ_classical_state(const Algorithm *current) {
    assert(!current->has_meas());
    if (current->is_unitary()) {
        return current->classical_state;
    }

    assert(current->has_classical_instruction());

    int answer = current->classical_state;
    for(Instruction instruction : current->action->instruction_sequence) {
        
        if(instruction.instruction_type == InstructionType::Classical) {
            if (instruction.gate_name == GateName::Write1) {
                answer = answer | (1 << instruction.c_target);
            } else {
                assert(instruction.gate_name == GateName::Write0);
                answer &= ~(1 << instruction.c_target);
            }
            
        }
    }

    return answer;

}



void ConvexDistributionSolver::get_matrix_maximin(const vector<POMDPVertex*> &initial_states, 
    Algorithm *current_algorithm, 
    unordered_map<int, unordered_map<int, double>> &minimax_matrix,
    const int &max_horizon,
    unordered_map<int, Algorithm*> &mapping_index_algorithm) {
        if(algorithm_exists(mapping_index_algorithm, current_algorithm) != nullptr) {
            return;
        }
        this->set_minimax_values(current_algorithm, initial_states, minimax_matrix, mapping_index_algorithm);

        vector<Algorithm *> end_nodes;
        if (current_algorithm != nullptr)
            get_algorithm_end_nodes(current_algorithm, end_nodes);

        if (current_algorithm == nullptr) {
            
            for (auto action : pomdp.actions) {
                Algorithm * new_node = new Algorithm(&action, this->initial_classical_state, this->precision, 1); // assumes initial classical state is 0
                get_matrix_maximin(initial_states, new_node, minimax_matrix, max_horizon, mapping_index_algorithm);
                delete new_node;
            }
            
            
        } else {
            for (Algorithm* end_node : end_nodes) {
                if (end_node->depth < max_horizon) {
                    for (POMDPAction action : pomdp.actions) {
                        if (end_node->has_meas()){
                            int next_cstate = 0;
                            if (end_node->children.size() == 0) {
                                Algorithm * new_node = new Algorithm(&action, next_cstate, end_node->depth + 1);
                                end_node->children.push_back(new_node);
                                get_matrix_maximin(initial_states, current_algorithm, minimax_matrix, max_horizon, mapping_index_algorithm);
                                end_node->children.pop_back();
                                delete new_node;

                                next_cstate = 1;
                                new_node = new Algorithm(&action, next_cstate, end_node->depth + 1);
                                end_node->children.push_back(new_node);
                                get_matrix_maximin(initial_states, current_algorithm, minimax_matrix, max_horizon, mapping_index_algorithm);
                                end_node->children.pop_back();
                                delete new_node;

                            } else {
                                assert(end_node->children.size() == 1);

                                if (end_node->children[0]->classical_state == 0) {
                                    next_cstate = 1;
                                    Algorithm * new_node = new Algorithm(&action, next_cstate, end_node->depth + 1);
                                    end_node->children.push_back(new_node);
                                    get_matrix_maximin(initial_states, current_algorithm, minimax_matrix, max_horizon, mapping_index_algorithm);
                                    end_node->children.pop_back();
                                    delete new_node;
                                }
                            }

                            

                        } else {
                            assert(end_node->children.size() == 0);
                            int next_classical_state = get_succ_classical_state(end_node);
                            Algorithm * new_node = new Algorithm(&action, next_classical_state, end_node->depth + 1);
                            assert(!end_node->exist_child_with_cstate(next_classical_state));
                            end_node->children.push_back(new_node);
                            get_matrix_maximin(initial_states, current_algorithm, minimax_matrix, max_horizon, mapping_index_algorithm);
                            end_node->children.pop_back();
                            delete new_node;
                        }
                    }
                }
            }   
        }
}

int get_classical_state(const vector<POMDPVertex*> &states) {
    int answer = -1;
    for (auto state: states) {
        if (answer == -1) {
            answer = state->hybrid_state->classical_state->get_memory_val();
        } else {
            assert(answer == state->hybrid_state->classical_state->get_memory_val());
        }
    }

    return answer;
}

pair<vector<double>, double> ConvexDistributionSolver::solve_lp_maximin(const unordered_map<int, unordered_map<int, double>> &maximin_matrix, const int &n_algorithms, const int &n_initial_states) {


    // for (int i = 0; i < maximin_matrix.size(); i++) {
    //     for(int j = 0; j < (*maximin_matrix.find(i)).second.size(); j++) {
    //         cout << " " << (*(*maximin_matrix.find(i)).second.find(j)).second;
    //     }
    //     cout << endl;
    // }

    operations_research::MPSolver solver("max_v", operations_research::MPSolver::GLOP_LINEAR_PROGRAMMING);

    // Variables: x_i >= 0
    std::vector<operations_research::MPVariable*> x(n_algorithms);
    for (int i = 0; i < n_algorithms; ++i) {
        x[i] = solver.MakeNumVar(0.0, 1.0, "x_" + std::to_string(i));
    }

    // Variable: v
    operations_research::MPVariable* v = solver.MakeNumVar(0.0, INFINITY, "v");

    // Constraint: sum_i x_i = 1
    operations_research::MPConstraint* prob_sum = solver.MakeRowConstraint(1.0, 1.0);
    for (int i = 0; i < n_algorithms; ++i) {
        prob_sum->SetCoefficient(x[i], 1.0);
    }

    // Constraints: sum_i x_i * M_ij >= v  for all j
    for (int j = 0; j < n_initial_states; ++j) {
        operations_research::MPConstraint* c = solver.MakeRowConstraint(0.0, solver.infinity());
        for (int i = 0; i < n_algorithms; ++i) {
            auto temp = *maximin_matrix.find(i);
            c->SetCoefficient(x[i], ((temp.second.find(j)))->second);
        }
        c->SetCoefficient(v, -1.0); // sum_i(...) - v >= 0  → sum_i(...) >= v
    }

    // Objective: maximize v
    operations_research::MPObjective* objective = solver.MutableObjective();
    objective->SetCoefficient(v, 1.0);
    objective->SetMaximization();

    // Solve
    auto result = solver.Solve();
    vector<double> mixed_algorithm;
    cout << "v: " << v->solution_value() << endl;
    double final_value = v->solution_value();
    if (result == operations_research::MPSolver::OPTIMAL) {
        for (int i = 0; i < n_algorithms; ++i) {
            mixed_algorithm.push_back(x[i]->solution_value());
        }
    }

    return make_pair(mixed_algorithm, final_value);
}

pair<Algorithm*, double> ConvexDistributionSolver::solve(const vector<POMDPVertex*> &initial_states, const int &horizon) {
    unordered_map<int, unordered_map<int, double>> maximin_matrix;
    unordered_map<int, Algorithm *> mapping_index_algorithm;
    
    this->initial_classical_state = get_classical_state(initial_states);

    this->get_matrix_maximin(initial_states, nullptr, maximin_matrix, horizon, mapping_index_algorithm);

    auto result = this->solve_lp_maximin(maximin_matrix, maximin_matrix.size(), initial_states.size());

    Algorithm * mixed_algorithm = get_mixed_algorithm(result.first, mapping_index_algorithm, this->initial_classical_state);
    return make_pair(mixed_algorithm, result.second);
}
