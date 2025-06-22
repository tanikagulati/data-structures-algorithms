#include <bits/stdc++.h>
using namespace std;

// Given an array and target sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals k.

bool checkSubsequenceWithSumK(vector<int> &nums, int target, int index, int sum)
{
    if (sum > target) // Optimization (only in case of positive integer array)
        return false;

    if (index == nums.size())
    {
        if (sum == target)
            return true;
        else
            return false;
    }

    sum += nums[index];
    if (checkSubsequenceWithSumK(nums, target, index + 1, sum) == true)
        return true;
    sum -= nums[index];

    if (checkSubsequenceWithSumK(nums, target, index + 1, sum) == true)
        return true;

    return false;
    // TC: O(2^n)
    // SC: O(n)
}

int main()
{
    vector<int> nums = {1, 2, 1};
    int target = 5;
    cout << checkSubsequenceWithSumK(nums, target, 0, 0) << endl;
}