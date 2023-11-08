#pragma once

#include <vector>

using namespace std;

const double epsilon = 1e-9;

double func1(double x1, double x2);
double func2(double x1, double x2);
vector<vector<double>> jacobi(double x1, double x2);
vector<vector<double>> jacobi(double x1, double x2,double M);
vector <double> gauss(vector<vector<double>> a, vector <double> y);
vector <double> newtonMethod(vector <double> x1);
vector <double> newtonMethod(vector <double> x1,int NIT,double M);

void printRes(const vector<double>& res);