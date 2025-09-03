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
};

string to_string(Algorithm * algorithm, const string& tabs="");
bool dump_to_file(const fs::path &, Algorithm *);

int get_algorithm_from_list(const vector<Algorithm *> &algorithms, Algorithm* new_algorithm);

#endif