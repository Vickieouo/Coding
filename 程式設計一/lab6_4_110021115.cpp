#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
START_A:
    int c = 2;
    unsigned long long A1, A2, B1, B2;

    cout << "The number a, first part (input -1 to exit): ";
    cin >> A1;
    if (A1 == -1)
    {
        return 0;
    }
    else if ((A1 != -1 && A1 < 0) || A1 >= (long long)pow(10, 18))
    {
        cout << "Invalid input\n";
        goto START_A;
    }

    cout << "The number a, second part (input -1 to exit): ";
    cin >> A2;
    if (A2 == -1)
    {
        return 0;
    }
    else if ((A2 != -1 && A2 < 0 && A1 >= 0) || A2 >= (long long)pow(10, 18))
    {
        cout << "Invalid input\n";
        goto START_A;
    }
    else if (A1 == 0 && A2 == 0)
    {
        cout << "Invalid input\n";
        goto START_A;
    }
    else if (A2 >= 0 && A1 >= 0)
    {
        if (A1 == 0)
        {
            cout << "The number a = " << A2 << "\n";
        }
        else
        {
            cout << "The number a = " << A1 << setw(18) << setfill('0') << A2 << "\n";
        }
    }

START_B:
    cout << "The number b, first part (input -1 to exit): ";
    cin >> B1;
    if (B1 == -1)
    {
        return 0;
    }
    else if ((B1 != -1 && B1 < 0 && A1 >= 0 && A2 >= 0) || B1 >= (long long)pow(10, 18))
    {
        cout << "Invalid input\n";
        goto START_B;
    }

    cout << "The number b, second part (input -1 to exit): ";
    cin >> B2;
    if (B2 == -1)
    {
        return 0;
    }
    else if ((B2 != -1 && B2 < 0 && A1 >= 0 && A2 >= 0 && B1 >= 0) || B2 >= (long long)pow(10, 18))
    {
        cout << "Invalid input\n";
        goto START_B;
    }
    else if (B1 == 0 && B2 == 0)
    {
        cout << "Invalid input\n";
        goto START_B;
    }
    else if (B2 >= 0 && B1 >= 0)
    {
        if (B1 == 0)
        {
            cout << "The number b = " << B2 << "\n";
        }
        else
        {
            cout << "The number b = " << B1 << setw(18) << setfill('0') << B2 << "\n";
        }
    }

    while (c != 0)
    {
        if (A1 > B1)
        {
            c = 1;
        }
        else if (A1 == B1)
        {
            if (A2 == B2)
            {
                c = 0;
            }
            else if (A2 > B2)
            {
                c = 1;
            }
            else if (A2 < B2)
            {
                c = -1;
            }
        }
        else
        {
            c = -1;
        }

        if (c == 1) //A > B => A = A - B
        {
            if (A2 <= B2)
            {
                A1 = A1 - 1;
                A2 = A2 + pow(10, 18);
            }
            A1 = A1 - B1;
            A2 = A2 - B2;
        }
        else if (c == -1) //B > A => B = B - A
        {
            if (B2 <= A2)
            {
                B1 = B1 - 1;
                B2 = B2 + pow(10, 18);
            }
            B1 = B1 - A1;
            B2 = B2 - A2;
        }
    }

    if (A1 == 0)
    {
        cout << "The gcd(a, b) = " << A2 << "\n"
             << "\n";
    }
    else
    {
        cout << "The gcd(a, b) = " << A1 << setw(18) << setfill('0')
             << A2 << "\n"
             << "\n";
    }

    goto START_A;
}