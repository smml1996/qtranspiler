#ifndef UTILS_H
#define UTILS_H

#include <complex>
#include <random>
#include <set>
#include <boost/multiprecision/cpp_int.hpp>

#include "verification.hpp"

using namespace std;

double get_abs_tol(const int &precision);
double get_rel_tol(const int &precision);
bool is_close(const double &a, const double &b, const int &precision);
bool is_close(const complex<double> &a, const complex<double> &b, const int &precision);
template <typename T>
T weighted_choice(const std::vector<T> &elements, const std::vector<double> &weights) {
    if (elements.size() != weights.size() || elements.empty()) {
        throw std::invalid_argument("Elements and weights must have the same non-zero size.");
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());

    discrete_distribution<> dist(weights.begin(), weights.end());
    return elements[dist(gen)];
}
double round_to(double value, int decimals);
string to_binary(boost::multiprecision::cpp_int basis);
bool are_matrices_equal(const vector<vector<complex<double>>> &arr1, const vector<vector<complex<double>>> &arr2, int precision);
bool is_matrix_in_list(const vector<vector<complex<double>>> & matrix, const vector<vector<vector<complex<double>>>> &matrix_list, int precision);

inline double round_to(double value, int decimals) {
    double power = pow(10.0, decimals);
    return std::round(value * power) / power;
}

vector<vector<complex<double>>> multiply_matrices(const vector<vector<complex<double>>> &left, const vector<vector<complex<double>>> &right);

pair<double, pair<complex<double>, complex<double>>> get_kraus_matrix_probability(const vector<vector<complex<double>>> &matrix, const complex<double> &a, const complex<double> &b);
set<int> get_intersection(set<int> set1, set<int> set2);
void split_str(string const &str, const char &delim, vector<string> &out);


template <typename FloatT>
class Ensemble {
    int does_hybrid_state_exists(shared_ptr<HybridState> &state) const;
public:
    vector<pair<shared_ptr<HybridState>, FloatT>> probs;
    int precision;

    explicit Ensemble(int precision) : precision(precision) {};
    Ensemble(){this->precision=-1;};
    bool insert_prob(shared_ptr<HybridState> &hs, FloatT &value);
    void add_prob(shared_ptr<HybridState> &hs, FloatT value);
    FloatT get_weight();
    void normalize();
    bool operator==(const Ensemble<FloatT> &other) const;
};

template <typename FloatT>
bool Ensemble<FloatT>::insert_prob(shared_ptr<HybridState> &hs, FloatT &value) {
    assert(this->precision != -1);
    if (this->does_hybrid_state_exists(hs) == -1) return false;
    this->probs.push_back(make_pair(hs, value));
    return true;
}

template <typename FloatT>
bool is_new_ensemble(const vector<shared_ptr<Ensemble<FloatT>>> &all_ensembles, const shared_ptr<Ensemble<FloatT>> &new_ensemble) {
    for (auto e : all_ensembles) {
        if (*e == *new_ensemble ) {
            return false;
        }
    }
    return true;
}

shared_ptr<Ensemble<MyFloat>> to_myfloat(const shared_ptr<Ensemble<double>> &ensemble);

shared_ptr<Ensemble<double>> to_double(const shared_ptr<Ensemble<MyFloat>> &ensemble);

Ensemble<z3::expr> get_symbolic_ensemble(const std::vector<shared_ptr<Ensemble<MyFloat>>> &ensembles,
    const z3::expr_vector &weights,
    z3::context &ctx);


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

template <typename FloatT>
class Polygon {
public:
    vector<shared_ptr<Ensemble<FloatT>>> corners;
};
#endif
