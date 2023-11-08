#include "Gauss.h"

void sysout(const vector<vector<double>>& matrix, const vector<double>& res) {
    int n = res.size();
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

vector<double> calcMatrix(const vector<vector<double>>& matrix, const vector<double>& v) {
    int n = v.size();
    vector<double> res(n);
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++)
            sum += matrix[i][j] * v[j];
        res[i] = sum;
    }
    return res;
}

vector<double> gauss(vector<vector<double>> a, vector<double> y) {
    int n = y.size();
    vector<double> x(n);
    double max;
    int index;

    for (int k = 0; k < n; k++) {
        max = a[k][k];
        index = k;
        for (int i = k + 1; i < n; i++) {
            if (a[i][k] > max) {
                max = a[i][k];
                index = i;
            }
        }
        if (k != index) {
            swap(a[k], a[index]);
            swap(y[k], y[index]);
        }

        for (int i = k; i < n; i++) {
            double temp = a[i][k];
            for (int j = 0; j < n; j++)
                a[i][j] /= temp;
            y[i] /= temp;
            if (i == k)  continue;
            for (int j = 0; j < n; j++)
                a[i][j] -= a[k][j];
            y[i] -= y[k];
        }
    }

    for (int k = n - 1; k >= 0; k--) {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * x[k];
    }
    return x;
}

vector<double> vectorNev(const vector<vector<double>>& matrix, const vector<double>& x, const vector<double>& res) {
    int n = x.size();
    vector<double> vecNev(n);
    vector<double> result = calcMatrix(matrix, res);

    for (int i = 0; i < n; i++)
        vecNev[i] = result[i] - x[i];

    return vecNev;
}

double searchError(const vector<double>& res1, const vector<double>& res2) {
    double Max = abs(res1[0] - res2[0]);
    double MaxRes = abs(res1[0]);

    for (int i = 1; i < res1.size(); i++) {
        double temp = abs(res1[i] - res2[i]);
        Max = max(Max, temp);
        MaxRes = max(MaxRes, abs(res1[i]));
    }
    return Max / MaxRes;
}

double searchNorm(const vector<double>& vecNev) {
    double Max = 0;
    for (double elem : vecNev)
        Max = max(Max, abs(elem));

    return Max;
}