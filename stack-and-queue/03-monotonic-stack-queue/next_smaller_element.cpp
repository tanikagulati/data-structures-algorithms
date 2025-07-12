#include <bits/stdc++.h>
using namespace std;

// Next smaller element (NSE)

vector<int> nextSmallerElement(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> nse(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[i] <= st.top())
        {
            st.pop();
        }
        nse[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
    }
    return nse;
    // TC: O(2n) -> for and while
    // SC: O(2n) -> stack and nse
}

int main()
{
    vector<int> nums = {3, 7, 1, 4, 2};

    vector<int> res = nextSmallerElement(nums);

    for (auto i : res)
        cout << i << " ";
}