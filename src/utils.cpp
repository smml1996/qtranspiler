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