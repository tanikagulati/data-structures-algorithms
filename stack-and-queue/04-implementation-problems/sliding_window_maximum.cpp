#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sliding-window-maximum/description/

vector<int> slidingWindowMaximum(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
        {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
    // TC: O(2n)
    // SC: O(k) + O(n-k)
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

    vector<int> res = slidingWindowMaximum(nums, 3);

    for (auto i : res)
    {
        cout << i << " ";
    }
}