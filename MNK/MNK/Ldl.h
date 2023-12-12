#include <vector>
using namespace std;
void ldlFactorization(const vector<vector<double>>& A, vector<vector<double>>& L, vector<double>& D);
vector<double> solveLDL(const vector<vector<double>>& A, const vector<double>& b);