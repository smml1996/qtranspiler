
#include "pomdp.hpp"

#include <cassert>
#include <iostream>

#include "utils.hpp"
#include<queue>

#include "algorithm.hpp"

int POMDPVertex::local_counter = 1;

POMDPVertex::POMDPVertex(HybridState *hybrid_state, int hidden_index) {
    this->id = POMDPVertex::local_counter;
    POMDPVertex::local_counter += 1;
    this->hybrid_state = new HybridState(new QuantumState(*hybrid_state->quantum_state), new ClassicalState(*hybrid_state->classical_state));
    this->hidden_index = hidden_index;
}

bool POMDPVertex::operator==(const POMDPVertex &other) const{
    assert(this->hybrid_state != nullptr);
    assert(other.hybrid_state != nullptr);
    return this->hidden_index == other.hidden_index && *this->hybrid_state == *other.hybrid_state;
}

ClassicalState *POMDPVertex::get_obs() const {
    return this->hybrid_state->classical_state;
}

std::size_t POMDPVertexHash::operator()(const POMDPVertex *v) const {
    return v->id;
}


bool POMDPVertexPtrEqual::operator()(const POMDPVertex* a, const POMDPVertex* b) const {
    assert(a != nullptr);
    assert(b != nullptr);
    return *a == *b;
}

bool POMDPVertexPtrEqualID::operator()(const POMDPVertex *a, const POMDPVertex *b) const {
    return a->id == b->id;
}



void POMDPAction::__handle_measure_instruction(const Instruction &instruction, const MeasurementChannel &channel, const POMDPVertex &vertex, vertex_dict &result, bool is_meas1) const {
    /*
    applies a measurement instruction to a given hybrid state (POMDP vertex)

        Args:
            instruction (Instruction): a measurement instruction
            channel (MeasChannel): measurement channel for the instruction
            vertex (POMDPVertex): current vertex for which we want to know the successors when we apply the instruction and the channel
            is_meas1 (bool, optional): _description_. is this a measurement 1 or 0?
            result (Dict[POMDPVertex, float], optional): _description_. This is a dictionary that maps a pomdp vertex and the probability of reaching it from the current vertex. We accumulate the result in this dictionary, this is why it is a parameter.
    */

    Instruction instruction1;
    if (!is_meas1) {
        instruction1 = Instruction(GateName::P0, instruction.target);
    } else {
        instruction1 = Instruction(GateName::P1, instruction.target);
    }

    auto temp = get_sequence_probability(vertex.hybrid_state->quantum_state, {instruction1}, this->precision);

    auto q = temp.first;
    auto meas_prob = temp.second;

    if (meas_prob > 0.0) {
        auto hidden_index = vertex.hidden_index;
        assert(instruction.c_target > -1);
        ClassicalState * classical_state0 = vertex.hybrid_state->classical_state->apply_instruction(Instruction(GateName::Write0, instruction.c_target));

        ClassicalState * classical_state1 = vertex.hybrid_state->classical_state->apply_instruction(Instruction(GateName::Write1, instruction.c_target));

        POMDPVertex* new_vertex_correct;
        POMDPVertex* new_vertex_incorrect;
        if (is_meas1) {
            new_vertex_correct = new POMDPVertex(new HybridState(q, classical_state1), hidden_index); // we receive the correct outcome
            new_vertex_incorrect = new POMDPVertex(new HybridState(q, classical_state0), hidden_index);
        } else {
            new_vertex_correct = new POMDPVertex(new HybridState(q, classical_state0), hidden_index); // we receive the correct outcome
            new_vertex_incorrect = new POMDPVertex(new HybridState(q, classical_state1), hidden_index);
        }
        auto prob = round_to(meas_prob * channel.get_ind_probability(is_meas1, is_meas1),  this->precision);
        if (prob > 0) {
            if (result.find(new_vertex_correct) != result.end()) {
                result[new_vertex_correct] = 0.0;
            }
            result[new_vertex_correct] += prob;
        }

        prob = round_to(meas_prob * channel.get_ind_probability( is_meas1, not is_meas1), this->precision);
        if (prob > 0){
            if (result.find(new_vertex_incorrect) != result.end()) {
                result[new_vertex_incorrect] = 0.0;
            }
            result[new_vertex_incorrect] += prob;
        }
        assert(is_close(channel.get_ind_probability(is_meas1, is_meas1) + channel.get_ind_probability(is_meas1, not is_meas1), 1, this->precision));
    }
}

