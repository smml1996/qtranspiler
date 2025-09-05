#ifndef HARDWARE_SPEC_H
#define HARDWARE_SPEC_H
#include <string>
#include <unordered_set>
#include <set>
#include "quantum_gates.hpp"
#include "instruction.hpp"
#include "channels.hpp"

using namespace std;

// all hardware specifications we can run experiments on
enum QuantumHardware { 
    Algiers,
    Almaden,
    Armonk,
    Athens,
    Auckland,
    Belem,
    Boeblingen,
    Bogota,
    Brisbane,
    Brooklyn,
    Burlington,
    Cairo,
    Cambridge,
    Casablanca,
    Cusco,
    Essex,
    Fez,
    Geneva,
    Guadalupe,
    Hanoi,
    Jakarta,
    Johannesburg,
    Kawasaki,
    Kolkata,
    Kyiv,
    Kyoto,
    Lagos,
    Lima,
    London,
    Makarresh,
    Melbourne,
    Manhattan,
    Manila,
    Montreal,
    Mumbai,
    Nairobi,
    Osaka,
    Oslo,
    Ourense,
    Paris,
    Perth,
    Poughkeepsie,
    Prague,
    Quito,
    Rochester,
    Rome,
    Santiago,
    Singapore,
    Sydney,
    Torino,
    Toronto,
    Valencia,
    Vigo,
    Washington,
    Yorktown,

    HardwareCount
};

string to_string(const QuantumHardware &quantum_hardware); // gets the string representation of the enum QuantumHardware
QuantumHardware to_quantum_hardware(const string &quantum_hardware);

class HardwareSpecification {
    QuantumHardware quantum_hardware;
    unordered_map<int, int> qubit_to_indegree;
    public:
        int num_qubits;
        BasisGates basis_gates_type;
        unordered_map<int, unordered_set<int>> digraph;
        unordered_map<Instruction*, Channel*, InstructionHash, InstructionPtrEqual>instructions_to_channels;
        unordered_set<GateName> basis_gates;
        HardwareSpecification(const QuantumHardware &quantum_hardware, const bool &thermal_relaxation);
        string get_hardware_name() const;
        vector<Instruction> to_basis_gates_impl(const Instruction &current_ins) const;
        int get_qubit_indegree(int qubit) const;
        vector<pair<int, double>> get_sorted_qubit_couplers(int target) const;
};

set<string> get_hardware_strings();
#endif
