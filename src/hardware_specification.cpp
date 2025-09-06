#include "hardware_specification.hpp"
#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "channels.hpp"
#define _USE_MATH_DEFINES
auto pi = M_PI;

using namespace std;


int HardwareSpecification::get_qubit_indegree(int qubit) const {
    if (this->qubit_to_indegree.find(qubit) != this->qubit_to_indegree.end()) {
        return this->qubit_to_indegree.at(qubit);
    }
    return 0;
}

vector<pair<int, double>> HardwareSpecification::get_sorted_qubit_couplers(int target) const {
    assert (target >= 0);
    vector<pair<int, double>> result;

    for (auto it : this->instructions_to_channels) {
        auto instruction = it.first;
        auto channel = it.second;

        if(instruction->instruction_type == InstructionType::UnitaryMultiQubit) {
            assert (instruction->controls.size() == 1);
            if (target == instruction->target) {
                result.push_back({instruction->controls[0], channel->estimated_success_prob});
            }
        }
    }

    sort(result.begin(), result.end(), [](const pair<int, double> &a, const pair<int, double> &b) {
        return a.second > b.second;
    });
    return result;
}

set<string> get_hardware_strings() {
    set<string> result;
    for (int i = 0; i < QuantumHardware::HardwareCount;  i++) {
        result.insert(to_string(static_cast<QuantumHardware>(i)));
    }
    return result;
}


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

    // compute in degree of qubits
    for (auto it : this->instructions_to_channels) {
        Instruction *ins = it.first;
        if (ins->instruction_type == InstructionType::UnitaryMultiQubit) {
            int target = ins->target;
            if (this->qubit_to_indegree.find(target) == this->qubit_to_indegree.end()) {
                this->qubit_to_indegree[target] = 0;
            }
            this->qubit_to_indegree[target]++;
        }
    }

    // compute digraph
    for (auto it : this->instructions_to_channels) {
        auto instruction = it.first;
        assert (instruction->controls.size() == 1);
        if (instruction->instruction_type == InstructionType::UnitaryMultiQubit) {
            int source = instruction->controls[0];
            int target = instruction->target;
            
            if (this->digraph.find(source) == this->digraph.end()) {
                this->digraph[source] = unordered_set<int>();
            }
            this->digraph[source].insert(target);
        }       
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
        case Singapore: return "singapore";
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

string to_string(const set<QuantumHardware> &quantum_hardware) {
    string result;

    for (auto hw : quantum_hardware) {
        if (!result.empty()) {
            result += ", ";
        }
        result += to_string(hw);
    }

    return result;
}

QuantumHardware to_quantum_hardware(const string &quantum_hardware) {
    for (int i = 0; i < QuantumHardware::HardwareCount; i++) {
        auto str_curr = to_string(static_cast<QuantumHardware>(i));
        if (str_curr == quantum_hardware) {
            return static_cast<QuantumHardware>(i);
        }
    }
    throw std::invalid_argument( "QuantumHardware string is not an quantum hardware: " + quantum_hardware);
}

string HardwareSpecification::get_hardware_name() const {
    return to_string(this->quantum_hardware);
}

vector<Instruction> HardwareSpecification::to_basis_gates_impl(const Instruction &current_ins) const {
    if ((basis_gates.find(current_ins.gate_name) != basis_gates.end() )  ||(current_ins.instruction_type == InstructionType::Measurement) || (current_ins.instruction_type == InstructionType::Classical)) return {current_ins};
    auto temp = unordered_set<BasisGates>({BasisGates::TYPE2, BasisGates::TYPE2, BasisGates::TYPE5, BasisGates::TYPE4, BasisGates::TYPE6});
    if (temp.find(basis_gates_type) != temp.end()){
        vector<Instruction> sx({Instruction(GateName::Sx, current_ins.target)});
        if (current_ins.gate_name == GateName::Ry){
            return {
                Instruction(GateName::Sx, current_ins.target),
                Instruction(GateName::Rz, current_ins.target, vector<double>({current_ins.params[0] + pi})),
                Instruction(GateName::Sx, current_ins.target),
                Instruction(GateName::Rz, current_ins.target, vector<double>({3*pi}))
            };
        }
        if( current_ins.gate_name == GateName::H) {
            return {Instruction(GateName::Rz, current_ins.target, vector<double>({pi/2})),
            Instruction(GateName::Sx, current_ins.target),
            Instruction(GateName::Rz, current_ins.target, vector<double>({pi/2})),
            };
        }

            if (current_ins.gate_name == GateName::Z)
                return {Instruction(GateName::Rz, current_ins.target, vector<double>({pi}))};
            if (current_ins.gate_name == GateName::U3) {
                vector<Instruction> rz_lambda({
                    Instruction(GateName::Rz, current_ins.target, vector<double>({current_ins.params[2]}))
                });
                vector<Instruction> rz_theta = this->to_basis_gates_impl(
                    Instruction(GateName::Rz, current_ins.target, vector<double>({current_ins.params[0] + pi}))
                );
                vector<Instruction> rz_phi = vector<Instruction>({Instruction(GateName::Rz, current_ins.target, vector<double>({current_ins.params[1] + 3*pi}))});

                for (auto ins : sx) {
                    rz_lambda.push_back(ins);
                }

                for (auto ins : rz_theta) {
                    rz_lambda.push_back(ins);
                }

                for (auto ins : sx) {
                    rz_lambda.push_back(ins);
                }

                for (auto ins : rz_phi) {
                    rz_lambda.push_back(ins);
                }


                return rz_lambda;
            }
            if( current_ins.gate_name == GateName::T)
                return {Instruction(GateName::Rz, current_ins.target, vector<double>({pi/4}))};
            if (current_ins.gate_name == GateName::Td)
                return {Instruction(GateName::Rz, current_ins.target, vector<double>({-pi/4}))};
            if (current_ins.gate_name == GateName::S)
                return {Instruction(GateName::Rz, current_ins.target, vector<double>({-pi/2}))};
            if (current_ins.gate_name == GateName::Sd)
                return {Instruction(GateName::Rz, current_ins.target, vector<double>({pi/2}))};
            if (current_ins.gate_name == GateName::Rx){
                assert(current_ins.params.size() == 1);

                Instruction rz_pi2 = Instruction(GateName::Rz, current_ins.target, vector<double>({pi/2}));
                auto rz_phi = Instruction(GateName::Rz, current_ins.target, vector<double>({current_ins.params[0] + pi}));
                auto rz_pi5pi2 = Instruction(GateName::Rz, current_ins.target, vector<double>({5*pi/2}));

                vector<Instruction> result;
                result.push_back(rz_pi2);

                for (auto ins : sx) {
                    result.push_back(ins);
                }
                result.push_back(rz_phi);
                for (auto ins : sx) {
                    result.push_back(ins);
                }
                result.push_back(rz_pi5pi2);

                return result;
            }
        }
        if (basis_gates_type == BasisGates::TYPE3) {
            if (current_ins.gate_name == GateName::H)
                return {Instruction(GateName::U2, current_ins.target, vector<double>({0, pi}))};
            if (current_ins.gate_name == GateName::S)
                return {Instruction(GateName::U1, current_ins.target, vector<double>({-pi/2}))};
            if (current_ins.gate_name == GateName::Z)
                return {Instruction(GateName::U1, current_ins.target, vector<double>({pi}))};
            if (current_ins.gate_name == GateName::Ry)
                return {Instruction(GateName::U3, current_ins.target, vector<double>({current_ins.params[0], 0, 0}))};
            if (current_ins.gate_name == GateName::Rx)
                return {Instruction(GateName::U3, current_ins.target, vector<double>({current_ins.params[0], -pi/2, pi/2}))};
            if (current_ins.gate_name == GateName::X)
                return {Instruction(GateName::U3, current_ins.target, vector<double>({pi, 0, pi}))};
        }
        throw invalid_argument("cannot translate to basis gates");
    }