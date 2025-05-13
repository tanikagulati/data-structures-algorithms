#include <bits/stdc++.h>
using namespace std;

// Given: No adjacent element is equal
// Peak = greater than all adjacent elements (top, bottom, left, right)

int findMaxElementRow(vector<vector<int>> &mat, int n, int m, int mid)
{
    int maxi = -1, maxInd = -1;
    for (int i = 0; i < n; i++)
    {
        if (maxi < mat[i][mid])
        {
            maxi = mat[i][mid];
            maxInd = i;
        }
    }
    return maxInd;
}

vector<int> findPeakElement(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m - 1, mid;
    // Column binary search
    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        int maxElRow = findMaxElementRow(mat, n, m, mid);
        int left = mid - 1 < 0 ? -1 : mat[maxElRow][mid - 1];
        int right = mid + 1 == m ? -1 : mat[maxElRow][mid + 1];
        if (mat[maxElRow][mid] > left && mat[maxElRow][mid] > right)
        {
            return {maxElRow, mid};
        }
        else if (mat[maxElRow][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
    // TC: O(nlogm)
}

int main()
{
    vector<vector<int>> mat = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    vector<int> ans = findPeakElement(mat);
    cout << ans[0] << " " << ans[1] << endl;
}

// 10 20 15
// 21 30 14
// 7  16 32