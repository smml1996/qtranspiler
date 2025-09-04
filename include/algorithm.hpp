#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <vector>
#include <unordered_map>
#include "pomdp.hpp"
#include <filesystem>
#include <iostream>

using namespace std;

namespace fs = std::filesystem;

POMDPAction random_branch("RANDOM_BRANCH", {}, 1, {});

class Algorithm {
public:
    POMDPAction* action;
    vector<Algorithm*> children;
    int classical_state;
    int depth;
    int precision;
    unordered_map<int, double> children_probs;

    Algorithm(POMDPAction* action, int classical_state, int precision, int depth=-1); 
    bool exist_child_with_cstate(const int &cstate);
    bool operator==(const Algorithm &algorithm) const;
    bool has_meas() const;
    bool has_classical_instruction() const;
    bool is_unitary() const;
    void get_successor_classical_states(const int &current_classical_state, unordered_set<int> &result) const;
};

string to_string(Algorithm * algorithm, const string& tabs="");
bool dump_to_file(const fs::path &, Algorithm *);

int get_algorithm_from_list(const vector<Algorithm *> &algorithms, Algorithm* new_algorithm);

Algorithm* algorithm_exists(unordered_map<int, Algorithm*> &mapping_index_algorithm, Algorithm *algorithm);

Algorithm* deep_copy_algorithm(Algorithm *algorithm);

void get_algorithm_end_nodes(Algorithm *algorithm, vector<Algorithm *> &end_nodes);

Algorithm* get_mixed_algorithm(const vector<double> &x, const unordered_map<int, Algorithm *> &mapping_index_algorithm);

#endif