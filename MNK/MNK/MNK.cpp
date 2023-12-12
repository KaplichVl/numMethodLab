#include "NK.h"



int main() {

    vector<double> x{1 / 0.164,1 / 0.328,1 / 0.656,1 / 0.984,1 / 1.312,1 / 1.640 };
    vector<double> y{ 0.448, 0.432, 0.421, 0.417, 0.414,0.412 };
    int degree = 1; 

    vector<double> coeff = leastSquaresMethod(x, y, degree);

    printRes(coeff);

    cout << endl << "disp : " << calcResidualVariance(x, y, coeff);

    return 0;
}