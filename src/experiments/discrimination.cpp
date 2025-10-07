#include "experiments.hpp"
#include "reset.cpp"

//
// Created by Stefanie Muroya Lei on 06.09.25.
//
class BasisStatesDiscrimination : public ResetProblem {
public:
    BasisStatesDiscrimination(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
        const set<MethodType> &method_types, const set<QuantumHardware>& hw_list, bool optimize) : ResetProblem(name, precision, with_thermalization, min_horizon, max_horizon, method_types, hw_list, optimize) {
        this->set_hidden_index = true;
    };

    BasisStatesDiscrimination() {
        this->set_hidden_index = true;
        this->name = "basic_zero_plus";
        this->precision = 8;
        this->with_thermalization = false;
        this->min_horizon = 1;
        this->max_horizon = 3;
    };

    MyFloat postcondition(const Belief &belief, const unordered_map<int, int> &embedding) override {
        assert (embedding.size() == 1);
        MyFloat result("0", this->precision*(this->max_horizon+1));
        for (auto it : belief.probs) {
            auto hybrid_state = it.first->hybrid_state;
            auto cs = hybrid_state->classical_state;
            assert (it.first->hidden_index == 0 || it.first->hidden_index == 1);
            if (it.first->hidden_index == cs->read(0)) {
                result = result + it.second;
            }
        }
        return result;
    }

    double postcondition_double(const VertexDict &belief, const unordered_map<int, int> &embedding) override {
        assert (embedding.size() == 1);
        double result = 0;
        for (auto it : belief.probs) {
            auto hybrid_state = it.first->hybrid_state;
            auto cs = hybrid_state->classical_state;
            assert (it.first->hidden_index == 0 || it.first->hidden_index == 1);
            if (it.first->hidden_index == cs->read(0)) {
                result = result + it.second;
            }
        }
        return result;
    }

    vector<shared_ptr<POMDPAction>> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {
        assert(embedding.size() == 1);
        assert(embedding.find(0) != embedding.end());


        vector<Instruction> H_seq = hardware_spec.to_basis_gates_impl(Instruction(GateName::H,
            embedding.at(0)));
        H_seq.emplace_back(GateName::Write1, 2);
        auto H0 = make_shared<POMDPAction>("H0", H_seq, this->precision, vector<Instruction>({Instruction(GateName::H, 0)}));

        auto P0 = make_shared<POMDPAction>("P0",
            vector<Instruction>({Instruction(GateName::Meas, embedding.at(0), 0), Instruction(GateName::Write1, 3)}),
            this->precision,
            vector<Instruction>({Instruction(GateName::Meas, 0, 0)}));

        auto determine0 = make_shared<POMDPAction>("Is0",
            vector<Instruction>({Instruction(GateName::Write0, 0), Instruction(GateName::Write1, 1)}),
            this->precision,
            vector<Instruction>({Instruction(GateName::Write0, 0)}));

        auto determinePlus = make_shared<POMDPAction>("IsPlus",
            vector<Instruction>({Instruction(GateName::Write1, 0), Instruction(GateName::Write1, 1)}),
            this->precision,
            vector<Instruction>({Instruction(GateName::Write1, 0)}));
        return {H0, P0, determine0, determinePlus};
    };




};

class CBasisStatesDiscrimination : public BasisStatesDiscrimination {
public:
    CBasisStatesDiscrimination(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
        const set<MethodType> &method_types, const set<QuantumHardware>& hw_list, bool optimize) : BasisStatesDiscrimination(name, precision, with_thermalization, min_horizon, max_horizon, method_types, hw_list, optimize) {
        this->set_hidden_index = true;
    };

    MyFloat postcondition(const Belief &belief, const unordered_map<int, int> &embedding) override {
        assert (embedding.size() == 1);
        MyFloat result("0", this->precision*(this->max_horizon+1));
        for (auto it : belief.probs) {
            auto hybrid_state = it.first->hybrid_state;
            auto cs = hybrid_state->classical_state;
            assert (it.first->hidden_index == 0 || it.first->hidden_index == 1);
            if (it.first->hidden_index == 0 == cs->read(0)) {
                result = result + it.second;
            }
        }
        return result;
    }

    double postcondition_double(const VertexDict &belief, const unordered_map<int, int> &embedding) override {
        assert (embedding.size() == 1);
        double result = 0.0;
        for (auto it : belief.probs) {
            auto hybrid_state = it.first->hybrid_state;
            auto cs = hybrid_state->classical_state;
            assert (it.first->hidden_index == 0 || it.first->hidden_index == 1);
            if (it.first->hidden_index == 0 == cs->read(0)) {
                result = result + it.second;
            }
        }
        return result;
    }

