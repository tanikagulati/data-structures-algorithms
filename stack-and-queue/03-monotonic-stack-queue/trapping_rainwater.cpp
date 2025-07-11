#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/trapping-rain-water/description/

int trappingRainwaterBrute(vector<int> &height)
{
    int n = height.size();
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);
    prefixMax[0] = height[0];
    suffixMax[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], height[i]);
        suffixMax[n - 1 - i] = max(suffixMax[n - i], height[n - 1 - i]);
    }

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (height[i] < prefixMax[i] && height[i] < suffixMax[i])
        {
            total += min(prefixMax[i], suffixMax[i]) - height[i];
        }
    }
    return total;
    // TC: O(3n)
    // SC: O(2n)
}

int trappingRainwaterBetter(vector<int> &height)
{
    // Do we really need prefixMax? No, eliminate.
    int n = height.size();
    vector<int> suffixMax(n);
    suffixMax[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        suffixMax[n - 1 - i] = max(suffixMax[n - i], height[n - 1 - i]);
    }

    int total = 0;
    int leftMax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        leftMax = max(leftMax, height[i]);
        if (height[i] < leftMax && height[i] < suffixMax[i])
        {
            total += min(leftMax, suffixMax[i]) - height[i];
        }
    }
    return total;
    // TC: O(2n)
    // SC: O(n)
}

int trappingRainwaterOptimal(vector<int> &height)
{
    // Intuition: we only need one (smaller one) out of lMax and rMax for a building
    // Traverse through the smaller ones first using two pointers
    int l = 0, r = height.size() - 1;
    int lMax = 0, rMax = 0;
    int total = 0;
    while (l < r)
    {
        if (height[l] <= height[r])
        {
            if (lMax > height[l])
                total += lMax - height[l];
            else
                lMax = height[l];
            l++;
        }
        else
        {
            if (rMax > height[r])
                total += rMax - height[r];
            else
                rMax = height[r];
            r--;
        }
    }
    return total;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Brute:
    cout << trappingRainwaterBrute(height) << endl;

    // Better:
    cout << trappingRainwaterBetter(height) << endl;

    // Optimal:
    cout << trappingRainwaterOptimal(height) << endl;
}