#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
double p = 1/3;

double f(double x)
{
    double ans = pow(x, 3) + 2*pow(x, 2) - 3*x - 1;
    // 27*pow(x, 4) + 162*pow(x, 3) - 180*x*x + 62*x - 7
    return ans;
}

double df(double x)
{
    double ans = 3*pow(x, 2) + 4*x - 3;
    // 4*27*pow(x, 3) + 3*162*x*x - 360*x + 62
    return ans;
}

int main()
{
    vector<double> v, e;
    double pn = -3, pn_plus1;
    v.emplace_back(pn);
    // e.emplace_back(fabs(pn-p));
    cout << "p0 = " << setprecision(10) << pn << "\n";
    // cout << "e0 = " << setprecision(10) << e[0] << "\n";

    for(int i = 0; i < 3; i++)
    {
        pn_plus1 = pn - (f(pn)/df(pn));
        cout << "p" << i+1 << " = " << fixed << setprecision(10) << pn_plus1 << "\n";
        v.emplace_back(pn_plus1);
        pn = pn_plus1;
        
        // e.emplace_back(fabs(v[i+1] - p));
        // cout << "e" << i+1 << " = "  << fixed << setprecision(10) << e[i+1] << "\n";

        // cout << "e" << i << "/e" << i-1 << " = " << fixed << setprecision(10) << e[i]/e[i-1] << "   ";
        // double u = pow(e[i-1], 1.618);
        // cout << "e" << i << "/e" << i-1 << "^1.618 = " << fixed << setprecision(10) << e[i]/u << "\n";

        // if (i > 1)
        // {
        //     double kn;
        //     kn = log(e[i]/e[i-1])/log(e[i-1]/e[i-2]);
        //     cout << "k" << i-1 << " = " << fixed << setprecision(10) << kn << "   " << "\n";
        // }
        // else
        // {
        //     cout << endl;
        // }

        // cout << "|p" << i+1 << "-p" << i << "| = " << fixed << setprecision(10) << fabs(v[i+1]-v[i]) << "   ";
        // cout << "|p" << i << "-p| = " << fixed << setprecision(10) << fabs(v[i]- p) << "   ";
        // cout << "|p" << i+1 << "-p| = " << fixed << setprecision(10) << fabs(v[i+1]- p) << "   ";
        
        // double a,b,c;
        // a = fabs(v[i+1]- p);
        // b = fabs(v[i]-p);
        // c = pow(b, 1.618);
        // // cout << "|p" << i+1 << "-p|/|p" << i << "-p|^1.618 = " << fixed << setprecision(10) << a/c << "\n";
        // cout << "e" << i+1 << "/e" << i << "^1.618 = " << fixed << setprecision(10) << a/c << "\n";
        // cout << endl;
    }
    // double df,d2f,A;
    // df = 3*p*p+2*p-3; d2f = 6*p+2;
    // A = fabs(d2f/(2*df));
    // cout << "|f''(p)/2f'(p)|^0.618 = " << pow(A, 0.618) << "\n";

    return 0;

}