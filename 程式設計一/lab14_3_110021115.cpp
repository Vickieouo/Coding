#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef struct coo_sparse_matrix_struct
{
    unsigned long rows;
    unsigned long cols;
    vector<unsigned long> row_ind;
    vector<unsigned long> col_ind;
    vector<long> val;
} coo_sparse_matrix;

typedef struct matrix_struct
{
    unsigned long rows;
    unsigned long cols;
    vector<vector<long>> val;
} matrix;

// void insert_coo_matrix_element(coo_sparse_matrix &coo_matrix, unsigned long row, unsigned long col, long val)
void sort_col_ind(coo_sparse_matrix &coo_matrix)
{
    for (int i = 0; i < coo_matrix.col_ind.size(); i++)
    {
        for (int j = i + 1; j < coo_matrix.col_ind.size(); j++)
        {
            if (coo_matrix.col_ind[i] > coo_matrix.col_ind[j])
            {
                swap(coo_matrix.col_ind[i], coo_matrix.col_ind[j]);
                swap(coo_matrix.row_ind[i], coo_matrix.row_ind[j]);
                swap(coo_matrix.val[i], coo_matrix.val[j]);
            }
        }
    }
}
void sort_row_ind(coo_sparse_matrix &coo_matrix)
{
    for (int i = 0; i < coo_matrix.row_ind.size(); i++)
    {
        for (int j = i + 1; j < coo_matrix.row_ind.size(); j++)
        {
            if (coo_matrix.row_ind[i] > coo_matrix.row_ind[j] ||
                (coo_matrix.row_ind[i] == coo_matrix.row_ind[j] &&
                 coo_matrix.col_ind[i] > coo_matrix.col_ind[j]))
            {
                swap(coo_matrix.row_ind[i], coo_matrix.row_ind[j]);
                swap(coo_matrix.col_ind[i], coo_matrix.col_ind[j]);
                swap(coo_matrix.val[i], coo_matrix.val[j]);
            }
        }
    }
}
void sort_coo_matrix(coo_sparse_matrix &coo_matrix)
{
    sort_col_ind(coo_matrix);
    sort_row_ind(coo_matrix);
}
void clean_up_input_buffer(char input_buffer[])
{
    for (int i = 0; input_buffer[i] != '\0'; i++)
    {
        input_buffer[i] = '\0';
    }
}
void parse_coo_matrix(coo_sparse_matrix &coo_matrix) //
{
    cin >> coo_matrix.rows;
    if (coo_matrix.rows <= 0)
    {
        cout << "Invalid matrix." << endl
             << endl;
        exit(0);
    }

    cin >> coo_matrix.cols;
    if (coo_matrix.cols <= 0)
    {
        cout << "Invalid matrix." << endl
             << endl;
        exit(0);
    }

    int elements;
    cin >> elements;
    if (elements < 0)
    {
        cout << "Invalid matrix." << endl
             << endl;
        exit(0);
    }

    unsigned long r, c;
    long v;
    for (int i = 0; i < elements; i++)
    {
        coo_matrix.row_ind.push_back(0);
        coo_matrix.col_ind.push_back(0);
        coo_matrix.val.push_back(0);
    }
    for (int i = 0; i < elements; i++)
    {
        cin >> r >> c >> v;
        if (r < 0 || r >= coo_matrix.rows || c < 0 || c >= coo_matrix.cols)
        {
            cout << "Invalid matrix." << endl;
            exit(0);
        }
        coo_matrix.row_ind[i] = r;
        coo_matrix.col_ind[i] = c;
        coo_matrix.val[i] = v;
    }

    for (int i = 0; i < coo_matrix.val.size(); i++)
    {
        if (coo_matrix.val[i] == 0)
        {
            coo_matrix.row_ind.erase(coo_matrix.row_ind.begin() + i);
            coo_matrix.col_ind.erase(coo_matrix.col_ind.begin() + i);
            coo_matrix.val.erase(coo_matrix.val.begin() + i);
        }
    }
    for (int i = 0; i < coo_matrix.row_ind.size(); i++)
    {
        for (int j = i + 1; j < coo_matrix.row_ind.size(); j++)
        {
            if (coo_matrix.row_ind[i] == coo_matrix.row_ind[j] && coo_matrix.col_ind[i] == coo_matrix.col_ind[j])
            {
                coo_matrix.row_ind.erase(coo_matrix.row_ind.begin() + i);
                coo_matrix.col_ind.erase(coo_matrix.col_ind.begin() + i);
                coo_matrix.val.erase(coo_matrix.val.begin() + i);
                j = i + 1;
            }
        }
    }

    sort_coo_matrix(coo_matrix);
}
void print_coo_matrix(coo_sparse_matrix &coo_matrix) //
{
    cout << coo_matrix.rows << endl
         << coo_matrix.cols << endl;
    for (int i = 0; i < coo_matrix.val.size(); i++)
    {
        cout << coo_matrix.row_ind[i] << " "
             << coo_matrix.col_ind[i] << " "
             << coo_matrix.val[i] << endl;
    }
}
matrix convert_coo_matrix_to_matrix(const coo_sparse_matrix &coo_matrix) //
{
    matrix m;
    vector<long> vec;
    for (int i = 0; i < coo_matrix.cols; i++)
    {
        vec.push_back(0);
    }
    m.rows = coo_matrix.rows;
    m.cols = coo_matrix.cols;
    unsigned long rowsize = coo_matrix.row_ind.size();
    unsigned long colsize = coo_matrix.col_ind.size();

    if (coo_matrix.row_ind.size() == 0)
    {
        for (int i = 0; i < m.rows; i++)
        {
            m.val.push_back(vec);
        }
        return m;
    }

    for (int i = 0; i < max(m.rows, rowsize); i++)
    {
        for (int j = 0; j < max(m.cols, colsize); j++)
        {
            if (i == coo_matrix.row_ind[j] && j < coo_matrix.col_ind.size())
            {
                vec[coo_matrix.col_ind[j]] = coo_matrix.val[j];
            }
        }
        m.val.push_back(vec);

        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j] != 0)
            {
                vec[j] = 0;
            }
        }
    }
    return m;
}
void print_matrix(const matrix &matrix) //
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            cout << matrix.val[i][j] << " ";
        }
        cout << endl;
    }
}
coo_sparse_matrix mult_coo_matrix(const coo_sparse_matrix &coo_matrix_M, const coo_sparse_matrix &coo_matrix_N)
{
    coo_sparse_matrix coo_matrix_P;
    coo_matrix_P.rows = coo_matrix_M.rows;
    coo_matrix_P.cols = coo_matrix_N.cols;

    for (int i = 0; i < coo_matrix_M.col_ind.size(); i++)
    {
        for (int j = 0; j < coo_matrix_N.row_ind.size(); j++)
        {
            if (coo_matrix_M.col_ind[i] == coo_matrix_N.row_ind[j])
            {
                coo_matrix_P.row_ind.push_back(coo_matrix_M.row_ind[i]);
                coo_matrix_P.col_ind.push_back(coo_matrix_N.col_ind[j]);
                coo_matrix_P.val.push_back(coo_matrix_M.val[i] * coo_matrix_N.val[j]);
            }
        }
    }

    sort_coo_matrix(coo_matrix_P);
    for (int i = 0; i < coo_matrix_P.val.size(); i++)
    {
        int j = i;
        while (coo_matrix_P.row_ind[j] == coo_matrix_P.row_ind[j + 1] && coo_matrix_P.col_ind[j] == coo_matrix_P.col_ind[j + 1] && j < coo_matrix_P.val.size() - 1)
        {
            coo_matrix_P.val[j] += coo_matrix_P.val[j + 1];
            coo_matrix_P.row_ind.erase(coo_matrix_P.row_ind.begin() + j + 1);
            coo_matrix_P.col_ind.erase(coo_matrix_P.col_ind.begin() + j + 1);
            coo_matrix_P.val.erase(coo_matrix_P.val.begin() + j + 1);
            j++;
        }
    }
    return coo_matrix_P;
}

int main()
{
    coo_sparse_matrix coo_matrix_M, coo_matrix_N, coo_matrix_P;
    cout << "Input COO matrix M:" << endl;
    parse_coo_matrix(coo_matrix_M);
    cout << "The COO matrix M is:" << endl;
    print_coo_matrix(coo_matrix_M);
    cout << "Input COO matrix N:" << endl;
    parse_coo_matrix(coo_matrix_N);
    cout << "The COO matrix N is:" << endl;
    print_coo_matrix(coo_matrix_N);
    if (coo_matrix_M.cols != coo_matrix_N.rows)
    {
        cout << "Invalid matrix." << endl
             << endl;
        return 0;
    }
    coo_matrix_P = mult_coo_matrix(coo_matrix_M, coo_matrix_N);
    cout << "The COO matrix P = M * N is:" << endl;
    print_coo_matrix(coo_matrix_P);
    matrix matrix_P = convert_coo_matrix_to_matrix(coo_matrix_P);
    cout << "The matrix P is:" << endl;
    print_matrix(matrix_P);
    return 0;
}
