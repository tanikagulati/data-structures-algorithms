#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

// Same as Binary subarrays with sum problem (Think of odd numbers as 1 and even as 0)

int countSubarraysLTE(vector<int> &nums, int k)
{
    // Count subarrays with odd numbers less than or equal to k
    if (k < 0)
        return 0;
    int n = nums.size();
    int oddCnt = 0;
    int subarraysCnt = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        oddCnt += nums[r] % 2;
        while (oddCnt > k)
        {
            oddCnt -= nums[l] % 2;
            l++;
        }
        subarraysCnt += r - l + 1;
        r++;
    }
    return subarraysCnt;
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << countSubarraysLTE(nums, k) - countSubarraysLTE(nums, k - 1) << endl;
    // TC: O(4n)
    // SC: O(1)
}