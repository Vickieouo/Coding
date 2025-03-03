#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
double p = 0.33333333333333333333;

double f(double x)
{
    double ans = 1 + log(x) - x;
    // 27*pow(x, 4) + 162*pow(x, 3) - 180*x*x + 62*x - 7;
    return ans;
}

double df(double x)
{
    double ans = 1/x - 1;
    // 4*27*pow(x, 3) + 3*162*x*x - 360*x + 62;
    return ans;
}

double F(double x)
{
    double ans = f(x)/df(x);
    return ans;
}

double dF(double x)
{
    double a, b;
    a = 9*x*x + 93*x + 331;
    b = 6*x + 31;
    double ans = a/(b*b);
    return ans;
}

int main()
{
    vector<double> v, e;
    double pn = 2, pn_plus1;
    v.emplace_back(pn);
    cout << "p0 = " << setprecision(10) << pn << "\n";
    e.emplace_back(fabs(pn - p));
    // cout << "e0 = " << setprecision(10) << e[0] << "\n";

    for(int i = 0; i < 10; i++)
    {
        // Method 1
        // pn_plus1 = pn - (F(pn)/dF(pn));

        // Method 2
        double m = 1;
        pn_plus1 = pn - m*(f(pn)/df(pn));

        cout << "p" << i+1 << " = " << fixed << setprecision(10) << pn_plus1 << "   ";
        v.emplace_back(pn_plus1);
        pn = pn_plus1;

        if (i >= 1)
        {
            double M,a,b,c;
            a = v[i+1] - v[i]; b = v[i] - v[i-1];
            c = 1 - a/b; M = 1/c;
            cout << "m = " << M << endl;
        }
        else
        {
            cout << endl;
        }

        // e.emplace_back(fabs(pn - p));
        // cout << "e" << i+1 << " = " << setprecision(10) << e[i+1] << "   ";
        
        // if (i >= 1)
        // {
        //     double a = pow(e[i], 2);
        //     cout << "e" << i+1 << "~/e" << i << "~^2 = " << fixed << setprecision(15) << e[i+1]/a << "\n";
        // }
        // else
        // {
        //     cout << endl;
        // }
    }

    return 0;

}