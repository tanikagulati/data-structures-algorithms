#include <bits/stdc++.h>
using namespace std;

void combinationSum2Brute(vector<int> &candidates, int target, int index, vector<int> &temp, set<vector<int>> &res)
{
    if (index == candidates.size())
    {
        if (target == 0)
        {
            sort(temp.begin(), temp.end());
            res.insert(temp);
        }
        return;
    }
    // Pick
    if (candidates[index] <= target)
    {
        temp.push_back(candidates[index]);
        combinationSum2Brute(candidates, target - candidates[index], index + 1, temp, res);
        temp.pop_back();
    }
    // Don't pick
    combinationSum2Brute(candidates, target, index + 1, temp, res);
}

void combinationSum2Optimal(vector<int> &candidates, int target, int index, vector<int> &temp, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }
    for (int i = index; i < candidates.size() - 1; i++)
    {
        if (i > index && candidates[i] == candidates[i - 1]) // For unique combinations
            continue;

        if (candidates[i] > target)
            break;

        temp.push_back(candidates[i]);
        combinationSum2Optimal(candidates, target - candidates[i], i + 1, temp, res);
        temp.pop_back();
    }
    // TC: O(2^n * k) k = avg length of combinations
    // SC: O(k * x)
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    set<vector<int>> res;
    vector<int> temp;

    // Brute: (using set for result and sort before adding to result)
    // combinationSum2Brute(candidates, target, 0, temp, res);

    // Optimal:
    vector<vector<int>> res2;

    sort(candidates.begin(), candidates.end());
    combinationSum2Optimal(candidates, target, 0, temp, res2);

    for (auto i : res2)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}