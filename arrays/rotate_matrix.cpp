#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &matrix)
{
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void rotateMatrixBy90DBrute(vector<vector<int>> &matrix)
{
    // Create another matrix and place every element at its correct place
    // TC: O(n^2)
    // SC: O(n^2)
}

void rotateMatrixBy90DOptimal(vector<vector<int>> &matrix)
{
    // Transpose and then reverse
    int n = matrix.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    printMatrix(matrix);

    // TC: O(n^2) + O(n*n/2)
    // SC: O(1)
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // 1 2 3 0
    // 4 5 6 0
    // 7 8 9 0
    // 7 6 3 9
    rotateMatrixBy90DBrute(matrix);

    rotateMatrixBy90DOptimal(matrix);
}