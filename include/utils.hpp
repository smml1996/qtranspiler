#include <complex>

using namespace std;

double get_abs_tol(const int &precision);
double get_rel_tol(const int &precision);
bool is_close(const double &a, const double &b, const int &precision);
template <typename T>
T weighted_choice(const std::vector<T> &elements, const std::vector<double> &weights);
double round_to(double value, int decimals);
string to_binary(int basis);
