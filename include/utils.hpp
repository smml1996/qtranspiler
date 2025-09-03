#ifndef UTILS_H
#define UTILS_H

#include <complex>

using namespace std;

double get_abs_tol(const int &precision);
double get_rel_tol(const int &precision);
bool is_close(const double &a, const double &b, const int &precision);
template <typename T>
T weighted_choice(const std::vector<T> &elements, const std::vector<double> &weights);
double round_to(double value, int decimals);
string to_binary(int basis);
bool are_matrices_equal(const vector<vector<complex<double>>> &arr1, const vector<vector<complex<double>>> &arr2, int precision);
bool is_matrix_in_list(const vector<vector<complex<double>>> & matrix, const vector<vector<vector<complex<double>>>> &matrix_list, int precision);

#endif
