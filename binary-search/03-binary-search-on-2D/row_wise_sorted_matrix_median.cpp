#include <bits/stdc++.h>
using namespace std;

// Row wise sorted
// Given there will always be odd no of elements (so median is possible)

int findNumbersLessThanEqualTo(vector<vector<int>> &mat, int n, int m, int target)
{
    // Find numbers LTE in each row, and add them
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1, mid;
        while (low <= high)
        {
            mid = low + ((high - low) / 2);
            if (mat[i][mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        sum += low;
    }
    return sum;
}

int matrixMedian(vector<vector<int>> &mat)
{
    {
        int n = mat.size();
        int m = mat[0].size();
        // Range
        int low = INT_MAX, high = INT_MIN, mid;
        for (int i = 0; i < n; i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        int reqd = (n * m) / 2;

        while (low <= high)
        {
            mid = low + ((high - low) / 2);
            int numbersLTE = findNumbersLessThanEqualTo(mat, n, m, mid);
            if (numbersLTE <= reqd)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
    // TC: O(log(max-min) * nlogm)
    // SC: O(1)
}

int main()
{
    vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};

    // Brute: Store all elements into a new array, sort it, and find median

    // Optimal:
    cout << matrixMedian(mat);
}
// 1 3 5
// 2 6 9
// 3 6 9

// 1 2 3 3 5 6 6 9 9 (Given matrix)
// 1 2 3 4 5 6 7 7 8 (Numbers <= mat[i][j])

// Median will be -> First occurence where (number <= mat [i][j]) > (n*m)/2