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
        shared_ptr<HybridState> hybrid_state;
        int hidden_index;
        int id;
        POMDPVertex() = default;
        ~POMDPVertex();
        explicit POMDPVertex(const shared_ptr<HybridState> &hybrid_state, int hidden_index=-1);
        bool operator==(const POMDPVertex &other) const;
        [[nodiscard]] shared_ptr<ClassicalState> get_obs() const;
        friend std::ostream &operator<<(ostream& os, const POMDPVertex& v);
};

// Custom hash
struct POMDPVertexHash {
    std::size_t operator()(const shared_ptr<POMDPVertex> &v) const;
};

struct POMDPVertexPtrEqual {
    bool operator()(const shared_ptr<POMDPVertex> &a, const shared_ptr<POMDPVertex> &b) const;
};

struct POMDPVertexPtrEqualID {
    bool operator()(const shared_ptr<POMDPVertex> &a, const shared_ptr<POMDPVertex> &b) const;
};

typedef unordered_map<shared_ptr<POMDPVertex>, double, POMDPVertexHash, POMDPVertexPtrEqual> vertex_dict;

class POMDPAction {
    int precision;

    void __handle_measure_instruction(const Instruction &instruction, const MeasurementChannel &channel, const POMDPVertex &vertex, vertex_dict &result, bool is_meas1=true) const;
    
    void __handle_unitary_instruction(const Instruction &instruction, const QuantumChannel &channel, const POMDPVertex &vertex, vertex_dict &result) const;

    void __handle_reset_instruction(const Instruction &instruction, const QuantumChannel &channel, const POMDPVertex &vertex, vertex_dict &result, bool is_meas1=true) const;

    vertex_dict __dfs(HardwareSpecification &hardware_specification, shared_ptr<POMDPVertex> vertex, int index_ins) const;

    public:
        string name;
        vector<Instruction> instruction_sequence;
        vector<Instruction> pseudo_instruction_sequence;
        POMDPAction(const string &name, const vector<Instruction> &instruction_sequence, int precision, const vector<Instruction> &pseudo_instruction_sequence);
        vertex_dict get_successor_states(HardwareSpecification &hardware_specification, const shared_ptr<POMDPVertex> &current_vertex) const;
        bool operator==(const POMDPAction &other) const;
};

string to_string(const POMDPAction &action);

string to_string(const shared_ptr<POMDPAction> &action);

// Custom hash
struct POMDPActionHash {
    std::size_t operator()(const shared_ptr<POMDPAction> &action) const;
};

struct POMDPActionPtrEqual {
    bool operator()(const shared_ptr<POMDPAction> &a, const shared_ptr<POMDPAction> &b) const;
};

typedef function<bool(POMDPVertex, unordered_map<int, int>, POMDPAction)> guard_type;

class POMDP {
    vector<shared_ptr<POMDPVertex>> states;
    int precision;
    unordered_map<shared_ptr<POMDPVertex>, unordered_map<shared_ptr<POMDPAction>, unordered_map<shared_ptr<POMDPVertex>,
    double, POMDPVertexHash, POMDPVertexPtrEqualID>, POMDPActionHash, POMDPActionPtrEqual>, POMDPVertexHash,
    POMDPVertexPtrEqualID> transition_matrix_;

public:
        shared_ptr<POMDPVertex> initial_state;
        unordered_map<shared_ptr<POMDPVertex>, unordered_map<shared_ptr<POMDPAction>, unordered_map<shared_ptr<POMDPVertex>, Rational, POMDPVertexHash,
            POMDPVertexPtrEqualID>, POMDPActionHash, POMDPActionPtrEqual>, POMDPVertexHash, POMDPVertexPtrEqualID>
        transition_matrix;
        vector<shared_ptr<POMDPAction>> actions;
        POMDP() = default;
        ~POMDP();
        POMDP(int precision);
        POMDP(const shared_ptr<POMDPVertex> &initialState, const vector<shared_ptr<POMDPVertex>> &states, const vector<shared_ptr<POMDPAction>> &actions, const unordered_map<shared_ptr<POMDPVertex>, unordered_map<shared_ptr<POMDPAction>, unordered_map<shared_ptr<POMDPVertex>, double,POMDPVertexHash, POMDPVertexPtrEqualID>,POMDPActionHash, POMDPActionPtrEqual>, POMDPVertexHash, POMDPVertexPtrEqualID> &transition_matrix);
        shared_ptr<POMDPVertex> get_vertex(const shared_ptr<HybridState> &new_hs, const int &hidden_index);
        shared_ptr<POMDPVertex> create_new_vertex(const shared_ptr<HybridState> &hybrid_state, int hidden_index);
        void build_pomdp(const vector<shared_ptr<POMDPAction>> &actions, HardwareSpecification &hardware_specification, int horizon, unordered_map<int, int> embedding, shared_ptr<HybridState> initial_state, const vector<pair<shared_ptr<HybridState>, double>> &initial_distribution, vector<int> &qubits_used, guard_type guard, bool set_hidden_index=false);
        void print_pomdp() const;
        void check_pomdp() const;
};
#endif