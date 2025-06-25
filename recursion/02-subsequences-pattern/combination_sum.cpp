#include <bits/stdc++.h>
using namespace std;

// Given an array of distinct integers candidates and a target integer, return a list of all unique combinations of candidates where the chosen numbers sum to target.
// The same number may be chosen from candidates an unlimited number of times.

void combinationSum(vector<int> &candidates, int target, int index, vector<int> &temp, vector<vector<int>> &res)
{
    // target == 0 can be a base case, but this is the generalized version (avoiding too many conditions)
    if (index == candidates.size())
    {
        if (target == 0)
        {
            res.push_back(temp);
        }
        return;
    }
    // Pick
    if (candidates[index] <= target)
    {
        temp.push_back(candidates[index]);
        combinationSum(candidates, target - candidates[index], index, temp, res);
        temp.pop_back();
    }
    // Don't pick
    combinationSum(candidates, target, index + 1, temp, res);

    // TC: O(2^t + (K*k))
    // where 2^t = estimate no of combinations (worst case),
    // K = no of valid combinations, k = avg length of valid combination
    // SC: O(t*K) -> For result + O(t) -> Recursion stack space
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res;
    vector<int> temp = {};

    combinationSum(candidates, target, 0, temp, res);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}