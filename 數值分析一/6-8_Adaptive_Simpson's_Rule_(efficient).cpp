#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double pi = 3.14159265358979323846264;
double onebysix = 0.1666666666666666666666666666666666666666666666;
int count = 0;

double f(double x)
{
    double ans;
    ans = pow(x, 16);
    double cs = cos(ans);
    ans = ans * cs;
    // if (x == pi) {ans = 0;}
    return ans;
}

double adapt1(double sab, double fa, double fc, double fb, double a, double b, double e)
{
    double c = (a+b)/2;
    double fd = f((a+c)/2);
    double fe = f((c+b)/2);
    count += 1;
    double sac = (c-a)*(fa + 4*fd + fc)*(onebysix);
    double scb = (b-c)*(fc + 4*fe + fb)*(onebysix);
    
    if (abs(sac+scb-sab)/10 < e)
    {
        return (sac + scb);
    }
    else
    {
        double e1 = e/2;
        return adapt1(sac, fa, fd, fc, a, c, e1) + adapt1(scb, fc, fe, fb, c, b, e1);
    }
}

double adapt(double a, double b, double e)
{
    double fa = f(a);
    double fc = f((a+b)/2);
    double fb = f(b);
    count += 3;
    double sab = (b-a)*(fa + 4*fc + fb)*(onebysix);
    return adapt1(sab, fa, fc, fb, a, b, e);
}

int main()
{
    double a = 0, b = 1; // a < b
    double e = 5e-7;
    double I;
    
    I = adapt(a, b, e);
    cout << "count = " << count << "\n";
    cout << "I = " << fixed << setprecision(15) << I << "\n";
    
    return 0;
}