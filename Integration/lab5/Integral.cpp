#include "Integral.h"

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

double methodSimpson(double a, double b, double c, double d, int nx, int ny)
{
    double hx = (b - a) / (nx << 1);
    double hy = (d - c) / (ny << 1);
    double sum = 0.0;

    for (int i = 0; i <= nx << 1; i++) {
        for (int j = 0; j <= ny << 1; j++) {
            double x = a + i * hx;
            double y = c + j * hy;

            int coeff = 1;

            if (i == 0 || i == nx << 1);
           
            else if (i % 2 == 1)
                coeff <<= 2;

            else
                coeff <<= 1;

            if (j == 0 || j == ny << 1);
     
            else if (j % 2 == 1)
                coeff <<= 2;

            else
                coeff <<= 1;

            sum += (double) coeff * func(x, y);
        }
    }

    
    return sum * hx * hy / 9;
}

bool rungeCriterion(double integral1, double integral2)
{
	return abs(integral1 - integral2) < 3 * eps;
}




