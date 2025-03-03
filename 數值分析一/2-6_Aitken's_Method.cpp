#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
double p = 1.1097123038867133005;

double g(double x)
{
    double a = log(x);
    double ans = (1.05 + a)/1.04;
    return ans;
}

int main()
{
    vector<double> v, v_hat(2, 0), e, e_hat(2, 0);
    double pn_minus1 = 1, pn;

    for(int i = 0; i <= 150; i++)
    {
        cout << "p" << i << " = "  << fixed << setprecision(10) << pn_minus1 << "   ";
        v.emplace_back(pn_minus1);
        v_hat.emplace_back(pn_minus1);
        e.emplace_back(fabs(pn_minus1-p));
        pn = g(pn_minus1);

        // cout << "e" << i << " = "  << fixed << setprecision(10) << e[i] << "   ";
        // if (i >= 1)
        // {
        //     cout << "e" << i << "/e" << i-1 << " = " << fixed << setprecision(10) << e[i]/e[i-1] << "\n";
        // }
        // else
        // {
        //     cout << endl;
        // }

        if (i >= 2)
        {
            double u = v[i] - (pow(v[i] - v[i-1], 2)/(v[i] - 2*v[i-1] + v[i-2]));
            v_hat.emplace_back(u);
            cout << "p" << i << fixed << setprecision(10) << "^ = " << u << "   ";

            e_hat.emplace_back(fabs(u-p));
            cout << "e" << i << "^ = "  << fixed << setprecision(10) << e_hat[i] << "   ";
            if (i >= 3)
            {
                cout << "e" << i << "^/e" << i-1 << "^ = " << fixed << setprecision(10) << e_hat[i]/e_hat[i-1] << "\n";
            }
            else
            {
                cout << endl;
            }
        }
        else
        {
            cout << endl;
        }
        
        pn_minus1 = pn;

        // if (i > 1)
        // {
        //     double kn;
        //     kn = log(e[i]/e[i-1])/log(e[i-1]/e[i-2]);
        //     cout << "k" << i-1 << " = " << setprecision(8) << kn << "\n" << "\n";
        // }
        // else
        // {
        //     cout << endl;
        // }
    }

    return 0;
}
