#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-greater-element-ii/description/

vector<int> nextGreaterElement2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            nge[i] = st.empty() ? -1 : st.top();
        }
        st.push(nums[i % n]);
    }
    return nge;
    // TC: O(4n)
    // SC: O(2n+n) -> stack and res
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 3};

    vector<int> res = nextGreaterElement2(nums);

    for (auto i : res)
        cout << i << " ";
}