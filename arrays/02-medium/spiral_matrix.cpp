#include <bits/stdc++.h>
using namespace std;

void spiralmat(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    vector<int> res;

    while (left <= right && top <= bottom)
    {
        // move right
        for (int i = left; i <= right; i++)
        {
            res.push_back(mat[top][i]);
        }
        top++;
        // move bottom
        for (int i = top; i <= bottom; i++)
        {
            res.push_back(mat[i][right]);
        }
        right--;
        // move left
        if (top <= bottom) // Check because top was updated after while check (to handle horizontal line)
        {
            for (int i = right; i >= left; i--)
            {
                res.push_back(mat[bottom][i]);
            }
        }

        bottom--;
        // move top
        if (left <= right) // Check because right was updated afetr while check (to handle vertical line)
        {
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(mat[i][left]);
            }
        }
        left++;
    }

    for (auto i : res)
    {
        cout << i << " ";
    }

    // TC: O(m*n)
    // SC: O(m*n) // To save result
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4, 5}, {16, 17, 18, 19, 6}, {15, 24, 25, 20, 7}, {14, 23, 22, 21, 8}, {13, 12, 11, 10, 9}};
    // 1  2  3  4  5
    // 16 17 18 19 6
    // 15 24 25 20 7
    // 14 23 22 21 8
    // 13 12 11 10 9

    spiralmat(mat);
}