#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void output_matrix(vector<vector<double>> A)
{
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
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

int main()
{
    int n = 3;  // size of matrix A(n*n)
    vector<vector<double>> A(n+1, vector<double>(n+1)), L(n+1, vector<double>(n+1)), U(n+1, vector<double>(n+1));
    vector<double> X(n+1);
    vector<vector<double>> b(n+1, vector<double>(2));

    cout << "A = \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double a;
            cin >> a;
            A[i][j] = a;
            U[i][j] = a;
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

    vector<int> S(n+1), R(n+1);
    for (int a = 1; a <= n; a++)
    {
        double s = find_max_valueS(A, a, n);
        S[a] = s;
    }
    for (int r = 1; r <= n; r++)
    {
        R[r] = r;
    }

    for (int pass = 1; pass <= n-1; pass++)
    {
        vector<double> P(n+1);
        for (int k = pass; k <= n; k++)
        {
            P[k] = abs(U[R[k]][pass] / S[R[k]]);
        }
        double M = find_max_valueP(P, pass, n);  
        int j = find_max_indexP(P, pass, n);
        if (j > pass)
        {
            swap(U[pass], U[j]);
            swap(L[pass], L[j]);
            swap(R[pass], R[j]);
        }

        for (int row = pass+1; row <= n; row++)
        {
            double m;
            m = -U[row][pass]/U[pass][pass];
            U[row][pass] = 0;
            for (int col = pass+1; col <= n; col++)
            {
                U[row][col] = U[row][col] + m*U[pass][col];
            }
            L[row][pass] = -1*m;
        }
        // output_matrix(U);

        // cout << "r = [" << R[1];
        // for (int i = 2; i <= n; i++)
        // {
        //     cout << ", " << R[i];
        // }
        // cout << "]\n" << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        L[i][i] = 1;
    }

    cout << "L = \n"; output_matrix(L); cout << "\n";
    cout << "U = \n"; output_matrix(U); cout << "\n";
    // cout << "LU = \n"; output_matrix(multi(L, U)); cout << "\n";
    // cout << "A = \n"; output_matrix(A); cout << "\n";

    cout << "r = [" << R[1];
    for (int i = 2; i <= n; i++)
    {
        cout << ", " << R[i];
    }
    cout << "]\n" << "\n";

    vector<vector<double>> P(n+1, vector<double>(n+1));
    for (int i = 1; i <= n; i++)
    {
        P[i][R[i]] = 1;
    }
    // cout << "P = \n"; output_matrix(P); cout << "\n";

    X[n] = A[n][n+1]/A[n][n];
    for (int row = n-1; row > 0; row--)
    {
        double sum;
        sum = A[row][n+1];
        for (int col = row+1; col <= n; col++)
        {
            sum = sum - A[row][col]*X[col];
        }
        X[row] = sum/A[row][row];
    }

    // cout << "X = [" << fixed << setprecision(4) << X[1];
    // for (int i = 2; i <= n; i++)
    // {
    //     // cout << "x" << i << " = " << X[i] << "\n";
    //     cout << ", " << fixed << setprecision(4) << X[i];
    // }
    // cout << "]\n";

    return 0;
}