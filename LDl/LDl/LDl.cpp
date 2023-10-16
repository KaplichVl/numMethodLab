#include <iostream>
#include <vector>


using namespace std;

void ldlFactorization(const vector<vector<double>>& A, vector<vector<double>>& L, vector<double>& D) {
    int n = A.size();
    L.resize(n, vector<double>(n, 0.0));
    D.resize(n, 0.0);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (j > i)
                continue;
            else {
                double sum = 0;
                for (int k = 0; k <= j; k++)
                    sum += L[i][k] * L[i][k] * D[k];
                if (i == j) {
                    D[j] = A[i][j] - sum;
                    L[i][i] = 1;
                }
                else
                    L[i][j] = (A[i][j] - sum) / D[j];
            }

        }
    }
}

vector<double> solveLDL(const vector<vector<double>>& A, const vector<double>& b) {
    int n = A.size();
    vector<vector<double>> L;
    vector<double> D;

    ldlFactorization(A, L, D);

    // Решаем систему Ly = b
    vector<double> y(n);
    for (int k = 0; k < n; k++) {
        double sum = 0;
        for (int i = 0; i < k; i++)
            sum += L[k][i] * y[i];
        y[k] = b[k] - sum;
    }
    // Решаем систему L(T)x = z
    vector<double> z(n);
    for (int k = 0; k < n; k++)
        z[k] = y[k] / D[k];

    vector<double> x(n);
    for (int k = n - 1; k >= 0; k--) {
        cout << k << endl;
        double sum = 0;
        for (int i = k + 1; i < n; i++)
            sum += L[i][k] * x[i];
        x[k] = z[k] - sum;
    }

    return x;
}

void sysout(vector<vector<double>> matrix, vector<double> res) {
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res.size(); j++) {
            cout << matrix[i][j] << "*x" << j;
            if (j < res.size() - 1)
                cout << " + ";
        }
        cout << " = " << res[i] << endl;
    }
    cout << endl;
    return;
}


int main() {
    double a1, a2, a3;
    cout << "write a1: ";
    cin >> a1;
    cout << "write a2: ";
    cin >> a2;
    cout << "write a3: ";
    cin >> a3;
    cout << endl;

    vector<vector<double>> A = { {2 * a1 + 4 * a2, 2 * (a1 - a2), 2 * (a1 - a2)},
                                {2 * (a1 - a2), 2 * a1 + a2 + 3 * a3, 2 * a1 + a2 - 3 * a3},
                                {2 * (a1 - a2), 2 * a1 + a2 - 3 * a3, 2 * a1 + a2 + 3 * a3} };
    vector<double> b = { -4 * a1 - 2 * a2, -4 * a1 + a2 + 9 * a3, -4 * a1 + a2 - 9 * a3 };
    sysout(A, b);

    vector<double> x = solveLDL(A, b);

    cout << "ans x : ";
    for (double val : x)
        cout << val << " ";
    cout << endl;

    return 0;
}
