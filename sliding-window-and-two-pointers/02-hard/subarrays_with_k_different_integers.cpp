#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subarrays-with-k-different-integers/description/

int subarraysWithKDistinctLTE(vector<int> &nums, int k)
{
    // Count subarrays with distinct elements <= k
    int l = 0, r = 0;
    int cnt = 0;
    map<int, int> mp;
    while (r < nums.size())
    {
        mp[nums[r]]++;
        while (mp.size() > k)
        {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);
            l++;
        }
        cnt += r - l + 1;
        r++;
    }
    return cnt;
    // TC: O(2n)
    // SC: O(k)
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    // Brute: Generate all subarrays
    // Optimal:
    cout << subarraysWithKDistinctLTE(nums, k) - subarraysWithKDistinctLTE(nums, k - 1) << endl;
    // TC: O(4n)
}