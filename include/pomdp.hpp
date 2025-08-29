#include <string>
#include "states.hpp"
#include "channels.hpp"
#include "hardware_specification.hpp"

#ifndef POMDP_H
#define POMDP_H


typedef unordered_map<POMDPVertex, double, POMDPVertexHash,POMDPVertexPtrEqual> vertex_dict;
typedef function<bool(POMDPVertex, unordered_map<int, int>, POMDPAction)> guard_type;
using namespace std;

string INIT_CHANNEL = "INIT_";

class POMDPVertex {
    static int local_counter;
    public:
        HybridState *hybrid_state;
        int hidden_index;
        int id;
        POMDPVertex() = default;
        POMDPVertex(HybridState *hybrid_state, int hidden_index=-1);
        bool operator==(const POMDPVertex &other) const;
        ClassicalState *get_obs();
};

int POMDPVertex::local_counter = 1;

// Custom hash
struct POMDPVertexHash {
    std::size_t operator()(const POMDPVertex *instruction) const;
};

struct POMDPVertexPtrEqual {
    bool operator()(const POMDPVertex* a, const POMDPVertex* b) const;
};

class POMDPAction {
    int precision;
    
    vector<Instruction> instruction_sequence;

    vertex_dict __handle_measure_instruction(const Instruction &instruction, const MeasurementChannel &channel, const POMDPVertex &vertex, bool is_meas1=true, vertex_dict result = {});
    
    vertex_dict __handle_unitary_instruction(const Instruction &instruction, const QuantumChannel &channel, const POMDPVertex &vertex,vertex_dict result = {});

    vertex_dict __handle_reset_instruction(const Instruction &instruction, const QuantumChannel &channel, const POMDPVertex &vertex, bool is_meas1=true, vertex_dict result = {});

    vertex_dict __dfs(HardwareSpecification &hardware_specification, const POMDPVertex &vertex, int index_ins);
    public:
        string name;
        POMDPAction(const string &name, const vector<Instruction> &instruction_sequence, int precision);
        vertex_dict get_successor_states(HardwareSpecification &hardware_specification, const POMDPVertex &current_vertex);

};

class POMDP {
    vector<POMDPVertex> states;
    vector<POMDPAction> actions;
    unordered_map<POMDPVertex*, unordered_map<string, unordered_map<POMDPVertex*, double, POMDPVertexHash, POMDPVertexPtrEqual>>, POMDPVertexHash, POMDPVertexPtrEqual> transition_matrix;
    POMDPVertex *initial_state;
    int precision;

    POMDPVertex* get_vertex(POMDPVertex *vertex);
    POMDPVertex* create_new_vertex(HybridState *hybrid_state, int hidden_index);
    public:
        POMDP(int precision);
        POMDP(POMDPVertex *initialState, vector<POMDPVertex> &states, vector<POMDPAction> &actions, unordered_map<POMDPVertex*, unordered_map<string, unordered_map<POMDPVertex*, double, POMDPVertexHash, POMDPVertexPtrEqual>>, POMDPVertexHash, POMDPVertexPtrEqual> &transition_matrix);
        void build_pomdp(const vector<POMDPAction> &actions, HardwareSpecification &hardware_specification, int horizon, unordered_map<int, int> embedding, HybridState *initial_state, const vector<pair<HybridState*, double>> &initial_distribution, vector<int> &qubits_used, guard_type guard, bool set_hidden_index=false);


};
#endif