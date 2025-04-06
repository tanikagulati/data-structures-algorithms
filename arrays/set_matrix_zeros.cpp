#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &v)
{
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void markRowAndColumn(vector<vector<int>> &v, int row, int col)
{
    int n = v.size();
    int m = v[0].size();

    for (int j = 0; j < m; j++)
    {
        if (v[row][j] != 0)
        {
            v[row][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i][col] != 0)
        {
            v[i][col] = -1;
        }
    }
    // TC: O(n+m)
}

void setMatrixZerosBrute(vector<vector<int>> v)
{
    int n = v.size();
    int m = v[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                markRowAndColumn(v, i, j);
            }
        }
    }

    // convert all -1's to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == -1)
            {
                v[i][j] = 0;
            }
        }
    }

    printMatrix(v);

    // TC: O(n*m) * O(n+m) ~ O(n^3)
    // SC: O(1)
}

void setMatrixZerosBetter(vector<vector<int>> v)
{
    int n = v.size();
    int m = v[0].size();

    vector<int> rows(n);
    vector<int> cols(m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rows[i] == 1 || cols[j] == 1)
            {
                v[i][j] = 0;
            }
        }
    }

    printMatrix(v);

    // TC: O(n*m)
    // SC: O(n+m)
}

void setMatrixZerosOptimal(vector<vector<int>> v)
{
    // To optimize space complexity -> Mark in col[0] and row[0] instead of separate arrays

    int n = v.size();
    int m = v[0].size();

    int col0 = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = 0;

                if (j == 0)
                {
                    col0 = 0;
                }
                else
                {
                    v[0][j] = 0;
                }
            }
        }
    }

    // First, convert matrix 1 to n and 1 to m based on 0th row and 0th column
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][0] == 0 || v[0][j] == 0)
            {
                v[i][j] = 0;
            }
        }
    }

    // First iterate 0th row, because it depends upon v[0][0]
    if (v[0][0] == 0)
    {
        for (int j = 1; j < m; j++)
        {
            v[0][j] = 0;
        }
    }

    // Then, 0th column
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            v[i][0] = 0;
        }
    }

    printMatrix(v);

    // TC: O(n*m)
    // SC: O(1)
}

int main()
{
    vector<vector<int>> v = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    // 0 1 2 0
    // 3 4 5 2
    // 1 3 1 5

    setMatrixZerosBrute(v);

    setMatrixZerosBetter(v);

    setMatrixZerosOptimal(v);
}