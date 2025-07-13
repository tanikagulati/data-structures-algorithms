#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-subarray-ranges/description/

vector<int> nextSmallerElement(vector<int> &nums)
{
    // Find index of nse for each element
    int n = nums.size();
    vector<int> nse(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
    // TC: O(2n)
    // SC: O(2n)
}

vector<int> prevSmallerOrEqualElement(vector<int> &nums)
{
    // Find index of psee for each element
    int n = nums.size();
    vector<int> psee(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
    // TC: O(2n)
    // SC: O(2n)
}

int sumOfSubarrayMinimums(vector<int> &nums)
{
    vector<int> nse = nextSmallerElement(nums);
    vector<int> psee = prevSmallerOrEqualElement(nums);
    long long total = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int left = i - psee[i];
        int right = nse[i] - i;
        total += (1LL * left * right) * nums[i];
    }
    return total;
    // TC: O(5n)
    // SC: O(4n)
}

vector<int> nextGreaterElement(vector<int> &nums)
{
    // Find index of nge for each element
    int n = nums.size();
    vector<int> nge(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nge;
    // TC: O(2n)
    // SC: O(2n)
}

vector<int> prevGreaterOrEqualElement(vector<int> &nums)
{
    // Find index of pgee for each element
    int n = nums.size();
    vector<int> pgee(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }
        pgee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pgee;
    // TC: O(2n)
    // SC: O(2n)
}

int sumOfSubarrayMaximums(vector<int> &nums)
{
    vector<int> nge = nextGreaterElement(nums);
    vector<int> pgee = prevGreaterOrEqualElement(nums);
    long long total = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int left = i - pgee[i];
        int right = nge[i] - i;
        total += (1LL * left * right) * nums[i];
    }
    return total;
    // TC: O(5n)
    // SC: O(4n)
}

int main()
{
    vector<int> nums = {4, -2, -3, 4, 1};

    // Brute: Generate all subarrays, add max - min to result for each subarray

    // Optimal: TC: O(10n ~ n),  SC: O(8n ~ n)
    int res = sumOfSubarrayMaximums(nums) - sumOfSubarrayMinimums(nums);
    cout << res << endl;
}