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
    int n = 5;  // size of matrix A(n*n)
    double q = 3;
    vector<vector<double>> A(n+1, vector<double>(n+1));
    vector<vector<double>> x(n+1, vector<double>(2)), y(n+1, vector<double>(2)), l(n+1, vector<double>(2));

    // Compute (A-qI)^-1 !!!!!!!!!!!!!!!!!!!!!!!!!!
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

    double xtx = multi(T(x), x)[1][1];
    // cout << "x0Tx0 = " << fixed << setprecision(10) << xtx << "\n";

    for (int i = 1; i <= 30; i++)
    {
        y = multi(A, x);
        // cout << "y" << i << " = ["; output_matrixT(y); cout << "]^T\n";
        double l = multi(T(x), y)[1][1]; // cout << "l" << i+1 << " = " << fixed << setprecision(10) << l << "\n";
        l = 1/l; cout << "q+1/l" << i+1 << " = " << fixed << setprecision(10) << q+l << "\n";
        
        double k = multi(T(y), y)[1][1]; k = 1/k;
        x = c_multi(y, pow(k, 0.5));

        cout << "x" << i+1 << " = ["; output_matrixT(x); cout << "]^T\n";
        cout << "\n";

        if (abs(l-12) < 5e-5)
        {
            return 0;
        }
    }

    return 0;
}