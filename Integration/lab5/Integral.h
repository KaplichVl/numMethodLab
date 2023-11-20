#pragma once

#include <cmath>

using namespace std;

const double eps = 1e-5;

double func(double x);

double func(double x,double y);

double methodTrapezoid(double a, double b, int n);

bool rungeCriterion(double integral1, double integral2);

double methodSimpson(double a, double b, int n);
double methodSimpson(double a, double b, double c, double d, int nx,int ny);