void POMDPAction::__handle_unitary_instruction(const Instruction &instruction, const QuantumChannel &channel, const POMDPVertex &vertex, vertex_dict &result) const {
    for (int index = 0; index < channel.errors_to_probs.size(); index++) {
        auto err_seq = channel.errors_to_probs[index].first;
        auto prob = channel.errors_to_probs[index].second;

        assert (err_seq.size() > 0);

        QuantumState* new_qs = vertex.hybrid_state->quantum_state->apply_instruction(instruction);
        auto temp = get_sequence_probability(new_qs, err_seq, this->precision);
        auto errored_seq = temp.first;
        auto seq_prob = temp.second;
        if (seq_prob > 0.0) {
            auto new_vertex = new POMDPVertex(new HybridState(errored_seq, vertex.hybrid_state->classical_state), vertex.hidden_index);
            if (result.find(new_vertex) != result.end()) {
                result[new_vertex] = 0.0;
            }
            result[new_vertex] += round_to(seq_prob * prob, this->precision);
        }
    }
}

void POMDPAction::__handle_reset_instruction(const Instruction &instruction, const QuantumChannel &channel, const POMDPVertex &vertex, vertex_dict &result, bool is_meas1) const {
    assert (instruction.gate_name == GateName::Reset);
    Instruction projector;

    if (is_meas1) {
        projector = Instruction(GateName::P1, instruction.target);
    } else {
        projector = Instruction(GateName::P0, instruction.target);
    }

    for (int index = 0; index < channel.errors_to_probs.size(); index++) {
        auto err_seq = channel.errors_to_probs[index].first;
        auto prob = channel.errors_to_probs[index].second;
        auto temp = get_sequence_probability(vertex.hybrid_state->quantum_state, {projector}, this->precision);
        auto new_qs = temp.first;
        auto prob_new_qs = temp.second;
        if (prob_new_qs > 0) {
            if (is_meas1){
                auto x_instruction = Instruction(GateName::X, instruction.target);
                new_qs = new_qs->apply_instruction(x_instruction);
            }
            auto temp2 = get_sequence_probability(new_qs, err_seq, this->precision);
            auto errored_seq = temp2.first;
            auto seq_prob = temp2.second;
            seq_prob = round_to(prob_new_qs * seq_prob, this->precision);
            if (seq_prob > 0.0) {
                auto new_vertex = new POMDPVertex(new HybridState(errored_seq, vertex.hybrid_state->classical_state), vertex.hidden_index);
                if (result.find(new_vertex) != result.end()) {
                    result[new_vertex] = 0.0;
                }
                result[new_vertex] += round_to(seq_prob * prob, this->precision);
            }
        }
    }
}

