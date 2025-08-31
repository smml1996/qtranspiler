#include "../include/algorithm.hpp"
#include <fstream>

Algorithm::Algorithm(POMDPAction* action, int classical_state, int depth=-1) {
    this->action = action;
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

string to_string(Algorithm* algorithm, const string& tabs="") {
    if (algorithm == nullptr) return "";

    string result = tabs + to_string(algorithm->action) + "\n";

    for(auto child : algorithm->children) {
        string child_alg;
        if (algorithm->children.size() > 1) {
            result += tabs + "if c = " + to_string(child->classical_state) + ":\n" ;
            child_alg = to_string(child, tabs+"\t");
        } else {
            child_alg = to_string(child, tabs);
        }
        result += child_alg;
    }
    return result;
}

bool dump_to_file(const fs::path &path, Algorithm * algorithm) {
    // Open file for writing
    std::ofstream out(path);  // creates the file or overwrites if it exists
    if (!out) {
        std::cerr << "Failed to open file: " << path << "\n";
        return 0;
    }


    out << to_string(algorithm);

    out.close();
}
