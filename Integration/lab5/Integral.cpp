#include "Integral.h"
#include <iostream>

double func(double x)
{
	return (1 + x + x * x) / (sqrt(x * x * x - 1));
}

double func(double x,double y)
{
	return (x * x )/ (1 + y * y);
}

double methodTrapezoid(double a, double b, int n)
{
	double h = (b - a) / n;
	double sum = func(a) + func(b);

	for (int i = 1; i < n; i++)
		sum += 2 * func(a + i * h);

	sum *= h / 2;

	return sum;
}
double solveMethodTrapezoid(int a,int b) {
   int integral1 = 0,
       integral2 = 0,
       n = 1;
    do {
        integral1 = methodTrapezoid(a, b, n);
        integral2 = methodTrapezoid(a, b, 2 * n);
        n <<= 1;
    } while (!rungeCriterion(integral1, integral2, 3));

    return integral2;
}

double methodSimpson(double a, double b, int n)
{
	double h = (b - a) / n; 
	double sum = func(a) + func(b);

	for (int i = 1; i < n; i++) {
		double x = a + i * h;
		sum += (i % 2 == 0) ? 2 * func(x) : 4 * func(x); 
	}

	return (h / 3) * sum;
}
double solveMethodSimpson(int a, int b) {
    int integral1 = 0,
        integral2 = 0,
        n = 1;
    do {
        integral1 = methodSimpson(a, b, n);
        integral2 = methodSimpson(a, b, 2 * n);
        n <<= 1;
    } while (!rungeCriterion(integral1, integral2, 15));
    return integral2;
}

double methodSimpson(double a, double b, double c, double d, int nx, int ny)
{

    double hx = (b - a) / nx / 2;
    double hy = (d - c) / ny / 2;
    double sum = 0.0;
	for (int i = 0; i <= nx - 1; i++) {
		for (int j = 0; j <= ny - 1; j++) {
			int i2 = i << 1, j2 = j << 1;
			sum += funcXYSipmson(hx,hy,a,c,i2,j2) + 4 * funcXYSipmson(hx, hy, a, c, i2 + 1, j2) + funcXYSipmson(hx, hy, a, c, i2 + 2, j2);
			sum += 4 * funcXYSipmson(hx, hy, a, c, i2, j2 + 1) + 16 * funcXYSipmson(hx, hy, a, c, i2 + 1, j2 + 1) + 4 * funcXYSipmson(hx, hy, a, c, i2 + 2, j2 + 1);
			sum += funcXYSipmson(hx, hy, a, c, i2, j2 + 2) + 4 * funcXYSipmson(hx, hy, a, c, i2 + 1, j2 + 2) + funcXYSipmson(hx, hy, a, c, i2 + 2, j2 + 2);
		}
	}

   
    return sum * hx * hy / 9.;
}

double funcXYSipmson(double h1, double h2, double a, double b, int i, int j)
{
    return func(a+h1*i,b+h2*j);
}

bool rungeCriterion(double integral1, double integral2,int cnt)
{
	return abs(integral1 - integral2) < cnt * eps;
}




