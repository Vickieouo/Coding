#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    START_N:
        int digitN1 = 1, digitN2 = 1, digitD1 = 1, i = 0, I = 0;
        unsigned long long N1, n1, N2, n2, D1, d1, D2;
        unsigned long long a, b;

        cout << "The number N, first part (input -1 to exit): ";
        cin >> N1;
        if (N1 == -1)
        {
            return 0;
        }
        else if ((N1 != -1 && N1 < 0) || N1 >= pow(10,18))
        {
            cout << "Invalid input\n";
            goto START_N;
        }
    
    n1 = N1;
    while (n1 > 10)
    {
        n1 = n1 / 10;
        digitN1++;
    }
    n1 = N1;
    a = pow(10,18-digitN1);
    N1 = N1 * a;

    cout << "The number N, second part (input -1 to exit): ";
    cin >> N2;
    if (N2 == -1)
    {
        return 0;
    }
    else if ((N2 != -1 && N2 < 0 && N1 >= 0) || N2 >= pow(10,18))
    {
        cout << "Invalid input\n";
        goto START_N;
    }
    else if (N2 >= 0 && N1 >= 0)
    {
        if (N1 == 0)
        {
            cout << "The number N = " <<  N2 << "\n";
        }
        else
        {
            cout << "The number N = " << n1 << setw(18) << setfill('0') << N2 << "\n";
        }

    }
    n2 = N2;
    while (n2 > 10)
    {
        n2 = n2 / 10;
        digitN2++;
    }

    START_D:
        cout << "The number D, first part (input -1 to exit): ";
        cin >> D1;
        if (D1 == -1)
        {
            return 0;
        }
        else if ((D1 != -1 && D1 < 0 && N1 >= 0 && N2 >= 0) || D1 >= pow(10,18))
        {
            cout << "Invalid input\n";
            goto START_D;
        }
    
    d1 = D1;
    while (d1 > 10)
    {
        d1 = d1 / 10;
        digitD1++;
    }
    d1 = D1;
    b = pow(10,18-digitD1);
    D1 = D1 * b;

    cout << "The number D, second part (input -1 to exit): ";
    cin >> D2;
    if (D2 == -1)
    {
        return 0;
    }
    else if ((D2 != -1 && D2 < 0 && N1 >= 0 && N2 >= 0 && D1 >= 0) || D2 >= pow(10,18))
    {
        cout << "Invalid input\n";
        goto START_D;
    }
    else if (D2 >= 0 && D1 >= 0)
    {
        if (D1 == 0)
        {
            cout << "The number D = " <<  D2 << "\n";
        }
        else
        {
            cout << "The number D = " << d1 << setw(18) << setfill('0') << D2 << "\n";
        }
    }


    if (N1 > 0 && N2 >= 0 && D1 > 0 && D2 >= 0)
    {
        if (N1 < D1)
        {
            cout << "The remainder N % "
                 << "D = " << N1 << N2 << "\n" << "\n";
        }
        else
        {
            while (N1 >= D1)
            {
                if (N2 >= D2)
                {
                    N1 = N1 - D1;
                    N2 = N2 - D2;
                }
                else if (N2 < D2)
                {
                    while (N2 < D2)
                    {
                        I = 1*pow(10,i);
                        N1 = N1 - I;
                        N2 = 1*pow(10, digitN2 + i) + N2;
                        i++;
                    }
                    N1 = N1 - D1;
                    N2 = N2 - D2;
                }
            }
            if (N1 == 0)
            {
                cout << "The remainder N % "
                     << "D = " << N2 << "\n" << "\n";
            }
            else
            {
                cout << "The remainder N % "
                     << "D = " << N1 << setw(18) << setfill('0')
                     << N2 << "\n" << "\n";
            }
        }
    }
    else if (N1 == 0 || D1 == 0)
    {
        if(N2 >= D2 && D2 != 0)
        {
            while(N2 > D2)
            {
                N2 = N2 - D2;
            }
            cout << "The remainder N % "
                 << "D = " << N2 << "\n" << "\n";
        }
        else if (D2 == 0 || N2 < D2)
        {
            cout << "The remainder N % "
                 << "D = " << N2 << "\n" << "\n";
        }
    }

    goto START_N;
}
