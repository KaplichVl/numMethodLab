#include <iostream>
#include <vector>

using namespace std;


vector<double> gauss(vector<vector<double>> a, vector<double> y);

vector<double> leastSquaresMethod(const vector<double>& x, const vector<double>& y, unsigned int degree);

double calcPolynom(const vector<double>& coeff, double x);

double calcResidualVariance(const vector<double>& x, const vector<double>& y, const vector<double>& coeff);

void printRes(const vector<double>& coeff);

