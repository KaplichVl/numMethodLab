#include "gauss.h"

vector<double> gauss(vector<vector<double>> a, vector<double> y)
{
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

void printRes(const vector<double>& res)
{
    cout << "Resolution : " << endl;
    for (double elem : res)
        cout << elem << " ";

}