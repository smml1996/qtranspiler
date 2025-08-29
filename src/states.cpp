#include "../include/states.hpp"
#include <complex>
#include <algorithm>
#include <cassert>
#include "../include/utils.hpp"
#include "states.hpp"
#include <numbers>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

auto pi = M_PI;

// Quantum states
QuantumState::QuantumState(vector<int> qubits_used, int precision) {
    this->precision = precision;
    this->qubits_used = qubits_used;
    sort(this->qubits_used.begin(), this->qubits_used.end());

    // initialize to state |0>
    this->sparse_vector[0] = complex<double>(1.0, 0.0);
}

QuantumState* QuantumState::eval_qubit_unitary(const Instruction &instruction) const {
    assert (this->is_qubit());
    assert (instruction.instruction_type == InstructionType::UnitarySingleQubit);

    auto result = new QuantumState(this->qubits_used, this->precision);

    auto qubit_amplitudes = this->get_qubit_amplitudes();
    auto a0 = qubit_amplitudes.first;
    auto a1 = qubit_amplitudes.second;
    

    complex<double> half_prob(1/sqrt(2), 0.0);
    complex<double> I(0, 1);
    auto E_CONST = exp(1.0);

    if (instruction.gate_name == GateName::I){
        result->insert_amplitude(0, a0);
        result->insert_amplitude(1, a1);
    } else if( instruction.gate_name == GateName::X){
        result->insert_amplitude(0, a1);
        result->insert_amplitude(1, a0);
    } else if ( instruction.gate_name == GateName::Y){
        result->insert_amplitude(0, I*a1);
        result->insert_amplitude(1, -I*a0);
    } else if ( instruction.gate_name == GateName::Z){
        result->insert_amplitude(0, a0);
        result->insert_amplitude(1, -a1);
    } else if ( instruction.gate_name == GateName::H){
        result->insert_amplitude(0, half_prob * (a0 + a1));
        result->insert_amplitude(1, half_prob * (a0 - a1));
    } else if ( instruction.gate_name == GateName::S){
        result->insert_amplitude(0, a0);
        result->insert_amplitude(1, I*a1);
    } else if ( instruction.gate_name == GateName::Sd){
        result->insert_amplitude(0, a0);
        result->insert_amplitude(1, -I*a1);
    } else if ( instruction.gate_name == GateName::Sx){
        result->insert_amplitude(0, half_prob* (a0 - I*a1));
        result->insert_amplitude(1, half_prob*(-I*a0  + a1));
    } else if ( instruction.gate_name == GateName::Sxd) {
        result->insert_amplitude(0, half_prob * (a0 + a1*I));
        result->insert_amplitude(1, half_prob * (a0*I + a1));
    } else if ( instruction.gate_name == GateName::Td){
        result->insert_amplitude(0, a0);
        // we have to calculate e^(-i*pi/4) = cos(-pi/4) + isin(-pi/4) = 1/sqrt{2} - i/sqrt{2}
        result->insert_amplitude(1, a1 * ( half_prob - (I * half_prob)));
    } else if ( instruction.gate_name == GateName::T){
        // assert not is_inverse
        result->insert_amplitude(0, a0);
        // we have to calculate e^(i*pi/4) = cos(pi/4) + isin(pi/4) = 1/sqrt{2} + i/sqrt{2}
        result->insert_amplitude(1, a1 * ( half_prob + (I * half_prob)));
    } else if ( instruction.gate_name == GateName::U3){
        assert(instruction.params.size() == 3);
        auto cos_result = cos(instruction.params[0]/2);
        auto sin_result = sin(instruction.params[0]/2);
        auto pow2 = pow(E_CONST,(I*instruction.params[2]));
        auto pow1 = pow(E_CONST,(I*instruction.params[1]));
        auto pow12 = pow(E_CONST,(I*(instruction.params[1]+instruction.params[2])));
        result->insert_amplitude(0, (a0*cos_result)-(a1*pow2*sin_result));
        result->insert_amplitude(1, a0*pow1*sin_result+a1*pow12*cos_result);
    } else if ( instruction.gate_name == GateName::Custom){
        throw invalid_argument("Custom gate not implemented in eval");
        // assert params is not None
        // assert not is_inverse
        // prob, new_a0, new_a1 = get_kraus_matrix_probability(params, a0, a1, return_new_ampl=True)
        // if isclose(prob, 0):
        //     return None
        // result->insert_amplitude(0, new_a0)
        // result->insert_amplitude(1, new_a1)
    } else if ( instruction.gate_name == GateName::Rx){
        assert (instruction.params.size() == 1);
        auto temp_v = vector<double>({instruction.params[0], 3*pi/2, pi/2});
        Instruction u3_instruction(GateName::U3, 
            instruction.target, 
            temp_v);
        return this->eval_qubit_unitary(u3_instruction);
    } else if ( instruction.gate_name == GateName::Ry){
        assert (instruction.params.size() == 1);
        auto temp_v = vector<double>({instruction.params[0], 0, 0});
        Instruction u3_instruction(GateName::U3, 
            instruction.target, 
            temp_v);

        return this->eval_qubit_unitary(u3_instruction);
    } else if ( instruction.gate_name == GateName::Rz){
        assert (instruction.params.size() == 1);
        Instruction u1_instruction (GateName::U1, instruction.target, instruction.params);
        return this->eval_qubit_unitary(u1_instruction);
    } else if ( instruction.gate_name == GateName::U2){
        assert (instruction.params.size() == 2);
        return this->eval_qubit_unitary(Instruction(GateName::U3, instruction.target, vector<double>({pi/2.0, instruction.params[0], instruction.params[1]})));
    } else if ( instruction.gate_name == GateName::U1){
        // if is_inverse:
        //     raise Exception("Missing implementation of reverse of op U1")
        // assert len(params) == 1
        return this->eval_qubit_unitary(Instruction(GateName::U3, instruction.target, vector<double>({0,0,instruction.params[0]})));
    } else if ( instruction.gate_name == GateName::Reset){
        assert(a0 == 1.0 or a1 == 1.0);
        result->insert_amplitude(0, 1.0);
    } else if (instruction.instruction_type == InstructionType::Projector){
        if (instruction.gate_name == GateName::P0) {
            if (a0 == complex<double>(0, 0)) return nullptr;
            result->insert_amplitude(0, complex<double>(1.0, 0.0));
        } else {
            assert (instruction.gate_name == GateName::P1);
            if (a1 == complex<double>(0,0)) return nullptr;
            result->insert_amplitude(1, complex<double>(1, 0.0));
        }
    } else {
        throw invalid_argument("Not implemented (eval gate): " + instruction.gate_name);
    }
    return result;
}


