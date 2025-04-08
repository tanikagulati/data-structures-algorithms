#include <bits/stdc++.h>
using namespace std;

void spiralMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int j = 0;

    vector<int> res;
    for (int i = 0; i <= n / 2; i++)
    {
        for (int j = i; j < m - i; j++)
        {
            res.push_back(matrix[i][j]);
        }
        for (int j = i + 1; j < n - i; j++)
        {
            res.push_back(matrix[j][m - i - 1]);
        }
        for (int j = m - i - 2; j >= i; j--)
        {
            res.push_back(matrix[n - i - 1][j]);
        }
        for (int j = n - i - 2; j > i; j--)
        {
            res.push_back(matrix[j][i]);
        }
    }
    for (auto i : res)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5}, {16, 17, 18, 19, 6}, {15, 24, 25, 20, 7}, {14, 23, 22, 21, 8}, {13, 12, 11, 10, 9}};
    // 1  2  3  4  5
    // 16 17 18 19 6
    // 15 24 25 20 7
    // 14 23 22 21 8
    // 13 12 11 10 9

    spiralMatrix(matrix);
}