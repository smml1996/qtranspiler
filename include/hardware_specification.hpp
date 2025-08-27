#include <iostream>
#include <filesystem>  // C++17 and above
#include <string>
#include <unordered_set>
#include "quantum_gates.hpp"
#include "instruction.hpp"
#include "quantum_channels.hpp"

using namespace std;

// all hardware specifications we can ran experiments on
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
};

string to_string(const QuantumHardware &quantum_hardware); // gets the string representation of the enum QuantumHardware

class HardwareSpecification {
    QuantumHardware quantum_hardware;
    BasisGates basis_gates_type;
    unordered_set<GateName> basis_gates;
    int num_qubits;
    unordered_map<Instruction*, Channel*, InstructionHash, InstructionPtrEqual>instructions_to_channels;

    public:
        HardwareSpecification(const QuantumHardware &quantum_hardware, const bool &thermal_relaxation);
        
};
