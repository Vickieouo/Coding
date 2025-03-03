#include <iostream>
#include <iomanip>
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

        tmpPoint.m_x = stoi(split_vector[0]);
        tmpPoint.m_y = stoi(split_vector[1]);

        data.push_back(tmpPoint);
    }
    infile.close();

    return data;
}

void output_matrix(vector<vector<double>> &A)
{
    int n = A.size(), m = A[1].size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            cout << fixed << A[i][j] << ",";
        }
        cout << "\n";
    }
}

int main()
{
    string filename{"Data_81-107(92x).csv"};
    const vector<DataPoint> &train_data{ReadData(filename)};
    int n = train_data.size();
    vector<vector<double>> X(n+1, vector<double>(5)), Y(n+1, vector<double>(2)), A;

    for (int i = 1; i <= n; i++)
    {
        X[i][1] = 1;
        X[i][2] = train_data[i-1].m_x;
        X[i][3] = pow(train_data[i-1].m_x, 2);
        X[i][4] = pow(train_data[i-1].m_x, 3);
        Y[i][1] = train_data[i-1].m_y;
    }

    output_matrix(X);

    return 0;
}