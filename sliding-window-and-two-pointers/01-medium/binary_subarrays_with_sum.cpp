#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-subarrays-with-sum/description/

int numSubarraysWithSum(vector<int> nums, int k)
{
    if (k < 0)
        return 0;
    int n = nums.size();
    int sum = 0;
    int cnt = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        sum += nums[r];
        while (sum > k)
        {
            sum -= nums[l];
            l++;
        }
        cnt += r - l + 1;
        r++;
    }
    return cnt;
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << numSubarraysWithSum(nums, goal) - numSubarraysWithSum(nums, goal - 1) << endl;
}