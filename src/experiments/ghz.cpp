#ifndef GHZ_H
#define GHZ_H
#include <absl/strings/internal/str_format/extension.h>

#include "experiments.hpp"

inline bool are_adjacent_qubits(const unordered_map<int, unordered_set<int>> &graph, int qubit1,
                         const unordered_set<int> &qubits) {
    queue<int> q;
    unordered_set<int> visited;

    q.push(qubit1);
    visited.insert(qubit1);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        auto it = graph.find(current);
        if (it != graph.end()) {
            for (int succ : it->second) {
                if (visited.find(succ) == visited.end()) {
                    if (qubits.find(succ) != qubits.end()) {
                        visited.insert(succ);
                        q.push(succ);
                    }
                }
            }
        }
    }
    for (auto qubit : qubits) {
        if (visited.find(qubit) == visited.end()) {
            return false;
        }
    }
    return true;
}

inline bool is_repeated_embedding(const vector<unordered_map<int, int>> &all_embeddings, const unordered_map<int, int> &current) {
    unordered_set<int> current_set;
    for (auto it : current) {
        current_set.insert(it.second);
    }
        
    for (auto embedding : all_embeddings) {
        unordered_set<int> temp_s;
        for (const auto it : embedding)
            temp_s.insert(it.second);
        if (temp_s == current_set)
            return true;
    }
    return false;
}

// GHZ state preparation of 3 qubits
class GHZStatePreparation3 : public Experiment {
    public:
    GHZStatePreparation3(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
    const set<MethodType> &method_types, const set<QuantumHardware>& hw_list) :
Experiment(name, precision, with_thermalization, min_horizon, max_horizon, false, method_types, hw_list){};
        GHZStatePreparation3() : Experiment() {
            this->name = "ghz_state_preparation3";
            this->precision = 8;
            this->with_thermalization = false;
            this->min_horizon = 3;
            this->max_horizon = 3;
            this->set_hidden_index = false;
            this->method_types.erase(MethodType::ConvexDist); // there is only one initial state, is not worth it
        };

        virtual QuantumState* get_target_state(const unordered_map<int, int> &embedding) const {
            auto H0 = Instruction(GateName::H, embedding.at(0));
            auto CX01 = Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1));
            auto CX12 = Instruction(GateName::Cnot, vector<int>({embedding.at(1)}),embedding.at(2));
            auto qs_ = QuantumState({embedding.at(0), embedding.at(1), embedding.at(2)}, this->precision);
            auto qs0 = qs_.apply_instruction(H0);
            auto qs1 = qs0->apply_instruction(CX01);
            delete qs0;
            auto qs = qs1->apply_instruction(CX12);
            delete qs1;
            return qs;
        }


        vector<pair<HybridState*, double>> get_initial_distribution(unordered_map<int, int> &embedding) const override {
            vector<pair<HybridState*, double>> result;

            ClassicalState * classical_state = new ClassicalState();

            // the zero state
            QuantumState * initial_state = new QuantumState(get_qubits_used(embedding), this->precision);
            result.push_back(make_pair(new HybridState(initial_state, classical_state), 0.25));

            return result;
        }

        Rational postcondition(const Belief &belief, const unordered_map<int, int> &embedding) const override {
            Rational answer("0", "1", this->precision*(this->max_horizon+1));

            auto local_target_state = this->get_target_state(embedding);
            for (auto it : belief.probs) {
                if(*it.first->hybrid_state->quantum_state == *local_target_state) {
                    answer = answer + it.second;
                }
            }

            delete local_target_state;
            return answer;
        }

        virtual vector<unordered_map<int, int>> get_hardware_scenarios(HardwareSpecification const & hardware_spec) const override {
            vector<unordered_map<int, int>> result;
            for (int qubit1 = 0; qubit1 < hardware_spec.num_qubits; qubit1++) {
                for (int qubit2 = 0; qubit2 < hardware_spec.num_qubits; qubit2++) {
                    for (int qubit3 = 0; qubit3 < hardware_spec.num_qubits; qubit3++) {
                        unordered_set<int >current_set({qubit1, qubit2, qubit3});
                        if (current_set.size() == 3) {
                            if (are_adjacent_qubits(hardware_spec.digraph, qubit1, {qubit1, qubit2, qubit3})) {
                                    unordered_map<int, int> d_temp;
                                    d_temp[0] = qubit1;
                                    d_temp[1] = qubit2;
                                    d_temp[2] = qubit3;
                                    if (!is_repeated_embedding(result, d_temp))
                                        result.push_back(d_temp);
                            }
                        }
                    }
                }
            }
            return result;
        }

        vector<POMDPAction*> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {
            vector<POMDPAction*> result;
            for (auto it : embedding) {
                result.push_back(
                    new POMDPAction("H" + to_string(it.first),
                        hardware_spec.to_basis_gates_impl(Instruction(GateName::H, it.second)),
                        this->precision,
                        {Instruction(GateName::H, it.first)}
                        )
                    );
            }

            for (auto it1 : embedding) {
                int v_control = it1.first;
                int control = it1.second;
                for (auto it2 : embedding) {
                    int v_target = it2.first;
                    int target = it2.second;
                    if (control != target) {
                        unique_ptr<Instruction> instruction = make_unique<Instruction>(GateName::Cnot, vector<int>({control}), target);
                        if (hardware_spec.instructions_to_channels.find(instruction.get()) != hardware_spec.instructions_to_channels.end() ) {
                            result.push_back(
                                new POMDPAction(
                                    "CX" + to_string(v_control)+"-"+to_string(v_target),
                                    {*instruction},
                                    this->precision,
                                    {Instruction(GateName::Cnot, vector<int>({v_control}), v_target)}
                                    )
                                );
                        }
                    }
                }
            }
            return result;
        }
};

