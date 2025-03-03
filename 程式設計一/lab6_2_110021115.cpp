#include <iostream>
using namespace std;

int main(void)
{
    long long a = 1, b = 1;

    while (true)
    {
        cout << "The number a (input 0 to exit): ";
        cin >> a;

        while (a <= 0)
        {
            if (a == 0)
                return 0;
            else if (a < 0)
                cout << "Invalid input\n";
            cout << "The number a (input 0 to exit): ";
            cin >> a;
        }

        cout << "The number b (input 0 to exit): ";
        cin >> b;
        while (b <= 0 && a > 0)
        {
            if (b == 0)
                return 0;
            else if (b < 0)
                cout << "Invalid input\n";
            break;
        }

        if (a > 0 && b > 0)
        {
            while (a != b)
            {
                if (a > b)
                    a = a - b;
                else
                    b = b - a;
            }
            cout << "The gcd(a, b) = " << a << "\n";
            cout << "\n";
        }
    }

    return 0;
}
