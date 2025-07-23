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

int longestSubarrayBetter(vector<int> &nums, int k)
{
    // Two pointers (expand and shrink)
    int n = nums.size();
    int l = 0, r = 0;
    int sum = 0;
    int maxLen = 0;

    while (r < n)
    {
        sum += nums[r];
        while (sum > k && l <= r)
        {
            sum -= nums[l];
            l++;
        }
        if (sum <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
    // TC: O(2n)
    // SC: O(1)
}

int longestSubarrayOptimal(vector<int> &nums, int k)
{
    // Two pointers (expand and shrink)
    int n = nums.size();
    int l = 0, r = 0;
    int sum = 0;
    int maxLen = 0;

    while (r < n)
    {
        sum += nums[r];
        if (sum > k && l <= r)
        {
            sum -= nums[l];
            l++;
        }
        if (sum <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    // Pattern 1: Constant window (v.easy)
    // Eg. Maximum subarray sum having window size k
    vector<int> nums1 = {-1, 2, 3, 3, 4, 5, -1};
    int k = 10;
    cout << subarraySum(nums1, 4) << endl;

    // Pattern 2: Longest subarray/substring where <condition> (imp)
    // Eg. Longest subarray with sum <= k

    // Note: Assuming array elements are positive, sliding window will not work with negatives

    vector<int> nums2 = {2, 3, 1, 1, 2, 1, 10};

    cout << longestSubarrayBrute(nums2, k) << endl;
    cout << longestSubarrayBetter(nums2, k) << endl;
    cout << longestSubarrayOptimal(nums2, k) << endl;

    // Pattern 3: No. of subarrays where <condition>
    // Eg. No. of subarrays where sum = k

    // Soln: (No. of subarrays where sum <= k) - (No. of subarrays where sum <= k-1)
    // Because it is difficult to determine when to expand/shrink for sum = k case

    // Pattern 4: Shortest/Minimum window where <condition>
    // Approach: Find a valid window and try to shrink it down until valid
}