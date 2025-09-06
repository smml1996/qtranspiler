#ifndef BITFLIP_H
#define BITFLIP_H

#include <cassert>

#include "experiments.hpp"
#include "utils.hpp"
#include <complex>
#include <unordered_set>

using namespace std;

inline vector<pair<int, int>> get_selected_couplers(const HardwareSpecification &hardware_spec, int target) {
    vector<pair<int, double>> couplers = hardware_spec.get_sorted_qubit_couplers(target);
    pair<int, int> first_pair = {couplers[0].first, couplers[1].first}; // most noisy pair of couplers for this target

    pair<int, int> second_pair = {couplers[couplers.size() -1].first, couplers[couplers.size() -2].first}; // least noisy pair of couplers for this target
    return {first_pair, second_pair};
}


inline bool does_result_contains_d(const vector<unordered_map<int, int>> &result, const unordered_map<int, int> &d) {
    for (auto d_ : result) {
        unordered_set<int> controls1({d.at(0), d.at(1)});
        unordered_set<int> controls2({d_.at(0), d_.at(1)});
        if(d_.at(2) == d.at(2) && controls1 == controls2) return true;
    }
    return false;
}
    

class IPMABitflip : public Experiment {

    bool is_even_parity_bell_state(const QuantumState &qs);

    public:
    vector<vector<complex<double>>> BELL0;
    vector<vector<complex<double>>> BELL1;
    vector<vector<complex<double>>> BELL2;
    vector<vector<complex<double>>> BELL3;
    IPMABitflip(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
        const set<MethodType>& method_types, const set<QuantumHardware>& hw_list) :
            Experiment(name, precision, with_thermalization, min_horizon, max_horizon,
                false, method_types, hw_list) {this->setup();};
        IPMABitflip() : Experiment() {
            this->name = "bitflip_ipma";
            this->precision = 8;
            this->with_thermalization = false;
            this->min_horizon = 4;
            this->max_horizon = 7;
            this->set_hidden_index = false;
            this->method_types.erase(MethodType::ConvexDist);
            this->setup();

        }

        void setup() {
            this->BELL0 = vector<vector<complex<double>>>(
                4, vector<complex<double>>(4)
            );
            this->BELL0[0][0] = complex<double>(0.5, 0.0);
            this->BELL0[3][0] = complex<double>(0.5, 0.0);
            this->BELL0[0][3] = complex<double>(0.5, 0.0);
            this->BELL0[3][3] = complex<double>(0.5, 0.0);


            this->BELL1 = vector<vector<complex<double>>>(
                4, vector<complex<double>>(4)
            );
            this->BELL1[0][0] = complex<double>(0.5, 0.0);
            this->BELL1[3][0] = complex<double>(-0.5, 0.0);
            this->BELL1[0][3] = complex<double>(-0.5, 0.0);
            this->BELL1[3][3] = complex<double>(0.5, 0.0);

            this->BELL2 = vector<vector<complex<double>>>(
                4, vector<complex<double>>(4)
            );
            this->BELL2[1][1] = complex<double>(0.5, 0.0);
            this->BELL2[1][2] = complex<double>(0.5, 0.0);
            this->BELL2[2][1] = complex<double>(0.5, 0.0);
            this->BELL2[2][2] = complex<double>(0.5, 0.0);

            this->BELL3 = vector<vector<complex<double>>>(
                4, vector<complex<double>>(4)
            );
            this->BELL3[1][1] = complex<double>(0.5, 0.0);
            this->BELL3[1][2] = complex<double>(-0.5, 0.0);
            this->BELL3[2][1] = complex<double>(-0.5, 0.0);
            this->BELL3[2][2] = complex<double>(0.5, 0.0);
        }

