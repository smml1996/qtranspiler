#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "quantum_gates.hpp"
#include "json.hpp"
using json = nlohmann::json;

enum InstructionType {
    Measurement,
    Classical,
    UnitarySingleQubit,
    UnitaryMultiQubit,
    Projector
};

class Instruction {
    public:
        int target;
        int c_target; // for writes we need to specify a classical address
        vector<int> controls;
        GateName gate_name;
        vector<double> params;
        InstructionType instruction_type;
        vector<double> params_;

        Instruction() = default;
        Instruction(GateName gate_name, int target);
        Instruction(GateName gate_name, int target, const vector<double> &params); // for single-qubit parametric gates
        Instruction(GateName gate_name, vector<int> controls, int target); // for multiqubit gates
        Instruction(GateName gate_name, const vector<int> &controls, int target, const vector<double> &params); // for multiqubit gates with parameters
        Instruction(GateName gate_name, int target, int c_target); // for measurements
        Instruction(const json &json_val);
        
        InstructionType get_instruction_type() const;
        bool operator==(const Instruction& other) const;
};

string to_string(const Instruction &instruction);

// Custom hash
struct InstructionHash {
    std::size_t operator()(const Instruction *instruction) const;
};

struct InstructionPtrEqual {
    bool operator()(const Instruction* a, const Instruction* b) const;
};

bool is_identity(const vector<Instruction> &seq);
#endif
