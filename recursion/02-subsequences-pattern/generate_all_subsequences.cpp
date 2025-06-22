#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

vector<vector<int>> generateAllSubsequences(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    // Power set size will be 2^n
    // 2^n = 1 << n
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> temp = {};
        for (int j = 0; j < n; j++)
        {
            // Take if set bit, else not
            if ((i & (1 << j)) != 0)
            {
                temp.push_back(nums[j]);
            }
        }
        res.push_back(temp);
    }
    return res;
    // TC: O(2^n * n)
    // SC: O(2^n * n) -> For answer
}

void generateAllSubsequences2(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp, int index)
{
    if (index == nums.size())
    {
        res.push_back(temp);
        return;
    }

    // Exclude the current element
    generateAllSubsequences2(nums, res, temp, index + 1);
    // Include the current element
    temp.push_back(nums[index]);
    generateAllSubsequences2(nums, res, temp, index + 1);
    temp.pop_back();
    // TC: O(2^n)
    // SC: O(2^n * n) -> For answer + O(n) -> Recursion stack space
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res;

    // Using bits logic
    res = generateAllSubsequences(nums);

    // Using recursion (Pick / Don't pick)
    res = {};
    vector<int> temp = {};
    generateAllSubsequences2(nums, res, temp, 0);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
Which one is optimal?
- Use bits for raw performance and when elements are distinct and there are no constraints.
- Use recursion when the problem has filters, duplicate handling, or side conditions.
*/

/*
0 -> 00
1 -> 01
2 -> 10
3 -> 11
4 -> 100
5 -> 101
6 -> 110
7 -> 111
8 -> 1000
*/