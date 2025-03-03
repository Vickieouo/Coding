#include <iostream>
#include <iomanip>

int main(void)
{
    float before = 0, after = 0;
    std::cout << "Input real number, before decimal point: ";
    std::cin >> before;
    std::cout << "Input real number, after decimal point: ";
    std::cin >> after;
    std::cout << "The real number is: " 
              << before + after / 1000000;

    return 0;
}