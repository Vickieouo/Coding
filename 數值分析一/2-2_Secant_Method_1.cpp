#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
double root = 4.26148341;

double f(double x)
{
    double ans = pow(x, 4) - 18*pow(x, 2) + 45;
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
    double a = 3, b = 4, p = 0; 

    for(int i = 0; i < 5; i++)
    {
        double fa = f(a), fb = f(b);
        p = a - fa*(b-a)/(fb-fa);
        double fp = f(p);
        int sfa = sgn(fa), sfp = sgn(fp);

        if (sgn(f(a)) * sgn(f(p)) > 0)
        {
            // v.emplace_back(p);
            cout << setprecision(8) << p << "\n";
            a = p;
        }
        else if (sgn(f(a)) * sgn(f(p)) < 0)
        {
            // v.emplace_back(p);
            cout << setprecision(8) << p << "\n";
            b = p;
        }
    }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << "\n";
    // }

    return 0;
}

// when a_n = a is fixed for all n, e_n := p_n - p = lambda * e_n-1  for all n
// where lambda = (l*f"(p)) / (2f'(p) + l*f"(p)), l := a - p
// similar when b_n = b is fixed, replace a_n by b_n, l by b - p