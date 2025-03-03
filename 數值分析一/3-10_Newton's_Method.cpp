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
            cout << fixed << setprecision(4) << A[i][j] << " ";
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

const vector<vector<double>> inv(vector<vector<double>> A)
{
    vector<vector<double>> Ai(3, vector<double>(3));
    double det; det = A[1][1]*A[2][2] - A[1][2]*A[2][1];
    Ai[1][1] = A[2][2] / det; Ai[1][2] = -A[1][2] / det;
    Ai[2][2] = A[1][1] / det; Ai[2][1] = -A[2][1] / det;
    return Ai;
}

void output_matrixT(vector<vector<double>> &B)
{
    vector<vector<double>> A; A = T(B);
    int n = A.size(), m = A[1].size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            cout << fixed << setprecision(10) << A[i][j] << " ";
        }
    }
}

const vector<vector<double>> F(vector<vector<double>> x)
{
    vector<vector<double>> F(3, vector<double>(2)); double x1 = x[1][1], x2 = x[2][1];
    F[1][1] = x2; F[1][1] -= x1/3;
    F[2][1] = pow(x1, 2); F[2][1] /= (1 + pow(x1, 2)); F[2][1] -= x2/2;
    return F;
}

const vector<vector<double>> J(vector<vector<double>> x)
{
    vector<vector<double>> J(3, vector<double>(3)); double x1 = x[1][1], x2 = x[2][1];
    J[1][1] = -0.33333333333333333; J[1][2] = 1;
    J[2][1] = 2*x1 / pow((1 + pow(x1, 2)), 2); J[2][2] = -0.5;
    return J;
}

int main()
{
    int n = 2;  // size of matrix A(n*n)
    vector<vector<double>> v(3, vector<double>(2)), x(3, vector<double>(2)), f(3, vector<double>(2)), j(3, vector<double>(3));

    cout << "x0 = ";
    for (int i = 1; i <= n; i++)
    {
        double a;
        cin >> a;
        x[i][1] = a;
    }
    cout << "\n";

    for (int m = 0; m < 30; m++)
    {
        v = multi(c_multi((inv(J(x))), -1), F(x));
        cout << "v" << m << " = ["; output_matrixT(v); cout << "]^T\n";
        x = add(x, v);
        cout << "x" << m+1 << " = ["; output_matrixT(x); cout << "]^T\n";
        cout << "\n";
    }

    if (abs(v[1][1]) < 5e-7 || abs(v[2][1]) < 5e-7) {return 0;}

    return 0;
}