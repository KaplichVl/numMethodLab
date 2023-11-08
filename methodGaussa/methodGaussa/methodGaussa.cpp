#include "Gauss.h"


  
int main() {
    vector<vector<double>> matrix = { {2.5, -3, 4.6}, { -3.5, 2.6, 1.5}, { -6.5, -3.5, 7.3} };
    vector<double> x = { -1.05, -14.46, -17.73 };
    int n = x.size();
    sysout(matrix, x);

    vector<double> res = gauss(matrix, x);
    cout << "Resolution : " << endl;
    for (int i = 0; i < n; i++)
        cout << "x" << i << " " << res[i] << " ";
    cout << endl << endl;

    vector<double> vecNev = vectorNev(matrix, x, res);
    cout << "vecNev : " << endl;
    for (double num : vecNev)
        cout << num << " ";
    cout << endl << endl;

    double norm = searchNorm(vecNev);
    cout << "norma - " << norm << endl;

    vector<double> x1 = calcMatrix(matrix,res);
    vector<double> res1 = gauss(matrix, x1);

    double error = searchError(res, res1);
    cout << "error : " << error;
   
 
    return 0;
}
