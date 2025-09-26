#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <vector>
#include <unordered_map>
#include "pomdp.hpp"
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

inline POMDPAction random_branch("RANDOM_BRANCH", {}, 1, {});
inline POMDPAction HALT_ACTION("HALT__", {}, -1, {});

class Algorithm {
public:
    POMDPAction* action;
    vector<Algorithm*> children;
    cpp_int classical_state;
    int depth;
    int precision;
    unordered_map<int, double> children_probs;

    Algorithm(POMDPAction* action, const cpp_int &classical_state, int precision, int depth=-1);
    bool exist_child_with_cstate(const cpp_int &cstate) const;
    bool operator==(const Algorithm &algorithm) const;
    bool has_meas() const;
    bool has_classical_instruction() const;
    bool is_unitary() const; // returns true if all instructions used by the action of the current node use only unitary instructions (children are not checked)
    void get_successor_classical_states(const cpp_int &current_classical_state, unordered_set<cpp_int> &result) const; // returns a set containing all reachable classical states by executing the current acction (children are not checked)
};

string to_string(Algorithm * algorithm, const string& tabs="");
bool dump_to_file(const fs::path &, Algorithm *);

int get_algorithm_from_list(const vector<Algorithm *> &algorithms, const Algorithm* new_algorithm);

Algorithm* algorithm_exists(const unordered_map<int, Algorithm*> &mapping_index_algorithm, const Algorithm *algorithm);

Algorithm* deep_copy_algorithm(Algorithm *algorithm);

void get_algorithm_end_nodes(Algorithm *algorithm, vector<Algorithm *> &end_nodes);

Algorithm* get_mixed_algorithm(const vector<double> &x, const unordered_map<int, Algorithm *> &mapping_index_algorithm, cpp_int initial_classical_state);

#endif