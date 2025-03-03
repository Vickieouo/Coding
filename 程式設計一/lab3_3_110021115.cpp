#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    int s, exp;
    double sign, man, num, ff, fff, diff;
    float fnum;

    std::cout << "Input real number, sign: ";
    std::cin >> s;
    if (s >= 0)
    {
        sign = 1;
    }
    else //s<0
    {
        sign = -1;
    }
    std::cout << "Input real number, mantissa: ";
    std::cin >> man;
    std::cout << "Input real number, exponent: ";
    std::cin >> exp;

    std::cout.precision(9);
    num = man * (std::pow(10, exp - 8));
    fnum = float(num);
    ff = fnum / (std::pow(10, exp - 8));
    fff = std::round(ff);
    diff = (man - fff) * (std::pow(10, exp - 8));

    std::cout.precision(8);
    std::cout << "The real number is: "
              << std::scientific
              << sign * num << "\n";
    std::cout << "The IEEE-754 single precision number is: "
              << std::scientific
              << sign * fnum << "\n";

    if (diff > 0)
    {
        std::cout << "The difference (absolute value): "
                  << std::scientific
                  << diff << "\n";
    }
    else //diff<0
    {
        diff = -1 * diff;
        std::cout << "The difference (absolute value): "
                  << std::scientific
                  << diff << "\n";
    }

    return 0;
}