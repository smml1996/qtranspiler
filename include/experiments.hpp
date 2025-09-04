#ifndef EXPERIMENTS_H
#define EXPERIMENTS_H

#include "beliefs.hpp"
#include "hardware_specification.hpp"
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

enum MethodType {
    SingleDistBellman,
    SingleDistPBVI,
    ConvexDist
};

string to_string(const MethodType &method);

class Experiment {
    protected:
        string name;
        int precision;
        bool with_thermalization;
        int min_horizon;
        int max_horizon;
        bool set_hidden_index;
    unordered_set<MethodType> method_types;

    fs::path get_wd() const;
    bool setup_working_dir() const;

        static vector<int> get_qubits_used(const unordered_map<int, int> &embedding);
    vector<HardwareSpecification> get_hardware_specs() const;
    Belief get_initial_belief(const POMDP &pomdp) const;

        vector<POMDPVertex *> get_initial_states(const POMDP &pomdp) const;

    public:
        virtual ~Experiment() = default;
        Experiment() = default;

        virtual vector<QuantumHardware> get_allowed_hardware() const;
        virtual void run() const;
        virtual bool guard(const POMDPVertex&, const unordered_map<int, int>&, const POMDPAction&) const;

        // for an experiment we need to define at least these functions
        virtual vector<pair<HybridState*, double>> get_initial_distribution(unordered_map<int, int> &embedding) const = 0;
        virtual MyFloat postcondition(const Belief &belief, const unordered_map<int, int> &embedding) const = 0;
        virtual vector<POMDPAction> get_actions(HardwareSpecification &hardware_spec, const unordered_map<int, int> &embedding) const = 0;
        virtual vector<unordered_map<int, int>> get_hardware_scenarios(HardwareSpecification const & hardware_spec) const = 0;
};

class ReadoutNoise {
    public:
    int target;
    double success0, success1, diff, acc_err, abs_diff;
    ReadoutNoise(int target, double success0, double success1);
};

unordered_set<int> get_meas_pivot_qubits(const HardwareSpecification &hardware_spec);

#endif
