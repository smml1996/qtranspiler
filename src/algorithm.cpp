#include "algorithm.hpp"

#include <cassert>
#include <fstream>
#include <iostream>
#include "utils.hpp"

Algorithm::Algorithm(POMDPAction* action, int classical_state, int precision, int depth) {
    this->action = action;
    this->classical_state = classical_state;
    this->depth = depth;
    this->children_probs = unordered_map<int, double>();
    this->precision = precision;
}



bool Algorithm::exist_child_with_cstate(const int &cstate) const {
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

string to_string(Algorithm* algorithm, const string& tabs) {
    if (algorithm == nullptr) return "";

    string result = tabs + to_string(algorithm->action) + "\n";

    for(auto child : algorithm->children) {
        string child_alg;
        if (*algorithm->action == random_branch) {
            result += tabs + "{\n";
            string current_tabs = tabs + "\t";

            auto temp_algorithm = new Algorithm(algorithm->action, algorithm->classical_state, algorithm->precision, algorithm->depth);
            double condition_prob = 0.0;
            vector<Algorithm*> new_children;
            for (size_t i = 1; i < algorithm->children.size(); ++i) {
                condition_prob += algorithm->children_probs.at(i);
                temp_algorithm->children.push_back(algorithm->children.at(i));
                temp_algorithm->children_probs[i-1] = algorithm->children_probs.at(i);
            }

            result += to_string(algorithm->children.at(0), tabs + "\t");
            result += "\n } ⊕_" + to_string(condition_prob) + "{\n";
            result += to_string(temp_algorithm, tabs+ "\t");
            result += tabs + "}\n";
            delete temp_algorithm;
        } else {
            if (algorithm->children.size() > 1) {
                result += tabs + "if c = " + to_string(child->classical_state) + ":\n" ;
                child_alg = to_string(child, tabs+"\t");
            } else {
                child_alg = to_string(child, tabs);
            }
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
        return false;
    }
    out << to_string(algorithm);

    out.close();
    return true;
}

int get_algorithm_from_list(const vector<Algorithm *> &algorithms, const Algorithm* new_algorithm) {
    int index = 0;
    for (auto algorithm : algorithms) {
        if (*algorithm == *new_algorithm) {
            return index;
        }
        index++;
    }
    return -1;
}

Algorithm* algorithm_exists(const unordered_map<int, Algorithm*> &mapping_index_algorithm, const Algorithm *algorithm) {
    for (auto it : mapping_index_algorithm) {
        if (*it.second == *algorithm) {
            return it.second;
        }
    }

    return nullptr;
}

Algorithm * deep_copy_algorithm(Algorithm *algorithm)  {
    if (algorithm == nullptr) return algorithm;
    string action = algorithm->action->name;
    int classical_state = algorithm-> classical_state;
    int depth = algorithm->depth;

    Algorithm * algorithm_copy = new Algorithm(algorithm->action, classical_state, depth);

    for (auto child : algorithm->children) {
        algorithm_copy->children.push_back(deep_copy_algorithm(child));
    }

    return algorithm_copy;
}

bool Algorithm::has_meas() const {
    for (auto instruction : this->action->instruction_sequence) {
        if (instruction.instruction_type == InstructionType::Measurement) {
            return true;
        }
    }

    return false;
}

bool Algorithm::has_classical_instruction() const {
    for (auto instruction : this->action->instruction_sequence) {
        if (instruction.instruction_type == InstructionType::Classical) {
            return true;
        }
    }

    return false;

}
bool Algorithm::is_unitary() const {
    for (auto instruction : this->action->instruction_sequence) {
        if ((instruction.instruction_type != InstructionType::UnitarySingleQubit) && (instruction.instruction_type != InstructionType::UnitaryMultiQubit)) {
            return false;
        }
    }

    return true;
}
void Algorithm::get_successor_classical_states(const int &current_classical_state, unordered_set<int> &result) const {
    // get all bits that might change
    unordered_set<int> bits;
    for (auto instruction : this->action->instruction_sequence) {
        if (instruction.instruction_type == InstructionType::Measurement) {
            bits.insert(instruction.c_target);
        }
    }

    result.insert(current_classical_state);

    for (auto bit : bits) {
        result.insert(current_classical_state ^ (1 << bit)); // toggle bit
    }
}

void get_algorithm_end_nodes(Algorithm *algorithm, vector<Algorithm *> &end_nodes) {
    if (algorithm->children.size() == 0) {
        end_nodes.push_back(algorithm);
        return;
    }

   if (algorithm->has_meas()) {
        unordered_set<int> all_c_succs;
        algorithm->get_successor_classical_states(algorithm->classical_state, all_c_succs);
        if (algorithm->children.size() < all_c_succs.size()) {
            // TODO: this can be better (some classical states cannot happen)

            assert(algorithm->children.size() == 1);

            if (algorithm->children[0]->classical_state == 0) {
                end_nodes.push_back(algorithm);
            }
        }
   }
    

    for (auto child : algorithm->children) {
        get_algorithm_end_nodes(child, end_nodes);
    }
}

Algorithm *get_mixed_algorithm(const vector<double> &x, const unordered_map<int, Algorithm *> &mapping_index_algorithm, int initial_classical_state) {
    Algorithm * new_head = new Algorithm(&random_branch, initial_classical_state, -1);
    int count = 0;
    for(int i = 0; i < x.size(); i++) {
        if(x[i] > 0) {
            new_head->children.push_back(mapping_index_algorithm.find(i)->second);
            assert(new_head->children_probs.find(i) == new_head->children_probs.end());
            new_head->children_probs.insert({count, x[i]});
            count += 1;
        }
    }
    return new_head;
}
