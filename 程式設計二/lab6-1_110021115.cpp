#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Complex
{
private:
    // data members
    // save the real and imaginary parts of the complex number
    // with `double` precision
    double m_real;
    double m_imag;

public:
    // Constructor, initializes real and imaginary parts
    Complex(const double &arg_real = 0.0, const double &arg_imag = 0.0);
    // Copy constructor
    Complex(const Complex &arg_c);
    
    // assignment operator
    Complex &operator=(const Complex &arg_c);
    // add assignment operator
    Complex &operator+=(const Complex &arg_c);
    // subtract assignment operator
    Complex &operator-=(const Complex &arg_c);
    // multiply assignment operator
    Complex &operator*=(const Complex &arg_c);
    // divide assignment operator
    Complex &operator/=(const Complex &arg_c);

    // add function
    Complex operator+(const Complex &arg_c) const;
    // subtract function
    Complex operator-(const Complex &arg_c) const;
    // multiply function
    Complex operator*(const Complex &arg_c) const;
    // divide function
    Complex operator/(const Complex &arg_c) const;
    // note: be careful about the format of output
    // cout `<<` operator for print complex number
    friend ostream &operator<<(ostream &arg_os, const Complex &arg_c);
    // cin `>>` operator for input complex number
    // note: be careful about the format of input
    // hint: use `stod` to convert string to double
    friend istream &operator>>(istream &arg_is, Complex &arg_c);
};

Complex::Complex(const double &a, const double &b):m_real(a), m_imag(b){}
Complex::Complex(const Complex &arg_c):m_real(arg_c.m_real), m_imag(arg_c.m_imag){}

Complex &Complex::operator=(const Complex &arg_c)
{
    m_real = arg_c.m_real;
    m_imag = arg_c.m_imag;
    return *this;
}
Complex &Complex::operator+=(const Complex &arg_c)
{
    m_real += arg_c.m_real;
    m_imag += arg_c.m_imag;
    return *this;
}
Complex &Complex::operator-=(const Complex &arg_c)
{
    m_real -= arg_c.m_real;
    m_imag -= arg_c.m_imag;
    return *this;
}
Complex &Complex::operator*=(const Complex &arg_c)
{
    double re = m_real, im = m_imag;
    m_real = re * arg_c.m_real - im * arg_c.m_imag;
    m_imag = re * arg_c.m_imag + im * arg_c.m_real;
    return *this;
}
Complex &Complex::operator/=(const Complex &arg_c)
{
    double re = m_real, im = m_imag;
    double b = pow(arg_c.m_real,2) + pow(arg_c.m_imag,2);
    m_real = (re * arg_c.m_real + im * arg_c.m_imag) / b;
    m_imag = ((-1.0) * re * arg_c.m_imag + im * arg_c.m_real) / b;
    return *this;
}
Complex Complex::operator+(const Complex &arg_c) const
{
    Complex a(*this);
    a += arg_c;
    return a;
}
Complex Complex::operator-(const Complex &arg_c) const
{
    Complex a(*this);
    a -= arg_c;
    return a;
}
Complex Complex::operator*(const Complex &arg_c) const
{
    Complex a(*this);
    a *= arg_c;
    return a;
}
Complex Complex::operator/(const Complex &arg_c) const
{
    Complex a(*this);
    a /= arg_c;
    return a;
}
ostream &operator<<(ostream &arg_os, const Complex &arg_c)
{
    if (arg_c.m_imag == 0)
    {
        arg_os << arg_c.m_real;
    }
    else if (arg_c.m_imag < 0)
    {
        arg_os << arg_c.m_real << " - " << (-1) * arg_c.m_imag << "i";
    }
    else
    {
        arg_os << arg_c.m_real << " + " << arg_c.m_imag << "i";
    }
    return arg_os;
}
istream &operator>>(istream &arg_is, Complex &arg_c)
{
    string str1, str2;
    stringstream ss1, ss2;
    arg_is >> str1; arg_is >> str2;
    ss1 << str1; ss2 << str2;
    ss1 >> arg_c.m_real; ss2 >> arg_c.m_imag;
    return arg_is;
}

// used for process the test cases, do not modify
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
        else if (input.empty())
        {
            continue;
        }
        // input is a complex number
        else
        {
            stringstream ss(input);
            Complex current_complex;
            ss >> current_complex;
            switch (op)
            {
            case '+':
                result_complex += current_complex;
                break;
            case '-':
                result_complex -= current_complex;
                break;
            case '*':
                result_complex *= current_complex;
                break;
            case '/':
                result_complex /= current_complex;
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
    // cout << endl;
    cout << result_complex << endl;
    return 0;
}
