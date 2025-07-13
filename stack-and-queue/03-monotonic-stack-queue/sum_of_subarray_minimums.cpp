#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-subarray-minimums/description/

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
    int mod = 1e9 + 7;
    for (int i = 0; i < nums.size(); i++)
    {
        int left = i - psee[i];
        int right = nse[i] - i;
        total += (1LL * left * right % mod) * nums[i] % mod;
    }
    return total % mod;
    // TC: O(5n)
    // SC: O(4n)
}

int main()
{
    vector<int> nums = {1, 4, 6, 3, 2, 7, 1};
    
    // Brute: Generate all subarrays and add minimum of each

    // Optimal:
    cout << sumOfSubarrayMinimums(nums) << endl;
}