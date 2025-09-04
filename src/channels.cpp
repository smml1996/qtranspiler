#include "channels.hpp"

QuantumChannel::QuantumChannel(json &data) {

    vector<double> probabilities = data["probabilities"];
    vector<json> all_errors = data["errors"];

    assert(probabilities.size() == all_errors.size());

    for (int i = 0; i < probabilities.size(); i++) {
        vector<Instruction> final_errors;
        double probability = probabilities[i];

        
        for (int j = 0; j < all_errors[i].size(); j++){
            Instruction instruction = Instruction(all_errors[i][j]);
            final_errors.push_back(instruction);
        }
        
        this->errors_to_probs.push_back(make_pair(final_errors, probability));

    }

    //estimating success probability
    this->estimated_success_prob = 0.5;
    for (auto it : this->errors_to_probs) {
        auto instruction_seq = it.first;
        auto prob = it.second;
        if (is_identity(instruction_seq) or prob > 0.5) {
                this->estimated_success_prob = max(this->estimated_success_prob, prob);
        }
    }
        
}

MeasurementChannel::MeasurementChannel(json &json_val) {
    this->correct_0 = json_val["0"]["0"];
    this->incorrect_0 = json_val["0"]["1"];
    this->correct_1 = json_val["1"]["1"];
    this->incorrect_1 = json_val["1"]["0"];
}

double MeasurementChannel::get_ind_probability(int ideal_outcome, int noisy_outcome) const{
    if (ideal_outcome ==  noisy_outcome) {
        if (noisy_outcome == 0) {
            return this->correct_0;
        } else {
            return this->correct_1;
        }
    } else {
        if (ideal_outcome == 0) {
            return this->incorrect_0;
        } else {
            return this->incorrect_1;
        }
    }
}