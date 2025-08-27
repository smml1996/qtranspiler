#include "../include/channels.hpp"

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
}

MeasurementChannel::MeasurementChannel(json &json_val) {
    this->correct_0 = json_val["0"]["0"];
    this->incorrect_0 = json_val["0"]["1"];
    this->correct_1 = json_val["1"]["1"];
    this->incorrect_1 = json_val["1"]["0"];
}