        [[nodiscard]] bool guard(const POMDPVertex& vertex, const unordered_map<int, int>& embedding, const POMDPAction& action) const override {
            if (action.instruction_sequence[0].gate_name != GateName::Meas) return true;
            auto qs = vertex.hybrid_state->quantum_state;
            auto P0 = Instruction(GateName::P0, embedding.at(2));
            auto P1 = Instruction(GateName::P1, embedding.at(2));

            unique_ptr<QuantumState> qs0 = unique_ptr<QuantumState>(qs->apply_instruction(P0));
            unique_ptr<QuantumState> qs1 = unique_ptr<QuantumState>(qs->apply_instruction(P1));

            if (qs0 != nullptr) {
                
                auto pt0 = qs0->multi_partial_trace(vector<int>({embedding.at(2)}));
                if (!is_matrix_in_list(pt0, {BELL0, BELL1, BELL2, BELL3}, this->precision)) return false;
            }
                
            if (qs1 != nullptr) {
                auto pt1 = qs1->multi_partial_trace(vector<int>({embedding.at(2)}));
                return is_matrix_in_list(pt1, {BELL0, BELL1, BELL2, BELL3}, this->precision);
            }
                
            return true;

        }

        vector<pair<HybridState*, double>> get_initial_distribution(unordered_map<int, int> &embedding) const override {
            vector<pair<HybridState*, double>> result;

            ClassicalState * classical_state = new ClassicalState();


            auto H0 = Instruction(GateName::H, embedding.at(0));
            auto CX01 = Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1));
            auto X0 = Instruction(GateName::X, embedding.at(0));
            auto Z0 = Instruction(GateName::Z, embedding.at(0));

            // prepare first bell state
            unique_ptr<QuantumState>  temp0 = make_unique<QuantumState>(get_qubits_used(embedding), this->precision);
            unique_ptr<QuantumState>  temp1  = unique_ptr<QuantumState>(temp0->apply_instruction(H0));
            QuantumState *bell0 = temp1->apply_instruction(CX01);
            result.push_back(make_pair(new HybridState(bell0, classical_state), 0.25));

            // prepare second bell state
            auto bell1 = bell0->apply_instruction(X0);
            result.push_back(make_pair(new HybridState(bell1, classical_state), 0.25));
        
            // prepare third bell state
            auto bell2 = bell0->apply_instruction(Z0);
            result.push_back(make_pair(new HybridState(bell2, classical_state), 0.25));

            // preapre fourth bell state
            auto bell3 = bell2->apply_instruction(X0);
            result.push_back(make_pair(new HybridState(bell3, classical_state), 0.25));

            return result;
        }

        Rational postcondition(const Belief &belief, const unordered_map<int, int> &embedding) const override {
            Rational result("0", "1", this->precision*(this->max_horizon+1));
            for (auto it : belief.probs) {
                auto hybrid_state = it.first->hybrid_state;
                auto qs = hybrid_state->quantum_state;
                auto current_rho = qs->multi_partial_trace(vector<int>({embedding.at(2)}));
                assert (current_rho.size() == 4);
                if (are_matrices_equal(current_rho, this->BELL0, this->precision) || are_matrices_equal(current_rho, this->BELL1, this->precision)) { // equality up to a threshold because there might be floating point overflow
                    result = result + it.second;
                } 
            }
            return result;
        }

    virtual vector<POMDPAction> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {

            assert(embedding.size() == 3);
            assert(embedding.find(0) != embedding.end());
            assert(embedding.find(1) != embedding.end());
            assert(embedding.find(2) != embedding.end());

            
            auto X0 = POMDPAction("X0", hardware_spec.to_basis_gates_impl(Instruction(GateName::X, 
                embedding.at(0))), this->precision, {Instruction(GateName::X, embedding.at(0))});

            auto P2 = POMDPAction("P2", 
                {Instruction(GateName::Meas, embedding.at(2), 2)},
                this->precision, 
                {Instruction(GateName::Meas, embedding.at(2), 2)});

            auto CX02 = POMDPAction("CX02", 
                hardware_spec.to_basis_gates_impl(Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(2)))
                , this->precision, {Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(2))});

            auto CX12 = POMDPAction("CX12", 
                hardware_spec.to_basis_gates_impl(Instruction(GateName::Cnot, vector<int>({embedding.at(1)}), embedding.at(2))), 
                this->precision, 
                {Instruction(GateName::Cnot, vector<int>({embedding.at(1)}), embedding.at(2))});

            return {X0, P2, CX02, CX12};
        }

        vector<unordered_map<int, int>> get_hardware_scenarios(HardwareSpecification const & hardware_spec) const override {
            vector<unordered_map<int, int>> result;
            unordered_set<int> pivot_qubits;
            if (hardware_spec.num_qubits < 14) {
                
                for(int qubit = 0; qubit < hardware_spec.num_qubits; qubit++) {
                    if (hardware_spec.get_qubit_indegree(qubit) > 1) {
                        pivot_qubits.insert(qubit);
                    }
                        
                }
            } else {
                pivot_qubits = get_meas_pivot_qubits(hardware_spec);
            }

            for (auto target : pivot_qubits) {
                for (auto p : get_selected_couplers(hardware_spec, target)) {
                    unordered_map<int, int> d_temp;
                    d_temp[0] = p.first;
                    d_temp[1] = p.second;
                    d_temp[2] = target;
                    if (!does_result_contains_d(result, d_temp)) result.push_back(d_temp);
                }
            }
            return result; 
        }
};


