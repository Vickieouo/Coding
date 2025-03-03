#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
double root = 4.26148341;

double f(double x)
{
    // double ans = (3/2)*x - 6 - (1/2)*sin(2*x);
    // double ans = 3*x/2;
    // ans = ans - 6;
    // double s = 0.5 * sin(2*x);
    // ans = ans - s;
    double ans = 27*pow(x, 4) + 162*pow(x, 3) - 180*x*x + 62*x - 7;
    return ans;
}

int sgn(double x)
{
    if(x >= 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<double> v;
    double a = -1, b = 1, p = 0; 

    for(int i = 0; i < 11; i++)
    {
        p = (a+b)/2;
        double fa = f(a), fp = f(p);
        int sfa = sgn(fa), sfp = sgn(fp);

        if (sgn(f(a)) * sgn(f(p)) > 0)
        {
            v.emplace_back(p);
            cout << setprecision(10) << p << "\n";
            a = p;
        }
        else if (sgn(f(a)) * sgn(f(p)) < 0)
        {
            v.emplace_back(p);
            cout << setprecision(10) << p << "\n";
            b = p;
        }
    }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << "\n";
    // }

    return 0;
}
