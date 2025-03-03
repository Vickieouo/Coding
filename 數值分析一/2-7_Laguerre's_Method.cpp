#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

double p(double x)
{
    double ans = pow(x, 4) + 20.5*pow(x, 3) + 129.5*pow(x, 2) + 230*x - 150;
    return ans;
}

double dp(double x)
{
    double ans = 4*pow(x, 3) + 3*20.5*pow(x, 2) + 2*129.5*x + 230;
    return ans;
}

double d2p(double x)
{
    double ans = 4*3*pow(x, 2) + 3*2*20.5*x + 2*129.5;
    return ans;
}

int main()
{
    vector<double> v, A;
    int n = 4;
    double xn = 0, a = 10;
    v.emplace_back(xn);
    cout << "x0 = " << setprecision(10) << xn << "\n";

    for(int i = 0; i < 10; i++)
    {
        double G, H;
        G = dp(xn)/p(xn);
        cout << "G" << i << " = " << scientific << setprecision(10) << G << "   ";
        H = G*G - d2p(xn)/p(xn);
        cout << "H" << i << " = " << scientific << setprecision(10) << H << "   ";
        
        double denoP, denoN;
        denoP = G + sqrt((n-1)*(n*H-G*G));
        denoN = G - sqrt((n-1)*(n*H-G*G));
        if (abs(denoP) >= abs(denoN))
        {
            a = n/denoP;
        }
        else if (abs(denoP) < abs(denoN))
        {
            a = n/denoN;
        }
        cout << "a" << i << " = " << scientific << setprecision(10) << a << "   ";
        A.emplace_back(a);

        xn = xn - a;
        cout << "x" << i+1 << " = " << setprecision(10) << xn << "\n";
        v.emplace_back(xn);
    }

    return 0;

}