class IPMA2Bitflip : public IPMABitflip {
public:
    IPMA2Bitflip(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
        const set<MethodType> &method_types, const set<QuantumHardware>& hw_list) :
    IPMABitflip(name, precision, with_thermalization, min_horizon, max_horizon, method_types, hw_list){};
    IPMA2Bitflip() : IPMABitflip() {
        this->name = "bitflip_ipma2";
    }

    vector<POMDPAction> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {

            assert(embedding.size() == 3);
            assert(embedding.find(0) != embedding.end());
            assert(embedding.find(1) != embedding.end());
            assert(embedding.find(2) != embedding.end());

            
            auto X0 = POMDPAction("X0", hardware_spec.to_basis_gates_impl(Instruction(GateName::X, 
                embedding.at(0))), this->precision, {Instruction(GateName::X, embedding.at(0))});

            auto P2 = POMDPAction("P2", 
                {Instruction(GateName::Meas, embedding.at(2), 2)},
                this->precision, 
                {Instruction(GateName::Meas, embedding.at(2), 2)});
            
            auto vCX02_instructions = hardware_spec.to_basis_gates_impl(Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(2)));

            auto vCX12_instructions = hardware_spec.to_basis_gates_impl(Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1)));

            for (auto ins : vCX12_instructions) {
                vCX02_instructions.push_back(ins);
            }

            vector<Instruction> pseudo_instruction_CX = {Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(2)), Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1))};

            auto CX = POMDPAction("CX", 
                vCX02_instructions, this->precision, pseudo_instruction_CX);

            return {X0, P2, CX};
        }
};

class IPMA3Bitflip : public IPMABitflip {
    public:
    IPMA3Bitflip(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
        const set<MethodType> &method_types, const set<QuantumHardware>& hw_list) :
    IPMABitflip(name, precision, with_thermalization, min_horizon, max_horizon, method_types, hw_list){};
    IPMA3Bitflip() : IPMABitflip() {
        this->name = "bitflip_ipma2";
    }

    vector<POMDPAction> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {

            assert(embedding.size() == 3);
            assert(embedding.find(0) != embedding.end());
            assert(embedding.find(1) != embedding.end());
            assert(embedding.find(2) != embedding.end());

            
            auto X0 = POMDPAction("X0", hardware_spec.to_basis_gates_impl(Instruction(GateName::X, 
                embedding.at(0))), this->precision, {Instruction(GateName::X, embedding.at(0))});

            auto P2 = POMDPAction("P2", 
                {Instruction(GateName::Meas, embedding.at(2), 2)},
                this->precision, 
                {Instruction(GateName::Meas, embedding.at(2), 2)});
            
            auto vCX02_instructions = hardware_spec.to_basis_gates_impl(Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(2)));

            auto vCX12_instructions = hardware_spec.to_basis_gates_impl(Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1)));

            for (auto ins : vCX12_instructions) {
                vCX02_instructions.push_back(ins);
            }

            vector<Instruction> pseudo_instruction_CX = {Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(2)), Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1))};

            auto CX = POMDPAction("CX", 
                vCX02_instructions, this->precision, pseudo_instruction_CX);

            
            auto X2 = POMDPAction("X2", hardware_spec.to_basis_gates_impl(Instruction(GateName::X, 
                embedding.at(2))), this->precision, {Instruction(GateName::X, embedding.at(2))});
            return {X0, P2, CX, X2};
        }
};

