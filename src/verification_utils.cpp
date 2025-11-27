//
// Created by Stefanie Muroya Lei on 21.11.25.
//
#include "verification_utils.hpp"

template <typename FloatT>
int Ensemble<FloatT>::does_hybrid_state_exists(shared_ptr<HybridState> &state) const{
    for (int i = 0; i < this->probs.size(); i++) {
        auto hs = this->probs[i];
        if (*hs.first == *state) {
            return i;
        }
    }
    return -1;
}

template <typename FloatT>
void Ensemble<FloatT>::add_prob(shared_ptr<HybridState> &hs, FloatT value) {
    assert(this->precision != -1);
    int index = this->does_hybrid_state_exists(hs);
    if (index == -1) {
        this->probs.push_back(make_pair(hs, value));
        return;
    }
    auto temp = this->probs[index];
    this->probs[index] = make_pair(hs, value + temp.second) ;
}

template <>
bool Ensemble<MyFloat>::operator==(const Ensemble<MyFloat> &other) const {
    if (other.probs.size() != this->probs.size()) return false;
    for (auto e : other.probs) {
        auto index = this->does_hybrid_state_exists(e.first);
        if (index == -1) return false;
        if (e.second != other.probs[index].second) return false;
    }
    return true;
}

template <>
bool Ensemble<double>::operator==(const Ensemble<double> &other) const {
    if (other.probs.size() != this->probs.size()) return false;
    for (auto e : other.probs) {
        auto index = this->does_hybrid_state_exists(e.first);
        if (index == -1) return false;
        if (!is_close(e.second,other.probs[index].second, this->precision)) return false;
    }
    return true;
}

template <>
bool Ensemble<z3::expr>::operator==(const Ensemble<z3::expr> &other) const {
    if (other.probs.size() != this->probs.size()) return false;
    for (auto e : other.probs) {
        auto index = this->does_hybrid_state_exists(e.first);
        if (index == -1) return false;
        if (!is_close(e.second,other.probs[index].second, this->precision)) return false;
    }
    return true;
}

template <>
double Ensemble<double>::get_weight() {
    double result = 0;

    for (auto e : this->probs) {
        result += e.second;
    }
    return result;
}

template <>
z3::expr Ensemble<z3::expr>::get_weight() {
    throw runtime_error("get_weight not implemented for Ensemble<MyFloat>");
}

template <>
MyFloat Ensemble<MyFloat>::get_weight() {
    MyFloat result("0", this->precision);

    for (auto e : this->probs) {
        result = result + e.second;
    }

    return result;
}

template<>
void Ensemble<double>::normalize() {
    auto w = get_weight();
    for (int i = 0; i < this->probs.size(); i++) {
        this->probs[i].second = round_to(this->probs[i].second/w, this->precision);
    }
}

template<>
void Ensemble<MyFloat>::normalize() {
    throw runtime_error("normalize not implemented for Ensemble<MyFloat>");
}

template<>
void Ensemble<z3::expr>::normalize() {
    throw runtime_error("normalize not implemented for Ensemble<z3::expr>");
}

Ensemble<z3::expr> get_symbolic_ensemble(const std::vector<shared_ptr<Ensemble<MyFloat>>> &ensembles, const z3::expr_vector &weights, z3::context &ctx) {
    Ensemble<z3::expr> result;

    assert( weights.size() == ensembles.size());
    for (int i = 0; i <ensembles.size(); i++) {
        for (auto e : ensembles[i]->probs) {
            result.add_prob(e.first, weights[i] * ctx.real_val(to_string(e.second).c_str()));
        }
    }
    return result;
}



shared_ptr<Ensemble<MyFloat>> to_myfloat(const shared_ptr<Ensemble<double>> &ensemble) {
    shared_ptr<Ensemble<MyFloat>> result = make_shared<Ensemble<MyFloat>>(mc_precision * (max_depth + 1));

    for (auto p : ensemble->probs) {
        result->add_prob(p.first, MyFloat(to_string(p.second), mc_precision* (max_depth + 1)));
    }

    return result;
}

shared_ptr<Ensemble<double>> to_double(const shared_ptr<Ensemble<MyFloat>> &ensemble) {
    shared_ptr<Ensemble<double>> result = make_shared<Ensemble<double>>(mc_precision);

    for (auto p : ensemble->probs) {
        result->add_prob(p.first, round_to(to_double(p.second), mc_precision));
    }

    return result;
}

[[nodiscard]] bool Configuration::is_atomic_program() const {
    if (dynamic_cast<ProgrammingLanguageParser::SkipContext*>(program)) {
        return true;
    }

    if (program->children.size() == 1  && dynamic_cast<ProgrammingLanguageParser::Classical_statementContext*>(program->children[0])) {
        return true;
    }

    if (dynamic_cast<ProgrammingLanguageParser::UnitaryContext*>(program)) {
        return true;
    }

    return false;
}

