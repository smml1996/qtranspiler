#include "experiments.hpp"
#include "reset.cpp"
#include "utils.hpp"
//
// Created by Stefanie Muroya Lei on 06.09.25.
//
class BasisStatesDiscrimination : public ResetProblem {
public:
    BasisStatesDiscrimination(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
        const set<MethodType> &method_types, const set<QuantumHardware>& hw_list) : ResetProblem(name, precision, with_thermalization, min_horizon, max_horizon, method_types, hw_list) {
        this->set_hidden_index = true;
    };

    Rational postcondition(const Belief &belief, const unordered_map<int, int> &embedding) const override {
        assert (embedding.size() == 1);
        auto state0 = QuantumState({embedding.at(0)}, this->precision);
        auto X = Instruction(GateName::X, embedding.at(0), this->precision);
        auto state1 = state0.apply_instruction(X);
        Rational result("0", "1", this->precision*(this->max_horizon+1));
        for (auto it : belief.probs) {
            auto hybrid_state = it.first->hybrid_state;
            auto qs = hybrid_state->quantum_state;
            if (*qs == state0) {
                if (it.first->hidden_index == 0) {
                    result = result + it.second;
                }
            } else {
                assert (*qs == *state1);
                if (it.first->hidden_index == 1) {
                    result = result + it.second;
                }
            }
        }
        return result;
    }
};
