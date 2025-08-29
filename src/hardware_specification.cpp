#include "../include/hardware_specification.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include "../include/channels.hpp"

using namespace std;

HardwareSpecification::HardwareSpecification(const QuantumHardware &quantum_hardware, const bool &thermal_relaxation) {
    this->quantum_hardware = quantum_hardware;
    
    // determining hardware specification path
    string spec_path;
    if (thermal_relaxation) {
        spec_path = "../with_thermalization/fake_" + to_string(quantum_hardware) + ".json";
    } else {
        spec_path = "../no_thermalization/fake_" + to_string(quantum_hardware) + ".json";
    }

    std::ifstream f(spec_path);
    if (!f.is_open()) {
        std::cerr << "Failed to open file: " + spec_path << endl;
    }
    json json_hardware_spec = json::parse(f);
    f.close();

    this->num_qubits = json_hardware_spec["num_qubits"];

    // basis gates
    for (string raw_gate : json_hardware_spec["basis_gates"]) {
        this->basis_gates.insert(get_enum_obj(raw_gate));
    }
    this->basis_gates_type = get_basis_gates_type(this->basis_gates);

    vector<json> instructions = json_hardware_spec["instructions"];

    vector<json> channels = json_hardware_spec["channels"];

    assert (instructions.size() == channels.size());

    for(int i=0; i < instructions.size(); i++) {
        Instruction *instruction = new Instruction(instructions[i]);
        Channel *channel;
        if(instruction->get_instruction_type() == InstructionType::Measurement) {
            channel = new MeasurementChannel(channels[i]);
        } else {
            channel = new QuantumChannel(channels[i]);
        }

        this->instructions_to_channels[instruction] = channel;   
    }
    
}

std::string to_string(const QuantumHardware &quantum_hardware) {
    switch(quantum_hardware) {
        case Algiers: return "algiers";
        case Almaden: return "almaden";
        case Armonk: return "armonk";
        case Athens: return "athens";
        case Auckland: return "auckland";
        case Belem: return "belem";
        case Boeblingen: return "boeblingen";
        case Bogota: return "bogota";
        case Brisbane: return "brisbane";
        case Brooklyn: return "brooklyn";
        case Burlington: return "burlington";
        case Cairo: return "cairo";
        case Cambridge: return "cambridge";
        case Casablanca: return "casablanca";
        case Cusco: return "cusco";
        case Essex: return "essex";
        case Fez: return "fez";
        case Geneva: return "geneva";
        case Guadalupe: return "guadalupe";
        case Hanoi: return "hanoi";
        case Jakarta: return "jakarta";
        case Johannesburg: return "Johannesburg";
        case Kawasaki: return "kawasaki";
        case Kolkata: return "kolkata";
        case Kyiv: return "kyiv";
        case Kyoto: return "kyoto";
        case Lagos: return "lagos";
        case Lima: return "lima";
        case London: return "london";
        case Makarresh: return "makarresh";
        case Melbourne: return "melbourne";
        case Manhattan: return "manhattan";
        case Manila: return "manila";
        case Montreal: return "montreal";
        case Mumbai: return "mumbai";
        case Nairobi: return "nairobi";
        case Osaka: return "osaka";
        case Oslo: return "oslo";
        case Ourense: return "ourense";
        case Paris: return "paris";
        case Perth: return "perth";
        case Poughkeepsie: return "poughkeepsie";
        case Prague: return "prague";
        case Quito: return "quito";
        case Rochester: return "rochester";
        case Rome: return "rome";
        case Santiago: return "santiago";
        case Sydney: return "sydney";
        case Torino: return "torino";
        case Toronto: return "toronto";
        case Valencia: return "valencia";
        case Vigo: return "vigo";
        case Washington: return "washington";
        case Yorktown: return "yorktown";
        default: throw invalid_argument( "Cannot retrieve string representation of quantum hardware" );
    }
}