shared_ptr<Configuration> Configuration::get_atomic_program_ensemble(HardwareSpecification &spec, const unordered_map<int, int> &embedding) {
        assert(!this->ensemble->probs.empty());
        shared_ptr<Ensemble<double>> result_ensemble = make_shared<Ensemble<double>>(mc_precision);
        assert(is_atomic_program());

        if (dynamic_cast<ProgrammingLanguageParser::SkipContext*>(program)) {
            return make_shared<Configuration>(nullptr, ensemble);
        }
        auto *c = dynamic_cast<ProgrammingLanguageParser::Classical_statementContext*>(program->children[0]);
        if (program->children.size() == 1  && c) {
            if (auto a = dynamic_cast<ProgrammingLanguageParser::AssignZeroContext*>(c)) {
                string cid = a->CID()->toString();
                int index = std::stoi(cid.substr(1));
                Instruction W0 = Instruction(GateName::Write0, index);
                for (int i = 0; i < this->ensemble->probs.size(); i++) {
                    auto temp = this->ensemble->probs[i].first->apply_instruction(W0);
                    result_ensemble->add_prob( temp,this->ensemble->probs[i].second);
                }
            }
            else if (auto a = dynamic_cast<ProgrammingLanguageParser::AssignOneContext*>(c)) {
                string cid = a->CID()->toString();
                int index = std::stoi(cid.substr(1));
                Instruction W1 = Instruction(GateName::Write1, index);
                for (int i = 0; i < this->ensemble->probs.size(); i++) {
                    auto temp = this->ensemble->probs[i].first->apply_instruction(W1);
                    result_ensemble->add_prob( temp,this->ensemble->probs[i].second);
                }
            }
            else if (auto a = dynamic_cast<ProgrammingLanguageParser::AssignCopyContext*>(c)) {
                string write_cid = a->CID()[0]->toString();
                string read_cid = a->CID()[1]->toString();
                int w_index = std::stoi(write_cid.substr(1));
                int r_index = std::stoi(read_cid.substr(1));
                for (int i = 0; i < this->ensemble->probs.size(); i++) {
                    int value = this->ensemble->probs[i].first->classical_state->read(r_index);
                    Instruction instruction;
                    if (value == 0) {
                        instruction = Instruction(GateName::Write0, w_index);
                    } else {
                        assert(value == 1);
                        instruction = Instruction(GateName::Write1, w_index);
                    }
                    auto temp = this->ensemble->probs[i].first->apply_instruction(instruction);
                    result_ensemble->add_prob( temp,this->ensemble->probs[i].second);
                }
            } else if (auto a = dynamic_cast<ProgrammingLanguageParser::AssignMeasureContext*>(c)) {
                string cid = a->CID()->toString();
                string qid = a->QID()->toString();
                int c_index = std::stoi(cid.substr(1));
                int q_index = embedding.at(std::stoi(qid.substr(1)));
                Instruction meas_ins = Instruction(GateName::Meas, q_index, c_index);
                for (int i = 0; i < this->ensemble->probs.size(); i++) {
                    POMDPAction action = POMDPAction("some action", {meas_ins}, mc_precision, {});
                    shared_ptr<POMDPVertex> current_vertex = make_shared<POMDPVertex>(this->ensemble->probs[i].first);
                    auto succs = action.get_successor_states(spec, current_vertex);
                    for (auto t : succs) {
                        result_ensemble->add_prob( t.first->hybrid_state,this->ensemble->probs[i].second * t.second);
                    }
                }
            } else {
                throw runtime_error("Classical statement does not matches anything");
            }
        }

        if (auto *U = dynamic_cast<ProgrammingLanguageParser::UnitaryContext*>(program)) {
            string unitary = U->UNITARY()->toString();
            Instruction instruction;
            auto qlist = U->UnitaryContext::qlist()->getQList();
            for (int & i : qlist) {
                i = embedding.at(i);
            }

            if (unitary == "X") {
                assert(qlist.size() == 1);
                instruction = Instruction(GateName::X, qlist[0]);
            } else if (unitary == "CX") {
                assert(qlist.size() == 2);
                instruction = Instruction(GateName::Cnot, vector<int>({qlist[0]}), qlist[1]);
            } else if (unitary == "H") {
                assert(qlist.size() == 1);
                instruction = Instruction(GateName::H, qlist[0]);
            } else {
                throw runtime_error("invalid unitary gate:" + unitary);
            }
            for (int i = 0; i < this->ensemble->probs.size(); i++) {
                POMDPAction action = POMDPAction("some action", spec.to_basis_gates_impl(instruction), mc_precision, {});
                shared_ptr<POMDPVertex> current_vertex = make_shared<POMDPVertex>(this->ensemble->probs[i].first);
                auto succs = action.get_successor_states(spec, current_vertex);
                for (auto t : succs) {
                    result_ensemble->add_prob( t.first->hybrid_state,this->ensemble->probs[i].second * t.second);
                }
            }
        }

        return make_shared<Configuration>(nullptr, result_ensemble);
    }

