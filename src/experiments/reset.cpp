#ifndef RESET_H
#define RESET_H
#include <cassert>

#include "experiments.hpp"
#include <iostream>
using namespace std;
class ResetProblem : public Experiment {
    public:
    ResetProblem(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
const set<MethodType> &method_types, const set<QuantumHardware> &hw_list) :
Experiment(name, precision, with_thermalization, min_horizon, max_horizon, false, method_types, hw_list){};
        ResetProblem () : Experiment() {
            this-> name = "reset";
            this->precision = 8;
            this->with_thermalization = false;
            this->min_horizon = 2;
            this->max_horizon = 7;
            this->set_hidden_index = false;
        }

        vector<pair<HybridState*, double>> get_initial_distribution(unordered_map<int, int> &embedding) const override {
            vector<pair<HybridState*, double>> result;

            ClassicalState * classical_state = new ClassicalState();

            auto X0 = Instruction(GateName::X, embedding.at(0));

            // prepare first bell state
            auto state0 = new QuantumState(get_qubits_used(embedding), this->precision);
            result.emplace_back(new HybridState(state0, classical_state), 0.5);

            // prepare second bell state
            auto state1 = state0->apply_instruction(X0);
            assert (!(*state1 == *state0));
            result.emplace_back(new HybridState(state1, classical_state), 0.5);

            return result;
        }

        Rational postcondition(const Belief &belief, const unordered_map<int, int> &embedding) const override {
            const unique_ptr<QuantumState> state0(new QuantumState({embedding.at(0)}, this->precision));
            Rational answer("0", "1", this->precision*(this->max_horizon+1));

            for(auto it : belief.probs) {
                if (*(it.first->hybrid_state->quantum_state) == *state0) {
                    answer = answer + it.second;
                }
            }

            return answer;
        }

        vector<POMDPAction> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {

            assert(embedding.size() == 1);
            assert(embedding.find(0) != embedding.end());

            
            auto X0 = POMDPAction("X0", hardware_spec.to_basis_gates_impl(Instruction(GateName::X, 
                embedding.at(0))), this->precision, {Instruction(GateName::X, 0)});

            auto P0 = POMDPAction("P0", 
                {Instruction(GateName::Meas, embedding.at(0), 0)},
                this->precision, 
                {Instruction(GateName::Meas, 0, 0)});

            return {X0, P0};
        }

        vector<unordered_map<int, int>> get_hardware_scenarios(HardwareSpecification const & hardware_spec) const override {

            vector<unordered_map<int, int>> result;
            unordered_set<int> parsed_pivots;
            auto pivot_qubits = get_meas_pivot_qubits(hardware_spec);
            for (auto target: pivot_qubits) {
                unordered_map<int, int> d_temp;
                d_temp[0] = target;
                result.push_back(d_temp);
                parsed_pivots.insert(target);
            }
                
            return result;

        }
};
#endif