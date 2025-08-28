#include "../include/utils.hpp"


double get_rel_tol(const int &precision) {
    return 1/(pow(10,(precision-1)));
}

double get_abs_tol(const int &precision) {
    return 1/(pow(10,(precision-1)));
}

bool is_close(const double &a, const double &b, const int &precision) {
    double rel_tol = get_rel_tol(precision);
    double abs_tol = get_abs_tol(precision);
    return std::fabs(a - b) <= std::max(rel_tol * std::max(std::fabs(a), std::fabs(b)), abs_tol);
}

template <typename T>
T weighted_choice(const std::vector<T> &elements, const std::vector<double> &weights) {
    if (elements.size() != weights.size() || elements.empty()) {
        throw std::invalid_argument("Elements and weights must have the same non-zero size.");
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::discrete_distribution<> dist(weights.begin(), weights.end());
    return elements[dist(gen)];
}

double round_to(double value, int decimals) {
    double factor = std::pow(10.0, decimals);
    return std::round(value * factor) / factor;
}

// helper: convert integer to binary string (no leading zeros)
string to_binary(int basis) {
    if (basis == 0) return "0";
    std::string result;
    while (basis > 0) {
        result.push_back((basis % 2) + '0');
        basis /= 2;
    }
    return result;  // already reversed because of push_back order
}