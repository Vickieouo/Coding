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
    vector<double> v_hat,v1n, v2n, e_hat(1, 0);
    double pn_minus1 = 1, pn;
    v_hat.emplace_back(pn_minus1);
    cout << "p0 = "  << setprecision(10) << pn_minus1 << "   ";
    cout << "p10 = "  << setprecision(10) << g(pn_minus1) << "   ";
    cout << "p20 = "  << setprecision(10) << g(g(pn_minus1)) << "\n";

    for(int i = 0; i <= 10; i++)
    {        
        double u = g(pn_minus1);
        v1n.emplace_back(u);
        v2n.emplace_back(g(u));

        double s = v2n[i] - (pow(v2n[i] - v1n[i], 2)/(v2n[i] - 2*v1n[i] + v_hat[i]));
        v_hat.emplace_back(s);

        e_hat.emplace_back(fabs(s - p));
        pn_minus1 = s;

        if (i != 0)
        {
            cout << "p" << i << "~ = " << fixed << setprecision(10)<< v_hat[i] << "   ";
            cout << "e" << i << "~ = " << fixed << setprecision(10) << e_hat[i] << "   ";
            if (i == 1) cout << endl;
        }
        if (i >= 2)
        {
            double a = pow(e_hat[i-1], 2);
            cout << "e" << i << "~/e" << i-1 << "~^2 = " << fixed << setprecision(10) << e_hat[i]/a << "\n";
        }

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