complex<double> QuantumState::get_amplitude(const int &basis) const {
    auto it = this->sparse_vector.find(basis);
    if ( it != this->sparse_vector.end()) {
        return it->second;
    }

    return complex<double>(0.0, 0.0);
}

bool QuantumState::is_qubit() const {
    if (this->sparse_vector.size() > 2) {
        return false;
    }

    for (auto it : this->sparse_vector) {
        if (it.first > 0) {
            return false;
        }
    }

    return true;
}

bool QuantumState::is_qubit_0() const {
    assert(this->is_qubit());

    complex<double> amplitude0 = this->get_amplitude(0);
    return is_close(norm(amplitude0), 1.0, this->precision);
}

pair<complex<double>, complex<double>> QuantumState::get_qubit_amplitudes() const {
    make_pair(this->get_amplitude(0), this->get_amplitude(1));
}

bool QuantumState::insert_amplitude(const int &basis, const complex<double> &amplitude) {
    if (is_close(amplitude.real(), 0.0, this->precision) && is_close(amplitude.imag(), 0.0, this->precision)) {
        return false;
    }

    this->sparse_vector[basis] = amplitude;
    return true;
}

bool QuantumState::add_amplitude(const int &basis, const complex<double> &amplitude) {

    if (is_close(amplitude.real(), 0.0, this->precision) && is_close(amplitude.imag(), 0.0, this->precision)){
        // if both the real and the imaginary part of the amplitude are 0 then we return False because we do not add any amplitude
        return false;
    }
    
    complex<double> prev_amplitude = this->get_amplitude(basis);
    complex<double>current_amplitude = prev_amplitude + amplitude;
    if (is_close(current_amplitude.real(), 0.0, this->precision) and is_close(current_amplitude.imag(), 0.0, this->precision)){
        // if the new amplitude is 0 in both the real and imaginary part we delete this key
        this->sparse_vector.erase(basis);
        return false;
    }
    this->sparse_vector[basis] = current_amplitude;
    return true;
}

