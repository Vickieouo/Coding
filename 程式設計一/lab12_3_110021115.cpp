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
void calculate_postfix_expression(vector<string> &tokens, int &last_pos);
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
    int last_pos = tokens.size() - 1;
    calculate_postfix_expression(tokens, last_pos);
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
        }
        if (num <= oper)
        {
            return (false);
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
void calculate_postfix_expression(vector<string> &tokens, int &last_pos)
{
    if (tokens.size() == 1)
    {
        cout << " " << tokens[0];
    }
    int size = tokens.size();
    for (int i = 0; i <= last_pos; i++)
    {
        if (tokens[i] == "+")
        {
            stringstream s;
            s << stoi(tokens[i - 2]) + stoi(tokens[i - 1]);
            s >> tokens[i - 2];
            cout << " " << tokens[i - 2];
            tokens.erase(tokens.begin() + (i - 1));
            tokens.erase(tokens.begin() + (i - 1));
        }
        else if (tokens[i] == "-")
        {
            stringstream s;
            s << stoi(tokens[i - 2]) - stoi(tokens[i - 1]);
            s >> tokens[i - 2];
            cout << " " << tokens[i - 2];
            tokens.erase(tokens.begin() + (i - 1));
            tokens.erase(tokens.begin() + (i - 1));
        }
        else if (tokens[i] == "*")
        {
            stringstream s;
            s << stoi(tokens[i - 2]) * stoi(tokens[i - 1]);
            s >> tokens[i - 2];
            cout << " " << tokens[i - 2];
            tokens.erase(tokens.begin() + (i - 1));
            tokens.erase(tokens.begin() + (i - 1));
        }
        else if (tokens[i] == "/")
        {
            stringstream s;
            s << stoi(tokens[i - 2]) / stoi(tokens[i - 1]);
            s >> tokens[i - 2];
            cout << " " << tokens[i - 2];
            tokens.erase(tokens.begin() + (i - 1));
            tokens.erase(tokens.begin() + (i - 1));
        }
        if (size > tokens.size() && tokens.size() > 1)
        {
            i = 0;
            size = tokens.size();
        }
    }
}