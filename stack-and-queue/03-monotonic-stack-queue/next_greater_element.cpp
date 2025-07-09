#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums2.size();
    stack<int> st;
    unordered_map<int, int> nge;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            nge[nums2[i]] = -1;
        }
        else
        {
            nge[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }
    vector<int> res;
    for (auto i : nums1)
    {
        res.push_back(nge[i]);
    }
    return res;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    // Brute: Iterate for each element -> O(n^2)

    // Optimal: Monotonic stack -> Stack that stores elements in an order
    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (auto i : ans)
        cout << i << endl;
}