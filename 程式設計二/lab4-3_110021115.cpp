#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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

    // print function
    // note: be careful about the format of output
    // especially the ` ` and newline (endl)
    void print();
    Complex add(const Complex a);
    // add function
    Complex sub(const Complex &a);
    // subtract function
    Complex mul(const Complex &a);
    // multiply function
    Complex div(const Complex &a);
    // divide function
    bool parse(const string &str)
    {
        vector<string> v;
        string str1;
        stringstream ss;
        ss << str;
        while (getline(ss, str1, ' '))
        {
            if (!str1.empty())
            {
                v.push_back(str1);
            }
        }
        if (v.size() != 2)
        {
            return false;
        }
        for(int i = 0; i < 2; i++)
        {
            stringstream ss1;
            ss1 << v[i];
            if (i == 0)
            {
                ss1 >> real;
            }
            else if (i == 1)
            {
                ss1 >> imag;
            }
            if (ss1.fail())
            {
                return false;
            }
            ss1.clear();        
        }
        return true;
    }
    // parse function
    // note: use `stringstream` and `>>` to parse the string to double
    // and use `stringstream::fail()` to check the conversion is successful
};

void Complex::print()
{
    cout << real << " + " << imag << " i\n";
}
Complex::Complex(const double &a, const double &b):real(a), imag(b){}

// parse op global function
char parse_op(const string &str)
{
    if (str.length() != 1)
    {
        return '\0';
    }
    else
    {
        switch (str[0])
        {
        case '+':
            return str[0];
        case '-':
            return str[0];
        case '*':
            return str[0];
        case '/':
            return str[0];
        default:
            return '\0';
        }
    }
}

// prompt invalid input and exit
void prompt_invalid_input()
{
    cout << "Error: Invalid input" << endl;
    exit(1);
}

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
    char op = ' ';                   // default op is ' '
    bool is_process_continue = true; // current process should be continued or not

    while (is_process_continue)
    {
        // get the first input
        getline(cin, input);
        // check is not end of input
        if (input.empty() || cin.eof())
        {
            prompt_invalid_input();
        }
        // check the input is a valid complex number
        Complex input_complex;
        bool is_valid_complex = input_complex.parse(input);
        if (!is_valid_complex)
        {
            prompt_invalid_input();
        }
        // calculate the result
        switch (op)
        {
        case '+':
            result_complex = result_complex.add(input_complex);
            break;
        case '-':
            result_complex = result_complex.sub(input_complex);
            break;
        case '*':
            result_complex = result_complex.mul(input_complex);
            break;
        case '/':
            result_complex = result_complex.div(input_complex);
            break;
        case ' ':
            result_complex = input_complex;
            break;
        default:
            prompt_invalid_input();
        }
        // get the second input
        getline(cin, input);
        // check is end of input or not
        if (input.empty() || cin.eof())
        {
            is_process_continue = false;
        }
        else
        {
            op = parse_op(input);
            if (op == '\0')
            {
                prompt_invalid_input();
            }
        }
        // if not end of input, check the input is a valid operator
        
    }
    result_complex.print();
    return 0;
}
