#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    int sa = 0, expa = 0, sb = 0, expb = 0;
    long double signa = 0, mana = 0, signb = 0, manb = 0;
    long double a = 0, b = 0;

    std::cout << "Input real number (a), sign: ";
    std::cin >> sa;
    if (sa >= 0)
    {
        signa = 1;
    }
    else //sa<0
    {
        signa = -1;
    }

    std::cout << "Input real number (a), mantissa: ";
    std::cin >> mana;
    std::cout << "Input real number (a), exponent: ";
    std::cin >> expa;

    std::cout << "Input real number (b), sign: ";
    std::cin >> sb;
    if (sb >= 0)
    {
        signb = 1;
    }
    else //sb<0
    {
        signb = -1;
    }
    std::cout << "Input real number (b), mantissa: ";
    std::cin >> manb;
    std::cout << "Input real number (b), exponent: ";
    std::cin >> expb;

    a = signa * (mana / (std::pow(10, 18)));
    b = signb * (manb / (std::pow(10, 18)));

    std::cout << "The real number (a) is: "
              << std::fixed << std::setprecision(18)
              << std::noshowpos << a << "e" << std::showpos << expa << "\n";
    std::cout << "The real number (b) is: "
              << std::fixed << std::setprecision(18)
              << std::noshowpos << b << "e" << std::showpos << expb << "\n";

    a = a * std::pow(10, expa);
    b = b * std::pow(10, expb);

    if (a > b)
    {
        std::cout << "Compare result: 1"
                  << "\n";
    }
    else if (a == b)
    {
        std::cout << "Compare result: 0"
                  << "\n";
    }
    else //a<b
    {
        std::cout << "Compare result: -1"
                  << "\n";
    }

    return 0;
}