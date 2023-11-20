#include "NK.h"



int main() {

    vector<double> x{ 0.164, 0.328, 0.656, 0.984, 1.312, 1.640 };
    vector<double> y{ 0.448, 0.432, 0.421, 0.417, 0.414,0.412 };
    int degree = 1; 

    vector<double> coeff = leastSquaresMethod(x, y, degree);
    printRes(coeff);

    cout << endl << "disp : " << calcResidualVariance(x, y, coeff);

    return 0;
}