void QuantumState::normalize() {
    double sum_ = 0;
    for (auto it : this->sparse_vector) {
        sum_ += norm(it.second);
    }

    double norm = sqrt(sum_);

    for (auto it : this->sparse_vector) {
        this->sparse_vector[it.first] = it.second/norm;
    }
}

bool QuantumState::operator==(const QuantumState& other) const {
    if (this->sparse_vector.size() != other.sparse_vector.size()) return false;
        
    // here we check for global phases: two states are equal if they only differ by a global factor
    double inner_product = get_fidelity(*this, other);
    assert(inner_product >= 0);
    return is_close(inner_product, 1, this->precision);
}

pair<QuantumState*, double> get_sequence_probability(QuantumState quantum_state0, vector<Instruction> seq, int precision) {
    int count_meas = 0;
    QuantumState *quantum_state = &quantum_state0;
    QuantumState* prev_quantum_state = nullptr;
    for (auto instruction : seq) {
        assert(instruction.gate_name != GateName::Meas);
        if (instruction.gate_name== GateName::P0 or instruction.gate_name== GateName::P1){
            count_meas += 1;
            if (count_meas > 1)throw invalid_argument("Invalid Measurement instruction");
        }
        prev_quantum_state = quantum_state;
        quantum_state = quantum_state->apply_instruction(instruction, false);
        delete prev_quantum_state;
        if (quantum_state == nullptr) {
            return make_pair(nullptr, 0.0);
        }
        prev_quantum_state = quantum_state;
    }

    auto prob = get_inner_product(*quantum_state, *quantum_state);
    
    assert(is_close(prob.imag(), 0.0, precision));
    // round down was here
    auto prob_answer = round_to(prob.real(), precision);
    quantum_state->normalize();
    return make_pair(quantum_state, prob_answer);
}

QuantumState* QuantumState::apply_instruction(const Instruction &instruction, bool normalize=true) const {
    assert(this->sparse_vector.size() > 0);
    QuantumState * result;
    if (instruction.instruction_type == InstructionType::UnitaryMultiQubit){
        if( instruction.gate_name == GateName::Swap) {
            assert(instruction.controls.size() == 1);
            auto index1 = instruction.target;
            auto index2 = instruction.controls[0];
            
            auto result0 = this->apply_instruction(Instruction(GateName::Cnot, vector<int>({index1}), index2), normalize=false);
            auto result1 = result0->apply_instruction(Instruction(GateName::Cnot, vector<int>({index2}), index1), normalize=false);
            result = result1->apply_instruction(Instruction(GateName::Cnot, vector<int>({index1}), index2), normalize=false);
            delete result0;
            delete result1;
        } else if (instruction.gate_name == GateName::Rzx){
            assert (instruction.params.size() == 1);
            auto angle = instruction.params[0];
            auto H1 = Instruction(GateName::H, instruction.target);
            auto CX01 = Instruction(GateName::Cnot, instruction.controls, instruction.target);
            auto RZ1 = Instruction(GateName::Rz, instruction.target, vector<double>({angle}));
            auto result0 = this->apply_instruction(H1, normalize=false);
            auto result1 = result0->apply_instruction(CX01, normalize=false);
            auto result2 = result1->apply_instruction(RZ1, normalize=false);
            auto result3 = result2->apply_instruction(CX01, normalize=false);
            result = result3->apply_instruction(H1, normalize=false);
            delete result0, result1, result2, result3;
        } else if (instruction.gate_name == GateName::Ecr) {
            assert (instruction.controls.size() == 1);
            auto angle = pi / 4;
            auto RZX = Instruction(GateName::Rzx,  instruction.controls, instruction.target, vector<double>({angle}));
            auto RZXneg = Instruction(GateName::Rzx,  instruction.controls, instruction.target, vector<double>({-angle}));
            auto X0 = Instruction(GateName::X, instruction.controls[0]);
            auto result0 = this->apply_instruction(RZX, normalize=false);
            auto result1 = result0->apply_instruction(X0, normalize=false);
            auto result = result1->apply_instruction(RZXneg, normalize=false);
            delete result0, result1;
        } else {
            assert (instruction.gate_name == GateName::Cnot);
            result = this->eval_multiqubit_gate(instruction);
        }
    } else {
        if (instruction.gate_name == GateName::Reset){
            auto meas_instruction = Instruction(GateName::Meas, instruction.target, instruction.target);
            auto pair0 = get_sequence_probability(*this, vector<Instruction>({Instruction(GateName::P0, instruction.target)}), this->precision);
            auto q0 = pair0.first;
            auto prob0 = pair0.second;

            auto pair1 = get_sequence_probability(*this, vector<Instruction>({Instruction(GateName::P1, instruction.target)}), this->precision);
            auto q1 = pair1.first;
            auto prob1 = pair1.second;
            auto result0 = weighted_choice(vector<QuantumState*>({q0, q1}), vector<double>({prob0, prob1}));
            if (result0 == q1) {
                auto x_instruction = Instruction(GateName::X, instruction.target);
                result = result0->eval_single_qubit_gate(x_instruction);
            } else {
                result = result0;
            }
            delete result0;       
        } else {
            result = this->eval_single_qubit_gate(instruction);
        }
    }
    if (result){
        if (normalize) {
            result->normalize();
        }
        assert(result->sparse_vector.size() > 0);
    }
    return result;
}

