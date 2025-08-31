#include "../include/algorithm.hpp"


Algorithm::Algorithm(string action, int classical_state, int depth=-1) {
    this->action = std::move(action);
    this->classical_state = classical_state;
    this->depth = depth;
    this->children_probs = unordered_map<int, double>();
} 

      

bool Algorithm::exist_child_with_cstate(const int &cstate) {
    for (auto child : this->children) {
        if(child->classical_state == cstate) {
            return true;
        }
    }
    return false;
}
