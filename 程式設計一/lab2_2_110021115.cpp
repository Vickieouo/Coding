#include <iostream>
#include <iomanip>

int main(void)
{
    double a_before = 0, b_before = 0;
    double a_after = 0, b_after = 0;

    std::cout << "Input real number (a), before decimal point: ";
    std::cin >> a_before;
    std::cout << "Input real number (a), after decimal point: ";
    std::cin >> a_after;
    std::cout << "The real number (a) is: " << std::fixed
              << std::setprecision(6) << a_before + a_after / 1000000 << std::endl;

    std::cout << "Input real number (b), before decimal point: ";
    std::cin >> b_before;
    std::cout << "Input real number (b), after decimal point: ";
    std::cin >> b_after;
    std::cout << "The real number (b) is: " << std::fixed
              << std::setprecision(6) << b_before + b_after / 1000000 << std::endl;

    std::cout << "(a) + (b) = " << std::fixed
              << std::setprecision(6) << a_before + a_after / 1000000 + b_before + b_after / 1000000
              << std::endl;

    return 0;
}