
#include <iostream>
#include "Newton.h"
#include "gauss.h"

int main()
{
    vector<double> x0 = { 1,1 };
    cout << endl << "Method number 1: " << endl << endl;

    printRes(newtonMethod(x0,10));
    cout <<endl << "Method number 2: M = 0.01 " << endl << endl;

    printRes(newtonMethod(x0,10,0.01));
    cout << endl << "Method number 3: M = 0.05 " << endl << endl;

    printRes(newtonMethod(x0, 10, 0.05));
    cout << endl << "Method number 4: M = 0.1 " << endl << endl;
    printRes(newtonMethod(x0, 10, 0.1));

}

