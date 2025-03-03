#include <iostream>

int main(void)
{
    int days = 0, hours = 0;
    std::cout << "Employee workdays per week: ";
    std::cin >> days;
    std::cout << "Employee working hours per workday: ";
    std::cin >> hours;
    std::cout << "Employee works " << days * hours
              << " hour(s) per week." << std::endl;
    return 0;
}