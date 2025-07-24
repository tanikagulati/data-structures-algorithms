#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

int maxScore(vector<int> &nums, int k)
{
    int n = nums.size();
    int lSum = 0, rSum = 0;
    int maxSum = 0;
    for (int i = 0; i < k; i++)
    {
        lSum += nums[i];
    }
    maxSum = lSum;
    int rInd = n - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        lSum -= nums[i];
        rSum += nums[rInd];
        rInd--;
        maxSum = max(maxSum, lSum + rSum);
    }
    return maxSum;
    // TC: O(2*k)
    // SC: O(1)
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << maxScore(nums, k) << endl;
}