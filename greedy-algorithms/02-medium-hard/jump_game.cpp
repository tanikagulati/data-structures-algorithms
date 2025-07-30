#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game/description/

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxInd = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > maxInd)
            return false;
        maxInd = max(maxInd, i + nums[i]);
        if (maxInd >= n - 1)
            break;
    }
    return true;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4};

    cout << canJump(nums) << endl;
}