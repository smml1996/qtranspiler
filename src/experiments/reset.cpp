#ifndef RESET_H
#define RESET_H
#include <cassert>

#include "experiments.hpp"
using namespace std;
class ResetProblem : public Experiment {

    public:
    ResetProblem(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
const set<MethodType> &method_types, const set<QuantumHardware> &hw_list, bool optimize) :
Experiment(name, precision, with_thermalization, min_horizon, max_horizon, false, method_types, hw_list, optimize){};
        ResetProblem () : Experiment() {
            this-> name = "reset";
            this->precision = 8;
            this->with_thermalization = false;
            this->min_horizon = 2;
            this->max_horizon = 7;
            this->set_hidden_index = false;
        }

        vector<pair<shared_ptr<HybridState>, double>> get_initial_distribution(unordered_map<int, int> &embedding) const override {
            vector<pair<shared_ptr<HybridState>, double>> result;

            auto classical_state = make_shared<ClassicalState>();

            auto X0 = Instruction(GateName::X, embedding.at(0));

            // prepare first bell state
            auto state0 = make_shared<QuantumState>(get_qubits_used(embedding), this->precision);
            result.emplace_back(new HybridState(state0, classical_state), 0.5);

            // prepare second bell state
            auto state1 = state0->apply_instruction(X0);
            assert (embedding.size() == 1);
            assert (!(*state1 == *state0));
            result.emplace_back(make_shared<HybridState>(state1, classical_state), 0.5);

            return result;
        }

        MyFloat postcondition(const Belief &belief, const unordered_map<int, int> &embedding) override {
            auto state0 = make_shared<QuantumState>(vector<int>({embedding.at(0)}), this->precision);
            MyFloat answer("0", this->precision*(this->max_horizon+1));

            for(const auto& it : belief.probs) {
                auto is_target = this->target_vertices.find(it.first->id);
                if (is_target != this->target_vertices.end()) {
                    if (is_target->second) {
                        answer = answer + it.second;
                    }
                } else if (*(it.first->hybrid_state->quantum_state) == *state0) {
                    answer = answer + it.second;
                    this->target_vertices[it.first->id] =  true;
                } else {
                    this->target_vertices[it.first->id] =  false;
                }
            }

            return answer;
        }

        double postcondition_double(const VertexDict &belief, const unordered_map<int, int> &embedding) override {
                auto state0 = make_shared<QuantumState>(vector<int>({embedding.at(0)}), this->precision);
                double answer = 0;

                for(const auto& it : belief.probs) {
                    auto is_target = this->target_vertices.find(it.first->id);
                    if (is_target != this->target_vertices.end()) {
                        if (is_target->second) {
                            answer = answer + it.second;
                        }
                    } else if (*(it.first->hybrid_state->quantum_state) == *state0) {
                        answer = answer + it.second;
                        this->target_vertices[it.first->id] =  true;
                    } else {
                        this->target_vertices[it.first->id] =  false;
                    }
                }

                return answer;
            }

        vector<shared_ptr<POMDPAction>> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {

            assert(embedding.size() == 1);
            assert(embedding.find(0) != embedding.end());

            
            auto X0 = make_shared<POMDPAction>("X0", hardware_spec.to_basis_gates_impl(Instruction(GateName::X,
                embedding.at(0))), this->precision, vector<Instruction>({Instruction(GateName::X, 0)}));

            auto P0 = make_shared<POMDPAction>("P0",
                vector<Instruction>({Instruction(GateName::Meas, embedding.at(0), 0)}),
                this->precision, 
                vector<Instruction>({Instruction(GateName::Meas, 0, 0)}));

            return {X0, P0};
        }

        vector<unordered_map<int, int>> get_hardware_scenarios(HardwareSpecification const & hardware_spec) const override {
            vector<unordered_map<int, int>> result;
            auto pivot_qubits = get_meas_pivot_qubits(hardware_spec, 0);
            for (auto target: pivot_qubits) {
                unordered_map<int, int> d_temp;
                d_temp[0] = target;
                result.push_back(d_temp);
            }
            return result;
        }

    shared_ptr<Algorithm> get_textbook_algorithm(MethodType &method, const int &horizon) override {
        assert (method == MethodType::SingleDistBellman);
        auto hardware_spec = HardwareSpecification(QuantumHardware::PerfectHardware, false, false);
        auto action_mappings = this->get_actions_dictionary(hardware_spec, 1);
        shared_ptr<Algorithm> on1 = make_shared<Algorithm>(action_mappings["X0"], 0, 10, 1);
        shared_ptr<Algorithm> on0 = make_shared<Algorithm>(make_shared<POMDPAction>(HALT_ACTION), 0, 10, 1);
        return this->build_meas_sequence(horizon-1, 0, action_mappings["P0"], make_shared<ClassicalState>(), on0, on1);
    }
};
#endif