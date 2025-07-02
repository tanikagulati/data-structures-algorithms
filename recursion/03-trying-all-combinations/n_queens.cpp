#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &temp)
{
    int r = row, c = col;
    // Upper diagonal
    while (row >= 0 && col >= 0)
    {
        if (temp[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    // Left
    row = r, col = c;
    while (col >= 0)
    {
        if (temp[row][col] == 'Q')
            return false;
        col--;
    }
    // Lower diagonal
    row = r, col = c;
    while (row < temp.size() && col >= 0)
    {
        if (temp[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solveBrute(int col, int n, vector<string> &temp, vector<vector<string>> &res)
{
    if (col == n)
    {
        res.push_back(temp);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, temp))
        {
            temp[row][col] = 'Q';
            solveBrute(col + 1, n, temp, res);
            temp[row][col] = '.';
        }
    }
}

void solveOptimal(int col, int n, vector<string> &temp, vector<vector<string>> &res,
                  vector<bool> &leftRow, vector<bool> &lowerDiagonal, vector<bool> &upperDiagonal)
{
    if (col == n)
    {
        res.push_back(temp);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] != 1 && lowerDiagonal[row + col] != 1 && upperDiagonal[col - row + n - 1] != 1)
        {
            temp[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[col - row + n - 1] = 1;
            solveOptimal(col + 1, n, temp, res, leftRow, lowerDiagonal, upperDiagonal);
            temp[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[col - row + n - 1] = 0;
        }
    }
}

int main()
{
    int n = 2;
    vector<vector<string>> res;
    vector<string> temp(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        temp[i] = s;

    // Brute:
    // solveBrute(0, n, temp, res);

    // Optimal:
    vector<bool> leftRow(n);
    vector<bool> lowerDiagonal((2 * n) - 1);
    vector<bool> upperDiagonal((2 * n) - 1);

    solveOptimal(0, n, temp, res, leftRow, lowerDiagonal, upperDiagonal);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}