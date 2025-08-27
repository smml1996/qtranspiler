#include "../include/instruction.hpp"
#include <iostream>

using namespace std;

Instruction::Instruction(const GateName &gate_name, int target) {
    this->gate_name = gate_name;
    if (gate_name == GateName::Write0 || gate_name == GateName::Write1) {
        this->instruction_type = InstructionType::Classical;
        this->c_target = target;
    } else {
        this->instruction_type = InstructionType::UnitarySingleQubit;
        this->target = target;
    }
}

Instruction::Instruction(const GateName &gate_name, int target, vector<double> &params) {
    this->gate_name = gate_name;
    this->target = target;
    this->params = std::move(params);
    this->instruction_type = InstructionType::UnitarySingleQubit;
}

Instruction::Instruction(const GateName &gate_name, vector<int> controls, int target) {
    this->gate_name = gate_name;
    this->controls = std::move(controls);
    this->target = target;
    this->instruction_type = InstructionType::UnitaryMultiQubit;
}

Instruction::Instruction(const GateName &gate_name, int target, int c_target) {
    this->gate_name = gate_name;
    this->target = target;
    this->c_target= c_target;
    this->instruction_type = InstructionType::Measurement;
}

Instruction::Instruction(const json &json_val) {
    string raw_gate_name = json_val["op"];
    GateName gate_name = get_enum_obj(raw_gate_name);
    this->gate_name = gate_name;

    int target = json_val["target"];
    this->target = target;

    this->c_target = -1;

    vector<int> controls;
    
    InstructionType instruction_type = InstructionType::UnitarySingleQubit;

    
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
        case Meas:
            this->instruction_type = InstructionType::Measurement;
            this->c_target = target;
            break;
        case Custom:
            assert(false);
        // Multi-qubit gates
        case Cnot:
            int control = json_val["control"];
            this->controls.push_back(control);
            this->instruction_type = InstructionType::UnitaryMultiQubit;
            break;
        case Ecr:
            assert (false);
        case Rzx:
            assert(false);
        case Cz:
            int control = json_val["control"];
            this->controls.push_back(control);
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

InstructionType Instruction::get_instruction_type() {
    return this->instruction_type;
}

bool Instruction::operator==(const Instruction& other) const {
    return target == other.target
        && c_target == other.c_target
        && controls == other.controls
        && gate_name == other.gate_name
        && params == other.params;
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