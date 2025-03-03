#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

class BigReal_Calc;

class BigReal
{
private:
    // data members
    // save the digits before and after the decimal point of a before_decimal number
    // with `long long` precision
    const long long m_dec_upperbound = 1000000000;
    long long m_before_decimal;
    long long m_after_decimal; // times 10^-9
    void _output_normalization();

public:
    // Constructor, initializes before_decimal and after_decimalinary parts
    // hint: as like as `modify` function in examples
    // but use default constructor to implement
    BigReal(const long long &arg_before_decimal = 0.0,
            const long long &arg_after_decimal = 0.0);
    // Copy constructor
    BigReal(const BigReal &arg_big_real);
    // assignment operator
    BigReal &operator=(const BigReal &arg_big_real);
    // add assignment operator
    BigReal &operator+=(const BigReal &arg_big_real);
    // multiply assignment operator
    BigReal &operator*=(const BigReal &arg_big_real);
    // add function
    BigReal operator+(const BigReal &arg_big_real) const;
    // multiply function
    BigReal operator*(const BigReal &arg_big_real) const;
    // cout `<<` operator for print BigReal number
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const BigReal &arg_big_real);
    // cin `>>` operator for input BigReal number
    // note: be careful about the format of input
    // hint: use string `+=` to append digits
    friend istream &operator>>(istream &arg_is, BigReal &arg_big_real);
};

// BigReal calculator class declaration
class BigReal_Calc
{
private:
    // define current value
    BigReal m_curr_val;
    // define input value
    BigReal m_input_val;
    // define operation
    // `+`, `*`, and `=`
    char m_op;
    // define input status, truns `op` for true and turns `value` for false
    // bool m_op_input;
    // calculate result
    void _calc_result();
    // operation functions
    // set activation op to add
    void _add();
    // set activation op to subtract
    void _mul();
    // set activation op to divide
    void _assign();

public:
    // Constructor
    BigReal_Calc();
    // Copy constructor
    BigReal_Calc(const BigReal_Calc &arg_int_calc);

    // Destructor
    ~BigReal_Calc(){}; // no need to do anything

    // set input value or operation
    // as the same as the user input number or operation
    // into the calculator
    void set_input(const string &arg_input);

    // cout `<<` operator for print calculator status
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const BigReal_Calc &arg_comp_calc);
};

// error and exit
void error_and_exit()
{
    cerr << "Error: Invalid input" << endl;
    exit(1);
}

BigReal::BigReal(const long long &arg_before_decimal, const long long &arg_after_decima) : m_before_decimal(arg_before_decimal), m_after_decimal(arg_after_decima) {}
BigReal::BigReal(const BigReal &arg_big_real) : m_before_decimal(arg_big_real.m_before_decimal), m_after_decimal(arg_big_real.m_after_decimal) {}

