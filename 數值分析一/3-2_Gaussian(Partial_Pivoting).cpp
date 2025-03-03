#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void output_matrix(vector<vector<double>> &A)
{
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cout << fixed << setprecision(4) << A[i][j] << " ";
        }
        cout << "\n";
    }
}

double find_max_value(vector<vector<double>> &A, int i, int n)
{
    double v = abs(A[1][i]);
    for (int j = i; j <= n; j++)
    {
        if (v < abs(A[j][i]))
        {
            v = abs(A[j][i]);
        }
    }
    return v;
}

int find_max_index(vector<vector<double>> &A, int i, int n)
{
    double v = abs(A[1][i]); int d = i;
    for (int j = i; j <= n; j++)
    {
        if (v < abs(A[j][i]))
        {
            v = abs(A[j][i]);
            d = j;
        }
    }
    return d;
}

double find_max_valueS(vector<vector<double>> &A, int i, int n)
{
    double v = abs(A[i][1]);
    for (int j = i; j <= n; j++)
    {
        if (v < abs(A[i][j]))
        {
            v = abs(A[i][j]);
        }
    }
    return v;
}

double find_max_valueP(vector<double> &P, int i, int n)
{
    double v = abs(P[1]);
    for (int j = i; j <= n; j++)
    {
        if (v < abs(P[j]))
        {
            v = abs(P[j]);
        }
    }
    return v;
}

int find_max_indexP(vector<double> &P, int i, int n)
{
    double v = abs(P[1]); int d = i;
    for (int j = i; j <= n; j++)
    {
        if (v < abs(P[j]))
        {
            v = abs(P[j]);
            d = j;
        }
    }
    return d;
}

int main()
{
    int n = 5;  // size of matrix A(n*n)
    vector<vector<double>> A(n+1, vector<double>(n+2));
    vector<double> X(n+1);

    cout << "A|b = \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n+1; j++)
        {
            double a;
            cin >> a;
            A[i][j] = a;
        }
    }
    cout << "\n";

    int count = 0;
    for (int pass = 1; pass <= n-1; pass++)
    {
        double M = find_max_value(A, pass, n);  
        int j = find_max_index(A, pass, n);
        if (j > pass)
        {
            swap(A[pass], A[j]);
        }

        for (int row = pass+1; row <= n; row++)
        {
            double m;
            m = -A[row][pass]/A[pass][pass];
            A[row][pass] = 0;
            count++;
            for (int col = pass+1; col <= n+1; col++)
            {
                A[row][col] = A[row][col] + m*A[pass][col];
                count++; count++;
            }
        }
        output_matrix(A);
        cout << "\n";
    }

    X[n] = A[n][n+1]/A[n][n];
    count++;
    for (int row = n-1; row > 0; row--)
    {
        double sum;
        sum = A[row][n+1];
        for (int col = row+1; col <= n; col++)
        {
            sum = sum - A[row][col]*X[col];
            count++; count++;
        }
        X[row] = sum/A[row][row];
        count++;
    }

    cout << "X = [" << fixed << setprecision(4) << X[1];
    for (int i = 2; i <= n; i++)
    {
        // cout << "x" << i << " = " << X[i] << "\n";
        cout << ", " << fixed << setprecision(4) << X[i];
    }
    cout << "]\n";

    return 0;
}