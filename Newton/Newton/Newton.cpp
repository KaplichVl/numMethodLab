#include <iomanip>
#include <iostream>
#include "Newton.h"
#include "gauss.h"




double func1(double x1, double x2)
{
	return 1.5 * x1 * x1 * x1 - x2 * x2 - 1;
}

double func2(double x1, double x2)
{
	return x1 * x2 * x2 * x2 - x2 - 4;
}

vector<vector<double>> jacobi(double x1, double x2)
{
	vector <vector<double>> jacob = { {4.5 * x1 * x1,-2 * x2},
		           {x2 * x2 * x2,3 * x1 * x2 * x2 - 1} };
    return jacob;
}

vector<vector<double>> jacobi(double x1,double x2, double M)
{
    vector<vector<double>> J = { {(func1(x1 + M * x1, x2) - func1(x1, x2)) / (M * x1),(func1(x1, x2 + M * x2) - func1(x1, x2)) / (M * x2)} , 
                                 {(func2(x1 + M * x1, x2) - func2(x1, x2)) / (M * x1),(func2(x1, x2 + M * x2) - func2(x1, x2)) / (M * x2)} };
    return J;
}

vector<double> newtonMethod(vector <double> x1,int NIT)
{
        vector <double> dx{};
        int cnt = 0 ,n = x1.size();
        double delta_1 = 0, delta_2 = 0;
    
        cout << "Iteration " << setw(12) << "delta_1 " << setw(15)<< "delta_2 " << endl;
        do {
            double func_1 = func1(x1[0],x1[1]);
            double func_2 = func2(x1[0],x1[1]);
    
            vector<double> temp = { -1 * func_1, -1 * func_2};
    
            dx = gauss(jacobi(x1[0],x1[1]), temp);
    
            delta_1 = max(func_1, func_2);
    
            for (int i = 0; i < n; i++) {
                x1[i] += dx[i];
            }
    
            delta_2 = 0;
            for (int i = 0; i < n; i++) {
                if (abs(x1[i]) < 1)
                    delta_2 = max(delta_2, abs(dx[i]));
    
                else
                    delta_2 = max(delta_2, abs(dx[i]) / x1[i]);
    
            }
    
            cnt++;
            cout << cnt << setw(20) << delta_1 << setw(16)  << delta_2 << endl;
            if (cnt > NIT)
                exit(1);

        } while (delta_1 >= epsilon || delta_2 >= epsilon);
    
       
        return x1;
}

vector<double> newtonMethod(vector <double> x1, int NIT, double M) {
    int iter = 1;
    vector<vector<double>> J;
    vector<double> dx(2), x_k(2), F(2);
    double delta_1 =0 , delta_2 = 0,temp;
    cout << left << setw(4) << "iter    " << setw(20) << "delta_1" << setw(20) << "delta_2" << setw(20) << "x1" << setw(20) << "x2" << endl;
    do
    {
        F[0] = -1 * func1(x1[0],x1[1]);
        F[1] = -1 * func2(x1[0], x1[1]);
        J = jacobi(x1[0], x1[1]);
        dx = gauss(J, F);
        x_k[0] = x1[0] + dx[0];
        x_k[1] = x1[1] + dx[1];

        delta_1 = max(abs(F[0]),abs(F[1]));
        delta_2 = 0;
        for (int i = 0; i < x1.size(); i++) {
            if (abs(x1[i]) < 1)
                delta_2 = max(delta_2, abs(dx[i]));

            else
                delta_2 = max(delta_2, abs(dx[i]) / x1[i]);

        }
       x1[0] = x_k[0];
       x1[1] = x_k[1];
       cout << left << setw(8) << iter << setw(20) << delta_1 << setw(20) << delta_2 << setw(20) << x1[0] << setw(20) << x1[1] << endl;
       iter++;
       if (iter > NIT)
           exit(1);

    } while (delta_1 >= epsilon || delta_2 >= epsilon);


       return x1;
}


