#include<unordered_map>
#include<vector>

using namespace std;

class QuantumState {
    vector<int> qubits_used;
    int precision;
    public:
        unordered_map<int, complex<double>>  sparse_vector; // stores amplitudes for computational basis
        QuantumState(vector<int> qubits_used, int &precision);
        complex<double> get_amplitude(const int &basis) const;
        bool is_qubit() const;
        bool is_qubit_0() const;
        pair<complex<double>, complex<double>> get_qubit_amplitudes();
        bool insert_amplitude(const int &basis, const complex<double> &amplitude);
        bool add_amplitude(const int &basis, const complex<double> &amplitude);
        void normalize();
        bool operator==(const QuantumState& other);
};

complex<double> get_inner_product(const QuantumState &qs1, const QuantumState &qs2);
double get_fidelity(const QuantumState &qs1, const QuantumState &qs2);


class ClassicalState {
    unordered_map<int, bool> sparse_vector;
    public:
        ClassicalState() = default;
        ClassicalState(ClassicalState &cs);
        bool operator==(const ClassicalState&other) const;
        int get_memory_val() const;
        bool read(const int &address) const;
        ClassicalState* write(const int &address, bool &value);
};

class HybridState {
    QuantumState *quantum_state;
    ClassicalState *classical_state;

    public:
        HybridState(QuantumState *quantum_state, ClassicalState *classical_state);
};