    vector<shared_ptr<POMDPAction>> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const override {

        assert(embedding.size() == 1);
        assert(embedding.find(0) != embedding.end());


        auto X0 = make_shared<POMDPAction>("X0", hardware_spec.to_basis_gates_impl(Instruction(GateName::X,
            embedding.at(0))), this->precision, vector<Instruction>({Instruction(GateName::X, 0)}));

        auto P0 = make_shared<POMDPAction>("P0",
            vector<Instruction>({Instruction(GateName::Meas, embedding.at(0), 0)}),
            this->precision,
            vector<Instruction>({Instruction(GateName::Meas, 0, 0)}));

        auto determine0 = make_shared<POMDPAction>("Is0",
            vector<Instruction>({Instruction(GateName::Write0, 0)}),
            this->precision,
            vector<Instruction>({Instruction(GateName::Write0, 0)}));

        auto determine1 = make_shared<POMDPAction>("Is1",
            vector<Instruction>({Instruction(GateName::Write1, 0)}),
            this->precision,
            vector<Instruction>({Instruction(GateName::Write1, 0)}));
        return {X0, P0, determine0, determine1};
    }

};

class BasicZeroPlusDiscrimination : public BasisStatesDiscrimination {
public:
    BasicZeroPlusDiscrimination(const string &name, int precision, bool with_thermalization, int min_horizon, int max_horizon,
        const set<MethodType> &method_types, const set<QuantumHardware>& hw_list, bool optimize) :
    BasisStatesDiscrimination(name, precision, with_thermalization, min_horizon, max_horizon,
    method_types, hw_list, optimize) {
    };

    BasicZeroPlusDiscrimination() : BasisStatesDiscrimination() {};

    vector<pair<shared_ptr<HybridState>, double>> get_initial_distribution(unordered_map<int, int> &embedding) const override {
        assert (embedding.size() == 1);
        vector<pair<shared_ptr<HybridState>, double>> result;

        auto classical_state = make_shared<ClassicalState>();

        auto H0 = Instruction(GateName::H, embedding.at(0));

        auto state0 = make_shared<QuantumState>(vector<int>({embedding.at(0)}), this->precision);
        result.push_back(make_pair(make_shared<HybridState>(state0, classical_state), 0.5));

        // prepare first bell state
        auto state1 = state0->apply_instruction(H0);

        result.push_back(make_pair(make_shared<HybridState>(state1, classical_state), 0.5));

        return result;
    }

    [[nodiscard]] bool guard(const shared_ptr<POMDPVertex>& vertex, const unordered_map<int, int>& embedding, const shared_ptr<POMDPAction>& action) const override {
        if (vertex->hybrid_state->classical_state->read(1)) {
            return false;
        }
        if (vertex->hybrid_state->classical_state->read(2)) {
            if (action->name == "H0") return false;
        }

        if (vertex->hybrid_state->classical_state->read(3)) {
            return action->name != "H0";
        } else {
            return action->name != "Is0" && action->name != "IsPlus";
        }
        return true;
    }

    MyFloat postcondition(const Belief &belief, const unordered_map<int, int> &embedding) override {
        assert (embedding.size() == 1);
        auto state0 = QuantumState({embedding.at(0)}, this->precision);
        auto H = Instruction(GateName::H, embedding.at(0));
        auto state1 = state0.apply_instruction(H);
        MyFloat result("0", this->precision*(this->max_horizon+1));
        for (auto it : belief.probs) {
            assert(it.first->hidden_index == 0 || it.first->hidden_index == 1);
            auto hybrid_state = it.first->hybrid_state;
            auto cs = hybrid_state->classical_state;
            if (cs->read(0) == it.first->hidden_index) {
                result = result + it.second;
            }
        }
        return result;
    }

    double postcondition_double(const VertexDict &belief, const unordered_map<int, int> &embedding) override {
        assert (embedding.size() == 1);
        auto state0 = QuantumState({embedding.at(0)}, this->precision);
        auto H = Instruction(GateName::H, embedding.at(0));
        auto state1 = state0.apply_instruction(H);
        double result = 0.0;
        for (auto it : belief.probs) {
            assert(it.first->hidden_index == 0 || it.first->hidden_index == 1);
            auto hybrid_state = it.first->hybrid_state;
            auto cs = hybrid_state->classical_state;
            if (cs->read(0) == it.first->hidden_index) {
                result = result + it.second;
            }
        }
        return result;
    }
};
