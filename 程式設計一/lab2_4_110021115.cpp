#include <iostream>
#include <iomanip>

int main(void)
{
    long long a_before = 0, b_before = 0;
    long long a_after = 0, b_after = 0;
    long long before_sum = 0, after_sum = 0;

    std::cout << "Input real number (a), before decimal point: ";
    std::cin >> a_before;
    std::cout << "Input real number (a), after decimal point: ";
    std::cin >> a_after;
    std::cout << "The real number (a) is: " << a_before << "."
              << std::setw(18) << std::setfill('0')
              << a_after << std::endl;

    std::cout << "Input real number (b), before decimal point: ";
    std::cin >> b_before;
    std::cout << "Input real number (b), after decimal point: ";
    std::cin >> b_after;
    std::cout << "The real number (b) is: " << b_before << "."
              << std::setw(18) << std::setfill('0')
              << b_after << std::endl;

    before_sum = a_before + b_before;
    after_sum = a_after + b_after;

    std::cout << "(a) + (b) = "
              << before_sum + after_sum / 1000000000000000000
              << "." << std::setfill('0') << std::setw(18)
              << after_sum % 1000000000000000000
              << std::endl;

    return 0;
}