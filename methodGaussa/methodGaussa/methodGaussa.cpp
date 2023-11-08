#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;
const int n = 3;

void sysout(vector<vector<double>> matrix, vector<double> res) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "*x" << j;
            if (j < n - 1)
                cout << " + ";
        }
        cout << " = " << res[i] << endl;
    }
    cout << endl;
    return;
}

vector<double> calcMatrix(vector<vector<double>> matrix, vector<double> v) {
    vector<double> res(n);
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++)
            sum += matrix[i][j] * v[j];
        res[i] = sum;
    }
    return res;
}

vector<double> gauss(vector<vector<double>> a,vector<double> y) {
    vector<double> c(0);
    vector<double> x(n);
    double max;
    int k, index;
    k = 0;
    while (k < n) {
        max = a[k][k];
        index = k;
        for (int i = k + 1; i < n; i++) {
            if (a[i][k] > max) {
                max = a[i][k];
                index = i;
            }
        }
        if (k != index) {
            for (int j = 0; j < n; j++)
                swap(a[k][j], a[index][j]);
            swap(y[k], y[index]);
        }
       
        for (int i = k; i < n; i++) {
            double temp = a[i][k];
            for (int j = 0; j < n; j++)
                a[i][j] /= temp;
            y[i] /=  temp;
            if (i == k)  continue; 
            for (int j = 0; j < n; j++)
                a[i][j] -= a[k][j];
            y[i] -= y[k];
        }
        k++;
    }
 
    for (k = n - 1; k >= 0; k--) {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * x[k];
    }
    return x;
}

vector<double> vectorNev(vector<vector<double>> matrix, vector<double> x, vector<double> res) {
    vector<double> vecNev(n);
    vector<double> result = calcMatrix(matrix, res);
  
    for (int i = 0; i < n; i++) 
        vecNev[i] = result[i] - x[i];
       
    return vecNev;
}

double searchError(vector<double> res1,vector<double> res2) {
    double Max = abs(res1[0] - res2[0]);
    double MaxRes = abs(res1[0]);
    for (int i = 1; i < res1.size(); i++) {
        double temp = abs(res1[i] - res2[i]);
        Max = max(Max, temp);
        MaxRes = max(MaxRes, abs(res1[i]));
    }
    return Max / MaxRes;
}

double searchNorm(vector<double> vecNev) {
    double Max = 0;
    for (int i = 0; i < vecNev.size(); i++)
        Max = max(Max,abs(vecNev[i]));
   
    return Max;
}
  
int main() {
    vector<vector<double>> matrix = { {2.5, -3, 4.6}, { -3.5, 2.6, 1.5}, { -6.5, -3.5, 7.3} };
    vector<double> x = { -1.05, -14.46, -17.73 };

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
    for (int i = 1; i > 0; i++)
        cout << "i";
 
    return 0;
}
