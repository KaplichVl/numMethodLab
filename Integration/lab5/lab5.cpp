#include "Integral.h"
#include <iostream>


int main()
{
    double a = 1.01,
           b = 2.631,
           integral1{}, integral2{};
    int n = 1;

   do {
       integral1 = methodTrapezoid(a, b, n);
       integral2 = methodTrapezoid(a, b, 2 * n);
       n <<= 1;
   } while (!rungeCriterion(integral1, integral2));

   cout << "trapeze " << integral2 << endl;

   integral1 = integral2 = 0;
   do {
       integral1 = methodSimpson(a, b, n);
       integral2 = methodSimpson(a, b, 2 * n);
       n <<= 1;
   } while (!rungeCriterion(integral1, integral2));

   cout << "Simpson " << integral2 << endl;
   
   a = 0;
   b = 4;
   int c = 1, 
       d = 2,
       nx = 10,
       ny = 10;
      
   cout << "doubleSimpson " << methodSimpson(a,b,c,d,nx,ny) << endl;

  

}

