
#ifndef CHANNELS_H
#define CHANNELS_H

#include "instruction.hpp"
#include <vector>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

// ---- Base Class ----
class Channel {
public:
    virtual ~Channel() = default;
};


class QuantumChannel : public Channel {
public:
    vector<pair<vector<Instruction>, double>>errors_to_probs;
    QuantumChannel(json &data);
};

class MeasurementChannel : public Channel {
    double correct_0;   // probability of receiving 0 and that it is actually 0
    double correct_1;   // probability of receiving 1 and that it is actually 1
    double incorrect_0; // probability of receiving 0 and that it is actually 1
    double incorrect_1; // probability of receiving 1 and that it is actually 0
    public:
        MeasurementChannel(json &data);
        double get_ind_probability(int ideal_outcome, int noisy_outcome) const;
};
#endif
