#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-consecutive-ones-iii/description/

// Problem can be framed as - Longest subarray with at most of k 0's

int maxConsecutiveOnesBrute(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int len = 0, zeros = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
                zeros++;
            if (zeros > k)
                break;
            len = j - i + 1;
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
    // TC: O(n^2)
    // SC: O(1)
}

int maxConsecutiveOnesBetter(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = 0;
    int len = 0, maxLen = 0;
    int zeros = 0;
    while (r < n)
    {
        if (nums[r] == 0)
            zeros++;
        while (zeros > k)
        {
            if (nums[l] == 0)
                zeros--;
            l++;
        }
        len = r - l + 1;
        maxLen = max(maxLen, len);
        r++;
    }
    return maxLen;
    // TC: O(2n)
    // SC: O(1)
}

int maxConsecutiveOnesOptimal(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = 0;
    int len = 0, maxLen = 0;
    int zeros = 0;
    while (r < n)
    {
        if (nums[r] == 0)
            zeros++;
        if (zeros > k)
        {
            if (nums[l] == 0)
                zeros--;
            l++;
        }
        if (zeros <= k)
        {
            len = r - l + 1;
            maxLen = max(maxLen, len);
        }
        r++;
    }
    return maxLen;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    cout << maxConsecutiveOnesBrute(nums, k) << endl;

    cout << maxConsecutiveOnesBetter(nums, k) << endl;

    cout << maxConsecutiveOnesOptimal(nums, k) << endl;
}