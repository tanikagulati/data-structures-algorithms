#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game-ii/description/

int minimumJumpsBrute(vector<int> &nums, int ind, int jumps)
{
    if (ind >= nums.size() - 1)
    {
        return jumps;
    }
    int mini = INT_MAX;
    for (int i = 1; i <= nums[ind]; i++)
    {
        mini = min(mini, minimumJumpsBrute(nums, ind + i, jumps + 1));
    }
    return mini;
    // TC: O(n^n)
    // SC: O(n)
}

int minimumJumpsOptimal(vector<int> &nums)
{
    // Ranges
    int n = nums.size();
    int l = 0, r = 0;
    int jumps = 0;
    while (r < n - 1)
    {
        int farthest = 0;
        for (int i = l; i <= r; i++)
        {
            farthest = max(farthest, i + nums[i]);
        }
        l = r + 1;
        r = farthest;
        jumps++;
    }
    return jumps;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << minimumJumpsBrute(nums, 0, 0) << endl;

    cout << minimumJumpsOptimal(nums) << endl;
}