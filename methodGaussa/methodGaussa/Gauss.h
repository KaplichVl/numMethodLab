#pragma once

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void sysout(const vector<vector<double>>& matrix, const vector<double>& res);

vector<double> calcMatrix(const vector<vector<double>>& matrix, const vector<double>& v);

vector<double> gauss(vector<vector<double>> a, vector<double> y);

vector<double> vectorNev(const vector<vector<double>>& matrix, const vector<double>& x, const vector<double>& res);

double searchError(const vector<double>& res1, const vector<double>& res2);

double searchNorm(const vector<double>& vecNev);