#include "instruction.hpp"
#include <iostream>

using namespace std;

Instruction::Instruction(GateName gate_name, int target) {
    this->gate_name = gate_name;
    if (gate_name == GateName::Write0 || gate_name == GateName::Write1) {
        this->instruction_type = InstructionType::Classical;
        this->c_target = target;
    } else if(gate_name == GateName::P0 || gate_name == GateName::P1) {
        this->instruction_type = InstructionType::Projector;
        this->target = target;
    } else {
        this->instruction_type = InstructionType::UnitarySingleQubit;
        this->target = target;
    }
}

Instruction::Instruction(GateName gate_name, int target, const vector<double> &params) {
    this->gate_name = gate_name;
    this->target = target;
    this->params = params;
    this->instruction_type = InstructionType::UnitarySingleQubit;
    this->c_target = -1;
}

Instruction::Instruction(GateName gate_name, const vector<int> &controls, int target, const vector<double> &params) {
    this->gate_name = gate_name;
    this->controls = controls;
    this->target = target;
    this->params = params;
    this->instruction_type = InstructionType::UnitarySingleQubit;
    this->c_target = -1;
}

Instruction::Instruction(GateName gate_name, vector<int> controls, int target) {
    this->gate_name = gate_name;
    this->controls = std::move(controls);
    this->target = target;
    this->instruction_type = InstructionType::UnitaryMultiQubit;
    this->c_target = -1;
}

Instruction::Instruction(GateName gate_name, int target, int c_target) {
    this->gate_name = gate_name;
    this->target = target;
    this->c_target= c_target;
    this->instruction_type = InstructionType::Measurement;
}

Instruction::Instruction(const json &json_val) {
    string raw_gate_name = json_val["op"];
    this->gate_name = get_enum_obj(raw_gate_name);;

    this->target = json_val["target"];

    this->c_target = -1;
    
    this->instruction_type = InstructionType::UnitarySingleQubit;

    
    switch (gate_name) {
        // One-qubit gates
        case I:
        case X:
        case Y:
        case Z:
        case H:
        case S:
        case Sd:
        case Sx:
        case Sxd:
        case U1:
        case U2:
        case U3:
        case T:
        case Td:
        case Rz:
        case Ry:
        case Rx:
        case Reset:
        case GateName::Meas:
            this->instruction_type = InstructionType::Measurement;
            this->c_target = target;
            break;
        case GateName::Custom:
            assert(false);
        case GateName::Cnot:
            this->controls.push_back(json_val["control"]);
            this->instruction_type = InstructionType::UnitaryMultiQubit;
            break;
        case GateName::Ecr:
            assert(false);
        case GateName::Rzx:
            assert(false);
        case GateName::Cz:
            this->controls.push_back(json_val["control"]);
            this->instruction_type = InstructionType::UnitaryMultiQubit;
            break;
        case Ch:
            assert(false);
        case Swap:
            assert(false);
        case Toffoli:
            assert(false);
        // Classical gates
        case Write0:
            assert(false);
        case Write1:
            assert(false);
        default:
            std::cerr << "Coult not get instruction for " + to_string(json_val) << endl;
            break;
    }
    
}

InstructionType Instruction::get_instruction_type() const {
    return this->instruction_type;
}

bool Instruction::operator==(const Instruction& other) const {
    return target == other.target
        && c_target == other.c_target
        && controls == other.controls
        && gate_name == other.gate_name
        && params == other.params;
}

string to_string(const Instruction &instruction) {
    
    switch (instruction.instruction_type) {
        case Measurement: 
            return "x" + to_string(instruction.c_target) + " := measure(q"+ to_string(instruction.target) +"); ";
        case Classical:
            if (instruction.gate_name == GateName::Write0) {
                return "x" + to_string(instruction.c_target) + " := 0; ";
            } else {
                return "x" + to_string(instruction.c_target) + " := 1; ";
            }
        default:
            assert(instruction.instruction_type == InstructionType::UnitaryMultiQubit || instruction.instruction_type == InstructionType::UnitaryMultiQubit);
            string str_qvars = "";

            for (auto control : instruction.controls) {
                if (!str_qvars.empty()) {
                    str_qvars+=", ";
                }
                str_qvars +=  "q"+ to_string(control);
            }

            if (!str_qvars.empty()) {
                str_qvars +=",";
            }
            str_qvars += "q" + to_string(instruction.target);

            return to_string(instruction.gate_name) + "([" + str_qvars + "]); ";

    }
}


bool InstructionPtrEqual::operator()(const Instruction* a, const Instruction* b) const {
    return *a == *b;
}


std::size_t InstructionHash::operator()(const Instruction *instruction) const {
    std::size_t seed = 0;

    // Helper to combine hashes (boost style)
    auto hash_combine = [](std::size_t& s, std::size_t h) {
        s ^= h + 0x9e3779b9 + (s << 6) + (s >> 2);
    };

    hash_combine(seed, std::hash<int>{}(instruction->target));
    hash_combine(seed, std::hash<int>{}(instruction->c_target));
    hash_combine(seed, std::hash<int>{}(static_cast<int>(instruction->gate_name)));

    for (auto c : instruction->controls)
        hash_combine(seed, std::hash<int>{}(c));

    for (auto p : instruction->params)
        hash_combine(seed, std::hash<double>{}(p));

    return seed;
}

bool is_identity(const vector<Instruction> &seq) {
    for (auto s : seq) {
        // if isinstance(s, KrausOperator)
        //     return False
        if (s.gate_name != GateName::I) return false;
    }
        
    return true;
}