#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

void parse_expression(const string &expression, vector<string> &tokens);
bool check_expression(const vector<string> &tokens);
void print_ops(const vector<string> &tokens);
void print_nums(const vector<string> &tokens);
void calculate_postfix_expression(const vector<string> &tokens);
// hint: use std::to_string(long) to convert long to string

int main(int argc, char *argv[])
{
    string input_buffer;
    vector<string> tokens;

    cout << "Please input the expression: ";
    getline(cin, input_buffer);

    parse_expression(input_buffer, tokens);

    if (!check_expression(tokens))
    {
        cout << "Invalid expression." << endl;
        return EXIT_FAILURE;
    }

    print_nums(tokens);

    print_ops(tokens);

    cout << "Result:";
    calculate_postfix_expression(tokens);
    cout << endl;

    return EXIT_SUCCESS;
}

void parse_expression(const string &expression, vector<string> &tokens)
{
    stringstream ss;
    string n;
    ss << expression;
    while (getline(ss, n, ' '))
    {
        tokens.push_back(n);
    }
}
bool check_expression(const vector<string> &tokens)
{
    int num = 0, oper = 0;
    for (int i = 0; i < tokens.size(); i++)
    {
        char a[10000];
        for (int i = 0; i < 10000; i++)
        {
            a[i] = '0';
        }
        stringstream b(tokens[i]);
        b >> a;

        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            oper++;
            if (oper != num)
            {
                return (false);
            }
        }
        else
        {
            if (a[0] == '-' || isdigit(a[0]))
            {
                for (int j = 1; a[j] != '\0'; j++)
                {
                    if (isdigit(a[j]))
                    {
                        continue;
                    }
                    else
                    {
                        return (false);
                    }
                }
            }
            else
            {
                return (false);
            }
            num++;
            if (oper != num - 1)
            {
                return (false);
            }
        }
    }

    if (oper != num - 1)
    {
        return (false);
    }
    else
    {
        return (true);
    }
}
void print_nums(const vector<string> &tokens)
{
    cout << "Operands:";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
        {
            cout << " " << tokens[i];
        }
    }
    cout << endl;
}
void print_ops(const vector<string> &tokens)
{
    cout << "Operators:";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            cout << " " << tokens[i];
        }
    }
    cout << endl;
}
void calculate_postfix_expression(const vector<string> &tokens)
{
    vector<long> operands;
    vector<string> operators;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
        {
            operands.push_back(stol(tokens[i]));
        }
        else
        {
            operators.push_back(tokens[i]);
        }
    }

    for (int i = 0; i < operators.size(); i++)
    {
        if (operators[i] == "+")
        {
            operands[i + 1] = operands[i] + operands[i + 1];
        }
        else if (operators[i] == "-")
        {
            operands[i + 1] = operands[i] - operands[i + 1];
        }
        else if (operators[i] == "*")
        {
            operands[i + 1] = operands[i] * operands[i + 1];
        }
        else if (operators[i] == "/")
        {
            operands[i + 1] = operands[i] / operands[i + 1];
        }
    }
    operands.erase(operands.begin());

    if (tokens.size() == 1)
    {
        cout << " " << tokens[0];
    }
    else
    {
        for (int i = 0; i < operands.size(); i++)
        {
            cout << " " << operands[i];
        }
    }
}