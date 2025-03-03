#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void output_matrix(vector<vector<double>> &A)
{
    int n = A.size(), m = A[1].size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
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

const vector<vector<double>> add(vector<vector<double>> A, vector<vector<double>> B)
{
    vector<vector<double>> add(A.size(), vector<double>(A[1].size()));
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 1; j < A[1].size(); j++)
        {
            add[i][j] = A[i][j] + B[i][j];
        }
    }
    return add;
}

const vector<vector<double>> c_multi(vector<vector<double>> A, double c)
{
    vector<vector<double>> cmul(A.size(), vector<double>(A[1].size()));
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 1; j < A[1].size(); j++)
        {
            cmul[i][j] = A[i][j] * c;
        }
    }
    return cmul;
}

const vector<vector<double>> T(vector<vector<double>> A)
{
    vector<vector<double>> AT(A[1].size(), vector<double>(A.size()));
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 1; j < A[1].size(); j++)
        {
            AT[j][i] = A[i][j];
        }
    }
    return AT;
}

void output_matrixT(vector<vector<double>> &B)
{
    vector<vector<double>> A; A = T(B);
    int n = A.size(), m = A[1].size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
    }
}

double norm(vector<vector<double>> &A)
{
    int n = A.size(), m = A[1].size();
    double N = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (N < abs(A[i][j]))
            {
                N = abs(A[i][j]);
            }
        }
    }
    return N;
}

int main()
{
    int n = 4;  // size of matrix A(n*n)
    vector<vector<double>> A(n+1, vector<double>(n+1));
    vector<vector<double>> x(n+1, vector<double>(2)), y(n+1, vector<double>(2)), l(n+1, vector<double>(2));

    cout << "A = \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double a;
            cin >> a;
            A[i][j] = a;
        }
    }
    cout << "\n";
    cout << "x0 = ";
    for (int i = 1; i <= n; i++)
    {
        double a;
        cin >> a;
        x[i][1] = a;
    }
    cout << "\n";
    
    double p = norm(x);
    cout << "p0 = " << fixed << setprecision(10) << p << "\n";

    for (int i = 1; i <= 30; i++)
    {
        y = multi(A, x);
        cout << "y" << i << " = ["; output_matrixT(y); cout << "]^T\n";
        p = norm(y); cout << "p" << i+1 << " = " << fixed << setprecision(10) << p << "\n"; p = 1/p;
        x = c_multi(y, p);

        cout << "x" << i+1 << " = ["; output_matrixT(x); cout << "]^T\n";
        cout << "\n";

        p = 1/p;
        if (abs(p-12) < 5e-5)
        {
            return 0;
        }
    }

    return 0;
}