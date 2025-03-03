#include <iostream>

int main(void)
{
    long long a1 = 1, a2 = 2, an, an1, an2;
    double n, i;
    std::cout << "The number of terms: ";
    std::cin >> n;

    if (n != int(n) || n < 1 || n > 92)
    {
        std::cout << "Invalid input\n";
        return 0;
    }

    else if (n == 1)
    {
        std::cout << "The series: " << a1 << "\n";
    }
    else if (n == 2)
    {
        std::cout << "The series: "
                  << a1 << ", " << a2 << "\n";
    }

    else if (n >= 3)
    {
        an = a1 - a2; //an = a3
        an2 = a2;
        an1 = an2 - an; //an1 = a4
        std::cout << "The series: " << a1 << ", " << a2;

        while (i < n - 2)
        {
            std::cout << ", " << an;
            an2 = an - an1; //an2 = a5
            an = an1;       //an = a4
            an1 = an2;      //an1 = a5
            an2 = an - an1; //an2 = a6
            i++;
        }
    }
    return 0;
}