QuantumState *QuantumState::get_qubit_from_basis(int basis, int target) const {
    auto result = new QuantumState({target}, this->precision);
    std::string bin_number = to_binary(basis);  // reversed already
    if (target >= static_cast<int>(bin_number.size())) {
        result->insert_amplitude(0, complex<double>(1.0, 0.0));
    } else {
        int value = bin_number[target] - '0';  // char -> int
        result->insert_amplitude(value, complex(1.0, 0.0));
    }
    return result;
}

int QuantumState::glue_qubit_in_basis(int basis, int address, int value) const {
    // convert basis to binary string (reversed = least significant bit first)
    std::string bin_number;
    int temp = basis;
    if (temp == 0) bin_number.push_back('0');
    while (temp > 0) {
        bin_number.push_back((temp % 2) + '0');
        temp /= 2;
    }

    // append zeros until length > address
    while (static_cast<int>(bin_number.size()) <= address) {
        bin_number.push_back('0');
    }

    // set qubit at address
    bin_number[address] = static_cast<char>('0' + value);

    // compute integer result (reverse order back)
    int result = 0;
    for (auto it = bin_number.rbegin(); it != bin_number.rend(); ++it) {
        result = (result << 1) + (*it - '0');
    }
    return result;
}

QuantumState* QuantumState::eval_single_qubit_gate(const Instruction &instruction) const {
    auto result = new QuantumState(this->qubits_used, this->precision);
    bool at_least_one_perform_op = false;
    auto op = instruction.gate_name;
    int address = instruction.target;
    for (auto it : this->sparse_vector) {
        auto basis = it.first;
        auto value = it.second;
        auto qubit = this->get_qubit_from_basis(basis, address);
        bool should_perform_op = true;
        if (instruction.instruction_type == InstructionType::Projector) {
            if (op == GateName::P0 && (! qubit->is_qubit_0())) {
                // we cannot apply a projectin to \0> if the qubit is 1 already
                should_perform_op = false;
            } else if ( op == GateName::P1 && qubit->is_qubit_0()) {
                should_perform_op = false;
            }
        }

        if (should_perform_op) {
            qubit = qubit->eval_qubit_unitary(instruction);
            if (qubit != nullptr){
                auto a = qubit->get_qubit_amplitudes();
                auto a0 = a.first;
                auto a1 = a.second;
                a0 *= value;
                a1 *= value;
                auto basis0 = this->glue_qubit_in_basis(basis, address, 0);
                auto basis1 = this->glue_qubit_in_basis(basis, address, 1);
                result->add_amplitude(basis0, a0);
                result->add_amplitude(basis1, a1);
                at_least_one_perform_op = true;
            }
                
        }
    }
    if (not at_least_one_perform_op) return nullptr;
    if (result->sparse_vector.size() == 0)return nullptr;
    return result;
}

bool QuantumState::are_controls_true(int basis, vector<int> controls) const{
    for (int a : controls) {
        // if bit at position a is 0
        if (((basis >> a) & 1) == 0) {
            return false;
        }
    }
    return true;
}

