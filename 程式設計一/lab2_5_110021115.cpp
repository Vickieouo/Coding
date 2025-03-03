#include <iostream>
#include <iomanip>

int main(void)
{
    long long a = 0, c = 0; //a=a_before, c=b_before
    long long b = 0, d = 0; //b=a_after, d=b_after
    long long nine = 1000000000, eighteen = 1000000000000000000;

    std::cout << "Input real number (a), before decimal point: ";
    std::cin >> a;
    std::cout << "Input real number (a), after decimal point: ";
    std::cin >> b;
    std::cout << "The real number (a) is: " << a << "."
              << std::setw(9) << std::setfill('0')
              << b << "000000000" << std::endl;

    std::cout << "Input real number (b), before decimal point: ";
    std::cin >> c;
    std::cout << "Input real number (b), after decimal point: ";
    std::cin >> d;
    std::cout << "The real number (b) is: " << c << "."
              << std::setw(9) << std::setfill('0')
              << d << "000000000" << std::endl;

    std::cout << "(a) * (b) = "
              << a * c + (b * c + a * d) / nine + (((b * c + a * d) % nine) * nine + b * d) / eighteen
              << "." << std::setfill('0') << std::setw(18)
              << (((b * c + a * d) % nine) * nine + b * d) % eighteen
              << std::endl;

    return 0;
}