// GHZ state preparation of 4 qubits
class GHZStatePreparation4 : public GHZStatePreparation3 {
    public:
        GHZStatePreparation4(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon, const set<MethodType> &method_types, const set<QuantumHardware>& hw_list) : GHZStatePreparation3(name, precision, with_thermalization, min_horizon, max_horizon, method_types, hw_list){};
        GHZStatePreparation4() : GHZStatePreparation3() {
            this->name = "ghz_state_preparation4";
            this->precision = 8;
            this->with_thermalization = false;
            this->min_horizon = 4;
            this->max_horizon = 4;
            this->set_hidden_index = false;
            this->method_types.erase(MethodType::ConvexDist); // there is only one initial state, is not worth it
        };

        QuantumState* get_target_state(const unordered_map<int, int> &embedding) const override{
            auto H0 = Instruction(GateName::H, embedding.at(0));
            auto CX01 = Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1));
            auto CX12 = Instruction(GateName::Cnot, vector<int>({embedding.at(1)}),embedding.at(2));
            auto CX23 = Instruction(GateName::Cnot, vector<int>({embedding.at(2)}),embedding.at(3));
            auto qs_ = QuantumState({embedding.at(0), embedding.at(1), embedding.at(2)}, this->precision);
            auto qs0 = qs_.apply_instruction(H0);
            auto qs1 = qs0->apply_instruction(CX01);
            delete qs0;
            auto qs2 = qs1->apply_instruction(CX12);
            delete qs1;
            auto qs = qs2->apply_instruction(CX23);
            delete qs2;
            return qs;
        }

        vector<unordered_map<int, int>> get_hardware_scenarios(HardwareSpecification const & hardware_spec) const override {
            vector<unordered_map<int, int>> result;
            for (int qubit1 = 0; qubit1 < hardware_spec.num_qubits; qubit1++) {
                for (int qubit2 = 0; qubit2 < hardware_spec.num_qubits; qubit2++) {
                    for (int qubit3 = 0; qubit3 < hardware_spec.num_qubits; qubit3++) {
                        for (int qubit4 = 0; qubit4 < hardware_spec.num_qubits; qubit4++) {
                            unordered_set<int >current_set({qubit1, qubit2, qubit3, qubit4});
                            if (current_set.size() == 4) {
                                if (are_adjacent_qubits(hardware_spec.digraph, qubit1, {qubit1, qubit2, qubit3, qubit4})) {
                                        unordered_map<int, int> d_temp;
                                        d_temp[0] = qubit1;
                                        d_temp[1] = qubit2;
                                        d_temp[2] = qubit3;
                                        d_temp[3] = qubit4;
                                        if (!is_repeated_embedding(result, d_temp))
                                            result.push_back(d_temp);
                                }
                            }
                        }
                    }
                }
            }
            return result;
        }
};
#endif