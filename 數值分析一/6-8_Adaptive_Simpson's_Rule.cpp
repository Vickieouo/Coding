#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double pi = 3.14159265358979323846264;
double onebysix = 0.1666666666666666666666666666666666666666666666;
int count = 3;

double f(double x)
{
    double ans = 100/pow(x, 2);
    double s = sin(10/x);
    ans = ans * s;
    return ans;
}

double S(double a, double b)
{
    double ans;
    ans = (b-a)*(onebysix)*(f(a) + 4*(f((a+b)/2)) + f(b));
    return ans;
}

double adapt(double a, double b, double e)
{
    double sab = S(a, b);

    // cout << "S(" << a << ", " << b << ") = ";
    // cout << setprecision(15) << sab << "\n";

    double c = (a+b)/2;
    double sac = S(a, c);
    double scb = S(c, b);
    count += 2;
    
    if (abs(sac+scb-sab)/10 < e)
    {
        return (sac + scb);
    }
    else
    {
        double e1 = e/2;
        return adapt(a, c, e1) + adapt(c, b, e1);
    }
}

int main()
{
    double a = 1, b = 3; // a < b
    double e = 1e-4; // 10 decimal places of accuracy -> e = 5e-11
    double I;
    
    I = adapt(a, b, e);
    cout << "function evaluations = " << count << "\n";
    cout << "I = " << fixed << setprecision(15) << I << "\n";
    
    return 0;
}