#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double pi = 3.14159265358979323846264;

double f(double x)
{
    double ans;
    ans = sin(x);
    // if (x == pi) {ans = 0;}
    return ans;
}

int main()
{
    double a = 0, b = pi;
    double S_h, e_h = 2;
    double I_f = 2;
    
    for (double n = 1; n <= 10; n+=0.5)
    {
        double h = (b-a)/(2*n);
        cout << "n = " << 2*n << ", h = " << h << "\n";
        S_h = 0; double x_2j = a;
        for (double j = 1; j <= n; j++)
        {   
            S_h += (h/3)*(f(x_2j) + 4*f(x_2j + h) + f(x_2j + 2*h));
            x_2j += (2*h);
        }
        e_h = abs(I_f - S_h);
        cout << fixed << setprecision(15) << "S_h(f) = " << S_h << "\n";
        cout << fixed << setprecision(15) << "e_h = " << e_h << "\n";
        cout << "\n";
    }
    return 0;
}