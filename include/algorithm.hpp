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
    unordered_map<int, double> children_probs;

    Algorithm(POMDPAction* action, int classical_state, int depth=-1); 
    bool exist_child_with_cstate(const int &cstate);
};

string to_string(Algorithm * algorithm, const string& tabs="");
bool dump_to_file(const fs::path &, Algorithm *);

#endif