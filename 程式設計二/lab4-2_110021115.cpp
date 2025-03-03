#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

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
    Complex add(const Complex a);
    Complex sub(const Complex &a);
    Complex mul(const Complex &a);
    Complex div(const Complex &a);
    // print function
    // note: be careful about the format of output
    // especially the ` ` and newline (endl)
    // add function
    // subtract function
    // multiply function
    // divide function
};

void Complex::print()
{
    cout << real << " + " << imag << " i\n";
}
Complex::Complex(const double &a, const double &b):real(a), imag(b){}

Complex Complex::add(const Complex current)
{
    this->real += current.real;
    this->imag += current.imag;
    return *this;
}
Complex Complex::sub(const Complex &current)
{
    this->real -= current.real;
    this->imag -= current.imag;
    return *this;
}
Complex Complex::mul(const Complex &current)
{   
    double re = this->real, im = this->imag; 
    this->real = re * current.real - im * current.imag;
    this->imag = re * current.imag + im * current.real;
    return *this;
}
Complex Complex::div(const Complex &current)
{
    double re = this->real, im = this->imag; 
    this->real = (re * current.real + im * current.imag)/(pow(current.real,2) + pow(current.imag,2));
    this->imag = ((-1.0) * re * current.imag + im * current.real)/(pow(current.real,2) + pow(current.imag,2));
    return *this;
}

int main()
{
    string input;
    Complex result_complex;
    char op = ' ';

    while (getline(cin, input))
    {
        // input is a operation
        if (input == "+" || input == "-" || input == "*" || input == "/")
        {
            op = input[0];
            continue;
        }
        // input is a complex number
        else
        {
            stringstream ss(input);
            double real, imag;
            ss >> real >> imag;
            Complex current_complex(real, imag);
            switch (op)
            {
            case '+':
                result_complex = result_complex.add(current_complex);
                break;
            case '-':
                result_complex = result_complex.sub(current_complex);
                break;
            case '*':
                result_complex = result_complex.mul(current_complex);
                break;
            case '/':
                result_complex = result_complex.div(current_complex);
                break;
            case ' ':
                result_complex = current_complex;
                break;
            default:
                cerr << "Error: unknown operation" << endl;
                return 1;
            }
        }
    }
    result_complex.print();
    return 0;
}
