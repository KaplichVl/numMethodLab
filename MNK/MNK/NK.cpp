#include "NK.h"

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

vector<double> leastSquaresMethod(const vector<double>& x, const vector<double>& y, unsigned int degree) {
    int n = x.size();


    vector<double> sumX(2 * degree, 0);
    vector<double> sumXY(degree + 1, 0);

    for (int i = 0; i < n; i++) {          // ��������� ����� �����
        double xi = x[i];

        for (int j = 0; j < 2 * degree; j++) {
            sumX[j] += xi;
            xi *= x[i];
        }
    }

    for (int i = 0; i < n; i++) { // ��������� ������ �����
        double xi = x[i];

        sumXY[0] += y[i];
        for (int j = 1; j <= degree; j++) {
            sumXY[j] += y[i] * xi;
            xi *= x[i];
        }


    }

    vector <vector<double>> matrix((degree + 1), vector<double>(degree + 1));


    matrix[0][0] = 1;
    for (int i = 1; i < degree + 1; i++) {  // ��������� �������
        int j = i - 1;
        while (j < degree + 1) {

            matrix[j][i] = sumX[j];
            if (i != j) {
                matrix[i][j] = sumX[j];
            }
            j++;
        }
    }


    vector <double> coeff = gauss(matrix, sumXY);

    return coeff;
}

void printRes(const vector<double>& coeff)
{
    if (coeff.empty())
        return;

    cout << "Approximating function: f(x) = ";
    int i = 0;
    for (double elem : coeff) {
        if (i > 0) {
            cout << " + ";
        }
        cout << elem << " * x^" << i;
        i++;
    }
    cout << endl;
}

double calcPolynom(const vector<double>& coeff, double x)
{

    int n = coeff.size();
    double res(n);

    res = coeff[0];
    double cur = x;
    for (int i = 1; i < n; i++) {
        res = x * coeff[i];
        x *= x;
    }

    return res;
}

double calcResidualVariance(const vector<double>& x, const vector<double>& y, const vector<double>& coeff) {

    if (x.size() != y.size())
        return 0;

    int N = x.size(),
        m = coeff.size();
    double ResidualVar = 1 / (N - m - 1);


    for (int i = 1; i < N; i++)
    {
        double temp = y[i] - calcPolynom(coeff, x[i]);
        ResidualVar += temp * temp;
    }

    return sqrt(ResidualVar);
}
