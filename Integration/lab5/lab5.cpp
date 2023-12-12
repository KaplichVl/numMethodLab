#include "Integral.h"
#include <iostream>


int main()
{
    double a = 1.01,
           b = 2.631;
   cout << "trapeze " << solveMethodSimpson(a,b) << endl;

   cout << "Simpson " << solveMethodTrapezoid(a,b) << endl;
   
   a = 0;
   b = 4;
   int c = 1, 
       d = 2,
       nx = 10,
       ny = 10;
      
   cout << "doubleSimpson " << methodSimpson(a,b,c,d,nx,ny) << endl;

  

}

