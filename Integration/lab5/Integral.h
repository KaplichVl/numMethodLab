#pragma once

#include <cmath>

using namespace std;

const double eps = 1e-5;

double func(double x);

double func(double x,double y);

double methodTrapezoid(double a, double b, int n);
double solveMethodTrapezoid(int a, int b);

bool rungeCriterion(double integral1, double integral2,int cnt);

double methodSimpson(double a, double b, int n);
double solveMethodSimpson(int a, int b);
double methodSimpson(double a, double b, double c, double d, int nx,int ny);

double funcXYSipmson(double h1, double h2, double a, double b, int i, int j);
