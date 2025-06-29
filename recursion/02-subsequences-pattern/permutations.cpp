#include <bits/stdc++.h>
using namespace std;

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

void permutationsBrute(vector<int> &nums, vector<bool> &freq, vector<int> &temp, vector<vector<int>> &res)
{
    if (temp.size() == nums.size())
    {
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < freq.size(); i++)
    {
        if (!freq[i])
        {
            temp.push_back(nums[i]);
            freq[i] = 1;
            permutationsBrute(nums, freq, temp, res);
            temp.pop_back();
            freq[i] = 0;
        }
    }
    // TC: O(n!*n)
    // SC: O(n!) For res + O(n) For freq + O(n) For temp + O(n) Rec stack space
}

void permutationsOptimal(vector<int> &nums, int index, vector<vector<int>> &res)
{
    if (index == nums.size())
    {
        res.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        permutationsOptimal(nums, index + 1, res);
        swap(nums[index], nums[i]);
    }
    // TC: O(n! * n)
    // SC: O(n!) For res + O(n) Rec stack space
}

int main()
{
    vector<int> nums = {1, 2, 3};
    // No of possible permutations = n!

    vector<bool> freq(nums.size());
    vector<int> temp;
    vector<vector<int>> res;

    // permutationsBrute(nums, freq, temp, res);

    permutationsOptimal(nums, 0, res);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}