shared_ptr<Ensemble<MyFloat>> MarkovChain::get_final_ensemble (const shared_ptr<Configuration> &config) {
        assert(!config->ensemble->probs.empty());
        auto program = config->program;
        if (config->is_atomic_program()) {
            return to_myfloat(config->get_atomic_program_ensemble(this->spec, this->embedding)->ensemble);
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::IfContext*>(program)) {
            assert (s->program().size() == 2);
            string cid = s->CID()->toString();
            int c_index = std::stoi(cid.substr(1));


            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);

            shared_ptr<Ensemble<double>> ensemble_true = make_shared<Ensemble<double>>(mc_precision);
            shared_ptr<Ensemble<double>> ensemble_false = make_shared<Ensemble<double>>(mc_precision);

            for (auto p : config->ensemble->probs) {
                if (p.first->classical_state->read(c_index)) {
                    ensemble_true->add_prob(p.first, p.second);
                } else {
                    ensemble_false->add_prob(p.first, p.second);
                }
            }
            // auto w_true = MyFloat(to_string(ensemble_true->get_weight()), mc_precision*(max_depth+1));
            // cout << "w_true" << w_true << endl;
            // ensemble_true->normalize();
            // auto w_false = MyFloat(to_string(ensemble_false->get_weight()), mc_precision*(max_depth+1));
            // ensemble_false->normalize();
            // cout << "w_false" << w_false << endl;

            shared_ptr<Ensemble<MyFloat>> final_ensemble = make_shared<Ensemble<MyFloat>>(mc_precision*(max_depth+1));

            if (!ensemble_true->probs.empty()) {
                auto config_left = make_shared<Configuration>(program_left, ensemble_true);
                auto temp_ensemble = get_final_ensemble(config_left);
                for (auto p : temp_ensemble->probs) {
                    final_ensemble->add_prob(p.first,  p.second);
                }
            }


            if (!ensemble_false->probs.empty()) {
                auto config_right = make_shared<Configuration>(program_right, ensemble_false);
                auto temp_ensemble = get_final_ensemble(config_right);
                for (auto p : temp_ensemble->probs) {
                    final_ensemble->add_prob(p.first, p.second);
                }
            }
            return final_ensemble;
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::ProbContext*>(program)) {
            assert (s->program().size() == 2);
            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);
            double d_prob_left = round_to(1 - stod(s->REALNUM()->toString()), mc_precision);
            double d_prob_right = round_to(stod(s->REALNUM()->toString()), mc_precision);
            MyFloat prob_left = MyFloat(to_string(d_prob_left), mc_precision * (max_depth + 1));
            MyFloat prob_right = MyFloat(to_string(d_prob_right), mc_precision * (max_depth + 1));
            assert (prob_left + prob_right == MyFloat("1", mc_precision * (max_depth + 1)));
            auto config_left = make_shared<Configuration>(program_left, config->ensemble);
            auto config_right = make_shared<Configuration>(program_right, config->ensemble);
            auto final_ensemble_left = get_final_ensemble(config_left);
            auto final_ensemble_right = get_final_ensemble(config_right);

            shared_ptr<Ensemble<MyFloat>> final_ensemble = make_shared<Ensemble<MyFloat>>(mc_precision*(max_depth+1));
            for (auto p : final_ensemble_left->probs) {
                auto prob = prob_left * p.second;
                final_ensemble->add_prob(p.first, prob);
            }

            for (auto p : final_ensemble_right->probs) {
                auto prob = prob_right * p.second;
                final_ensemble->add_prob(p.first, prob);
            }
            return final_ensemble;
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::SeqContext*>(program)) {
            assert (s->program().size() == 2);
            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);
            auto config_left = make_shared<Configuration>(program_left, config->ensemble);
            auto final_ensemble_left = get_final_ensemble(config_left);
            auto config_right = make_shared<Configuration>(program_right, to_double(final_ensemble_left));
            return get_final_ensemble(config_right);
        }

        throw runtime_error("Programming language error");
    };

int MarkovChain::get_depth(const shared_ptr<Configuration> &config) {
        auto program = config->program;
        if (config->is_atomic_program()) {
            return 1;
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::IfContext*>(program)) {
            assert (s->program().size() == 2);
            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);
            auto config_left = make_shared<Configuration>(program_left, config->ensemble);
            auto config_right = make_shared<Configuration>(program_right, config->ensemble);
            return max(get_depth(config_left), get_depth(config_right));
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::ProbContext*>(program)) {
            assert (s->program().size() == 2);
            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);
            auto config_left = make_shared<Configuration>(program_left, config->ensemble);
            auto config_right = make_shared<Configuration>(program_right, config->ensemble);
            return max(get_depth(config_left), get_depth(config_right));
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::SeqContext*>(program)) {
            assert (s->program().size() == 2);
            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);
            auto config_left = make_shared<Configuration>(program_left, config->ensemble);
            auto config_right = make_shared<Configuration>(program_right, config->ensemble);
            return get_depth(config_left) + get_depth(config_right);
        }

        throw runtime_error("Programming language error");
    }