#include <iostream>

int main(void)
{
    int student_id = 0;
    std::cout << "Your student ID: ";
    std::cin >> student_id;
    std::cout << "Hello world! student "
              << student_id << std::endl;
    return 0;
}