QuantumState* QuantumState::eval_multiqubit_gate(const Instruction &instruction) const {
    auto op = instruction.instruction_type;
    assert (instruction.controls.size() == 1);
    auto controls = instruction.controls;
    auto address = instruction.target;
    auto result = new QuantumState(this->qubits_used, this->precision);

    for (auto it : this->sparse_vector) {
        auto basis = it.first;
        auto value = it.second;
        if (this->are_controls_true(basis, controls)) {
            auto basis_state = new QuantumState(this->qubits_used, this->precision);
            basis_state->insert_amplitude(basis, value);
            Instruction new_instruction;
            if (op == GateName::Cnot){
                new_instruction = Instruction(GateName::X, address);
            }else if (op == GateName::Ch){
                new_instruction = Instruction(GateName::H, address);
            // } else if( op == GateName::Cu3) {
            //     new_instruction = Instruction(GateName::U3, address, None, gate_data.params)
            } else if (op == GateName::Cz) {
                new_instruction = Instruction(GateName::Z, address);
            } else {
                throw invalid_argument("Multiqubit Gatename not defined" + op); 
            }

            auto written_basis = basis_state->eval_single_qubit_gate(new_instruction);
            if (written_basis != nullptr) {
                for (auto it : written_basis->sparse_vector) {
                    auto b = it.first;
                    auto v = it.second;
                    result->add_amplitude(b, v);
                }   
            } else {
                throw invalid_argument("written basis is none");
            }
            delete written_basis;
        } else {
            result->add_amplitude(basis, value);
        }
    }

    assert (result->sparse_vector.size() > 0);
    return result;
}

complex<double> get_inner_product(const QuantumState &qs1, const QuantumState &qs2) {
    complex<double> inner_product(0,0);

    for (const auto &it : qs1.sparse_vector) {
        const auto &val1 = it.second;

        auto it2 = qs2.sparse_vector.find(it.first);
        if (it2 != qs2.sparse_vector.end()) {
            const auto &val2 = it2->second;
            inner_product += val1 * std::conj(val2);
        }
    }
    return inner_product;
}

double get_fidelity(const QuantumState &qs1, const QuantumState &qs2) {
    auto inner_product = get_inner_product(qs1, qs2);
    return norm(inner_product);
}

ClassicalState::ClassicalState(const ClassicalState & cs) {
    for (auto it : cs.sparse_vector) {
        this->sparse_vector[it.first] = it.second;
    }
}
bool ClassicalState::operator==(const ClassicalState&other) const {
    return this->get_memory_val() == other.get_memory_val();
}

int ClassicalState::get_memory_val() const {
    int answer = 0;
    
    for(auto it : this->sparse_vector) {
        answer += (pow(2, it.first) * it.second);
    }

    return answer;
}
bool ClassicalState::read(const int &address) const {
    auto it = this->sparse_vector.find(address);

    if (it != this->sparse_vector.end()) {
        return it->second;
    }
    return false;
}

ClassicalState* ClassicalState::write(const int &address, bool value) const {
    ClassicalState *classical_state = new ClassicalState(*this);
    classical_state->sparse_vector[address] = value;
    return classical_state;
}

ClassicalState* ClassicalState::apply_instruction(const Instruction &instruction) const {
    assert(instruction.instruction_type == InstructionType::Classical);

    if (instruction.gate_name == GateName::Write0) {
        return this->write(instruction.c_target, false);
    } else {
        assert(instruction.gate_name == GateName::Write1);
        return this->write(instruction.c_target, true);
    }    
}

HybridState::HybridState(QuantumState *quantum_state, ClassicalState *classical_state) {
    this->quantum_state = quantum_state;
    this->classical_state = classical_state;
}

HybridState *HybridState::apply_instruction(const Instruction &instruction) const
{
    auto new_qs = this->quantum_state;
    auto new_cs = this->classical_state;

    if (instruction.instruction_type == InstructionType::Classical) {
        new_cs = new_cs->apply_instruction(instruction);
    } else{
        new_qs = new_qs->apply_instruction(instruction);
    }

    return new HybridState(new_qs, new_cs);
}

bool HybridState::operator==(HybridState &other) const {
    return (*this->quantum_state  == *other.quantum_state)  && (*this->classical_state  == *other.classical_state);
}