BigReal &BigReal::operator=(const BigReal &arg_big_real)
{
    m_before_decimal = arg_big_real.m_before_decimal;
    m_after_decimal = arg_big_real.m_after_decimal;
    return *this;
}
BigReal &BigReal::operator+=(const BigReal &arg_big_real)
{
    long long a = (m_after_decimal + arg_big_real.m_after_decimal) / m_dec_upperbound;
    m_before_decimal = m_before_decimal + arg_big_real.m_before_decimal + a;
    m_after_decimal = (m_after_decimal + arg_big_real.m_after_decimal) % m_dec_upperbound;
    return *this;
}
BigReal &BigReal::operator*=(const BigReal &arg_big_real)
{
    long long a = m_before_decimal, b = m_after_decimal, c = arg_big_real.m_before_decimal, d = arg_big_real.m_after_decimal;
    m_before_decimal = a * c + (a * d + b * c) / m_dec_upperbound;
    m_after_decimal = (a * d + b * c) % m_dec_upperbound + (b * d) / m_dec_upperbound;
    if (m_after_decimal > m_dec_upperbound)
    {
        m_before_decimal += (m_after_decimal / m_dec_upperbound);
        m_after_decimal %= m_dec_upperbound;
    }
    return *this;
}
BigReal BigReal::operator+(const BigReal &arg_big_real) const
{
    BigReal a(*this);
    a += arg_big_real;
    return a;
}
BigReal BigReal::operator*(const BigReal &arg_big_real) const
{
    BigReal a(*this);
    a *= arg_big_real;
    return a;
}
ostream &operator<<(ostream &arg_os, const BigReal &arg_big_real)
{
    int a = arg_big_real.m_after_decimal;
    if (a == 0)
    {
        arg_os << arg_big_real.m_before_decimal << ".000000000";
    }
    else
    {
        arg_os << arg_big_real.m_before_decimal << ".";
        long long a = arg_big_real.m_after_decimal, i;
        for (i = 1; (a / 10) != 0; i++)
        {
            a /= 10;
        }
        for (i; (9 - i) != 0; i++)
        {
            arg_os << "0";
        }
        arg_os << arg_big_real.m_after_decimal;
    }
    return arg_os;
}
istream &operator>>(istream &arg_is, BigReal &arg_big_real)
{
    string before, after;
    stringstream ss1, ss2;
    getline(arg_is, before, '.');
    getline(arg_is, after, '.');
    if (before.length() > 9 || after.length() > 9 || before.empty() || after.empty())
    {
        error_and_exit();
    }

    ss1 << before;
    ss1 >> arg_big_real.m_before_decimal;

    for (int i = 0; after.length() < 9; i++)
    {
        after += "0";
    }
    ss2 << after;
    ss2 >> arg_big_real.m_after_decimal;
    if (arg_big_real.m_before_decimal < 0 || arg_big_real.m_after_decimal < 0)
    {
        error_and_exit();
    }
    return arg_is;
}

BigReal_Calc::BigReal_Calc() : m_curr_val(), m_input_val(), m_op(' ') {}
BigReal_Calc::BigReal_Calc(const BigReal_Calc &arg_int_calc) : m_curr_val(arg_int_calc.m_curr_val), m_input_val(arg_int_calc.m_input_val), m_op(arg_int_calc.m_op) {}

void BigReal_Calc::_calc_result()
{
    switch (m_op)
    {
    case '+':
        m_curr_val += m_input_val;
        break;
    case '*':
        m_curr_val *= m_input_val;
        break;
    case '=':
    case ' ':
        m_curr_val = m_input_val;
        break;
    default:
        break;
    }
}
void BigReal_Calc::_add()
{
    m_op = '+';
}
void BigReal_Calc::_mul()
{
    m_op = '*';
}
void BigReal_Calc::_assign()
{
    m_op = '=';
}
ostream &operator<<(ostream &arg_os, const BigReal_Calc &arg_comp_calc)
{
    arg_os << arg_comp_calc.m_curr_val;
    return arg_os;
}
void BigReal_Calc::set_input(const string &arg_input)
{
    if (arg_input.empty())
    {
        return;
    }
    // input is a operation
    else if (arg_input == "+" || arg_input == "*")
    {
        if (m_op == 'k')
        {
            // set the activated operation
            // as the same as the user press the op button
            switch (arg_input[0])
            {
            case '+':
                _add();
                break;
            case '*':
                _mul();
                break;
            case '=':
                _assign();
                break;
            }
            // set to 'input a complex number' turn
        }
        else
        {
            error_and_exit();
        }
    }
    // input is a complex number
    // as the same as the user type a number
    // it performs as the same as the user pressed the '=' button
    // if the input is the first input
    // thus, we initialize the m_op to '='
    else
    {
        // set to 'input a op' turn
        if (m_op == '+' || m_op == '*' || m_op == ' ')
        {
            stringstream ss(arg_input);
            ss >> m_input_val;
            if (ss.fail() || ss.rdbuf()->in_avail() != 0)
            {
                error_and_exit();
            }
            else
            {
                _calc_result();
                m_op = 'k';
            }
        }
        else
        {
            error_and_exit();
        }
    }
}

// main function

int main()
{
    // create an instance of the class
    BigReal_Calc calc;
    string input;
    while (getline(cin, input))
    {
        calc.set_input(input);
        cout << calc << endl;
    }
}