vertex_dict POMDPAction::__dfs(HardwareSpecification &hardware_specification, POMDPVertex* current_vertex, int index_ins) const {
    /* perform a dfs to compute successors states of the sequence of instructions.
        It applies the instruction at index self.instructions_seq[index_ins] along with errors recursively

        Args:
            noise_model (NoiseModel): hardware noise model
            current_vertex (POMDPVertex):
            index_ins (int): should be less than or equal (base case that returns empty dictionary)

        Returns:
            Dict[POMDPVertex, float]: returns a dictionary where the key is a successors POMDPVertex and the corresponding probability of reaching it from current_vertex
    */

    if (index_ins == this->instruction_sequence.size()) {
        vertex_dict result;
        result[current_vertex] = 1.0;
        return result;
    }

    assert(index_ins < this->instruction_sequence.size());

    auto current_instruction = this->instruction_sequence[index_ins];
    vertex_dict temp_result;
    if (current_instruction.instruction_type == InstructionType::Classical) {
        auto new_classical_state = current_vertex->hybrid_state->classical_state->apply_instruction(current_instruction);
        auto new_vertex = new POMDPVertex(new HybridState(current_vertex->hybrid_state->quantum_state, new_classical_state), current_vertex->hidden_index);
        temp_result[new_vertex] = 1.0;
    } else {

        // assert(hardware_specification.instructions_to_channels.find(&current_instruction) != hardware_specification.instructions_to_channels.end());
        if(hardware_specification.instructions_to_channels.find(&current_instruction) == hardware_specification.instructions_to_channels.end()) {
            // cout << "current_instruction: " << current_instruction << endl;
            //
            // for (auto it : hardware_specification.instructions_to_channels) {
            //     cout << *it.first << endl;
            // }
            assert(false);
        }
        Channel *instruction_channel = hardware_specification.instructions_to_channels.find(&current_instruction)->second;
        if (current_instruction.instruction_type == InstructionType::Measurement) {
            // get successors for 0-measurements
            this->__handle_measure_instruction(current_instruction, *static_cast<MeasurementChannel*>(instruction_channel), *current_vertex, temp_result, false );

            // get successors for 1-measurements
            this->__handle_measure_instruction(current_instruction, *static_cast<MeasurementChannel*>(instruction_channel), *current_vertex, temp_result, true);
        } else if (current_instruction.gate_name == GateName::Reset){
            // WARNING: use of reset not known in all models, check when using real hardware specifications
            this->__handle_reset_instruction(current_instruction, *static_cast<QuantumChannel*>(instruction_channel), *current_vertex, temp_result, false);

            this->__handle_reset_instruction(current_instruction, *static_cast<QuantumChannel*>(instruction_channel), *current_vertex, temp_result, true);
        } else {
            this->__handle_unitary_instruction(current_instruction, *static_cast<QuantumChannel*>(instruction_channel), *current_vertex, temp_result);
        }
    }
    vertex_dict result;
    for (auto it : temp_result) {
        auto successor = it.first;
        auto prob = it.second;
        auto successors2 = this->__dfs(hardware_specification, successor, index_ins+1);
        for (auto it2 : successors2) {
            auto succ2 = it2.first;
            auto prob2 = it2.second;
            if ( result.find(succ2) != result.end()) result.at(succ2) = 0.0;
            result[succ2] += prob*prob2;
        }
    }
    for (auto it : result) {
        auto s = it.first;
        auto prob = it.second;
        result[s] = round_to(prob, this->precision);
    }
    assert (!result.empty());
    return result;
}


POMDPAction::POMDPAction(const string &name, const vector<Instruction> &instruction_sequence, int precision, const vector<Instruction> &pseudo_instruction_sequence) {
    assert (name.size() > 0);
    this->name = name;
    this->instruction_sequence = instruction_sequence;
    this->precision = precision;
    this->pseudo_instruction_sequence = pseudo_instruction_sequence;
}

vertex_dict POMDPAction::get_successor_states(HardwareSpecification &hardware_specification, POMDPVertex *current_vertex) const {
    return this->__dfs(hardware_specification, current_vertex, 0);
}

bool POMDPAction::operator==(const POMDPAction &other) const {
    return this->name == other.name;
}

string to_string(const POMDPAction &action) {
    assert(action.name.size() > 0);
    string result = "";
    if (action.name == HALT_ACTION.name) {
        return "HALT";
    }

    for (auto instruction : action.pseudo_instruction_sequence) {
        result += to_string(instruction);
    }
    return result;
}

string to_string(const POMDPAction* action) {
    return to_string(*action);
}

std::size_t POMDPActionHash::operator()(const POMDPAction *action) const {
    std::hash<std::string> str_hasher;
    return str_hasher(action->name);
}


bool POMDPActionPtrEqual::operator()(const POMDPAction* a, const POMDPAction* b) const {
    return *a == *b;
}

POMDPVertex* POMDP::get_vertex(const POMDPVertex *vertex) {
    for (int i = 0; i < this->states.size(); i++) {
        if (*this->states.at(i) == *vertex) return this->states.at(i);
    }
    return nullptr;
}

