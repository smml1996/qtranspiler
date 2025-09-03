#include "../include/algorithm.hpp"
#include <fstream>
#include <utils.hpp>

Algorithm::Algorithm(POMDPAction* action, int classical_state, int precision, int depth=-1) {
    this->action = action;
    this->classical_state = classical_state;
    this->depth = depth;
    this->children_probs = unordered_map<int, double>();
    this->precision = precision;
} 

      

bool Algorithm::exist_child_with_cstate(const int &cstate) {
    for (auto child : this->children) {
        if(child->classical_state == cstate) {
            return true;
        }
    }
    return false;
}

bool Algorithm::operator==(const Algorithm &other) const {
    if (other.action != this->action) {
        return false;
    }

    if (this->classical_state != other.classical_state) {
        return false;
    }

    if (this->children.size() != other.children.size()) {
        return false;
    }

    int c = 0;

    for (Algorithm * child : this->children) {
        double prob_child = this->children_probs.at(c);
        bool found = false;
        int c2 = 0;
        for (Algorithm* other_child : other.children) {
            double prob_other = other.children_probs.at(c2);

            if (is_close(prob_other, prob_child, this->precision)) {
                if (*other_child == *child) {
                    found = true;
                    break;
                }
            }
            c2 += 1;
        }
        c += 1;
        if (!found) {
            return false;
        }
    }
    return true;
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

int get_algorithm_from_list(const vector<Algorithm *> &algorithms, Algorithm* new_algorithm) {
    int index = 0;
    for (auto algorithm : algorithms) {
        if (*algorithm == *new_algorithm) {
            return index;
        }
        index++;
    }
    return -1;
}
