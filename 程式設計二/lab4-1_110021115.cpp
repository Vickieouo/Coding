#include <iostream>

using namespace std;

class Complex
{
private:
    double real, imag;
    // data members
    // save the real and imaginary parts of the complex number
    // with `double` precision

public:
    Complex(const double &a = 0.0, const double &b = 0.0);
    // Constructor, initializes real and imaginary parts
    // hint: as like as `modify` function in examples
    // but use default constructor to implement

    void print();
    // print function
    // note: be careful about the format of output
    // especially the ` ` and newline (endl)
};

void Complex::print()
{
    cout << real << " + " << imag << " i\n";
}
Complex::Complex(const double &a, const double &b):real(a), imag(b){}

int main()
{
    double real = 0.0, imag = 0.0;
    while (cin >> real >> imag)
    {
        Complex c(real, imag);
        c.print();
    }
    return 0;
}
