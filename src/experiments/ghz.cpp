#include "../../include/experiments.hpp"

// GHZ state preparation of 3 qubits
class GHZStatePreparation3 : public Experiment {
    public:
        GHZStatePreparation3() : Experiment() {
            this->name = "ghz_state_preparation";
            this->precision = 8;
            this->with_thermalization = false;
            this->min_horizon = 3;
            this->max_horizon = 3;
            this->set_hidden_index = false;
            this->method_types.erase(MethodType::ConvexDist); // there is only one intiial state, is not worth it
        };


        vector<pair<HybridState*, double>> get_initial_distribution(unordered_map<int, int> &embedding) const override {
            vector<pair<HybridState*, double>> result;

            ClassicalState * classical_state = new ClassicalState();

            // the zero state
            QuantumState * initial_state = new QuantumState(get_qubits_used(embedding), this->precision);
            result.push_back(make_pair(new HybridState(initial_state, classical_state), 0.25));

            return result;
        }

        
};

// GHZ state preparation of 4 qubits
class GHZStatePreparation4 : public GHZStatePreparation3 {
    public:
        GHZStatePreparation4() : GHZStatePreparation3() {
            this->name = "ghz_state_preparation";
            this->precision = 8;
            this->with_thermalization = false;
            this->min_horizon = 4;
            this->max_horizon = 4;
            this->set_hidden_index = false;
            this->method_types.erase(MethodType::ConvexDist); // there is only one intiial state, is not worth it
        };   
};