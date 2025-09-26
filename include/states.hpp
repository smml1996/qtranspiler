#ifndef STATES_H
#define STATES_H

#include <unordered_map>
#include <complex>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include "instruction.hpp"
#include "states.hpp"
#define _USE_MATH_DEFINES
inline auto pi = M_PI;

using namespace boost::multiprecision;
using namespace std;

class QuantumState {
public:
    vector<int> qubits_used;
    int precision;
    pair<complex<double>, complex<double>> get_qubit_amplitudes() const;
    QuantumState *get_qubit_from_basis(cpp_int basis, int target) const;

    static cpp_int glue_qubit_in_basis(cpp_int basis, int address, int value);
    QuantumState* eval_qubit_unitary(const Instruction &instruction) const;
    QuantumState* eval_multiqubit_gate(const Instruction &instruction) const;
    QuantumState* eval_single_qubit_gate(const Instruction &instruction) const;

    static bool are_controls_true(cpp_int basis, const vector<int> &controls);

    unordered_map<cpp_int, complex<double>>  sparse_vector; // stores amplitudes for computational basis
    QuantumState(const vector<int> &qubits_used, int precision);
    complex<double> get_amplitude(const cpp_int &basis) const;
    bool is_qubit() const;
    bool is_qubit_0() const;
    bool insert_amplitude(const cpp_int &basis, const complex<double> &amplitude);
    bool add_amplitude(const cpp_int &basis, const complex<double> &amplitude);
    void normalize();
    bool operator==(const QuantumState& other) const;
    QuantumState* apply_instruction(const Instruction &instruction, bool normalize=true) const;
    vector<vector<complex<double>>> multi_partial_trace(const vector<int> &remove_indices) const;
    friend std::ostream &operator<<(ostream& os, const QuantumState& quantum_state);
};

pair<QuantumState*, double> get_sequence_probability(QuantumState * const &quantum_state0, const vector<Instruction> &seq, int precision);
complex<double> get_inner_product(const QuantumState &qs1, const QuantumState &qs2);
double get_fidelity(const QuantumState &qs1, const QuantumState &qs2);


class ClassicalState {
    unordered_map<int, bool> sparse_vector;
    public:
        ClassicalState() = default;
        ClassicalState(const ClassicalState &cs);
        bool operator==(const ClassicalState &other) const;
        cpp_int get_memory_val() const;
        bool read(const int &address) const;
        ClassicalState* write(const int &address, bool value) const;
        ClassicalState* apply_instruction(const Instruction &instruction) const;
        friend std::ostream &operator<<(ostream& os, const ClassicalState& classical_state);
};

class HybridState {
    public:
        QuantumState *quantum_state;
        ClassicalState *classical_state;

        HybridState(QuantumState *quantum_state, ClassicalState *classical_state);
        HybridState *apply_instruction(const Instruction &instruction) const;
        bool operator==(const HybridState &other) const;
        friend std::ostream &operator<<(ostream& os, const HybridState& hybrid_state);
};

#endif