#include "../include/states.hpp"
#include <complex>
#include <algorithm>
#include <cassert>
#include "../include/utils.hpp"
#include "states.hpp"

using namespace std;

// Quantum states
QuantumState::QuantumState(vector<int> qubits_used, int &precision) {
    this->precision = precision;
    this->qubits_used = qubits_used;
    sort(this->qubits_used.begin(), this->qubits_used.end());

    // initialize to state |0>
    this->sparse_vector[0] = complex<double>(1.0, 0.0);
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

pair<complex<double>, complex<double>> QuantumState::get_qubit_amplitudes() {
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

bool QuantumState::operator==(const QuantumState& other) {
    if (this->sparse_vector.size() != other.sparse_vector.size()) return false;
        
    // here we check for global phases: two states are equal if they only differ by a global factor
    double inner_product = get_fidelity(*this, other);
    assert(inner_product >= 0);
    return is_close(inner_product, 1, this->precision);
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

ClassicalState::ClassicalState(ClassicalState & cs) {
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

ClassicalState* ClassicalState::write(const int &address, bool &value) {
    ClassicalState *classical_state = new ClassicalState(*this);
    classical_state->sparse_vector[address] = value;
    return classical_state;
}

HybridState::HybridState(QuantumState *quantum_state, ClassicalState *classical_state) {
    this->quantum_state = quantum_state;
    this->classical_state = classical_state;
}
