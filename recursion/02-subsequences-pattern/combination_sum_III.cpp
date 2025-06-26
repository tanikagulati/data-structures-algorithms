#include <bits/stdc++.h>
using namespace std;

// Find all valid (and distinct) combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.

void combinationSum3(int k, int sum, int i, vector<int> &temp, vector<vector<int>> &res)
{
    if (temp.size() == k)
    {
        if (sum == 0)
        {
            res.push_back(temp);
        }
        return;
    }
    for (int j = i; j <= 9; j++)
    {
        if (j > sum)
        {
            break;
        }
        temp.push_back(j);
        combinationSum3(k, sum - j, j + 1, temp, res);
        temp.pop_back();
    }
    // TC: O(C(9,k)) -> combinations of size k from 1 to 9 + O(k*x)
    // SC: O(k * x) For result + O(k) Recursion stack space
}

int main()
{
    int k = 3;   // reqd valid combination length
    int sum = 7; // reqd sum

    vector<int> temp;
    vector<vector<int>> res;

    combinationSum3(k, sum, 1, temp, res);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}