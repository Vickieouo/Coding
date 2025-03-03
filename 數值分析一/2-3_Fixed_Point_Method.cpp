#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
double p = 0.7390851332;

double g(double x)
{
    double ans = 2*x*(1-x);
    return ans;
}

int main()
{
    vector<double> v, e;
    double p0 = 0.001, pn, pn_plus1;
    pn = g(p0);
    v.emplace_back(p0);

    for(int i = 0; i < 15; i++)
    {
        cout << "p" << i+1 << " = " << setprecision(8) << pn << "\n";
        pn_plus1 = g(pn);
        v.emplace_back(pn);
        e.emplace_back(v[i+1] - v[i]);
        cout << "e" << i+1 << " = " << setprecision(8) << e[i] << "\n";
        pn = pn_plus1;

        if (i > 1)
        {
            double kn;
            kn = log(e[i]/e[i-1])/log(e[i-1]/e[i-2]);
            cout << "k" << i-1 << " = " << setprecision(8) << kn << "\n" << "\n";
        }
        else
        {
            cout << endl;
        }
    }

    return 0;
}
