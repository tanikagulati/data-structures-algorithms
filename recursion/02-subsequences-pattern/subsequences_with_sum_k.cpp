#include <bits/stdc++.h>
using namespace std;

// Given an array of non-negative integers and an integer target, count all subsets of the array whose sum is equal to target.

int count(vector<int> &nums, int target, int index, int sum)
{
    if (sum > target) // Optimization (only in case of positive integer array)
        return 0;

    if (index == nums.size())
    {
        if (sum == target)
            return 1;
        else
            return 0;
    }

    sum += nums[index];
    int l = count(nums, target, index + 1, sum);
    sum -= nums[index];
    int r = count(nums, target, index + 1, sum);
    return l + r;
    // TC: O(2^n)
    // SC: O(n)
}

int main()
{
    vector<int> nums = {1, 2, 1};
    int target = 2;
    cout << count(nums, target, 0, 0) << endl;
}