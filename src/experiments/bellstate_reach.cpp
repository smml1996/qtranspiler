//
// Created by Stefanie Muroya Lei on 01.10.25.
//

#include <cassert>

#include "experiments.hpp"
#include "utils.hpp"
#include <unordered_set>
#include "bitflip.cpp"

using namespace std;

class BellStateReach : public IPMABitflip {
    public:
    BellStateReach(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
    const set<MethodType>& method_types, const set<QuantumHardware>& hw_list, bool optimize) : IPMABitflip(name, precision, with_thermalization, min_horizon, max_horizon,
                method_types, hw_list, optimize) {this->method_types.insert(MethodType::ConvexDist);}

    BellStateReach()  : IPMABitflip(){ this->name = "BellStateReach"; };

    vector<pair<shared_ptr<HybridState>, double>> get_initial_distribution(unordered_map<int, int> &embedding) const override {
        vector<pair<shared_ptr<HybridState>, double>> result;
        shared_ptr<ClassicalState> classical_state0 = make_shared<ClassicalState>();

        auto H0 = Instruction(GateName::H, embedding.at(0));

        auto X0 = Instruction(GateName::X, embedding.at(0));
        auto Z0 = Instruction(GateName::Z, embedding.at(0));

        auto X3 = Instruction(GateName::X, embedding.at(3));

        auto  state0 =  make_shared<QuantumState>(get_qubits_used(embedding), this->precision);
        result.push_back(make_pair(make_shared<HybridState>(state0, classical_state0), 0.2)); // |00>

        auto state1 = state0->apply_instruction(X0); // |10>
        result.push_back(make_pair(make_shared<HybridState>(state1, classical_state0), 0.2));

        auto state_plus = state0->apply_instruction(H0);
        state_plus = state_plus->apply_instruction(X3); // |+1>
        result.push_back(make_pair(make_shared<HybridState>(state_plus, classical_state0), 0.3));

        auto state_minus = state_plus->apply_instruction(Z0);
        result.push_back(make_pair(make_shared<HybridState>(state_minus, classical_state0), 0.3));

        return result;
    }

    MyFloat postcondition(const Belief &belief, const unordered_map<int, int> &embedding) override {
        MyFloat result("0", this->precision*(this->max_horizon+1));
        for (auto it : belief.probs) {
            auto is_target = this->target_vertices.find(it.first->id);
            if (is_target != this->target_vertices.end()) {
                if (is_target->second) {
                    result = result + it.second;
                }
            } else {
                auto hybrid_state = it.first->hybrid_state;
                auto qs = hybrid_state->quantum_state;
                auto current_rho = qs->multi_partial_trace(vector<int>({embedding.at(3)}));
                assert (current_rho.size() == 4);
                if (are_matrices_equal(current_rho, this->BELL0, this->precision) || are_matrices_equal(current_rho, this->BELL1, this->precision)) { // equality up to a threshold because there might be floating point overflow
                    result = result + it.second;
                    this->target_vertices[it.first->id] =  true;
                }  else {
                    this->target_vertices[it.first->id] =  false;
                }
            }

        }
        return result;
    }

    double postcondition_double(const VertexDict &belief, const unordered_map<int, int> &embedding) override {
        double result = 0.0;
        for (auto it : belief.probs) {
            auto is_target = this->target_vertices.find(it.first->id);
            if (is_target != this->target_vertices.end()) {
                if (is_target->second) {
                    result = result + it.second;
                }
            } else {
                auto hybrid_state = it.first->hybrid_state;
                auto qs = hybrid_state->quantum_state;
                auto current_rho = qs->multi_partial_trace(vector<int>({embedding.at(3)}));
                assert (current_rho.size() == 4);
                if (are_matrices_equal(current_rho, this->BELL0, this->precision) || are_matrices_equal(current_rho, this->BELL1, this->precision)) { // equality up to a threshold because there might be floating point overflow
                    result = result + it.second;
                    this->target_vertices[it.first->id] =  true;
                    }  else {
                        this->target_vertices[it.first->id] =  false;
                    }
            }

        }
        return result;
    }
    [[nodiscard]] bool guard(const shared_ptr<POMDPVertex>& vertex, const unordered_map<int, int>& embedding, const shared_ptr<POMDPAction>& action) const override {
        return true;
    }


