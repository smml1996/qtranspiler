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

bool is_close(const complex<double> &a, const complex<double> &b, const int &precision) {
    double rel_tol = get_rel_tol(precision);
    double abs_tol = get_abs_tol(precision);

    double diff = std::abs(a - b);          // |a - b|
    double scale = std::max(std::abs(a), std::abs(b)); // max(|a|, |b|)

    return diff <= std::max(rel_tol * scale, abs_tol);
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

bool are_matrices_equal(const vector<vector<complex<double>>> &arr1, const vector<vector<complex<double>>> &arr2, int precision) {
    if (arr1.size() != arr2.size()) return false;
    
    for (int row_index = 0; row_index < arr1.size(); row_index++) {
        const auto row1 = arr1.at(row_index);
        const auto row2 = arr2.at(row_index);
        if (row1.size() != row2.size()) return false;

        for (int v_element= 0 ; v_element < row1.size(); v_element++) {
            auto v1 = row1[v_element];
            auto v2 = row2[v_element];
            if (!is_close(v2, v2, precision)) {
                return false;
            }
        }
    }
    return true;
}

bool is_matrix_in_list(const vector<vector<complex<double>>> & matrix, const vector<vector<vector<complex<double>>>> &matrix_list, int precision) {
    for (auto m : matrix_list) {
        if (are_matrices_equal(matrix, m, precision))
            return true;
    }
        
    return false;
}

 