POMDPVertex* POMDP::create_new_vertex(const HybridState *hybrid_state, int hidden_index) {
    auto new_hybrid_state =  new HybridState(new QuantumState(*hybrid_state->quantum_state), new ClassicalState(*hybrid_state->classical_state));
    assert(new_hybrid_state->quantum_state != nullptr);
    assert(new_hybrid_state->classical_state != nullptr);
    assert (new_hybrid_state->quantum_state->sparse_vector.size() > 0);
    auto new_vertex = new POMDPVertex(new_hybrid_state, hidden_index);
    auto v = this->get_vertex(new_vertex);
    if (v == nullptr) {
        assert(new_vertex->hybrid_state != nullptr);
        assert(new_vertex->hybrid_state->classical_state != nullptr);
        assert(new_vertex->hybrid_state->quantum_state != nullptr);
        this->states.push_back(new_vertex);
        return new_vertex;
    }
    // delete new_hybrid_state;
    // delete new_vertex;
    assert(v->hybrid_state != nullptr);
    assert(v->hybrid_state->classical_state != nullptr);
    assert(v->hybrid_state->quantum_state != nullptr);
    return v;
}

POMDP::POMDP(int precision) {
    this->precision = precision;
}

POMDP::POMDP(POMDPVertex *initial_state, const vector<POMDPVertex*> &states, const vector<POMDPAction> &actions, unordered_map<POMDPVertex*, unordered_map<POMDPAction*, unordered_map<POMDPVertex*, Rational,POMDPVertexHash, POMDPVertexPtrEqual>,POMDPActionHash, POMDPActionPtrEqual>, POMDPVertexHash, POMDPVertexPtrEqualID>  &transition_matrix) {
    this->initial_state = initial_state;
    this->states = states;
    this->actions = actions;
    this->transition_matrix = transition_matrix;
    this->precision = -1;
}

