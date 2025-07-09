#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1

vector<int> previousSmallerElement(vector<int> &nums)
{
    int n = nums.size();
    stack<int> s;
    vector<int> nge(n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && nums[i] <= s.top())
        {
            s.pop();
        }
        nge[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }
    return nge;
    // TC: O(2n)
    // SC: O(2n)
}

int main()
{
    vector<int> nums = {1, 6, 2, 3};

    vector<int> res = previousSmallerElement(nums);

    for (auto i : res)
        cout << i << " ";
}