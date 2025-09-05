#ifndef POMDP_H
#define POMDP_H

#include <string>
#include "states.hpp"
#include "channels.hpp"
#include "hardware_specification.hpp"
#include "rationals.hpp"


using namespace std;

class POMDPVertex {
    static int local_counter;
    public:
        HybridState *hybrid_state;
        int hidden_index;
        int id;
        POMDPVertex() = default;
        POMDPVertex(HybridState *hybrid_state, int hidden_index=-1);
        bool operator==(const POMDPVertex &other) const;
        ClassicalState *get_obs() const;
};

// Custom hash
struct POMDPVertexHash {
    std::size_t operator()(const POMDPVertex *instruction) const;
};

struct POMDPVertexPtrEqual {
    bool operator()(const POMDPVertex* a, const POMDPVertex* b) const;
};

typedef unordered_map<POMDPVertex*, double, POMDPVertexHash, POMDPVertexPtrEqual> vertex_dict;

class POMDPAction {
    int precision;

    vertex_dict __handle_measure_instruction(const Instruction &instruction, const MeasurementChannel &channel, const POMDPVertex &vertex, bool is_meas1=true, vertex_dict result = {}) const;
    
    vertex_dict __handle_unitary_instruction(const Instruction &instruction, const QuantumChannel &channel, const POMDPVertex &vertex,vertex_dict result = {}) const;

    vertex_dict __handle_reset_instruction(const Instruction &instruction, const QuantumChannel &channel, const POMDPVertex &vertex, bool is_meas1=true, vertex_dict result = {}) const;

    vertex_dict __dfs(HardwareSpecification &hardware_specification, POMDPVertex *vertex, int index_ins) const;

    public:
        string name;
        vector<Instruction> instruction_sequence;
        vector<Instruction> pseudo_instruction_sequence;
        POMDPAction(const string &name, const vector<Instruction> &instruction_sequence, int precision, const vector<Instruction> &pseudo_instruction_sequence);
        vertex_dict get_successor_states(HardwareSpecification &hardware_specification, POMDPVertex *current_vertex) const;
        bool operator==(const POMDPAction &other) const;
};

string to_string(const POMDPAction &action);

string to_string(const POMDPAction* action);

// Custom hash
struct POMDPActionHash {
    std::size_t operator()(const POMDPAction *action) const;
};

struct POMDPActionPtrEqual {
    bool operator()(const POMDPAction* a, const POMDPAction* b) const;
};

typedef function<bool(POMDPVertex, unordered_map<int, int>, POMDPAction)> guard_type;

class POMDP {
    vector<POMDPVertex> states;
    int precision;

    POMDPVertex* get_vertex(const POMDPVertex *vertex);
    POMDPVertex* create_new_vertex(const HybridState *hybrid_state, int hidden_index);
    public:
        POMDPVertex *initial_state;
        unordered_map<POMDPVertex *, unordered_map<POMDPAction *, unordered_map<POMDPVertex *, Rational, POMDPVertexHash,
            POMDPVertexPtrEqual>, POMDPActionHash, POMDPActionPtrEqual>, POMDPVertexHash, POMDPVertexPtrEqual>
        transition_matrix;
        vector<POMDPAction> actions;
        POMDP() = default;
        POMDP(int precision);
        POMDP(POMDPVertex *initialState, const vector<POMDPVertex> &states, const vector<POMDPAction> &actions, unordered_map<POMDPVertex*, unordered_map<POMDPAction*, unordered_map<POMDPVertex*, Rational,POMDPVertexHash, POMDPVertexPtrEqual>,POMDPActionHash, POMDPActionPtrEqual>, POMDPVertexHash, POMDPVertexPtrEqual> &transition_matrix);
        void build_pomdp(const vector<POMDPAction> &actions, HardwareSpecification &hardware_specification, int horizon, unordered_map<int, int> embedding, HybridState *initial_state, const vector<pair<HybridState*, double>> &initial_distribution, vector<int> &qubits_used, guard_type guard, bool set_hidden_index=false);
};
#endif