void POMDP::build_pomdp(const vector<POMDPAction> &actions_, HardwareSpecification &hardware_specification, int horizon, unordered_map<int, int> embedding, HybridState *initial_state_hs, const vector<pair<HybridState*, double>> &initial_distribution, vector<int> &qubits_used, guard_type guard, bool set_hidden_index) {
    this->actions = actions_;
    assert(this->states.empty());

    queue<pair<POMDPVertex*, int>> q;
    if (initial_state_hs == nullptr) {
        initial_state_hs = new HybridState(new QuantumState({0}, this->precision), new ClassicalState());
    }

    auto initial_v = this->create_new_vertex(initial_state_hs, -1);
    this->initial_state = initial_v;

    if (initial_distribution.empty()) {
        assert(false);
        q.emplace(initial_v, 0);
    } else {
        double total = 0.0;

        for (auto& p : initial_distribution) {
            total += p.second;
        }
        if (!is_close(total, 1.0, this->precision)){
            throw invalid_argument("Initial distribution must sum to 1");
        }

        this->transition_matrix[initial_v] = unordered_map<POMDPAction*, unordered_map<POMDPVertex*, Rational, POMDPVertexHash, POMDPVertexPtrEqual>, POMDPActionHash, POMDPActionPtrEqual>();
        assert(this->transition_matrix.find(initial_v) != this->transition_matrix.end());
        auto *INIT_CHANNEL = new POMDPAction("INIT__", {}, this->precision, {});
        this->transition_matrix[initial_v][INIT_CHANNEL] = unordered_map<POMDPVertex*, Rational, POMDPVertexHash, POMDPVertexPtrEqual>();
        assert(this->transition_matrix.at(initial_v).find(INIT_CHANNEL) != this->transition_matrix.at(initial_v).end());
        int hidden_index;
        for (int index = 0; index < initial_distribution.size(); index ++) {
            auto hybrid_state = initial_distribution[index].first;
            auto prob = initial_distribution[index].second;
            if (set_hidden_index){
                hidden_index = index;
            } else{
                hidden_index = -1;
            }
            auto v =  new POMDPVertex(new HybridState(*hybrid_state), hidden_index);
            this->transition_matrix[initial_v][INIT_CHANNEL].insert_or_assign(v, Rational(to_string(prob), "1", this->precision * (horizon+1)));
            assert (this->transition_matrix[initial_v][INIT_CHANNEL].find(v) != this->transition_matrix[initial_v][INIT_CHANNEL].end());
            assert (v->id > 0);
            q.push(make_pair(v, 0)); // second element denotes that this vertex is at horizon 0
        }
    }

    unordered_set<POMDPVertex*, POMDPVertexHash, POMDPVertexPtrEqual> visited;

    while (!q.empty()) {
        assert(initial_v->hybrid_state != nullptr);
        pair<POMDPVertex*, int> temp = q.front();
        q.pop();
        auto current_v = temp.first;
        if (current_v->id == 0) {
            continue;
        }
        auto current_horizon = temp.second;
        if (horizon != -1) {
            if (current_horizon == horizon) {
                continue;
            }
        }

        if (visited.find(current_v) != visited.end()) {
            continue;
        }

        visited.insert(current_v);

        if (this->transition_matrix.find(current_v) == this->transition_matrix.end()) {
            this->transition_matrix[current_v] = unordered_map<POMDPAction*, unordered_map<POMDPVertex*, Rational, POMDPVertexHash, POMDPVertexPtrEqual>, POMDPActionHash, POMDPActionPtrEqual>();
        }
        for (auto action : actions) {
            if (guard(*current_v, embedding, action)) {
                assert(this->transition_matrix[current_v].find(&action) == this->transition_matrix[current_v].end());

                auto copy_action = new POMDPAction(action);
                this->transition_matrix[current_v][copy_action] = unordered_map<POMDPVertex*, Rational, POMDPVertexHash, POMDPVertexPtrEqual>();
                auto successors = action.get_successor_states(hardware_specification, current_v);
                assert(!successors.empty());
                for (auto it : successors ) {
                    auto succ = it.first;
                    auto prob = it.second;
                    assert(succ->hybrid_state != nullptr);
                    assert(succ->hybrid_state->quantum_state != nullptr);
                    assert(succ->hybrid_state->classical_state != nullptr);
                    auto new_vertex = this->create_new_vertex(succ->hybrid_state, succ->hidden_index);
                    assert(new_vertex != nullptr);
                    assert(new_vertex->hybrid_state != nullptr);
                    assert(new_vertex->hybrid_state != nullptr);
                    if (this->transition_matrix[current_v][copy_action].find(new_vertex) == this->transition_matrix[current_v][copy_action].end()) {
                        this->transition_matrix[current_v][copy_action].insert_or_assign(new_vertex, Rational("0", "1", this->precision * (horizon+1)));
                    }

                    this->transition_matrix[current_v][copy_action][new_vertex] = this->transition_matrix[current_v][copy_action][new_vertex] + Rational(to_string(prob), "1", this->precision * (horizon+1));
                    if (visited.find(new_vertex) == visited.end()) {
                        if (horizon == -1 || (current_horizon + 1 < horizon)) {
                            q.push(make_pair(new POMDPVertex(*new_vertex), current_horizon));
                        }
                    }
                }
            }
        }
    }
}

ostream& operator<<(ostream& os, const POMDPVertex& v) {
    os << v.id << " " << v.hidden_index << " -- ";
    os << *v.hybrid_state;

    return os;
}

void POMDP::print_pomdp() const {
    cout << "states: " << endl;

    for (auto s : states) {
        cout <<  *s << endl;
    }
    cout << "transitions: " << endl;
    for (auto it : this->transition_matrix) {
        for (const auto it_action : it.second) {
            for (const auto it_successor: it_action.second) {
                cout << it.first->id << " ----- " << it_action.first->name << " " << round_to(to_double(it_successor.second), 3) << " " << it_successor.first->id << endl;
            }
        }

    }
}

void POMDP::check_pomdp() const {
    for (auto it : this->transition_matrix) {
        assert(it.first->hybrid_state != nullptr);
        assert(it.first->hybrid_state->quantum_state != nullptr);
        assert(it.first->hybrid_state->classical_state != nullptr);
        for (const auto it_action : it.second) {
            assert(it_action.first != nullptr);
            assert (it_action.first->name.size() > 0);
            for (const auto it_successor: it_action.second) {
                assert(it_successor.first->hybrid_state != nullptr);
                assert(it_successor.first->hybrid_state->quantum_state != nullptr);
                assert(it_successor.first->hybrid_state->classical_state != nullptr);
            }
        }
    }
}