class CXHBitflip : public IPMABitflip {
    public:
    CXHBitflip(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
        const set<MethodType> &method_types, const set<QuantumHardware>& hw_list) :
    IPMABitflip(name, precision, with_thermalization, min_horizon, max_horizon, method_types, hw_list){};
    CXHBitflip() : IPMABitflip() {
            this->name = "bitflip_cxh";
            this->min_horizon = 4;
            this->max_horizon = 7;
    };

    vector<POMDPAction> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {

            assert(embedding.size() == 3);
            assert(embedding.find(0) != embedding.end());
            assert(embedding.find(1) != embedding.end());
            assert(embedding.find(2) != embedding.end());

            
            auto H1 = POMDPAction("H1", hardware_spec.to_basis_gates_impl(Instruction(GateName::H, 
                embedding.at(1))), this->precision, {Instruction(GateName::H, embedding.at(0))});

            auto H2 = POMDPAction("H2", hardware_spec.to_basis_gates_impl(Instruction(GateName::H, 
                embedding.at(2))), this->precision, {Instruction(GateName::H, embedding.at(0))});

            auto P2 = POMDPAction("P2", 
                {Instruction(GateName::Meas, embedding.at(2), 2)},
                this->precision, 
                {Instruction(GateName::Meas, embedding.at(2), 2)});

            auto CX21 = POMDPAction("CX21", 
                hardware_spec.to_basis_gates_impl(Instruction(GateName::Cnot, vector<int>({embedding.at(2)}), embedding.at(1)))
                , this->precision, {Instruction(GateName::Cnot, vector<int>({embedding.at(2)}), embedding.at(1))});

            auto CX01 = POMDPAction("CX01", 
                hardware_spec.to_basis_gates_impl(Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1))), 
                this->precision, 
                {Instruction(GateName::Cnot, vector<int>({embedding.at(0)}), embedding.at(1))});

            return {H2, H1, CX21, CX01, P2};
        }
};

// CONVEX experiments
class BellStateDiscrimination2: public IPMA2Bitflip {
    map<int, vector<vector<complex<double>>>> indices_to_matrix;
public:
    BellStateDiscrimination2(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
        const set<MethodType> &method_types, const set<QuantumHardware>& hw_list) : IPMA2Bitflip(name, precision, with_thermalization, min_horizon, max_horizon, method_types, hw_list) {

        this->set_hidden_index = true;
        this->indices_to_matrix[0] = this->BELL0;
        this->indices_to_matrix[1] = this->BELL1;
        this->indices_to_matrix[2] = this->BELL2;
        this->indices_to_matrix[3] = this->BELL3;
    };

    Rational postcondition(const Belief &belief, const unordered_map<int, int> &embedding) const override {
        Rational result("0", "1", this->precision*(this->max_horizon+1));
        for (auto it : belief.probs) {
            auto hybrid_state = it.first->hybrid_state;
            auto cs = hybrid_state->classical_state;

            if (cs->get_memory_val() == it.first->hidden_index) {
                result = result + it.second;
            }
        }
        return result;
    }

};

class BellStateDiscrimination3: public BellStateDiscrimination2, IPMA3Bitflip {
    map<int, vector<vector<complex<double>>>> indices_to_matrix;
public:
    BellStateDiscrimination3(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
        const set<MethodType> &method_types, const set<QuantumHardware>& hw_list) : BellStateDiscrimination2(name, precision, with_thermalization, min_horizon, max_horizon, method_types, hw_list) {
    };

    Rational postcondition(const Belief &belief, const unordered_map<int, int> &embedding) const override {
        return BellStateDiscrimination2::postcondition(belief, embedding);
    }

    vector<POMDPAction> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {
        return IPMA3Bitflip::get_actions(hardware_spec, embedding);
    }

    void run() const override{
        return BellStateDiscrimination2::run();
    }

};
#endif