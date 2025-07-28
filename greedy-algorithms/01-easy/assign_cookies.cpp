#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/assign-cookies/description/

int findContentChildren(vector<int> g, vector<int> s)
{
    int n = g.size(), m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (g[i] <= s[j])
            i++;
        j++;
    }
    return i;
    // TC: O(nlogn + mlogm) + O(max(n, m))
    // SC: O(1)
}

int main()
{
    vector<int> greed = {1, 2, 3};
    vector<int> size = {1, 1, 2, 4};

    cout << findContentChildren(greed, size) << endl;
}