#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Complex_Calc;

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
    // cout `<<` operator for print complex number
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const Complex &arg_c);
    // cin `>>` operator for input complex number
    // note: be careful about the format of input
    // hint: use `stod` to convert string to double
    friend istream &operator>>(istream &arg_is, Complex &arg_c);

    friend class Complex_Calc;
};

// Complex calculator class declaration
class Complex_Calc
{
private:
    // define current value
    Complex m_curr_val;
    // define input value
    Complex m_input_val;
    // define operation
    // `+`, `-`, `*`, `/`, and `=`
    char m_op = ' ';
    // calculate result
    void _calc_result();
    // operation functions
    // add the input value to the current value
    void _add();
    // subtract the input value from the current value
    void _sub();
    // multiply the input value with the current value
    void _mul();
    // divide the current value by the input value
    void _div();
    // assign the input value to the current value
    void _assign();

public:
    // Constructor
    Complex_Calc();
    // Copy constructor
    Complex_Calc(const Complex_Calc &arg_int_calc);

    // Destructor
    ~Complex_Calc(){}; // no need to do anything

    // set input value or operation
    void set_input(const string &arg_input);

    // cout `<<` operator for print calculator status
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const Complex_Calc &arg_comp_calc);
};

// parse the test cases, do not modify belows

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

Complex_Calc::Complex_Calc():m_curr_val(), m_input_val(), m_op(' '){}
Complex_Calc::Complex_Calc(const Complex_Calc &arg_int_calc):
    m_curr_val(arg_int_calc.m_curr_val), m_input_val(arg_int_calc.m_input_val), m_op(arg_int_calc.m_op){}

void Complex_Calc::_calc_result()
{
    switch (m_op)
    {
    case '+':
        m_curr_val += m_input_val;
        break;
    case '-':
        m_curr_val -= m_input_val;
        break;
    case '*':
        m_curr_val *= m_input_val;
        break;
    case '/':
        m_curr_val /= m_input_val;
        break;
    case ' ':
    case '=':
        m_curr_val = m_input_val;
        break;
    default:
        break;
    }
}
void Complex_Calc::_add()
{
    m_op = '+';
}
void Complex_Calc::_sub()
{
    m_op = '-';
}
void Complex_Calc::_mul()
{
    m_op = '*';
}
void Complex_Calc::_div()
{
    m_op = '/';
}
void Complex_Calc::_assign()
{
    m_op = '=';
}
ostream &operator<<(ostream &arg_os, const Complex_Calc &arg_comp_calc)
{
    arg_os << arg_comp_calc.m_curr_val;
    return arg_os;
}
void Complex_Calc::set_input(const string &arg_input)
{
    // input is empty, read again
    if (arg_input.empty())
    {
        return;
    }
    // input is a operation
    else if (arg_input == "+" || arg_input == "-" || arg_input == "*" || arg_input == "/" || arg_input == "=")
    {
        // set the activated operation
        // as the same as the user press the op button
        switch (arg_input[0])
        {
        case '+':
            _add();
            break;
        case '-':
            _sub();
            break;
        case '*':
            _mul();
            break;
        case '/':
            _div();
            break;
        case '=':
            _assign();
            break;
        }
    }
    // input is a complex number
    // as the same as the user type a number
    // it performs as the same as the user pressed the '=' button
    // if the input is the first input
    // thus, we initialize the m_op to '='
    else
    {
        stringstream ss(arg_input);
        ss >> m_input_val;
        _calc_result();
    }
}

// main function

int main()
{
    // create an instance of the class
    Complex_Calc calc;
    string input;
    while (getline(cin, input))
    {
        calc.set_input(input);
        cout << calc << endl;
    }
}
