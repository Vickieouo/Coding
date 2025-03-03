#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <vector>
#include <cmath>

using namespace std;

struct DataPoint
{
    double m_x{};
    double m_y{};
};

const vector<DataPoint> &ReadData(string file)
{
    ifstream infile;
    static vector<DataPoint> data{};
    const char split_char{','};
    string line{};

    infile.open(file, ios::in);

    if (!infile.is_open())
    {
        cerr << "!!! Could not open file - '" << file << "'" << endl;
        exit(0);
    }

    while (getline(infile, line))
    {
        stringstream line_stream{line};
        vector<string> split_vector{};
        DataPoint tmpPoint{};

        while (getline(line_stream, line, split_char))
        {
            split_vector.push_back(line);
        }

        tmpPoint.m_x = stod(split_vector[0]);
        tmpPoint.m_y = stod(split_vector[1]);

        data.push_back(tmpPoint);
    }
    infile.close();

    return data;
}

const double det(double a, double b, double c, double d)
{
    double D;
    D = a*d - b*c;
    return D;
}

const double det3(vector<vector<double>> X)
{
    double a, b, c, d, e, f, g, h, i, D;
    a = X[1][1]; b = X[1][2]; c = X[1][3];
    d = X[2][1]; e = X[2][2]; f = X[2][3];
    g = X[3][1]; h = X[3][2]; i = X[3][3];
    D = c*(d*h-e*g) - f*(a*h-b*g) + i*(a*e-b*d);
    return D;
}

const vector<vector<double>> multi(vector<vector<double>> A, vector<vector<double>> B)
{
    vector<vector<double>> mul(A.size(), vector<double>(B[1].size()));
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 1; j < B[1].size(); j++)
        {
            for (int k = 1; k < A[1].size(); k++)
            {
                mul[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return mul;
}

const vector<vector<double>> inv(vector<vector<double>> A)
{
    vector<vector<double>> I(4, vector<double>(4));
    double detA = det3(A); detA = 1/detA;

    I[1][1] = det(A[2][2], A[2][3], A[3][2], A[3][3]) * detA;
    I[1][2] = -det(A[1][2], A[1][3], A[3][2], A[3][3]) * detA;
    I[1][3] = det(A[1][2], A[1][3], A[2][2], A[2][3]) * detA;

    I[2][1] = -det(A[2][1], A[2][3], A[3][1], A[3][3]) * detA;
    I[2][2] = det(A[1][1], A[1][3], A[3][1], A[3][3]) * detA;
    I[2][3] = -det(A[1][1], A[1][3], A[2][1], A[2][3]) * detA;

    I[3][1] = det(A[2][1], A[2][2], A[3][1], A[3][2]) * detA;
    I[3][2] = -det(A[1][1], A[1][2], A[3][1], A[3][2]) * detA;
    I[3][3] = det(A[1][1], A[1][2], A[2][1], A[2][2]) * detA;

    return I;
}

int main()
{
    string filename{"81-107(m).csv"};
    const vector<DataPoint> &train_data{ReadData(filename)};
    int n = train_data.size();
    vector<vector<double>> X(n+1, vector<double>(4)), Y(n+1, vector<double>(2)), A;

    for (int i = 1; i <= n; i++)
    {
        X[i][1] = 1;
        X[i][2] = train_data[i-1].m_x;
        X[i][3] = pow(train_data[i-1].m_x, 2);
        Y[i][1] = train_data[i-1].m_y;
    }

    vector<vector<double>> XT(4, vector<double>(n+1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            XT[j][i] = X[i][j];
        }
    }

    A = multi(XT, X);
    A = inv(A);
    A = multi(A, XT);
    A = multi(A, Y);

    cout << "The linear regression fitting model of 81y-107y is: "
         << "y = " << A[3][1] << "x^2 + " << A[2][1] << "x + " << A[1][1] << endl;

    return 0;
}