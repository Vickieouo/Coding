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

void output_matrixT(vector<vector<double>> &B)
{
    vector<vector<double>> A; A = T(B);
    int n = A.size(), m = A[1].size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            cout << fixed << setprecision(4) << A[i][j] << " ";
        }
    }
}

int main()
{
    int n = 6;  // size of matrix A(n*n)
    vector<vector<double>> A(n+1, vector<double>(n+1)), b(n+1, vector<double>(2));
    vector<vector<double>> x(n+1, vector<double>(2)), r(n+1, vector<double>(2)), d(n+1, vector<double>(2)), delta(n+1, vector<double>(2));
    vector<double> Delta;

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
    cout << "b = ";
    for (int i = 1; i <= n; i++)
    {
        double a;
        cin >> a;
        b[i][1] = a;
    }
    cout << "\n";

    cout << "x0 = ["; output_matrixT(x); cout << "]^T\n";

    r = multi(A, x); r = add(r, c_multi(b, -1)); cout << "r0 = ["; output_matrixT(r); cout << "]^T\n";
    d = c_multi(r, -1); cout << "d0 = ["; output_matrixT(d); cout << "]^T\n";
    delta = multi(T(r), r); cout << "delta0 = " << setprecision(10) << delta[1][1] << "\n" << "\n";
    Delta.emplace_back(delta[1][1]);

    for (int m = 0; m < 50; m++)
    {
        d = c_multi(r, -1); cout << "d" << m << " = ["; output_matrixT(d); cout << "]^T\n";
        double l; l = multi(c_multi(T(d), -1), r)[1][1] / multi(multi(T(d), A), d)[1][1]; cout << "lambda" << m << " = " << l << "\n";        
        x = add(x, c_multi(d, l)); cout << "x" << m+1 << " = ["; output_matrixT(x); cout << "]^T\n";
        r = add(r, c_multi(multi(A, d), l)); cout << "r" << m+1 << " = ["; output_matrixT(r); cout << "]^T\n";

        cout << "√r" << m+1 << "^T*r" << m+1 << " = " << setprecision(10) << pow(multi(T(r), r)[1][1], 0.5) << "\n";
        cout << "\n";
        if (pow(multi(T(r), r)[1][1], 0.5) <= 5e-7) {return 0;}
    }

    return 0;
}