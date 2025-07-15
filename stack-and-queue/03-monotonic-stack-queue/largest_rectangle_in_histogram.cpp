#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

vector<int> prevSmallerElement(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    vector<int> pse(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[i] <= heights[st.top()])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
    // TC: O(2n)
    // SC: O(2n)
}

vector<int> nextSmallerElement(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    vector<int> nse(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[i] <= heights[st.top()])
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

int largestRectangleBrute(vector<int> &heights)
{
    vector<int> pse = prevSmallerElement(heights);
    vector<int> nse = nextSmallerElement(heights);

    int maxi = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int area = heights[i] * (nse[i] - pse[i] - 1);
        maxi = max(maxi, area);
    }
    return maxi;
    // TC: O(5n)
    // SC: O(4n)
}

int largestRectangleOptimal(vector<int> &heights)
{
    // Keep pushing into stack until nse is encountered
    // Pop and compute area, if nse is encountered
    int n = heights.size();
    stack<int> st;
    int maxi = INT_MIN;
    int nse, pse;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int element = st.top();
            st.pop();
            nse = i;
            pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, heights[element] * (nse - pse - 1));
        }
        st.push(i);
    }
    // Elements left in stack are those that do not have an nse, so nse = n
    while (!st.empty())
    {
        int element = st.top();
        st.pop();
        nse = n;
        pse = st.empty() ? -1 : st.top();
        maxi = max(maxi, heights[element] * (nse - pse - 1));
    }
    return maxi;
    // TC: O(2n)
    // SC: O(n)
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // Brute:
    cout << largestRectangleBrute(heights) << endl;

    // Optimal: (without pre-computation)
    cout << largestRectangleOptimal(heights) << endl;
}