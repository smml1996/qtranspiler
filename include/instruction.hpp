#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "quantum_gates.hpp"
#include "utils.hpp"
#include <nlohmann/json.hpp>

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
        vector<vector<complex<double>>> matrix;

        Instruction() = default;
        Instruction(GateName gate_name, int target);
        Instruction(int target, vector<vector<complex<double>>> matrix);
        Instruction(GateName gate_name, int target, const vector<double> &params); // for single-qubit parametric gates
        Instruction(GateName gate_name, vector<int> controls, int target); // for multiqubit gates
        Instruction(GateName gate_name, const vector<int> &controls, int target, const vector<double> &params); // for multiqubit gates with parameters
        Instruction(GateName gate_name, int target, int c_target); // for measurements
        explicit Instruction(const json &json_val);
        
        [[nodiscard]] InstructionType get_instruction_type() const;
        bool operator==(const Instruction& other) const;
        friend std::ostream &operator<<(ostream& os, const Instruction&);
};

string to_string(const Instruction &instruction);

// Custom hash
struct InstructionHash {
    std::size_t operator()(const std::shared_ptr<Instruction>& instruction) const;
};

struct InstructionPtrEqual {
    bool operator()(const std::shared_ptr<Instruction>& a, const std::shared_ptr<Instruction>& b) const;
};

bool is_identity(const vector<Instruction> &seq);

bool are_instruction_seqs_equal(const vector<Instruction> &seq1, const vector<Instruction> &seq2);

Instruction to_custom(const Instruction &instruction);
#endif
