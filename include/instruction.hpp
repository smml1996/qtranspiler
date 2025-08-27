#include "quantum_gates.hpp"
#include "json.hpp"
using json = nlohmann::json;

enum InstructionType {
    Measurement,
    Classical,
    UnitarySingleQubit,
    UnitaryMultiQubit,
};

class Instruction {
    public:
        int target;
        int c_target; // for writes we need to specify a classical address
        vector<int> controls;
        GateName gate_name;
        vector<double> params;
        InstructionType instruction_type;
        Instruction(const GateName &gate_name, int target);
        Instruction(const GateName &gate_name, int target, vector<double> &params); // for single-qubit parametric gates
        Instruction(const GateName &gate_name, vector<int> controls, int target); // for multiqubit gates
        Instruction(const GateName &gate_name, int target, int c_target); // for measurements
        Instruction(const json &json_val);
        
        InstructionType get_instruction_type();
        bool operator==(const Instruction& other) const;
};

// Custom hash
struct InstructionHash {
    std::size_t operator()(const Instruction *instruction) const;
};

struct InstructionPtrEqual {
    bool operator()(const Instruction* a, const Instruction* b) const;
};
