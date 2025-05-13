#include <bits/stdc++.h>
using namespace std;

// Each row and column is sorted
// Not straight forward a BS question, but elimination tactics are used

bool searchInMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    // Start either from (0,m-1) or (n-1,0) so that elimination is possible
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        if (mat[row][col] == target)
        {
            return true;
        }
        // Either eliminate a row or a column
        else if (target < mat[row][col])
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
    // TC: O(n+m)
}

int main()
{
    vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 25;

    // Brute: Iterate over each element -> TC: O(n*m)
    // Better: BS on each row -> TC: O(nlogm)

    // Optimal: Observation based
    cout << searchInMatrix(mat, target) << endl;
}

//  1   4   7   11   15
//  2   5   8   12   19
//  3   6   9   16   22
//  10  13  14  17   24
//  18  21  23  26   30