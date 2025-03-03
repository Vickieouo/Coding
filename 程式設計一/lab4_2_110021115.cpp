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

    //input real number a, b
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

    return 0;
}
