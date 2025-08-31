#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <vector>
#include <unordered_map>
static auto HALT_ACTION = "halt";

using namespace std;
class Algorithm {
public:
    string action;
    vector<Algorithm*> children;
    int classical_state;
    int depth;
    unordered_map<int, double> children_probs;

    Algorithm(string action, int classical_state, int depth=-1); 

    bool exist_child_with_cstate(const int &cstate);
};

#endif