    virtual vector<shared_ptr<POMDPAction>> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {

        assert(embedding.size() == 3);
        assert(embedding.find(0) != embedding.end());
        assert(embedding.find(1) != embedding.end());
        assert(embedding.find(3) != embedding.end());


        vector<Instruction> meas_data_seq({Instruction(GateName::Meas, embedding.at(3), 3)});
        vector<Instruction> v_meas_data_seq({Instruction(GateName::Meas, 3, 3)});
        auto MEASData = make_shared<POMDPAction>("MEASData",meas_data_seq, this->precision, v_meas_data_seq);

        vector<Instruction> seq_prepare_bell;
        for (auto it : hardware_spec.to_basis_gates_impl(Instruction(GateName::H, embedding.at(0)))) {
            seq_prepare_bell.push_back(it);
        }
        seq_prepare_bell.push_back(Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1)));

        auto PrepareBell = make_shared<POMDPAction>("PrepareBell",
            seq_prepare_bell,
            this->precision, vector<Instruction>({
                Instruction(GateName::H, 0),
                Instruction(GateName::Cnot,
                    vector<int>({0}),
                    1)}));


        auto CX01 = make_shared<POMDPAction>("CX01",vector<Instruction>({Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1))}), this->precision, vector<Instruction>({Instruction(GateName::Cnot, vector<int>({0}), 1)}));
        return {PrepareBell, CX01, MEASData};
    }

    static set<int> get_fourth(const HardwareSpecification &hardware_spec, unordered_set<int> invalid_qubits) {
        auto vals = get_meas_pivot_qubits(hardware_spec, 0);
        for (auto it : invalid_qubits) {
            vals.erase(it);
        }
        return vals;
    }

    vector<int> get_shortest_path(const HardwareSpecification &hardware_spec, const int &source, const int &target) const {
        queue<pair<int, int>> q;
        unordered_set<int> visited;

        q.push(make_pair(source, 0));
        visited.insert(source);
        unordered_map<int, int> paths;
        while (!q.empty()) {
            auto current = q.front();
            auto qubit = current.first;
            auto distance = current.second;
            assert(qubit != target);
            q.pop();


            auto it = hardware_spec.digraph.find(qubit);
            if (it != hardware_spec.digraph.end()) {
                for (auto qubit2 : hardware_spec.digraph.at(qubit)) {
                    if (paths.find(qubit2)  == paths.end()) {
                        paths[qubit2] = qubit;
                    }
                    if (qubit2 == target) {
                        vector<int> answer;
                        int last_seen = target;
                        answer.push_back(target);
                        while (last_seen != source) {
                            last_seen = paths[last_seen];
                            answer.push_back(last_seen);
                        }
                        reverse(answer.begin(), answer.end());
                        return answer;
                    }

                    if (visited.find(qubit2) == visited.end()) {
                        q.push(make_pair(qubit2, distance + 1));
                        visited.insert(qubit2);
                    }
                }
            }
        }
        return {};
    }
    vector<unordered_map<int, int>> get_hardware_scenarios(HardwareSpecification const & hardware_spec) const override {
        if (hardware_spec.get_hardware() == QuantumHardware::PerfectHardware ) {
            unordered_map<int, int> m;
            m[0] = 0;
            m[1] = 1;
            m[3] = 3;
            return {m};
        }
        vector<unordered_map<int, int>> result;
        for (auto it_source : hardware_spec.digraph) {
            int qubit0 = it_source.first;
            for (auto qubit1 : it_source.second) {
                assert(qubit0 != qubit1);
                auto possible_fourth = get_fourth(hardware_spec, {qubit0, qubit1});
                for (auto qubit3 : possible_fourth) {
                    unordered_map<int, int> m;
                    m[0] = qubit0;
                    m[1] = qubit1;
                    m[3] = qubit3;
                    result.push_back(m);
                }
            }
        }
        return result;
    }
};