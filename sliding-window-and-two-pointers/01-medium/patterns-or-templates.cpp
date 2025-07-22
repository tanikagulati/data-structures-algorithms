#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = k - 1;
    int sum = 0;

    for (int i = l; i <= r; i++)
    {
        sum += nums[i];
    }

    int maxSum = sum;
    while (r < n - 1)
    {
        sum -= nums[l];
        l++;
        r++;
        sum += nums[r];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
    // TC: O(n)
    // SC: O(1)
}

int longestSubarrayBrute(vector<int> &nums, int k)
{
    // Generate all subarrays
    int maxLen = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum <= k)
                maxLen = max(maxLen, j - i + 1);
            else
                break;
        }
    }
    return maxLen;
    // TC: O(n^2)
    // SC: O(1)
}

int main()
{
    // Pattern 1: Constant window (v.easy)
    // Eg. Maximum subarray sum having window size k
    vector<int> nums = {-1, 2, 3, 3, 4, 5, -1};
    int k = 4;
    cout << subarraySum(nums, 4) << endl;

    // Pattern 2: Longest subarray/substring where <condition> (imp)
    // Eg. Longest subarray with sum <= k

    // Brute:
    cout << longestSubarrayBrute(nums, k) << endl;

    // Better:
}