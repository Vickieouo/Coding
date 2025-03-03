#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    //select operation
    int operation = 0;
    std::cout << "Simple scientific calculator\n"
              << "1) plus (+)\n"
              << "2) minus (-)\n"
              << "3) multiplication (*)\n"
              << "4) division (/)\n"
              << "5) modulation (%)\n"
              << "Please select the operator: ";
    std::cin >> operation;

    if (operation == 1)
    {
        std::cout << "You selected: +\n";
    }
    else if (operation == 2)
    {
        std::cout << "You selected: -\n";
    }
    else if (operation == 3)
    {
        std::cout << "You selected: *\n";
    }
    else if (operation == 4)
    {
        std::cout << "You selected: /\n";
    }
    else if (operation == 5)
    {
        std::cout << "You selected: %\n";
    }
    else
    {
        std::cout << "Invalid input\n";
        return 0;
    }

    //input real number a, b
    int sa = 0, sb = 0;
    long double signa = 0, mana = 0, expa = 0, signb = 0, manb = 0, expb = 0;
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
    if ((mana / std::pow(10, 9)) >= 1 || (mana / std::pow(10, 8)) < 1 || mana != int(mana))
    {
        std::cout << "Invalid input\n";
        return 0;
    }

    std::cout << "Input real number (a), exponent: ";
    std::cin >> expa;
    if (expa > 38 || expa < -38 || expa != int(expa))
    {
        std::cout << "Invalid input\n";
        return 0;
    }

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
    if ((manb / std::pow(10, 9)) >= 1 || (manb / std::pow(10, 8)) < 1 || manb != int(manb))
    {
        std::cout << "Invalid input\n";
        return 0;
    }

    std::cout << "Input real number (b), exponent: ";
    std::cin >> expb;
    if (expb > 38 || expb < -38 || expb != int(expb))
    {
        std::cout << "Invalid input\n";
        return 0;
    }

    a = signa * (mana * (std::pow(10, expa - 8)));
    b = signb * (manb * (std::pow(10, expb - 8)));

    std::cout << "The real number (a) is: "
              << std::scientific << std::setprecision(8)
              << a << "\n";
    std::cout << "The real number (b) is: "
              << std::scientific << std::setprecision(8)
              << b << "\n";

    //calculate
    if (operation == 1)
    {
        std::cout << "(a) + (b) = " << std::setprecision(14) << a + b << "\n";
    }
    else if (operation == 2)
    {
        std::cout << "(a) - (b) = " << std::setprecision(14) << a - b << "\n";
    }
    else if (operation == 3)
    {
        std::cout << "(a) * (b) = " << std::setprecision(14) << a * b << "\n";
    }
    else if (operation == 4)
    {
        std::cout << "(a) / (b) = " << std::setprecision(14) << a / b << "\n";
    }
    else if (operation == 5)
    {
        long long aa = a, bb = b;
        std::cout << "(a) / (b) = " << std::setprecision(14) << aa % bb << "\n";
    }

    return 0;
}
