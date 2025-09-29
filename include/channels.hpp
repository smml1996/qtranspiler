
#ifndef CHANNELS_H
#define CHANNELS_H

#include "instruction.hpp"
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

// ---- Base Class ----
class Channel {
public:
    double estimated_success_prob = 0;
    virtual ~Channel() = default;
};


class QuantumChannel : public Channel {
public:
    vector<pair<vector<Instruction>, double>>errors_to_probs;

    explicit QuantumChannel(json &data);
    QuantumChannel();

};

class MeasurementChannel : public Channel {
    public:
        double correct_0;   // probability of receiving 0 and that it is actually 0
        double correct_1;   // probability of receiving 1 and that it is actually 1
        double incorrect_0; // probability of receiving 0 and that it is actually 1
        double incorrect_1; // probability of receiving 1 and that it is actually 0
        MeasurementChannel(json &data);
        MeasurementChannel(double correct0, double correct1);
        double get_ind_probability(int ideal_outcome, int noisy_outcome) const;
};
#endif
