#include <iostream>

int main(void)
{
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

    return 0;
}
