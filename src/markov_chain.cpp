//
// Created by Stefanie Muroya Lei on 02.01.26.
//

#include "markov_chain.hpp"

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


shared_ptr<Configuration> Configuration::get_atomic_program_ensemble(HardwareSpecification &spec, const unordered_map<int, int> &embedding, const int &mc_precision) {
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
            else if (auto assign_one_context = dynamic_cast<ProgrammingLanguageParser::AssignOneContext*>(c)) {
                string cid = assign_one_context->CID()->toString();
                int index = std::stoi(cid.substr(1));
                Instruction W1 = Instruction(GateName::Write1, index);
                for (int i = 0; i < this->ensemble->probs.size(); i++) {
                    auto temp = this->ensemble->probs[i].first->apply_instruction(W1);
                    result_ensemble->add_prob( temp,this->ensemble->probs[i].second);
                }
            }
            else if (auto assign_copy_context = dynamic_cast<ProgrammingLanguageParser::AssignCopyContext*>(c)) {
                string write_cid = assign_copy_context->CID()[0]->toString();
                string read_cid = assign_copy_context->CID()[1]->toString();
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
            } else if (auto measure_context = dynamic_cast<ProgrammingLanguageParser::AssignMeasureContext*>(c)) {
                string cid = measure_context->CID()->toString();
                string qid = measure_context->QID()->toString();
                int c_index = std::stoi(cid.substr(1));
                int q_index = embedding.at(std::stoi(qid.substr(1)));
                Instruction meas_ins = Instruction(GateName::Meas, q_index, c_index);
                for (int i = 0; i < this->ensemble->probs.size(); i++) {
                    POMDPAction action = POMDPAction("some action", {meas_ins}, mc_precision, {});
                    shared_ptr<POMDPVertex> current_vertex = make_shared<POMDPVertex>(this->ensemble->probs[i].first);
                    auto succs = action.get_successor_states(spec, current_vertex);
                    for (const auto& [fst, snd] : succs) {
                        result_ensemble->add_prob( fst->hybrid_state,this->ensemble->probs[i].second * snd);
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
                for (const auto& [fst, snd] : succs) {
                    result_ensemble->add_prob( fst->hybrid_state,this->ensemble->probs[i].second * snd);
                }
            }
        }

        return make_shared<Configuration>(nullptr, result_ensemble);
}

shared_ptr<Ensemble<MyFloat>> MarkovChain::get_final_ensemble (const shared_ptr<Configuration> &config) {
        assert(!config->ensemble->probs.empty());
        auto program = config->program;
        if (config->is_atomic_program()) {
            return to_myfloat(config->get_atomic_program_ensemble(this->spec, this->embedding, this->mc_precision)->ensemble, this->mc_precision, this->max_depth);
        }

        if (auto s = dynamic_cast<ProgrammingLanguageParser::IfContext*>(program)) {
            assert (s->program().size() == 2);
            int classical_val = stoi(s->INTEGER()->toString());


            ProgrammingLanguageParser::ProgramContext* program_left = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[0]);
            ProgrammingLanguageParser::ProgramContext* program_right = dynamic_cast<ProgrammingLanguageParser::ProgramContext*>(s->program()[1]);

            shared_ptr<Ensemble<double>> ensemble_true = make_shared<Ensemble<double>>(mc_precision);
            shared_ptr<Ensemble<double>> ensemble_false = make_shared<Ensemble<double>>(mc_precision);

            for (auto p : config->ensemble->probs) {
                if (p.first->classical_state->get_memory_val() == classical_val) {
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
            auto config_right = make_shared<Configuration>(program_right, to_double(final_ensemble_left, this->mc_precision));
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
