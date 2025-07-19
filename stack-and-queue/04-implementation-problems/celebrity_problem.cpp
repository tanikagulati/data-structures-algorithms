#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

int celebrityProblemBrute(vector<vector<int>> &mat)
{
    // Celebrity = All know him, he knows none
    int n = mat.size();
    vector<int> knowsMe(n);
    vector<int> iKnow(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                knowsMe[j]++;
                iKnow[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (knowsMe[i] == n - 1 && iKnow[i] == 0)
            return i;
    }
    return -1;
    // TC: O(n^2 + n)
    // SC: O(2n)
}

int celebrityProblemOptimal(vector<vector<int>> &mat)
{
    // Two pointers
    {
        int n = mat.size();
        int top = 0, bottom = n - 1;
        while (top < bottom)
        {
            if (mat[top][bottom] == 1)
            {
                top++;
            }
            else if (mat[bottom][top] == 1)
            {
                bottom--;
            }
            else
            {
                top++;
                bottom--;
            }
        }
        if (top > bottom)
            return -1;
        for (int i = 0; i < n; i++)
        {
            if (i == top)
                continue;
            if (mat[top][i] == 0 && mat[i][top] == 1)
                continue;
            else
                return -1;
        }
        return top;
        // TC: O(2n)
        // SC: O(1)
    }
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

    cout << celebrityProblemBrute(mat) << endl;

    cout << celebrityProblemOptimal(mat) << endl;
}