#include <bits/stdc++.h>
using namespace std;

bool searchIn2DBetter(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        if (target > mat[i][m - 1])
        {
            continue; // Skip searching
        }
        int low = 0, high = m - 1, mid;
        while (low <= high)
        {
            mid = low + ((high - low) / 2);
            if (mat[i][mid] == target)
            {
                return true;
            }
            else if (mat[i][mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
    // TC: O((n-1) + logm)
}

bool searchInGivenRow(vector<int> &row, int target)
{
    int m = row.size();
    int low = 0, high = m - 1, mid;
    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (row[mid] == target)
        {
            return true;
        }
        else if (row[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

bool searchIn2DOptimal1(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (target >= mat[mid][0] && target <= mat[mid][m - 1])
        {
            return searchInGivenRow(mat[mid], target);
        }
        else if (target < mat[mid][0])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
    // TC: O(logn + logm) = O(log n*m)
}

bool searchIn2DOptimal2(vector<vector<int>> &mat, int target)
{
    // Flatten matrix into a 1D array hypothetically
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = (n * m) - 1, mid;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        int row = mid / m;
        int col = mid % m;
        if (mat[row][col] == target)
        {
            return true;
        }
        else if (mat[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
    // TC: O(log n*m)
}

int main()
{
    vector<vector<int>> mat = {{2, 3, 4}, {6, 7, 9}, {20, 24, 27}};
    int target = 2;

    // Brute: Iterate all elements -> O(n*m)

    cout << searchIn2DBetter(mat, target) << endl;

    cout << searchIn2DOptimal1(mat, target) << endl;

    cout << searchIn2DOptimal2(mat, target) << endl;
}