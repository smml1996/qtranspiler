//
// Created by Stefanie Muroya Lei on 01.10.25.
//

#include <cassert>

#include "experiments.hpp"
#include "utils.hpp"
#include <complex>
#include <unordered_set>
#include "bitflip.cpp"

using namespace std;

class BellStateReach : public IPMABitflip {
    public:
    BellStateReach(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
    const set<MethodType>& method_types, const set<QuantumHardware>& hw_list, bool optimize) : IPMABitflip(name, precision, with_thermalization, min_horizon, max_horizon,
                method_types, hw_list, optimize) {}

    vector<pair<shared_ptr<HybridState>, double>> get_initial_distribution(unordered_map<int, int> &embedding) const override {
        vector<pair<shared_ptr<HybridState>, double>> result;
        shared_ptr<ClassicalState> classical_state0 = make_shared<ClassicalState>();

        auto H0 = Instruction(GateName::H, embedding.at(0));
        auto CX01 = Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1));

        auto X0 = Instruction(GateName::X, embedding.at(0));
        auto Z0 = Instruction(GateName::Z, embedding.at(0));

        auto X1 = Instruction(GateName::X, embedding.at(1));
        auto X2 = Instruction(GateName::X, embedding.at(2));

        auto  state0 =  make_shared<QuantumState>(get_qubits_used(embedding), this->precision);
        state0 = state0->apply_instruction(X2);
        result.push_back(make_pair(make_shared<HybridState>(state0, classical_state0), 0.25));

        auto state1 = state0->apply_instruction(X0);
        state1 = state1->apply_instruction(X1); // |111>
        result.push_back(make_pair(make_shared<HybridState>(state1, classical_state0), 0.25));

        auto bell0 = state0->apply_instruction(H0);
        bell0 = bell0->apply_instruction(CX01);
        result.push_back(make_pair(make_shared<HybridState>(bell0, classical_state0), 0.25));

        auto bell1 = bell0->apply_instruction(Z0);
        result.push_back(make_pair(make_shared<HybridState>(bell1, classical_state0), 0.25));

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
                auto current_rho = qs->multi_partial_trace(vector<int>({embedding.at(2)}));
                assert (current_rho.size() == 4);
                if (are_matrices_equal(current_rho, this->BELL0, this->precision) ||
                    are_matrices_equal(current_rho, this->BELL1, this->precision) ||
                    are_matrices_equal(current_rho, this->BELL2, this->precision) ||
                    are_matrices_equal(current_rho, this->BELL3, this->precision)) { // equality up to a threshold because there might be floating point overflow
                    result = result + it.second;
                    this->target_vertices[it.first->id] =  true;
                }  else {
                    this->target_vertices[it.first->id] =  false;
                }
            }

        }
        return result;
    }

    virtual vector<shared_ptr<POMDPAction>> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {

        assert(embedding.size() == 3);
        assert(embedding.find(0) != embedding.end());
        assert(embedding.find(1) != embedding.end());
        assert(embedding.find(2) != embedding.end());


        auto MEAS2 = make_shared<POMDPAction>("MEAS",
            vector<Instruction>({Instruction(GateName::Meas, embedding.at(0), 0), Instruction(GateName::Meas, embedding.at(1), 1)}),
            this->precision,
            vector<Instruction>({Instruction(GateName::Meas, 0, 0), Instruction(GateName::Meas, 1, 1)}));

        vector<Instruction> seq_bell_meas = {Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1))};
        for (auto it : hardware_spec.to_basis_gates_impl(Instruction(GateName::H, embedding.at(0)))) {
            seq_bell_meas.push_back(it);
        }

        seq_bell_meas.push_back(Instruction(GateName::Meas, embedding.at(0), 0));
        seq_bell_meas.push_back(Instruction(GateName::Meas, embedding.at(1), 1));

        auto MEASBell = make_shared<POMDPAction>("MEASBell",
            seq_bell_meas,
            this->precision,
            vector<Instruction>({
                Instruction(GateName::Cnot, vector<int>({0}), 1),
                Instruction(GateName::H, 0), Instruction(GateName::Meas, 0, 0),
                Instruction(GateName::Meas, embedding.at(1), 1)}));

        auto PA = make_shared<POMDPAction>("PA",
            vector<Instruction>({Instruction(GateName::Meas, embedding.at(2), 2)}),
            this->precision,
            vector<Instruction>({Instruction(GateName::Meas, 2, 2)}));

        vector<Instruction> seq_prepare_bell;
        for (auto it : hardware_spec.to_basis_gates_impl(Instruction(GateName::H, embedding.at(0)))) {
            seq_prepare_bell.push_back(it);
        }
        seq_prepare_bell.push_back(Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1)));

        auto prepare_bell = make_shared<POMDPAction>("PrepareBell",
            seq_prepare_bell,
            this->precision, vector<Instruction>({Instruction(H, 0), Instruction(GateName::Cnot, vector<int>({0}), 1)}));

        return {PA, MEAS2, MEASBell, prepare_bell};
    }

    vector<unordered_map<int, int>> get_hardware_scenarios(HardwareSpecification const & hardware_spec) const override {
        if (hardware_spec.get_hardware() == QuantumHardware::PerfectHardware ) {
            unordered_map<int, int> m;
            m[0] = 0;
            m[1] = 1;
            m[2] = 2;
            return {m};
        }
        vector<unordered_map<int, int>> result;
        unordered_set<int> pivot_qubits;
        if (hardware_spec.get_hardware() != QuantumHardware::PerfectHardware && hardware_spec.num_qubits < 14) {

            for(int qubit = 0; qubit < hardware_spec.num_qubits; qubit++) {
                if (hardware_spec.get_qubit_indegree(qubit) > 1) {
                    pivot_qubits.insert(qubit);
                }

            }
        } else {
            pivot_qubits = get_meas_pivot_qubits(hardware_spec, 0);
        }
        auto sorted_couplers = hardware_spec.get_sorted_qubit_couplers2();
        for (auto ancilla : pivot_qubits) {
            unordered_map<int, int> d_temp;
            d_temp[0] = sorted_couplers.at(0).first.first;
            d_temp[1] = sorted_couplers.at(0).first.second;
            d_temp[2] = ancilla;

            if (d_temp.at(0) != d_temp.at(1) && d_temp.at(0) != d_temp.at(2) && d_temp.at(1) != d_temp.at(2) && !does_result_contains_d(result, d_temp)) result.push_back(d_temp);

            unordered_map<int, int> d_temp2;
            d_temp2[0] = sorted_couplers.at(sorted_couplers.size()-1).first.first;
            d_temp2[1] = sorted_couplers.at(sorted_couplers.size()-1).first.second;
            d_temp2[2] = ancilla;
            if (d_temp2.at(0) != d_temp2.at(1) && d_temp2.at(0) != d_temp2.at(2) && d_temp2.at(1) != d_temp2.at(2) && !does_result_contains_d(result, d_temp2)) result.push_back(d_temp2);

        }
        return result;
    }

};