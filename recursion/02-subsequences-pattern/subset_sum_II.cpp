#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

void subsetSum2(vector<int> &v, int index, vector<int> &temp, vector<vector<int>> &res)
{
    res.push_back(temp);

    // Base case not required, as for loop will handle it
    // if (index == v.size())
    // {
    //     return;
    // }

    for (int i = index; i < v.size(); i++)
    {
        if (i > index && v[i] == v[i - 1])
        {
            continue;
        }
        temp.push_back(v[i]);
        subsetSum2(v, i + 1, temp, res);
        temp.pop_back();
    }
    // TC: O(2^n * k) -> k = avg length
    // SC: O(2^n * k) For result + O(n) Recursion stack space
}

int main()
{
    vector<int> v = {1, 2, 2};
    vector<int> temp;
    vector<vector<int>> res;

    // Sort for managing duplicates in recursion
    sort(v.begin(), v.end()); // Additional nlogn
    subsetSum2(v, 0, temp, res);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}