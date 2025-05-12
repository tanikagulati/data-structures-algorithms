#include <bits/stdc++.h>
using namespace std;

vector<int> findMax1sRowBrute(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int maxi = 0;
    int maxiRow = 0;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
                cnt++;
        }
        if (cnt > maxi)
        {
            maxi = cnt;
            maxiRow = i;
        }
    }
    return {maxiRow, maxi};
    // TC: O(n*m)
}

vector<int> findMax1sRowOptimal(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int maxi = 0;
    int maxiRow = -1;
    int low = 0, high = m - 1, mid;

    for (int i = 0; i < n; i++)
    {
        low = 0, high = m - 1;
        while (low <= high)
        {
            mid = low + ((high - low) / 2);
            if (mat[i][mid] == 1)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        int numOf1s = m - low;
        if (numOf1s > maxi)
        {
            maxi = numOf1s;
            maxiRow = i;
        }
    }
    return {maxiRow, maxi};
    // TC: O(nlogm)
}

int main()
{
    vector<vector<int>> mat = {{0, 0, 1}, {0, 1, 1}};

    // Brute
    vector<int> ans = findMax1sRowBrute(mat);
    cout << ans[0] << " " << ans[1] << endl;

    // Optimal
    ans = findMax1sRowOptimal(mat);
    cout << ans[0] << " " << ans[1] << endl;
}