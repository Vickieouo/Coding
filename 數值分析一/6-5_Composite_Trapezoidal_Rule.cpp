#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double pi = 2*asin(1);

double f(double x)
{
    double ans;
    ans = sin(x);
    if (x == pi) {ans = 0;}
    return ans;
}

int main()
{
    double a = 0, b = pi;
    double T_h, e_h = 10;
    double I_f = 2;
    
    for (int n = 1; e_h > 2e-5; n+=1)
    {
        double h = (b-a)/n;
        double N = pi/h;
        cout << "n = " << n << ", h = " << h << "\n";
        T_h = 0; double x_j = a;
        for (int j = 1; j <= n; j++)
        {   
            T_h += (h/2)*(f(x_j) + f(x_j + h));
            x_j += h;
        }
        e_h = abs(I_f - T_h);
        cout << fixed << setprecision(15) << "T_h(f) = " << T_h << "\n";
        cout << fixed << setprecision(15) << "e_h = " << e_h << "\n";
        cout << "N = " << N << "\n";
        cout << "\n";
    }
    return 0;
}