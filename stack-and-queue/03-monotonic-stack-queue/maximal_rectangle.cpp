#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximal-rectangle/description/

int largestRectangleInHistogram(vector<int> &heights)
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

int maximalRectangle(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> prefixSum(n, vector<int>(m));
    for (int col = 0; col < m; col++)
    {
        int sum = 0;
        for (int row = 0; row < n; row++)
        {
            if (matrix[row][col] == 0)
            {
                sum = 0;
            }
            else
            {
                sum += matrix[row][col];
            }
            prefixSum[row][col] = sum;
        }
    }
    int maxArea = 0;
    for (int i = 0; i < prefixSum.size(); i++)
    {
        maxArea = max(maxArea, largestRectangleInHistogram(prefixSum[i]));
    }
    return maxArea;
    // TC: O(n*m + n*2m)
    // SC: O(n*m + m)
}

int main()
{
    vector<vector<int>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
}