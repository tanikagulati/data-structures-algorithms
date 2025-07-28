#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-window-substring/description/

string minimumWindowSubstringBrute(string &s, string &t)
{
    int m = s.size(), n = t.size();
    int minLen = INT_MAX;
    int stIndex = -1;
    for (int i = 0; i < m; i++)
    {
        int hash[256] = {0};
        int cnt = 0;
        for (int j = 0; j < n; j++)
            hash[t[j]]++;
        for (int j = i; j < m; j++)
        {
            if (hash[s[j]] > 0)
                cnt++;
            hash[s[j]]--;
            if (cnt == n)
            {
                if (j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                    stIndex = i;
                }
            }
        }
    }
    return stIndex == -1 ? "" : s.substr(stIndex, minLen);
    // TC: O(m*(m+n))
    // SC: O(1)
}

string minimumWindowSubstringOptimal(string &s, string &t)
{
    int m = s.size(), n = t.size();
    int hash[256] = {0};
    for (int i = 0; i < n; i++)
        hash[t[i]]++;
    int cnt = 0;
    int minLen = INT_MAX;
    int l = 0, r = 0, stIndex = -1;
    while (r < m)
    {
        if (hash[s[r]] > 0)
            cnt++;
        hash[s[r]]--;
        while (cnt == n)
        {
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                stIndex = l;
            }
            hash[s[l]]++;
            if (hash[s[l]] > 0)
                cnt--;
            l++;
        }
        r++;
    }
    return stIndex == -1 ? "" : s.substr(stIndex, minLen);
    // TC: O(2m + n)
    // SC: O(1)
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minimumWindowSubstringBrute(s, t) << endl;

    cout << minimumWindowSubstringOptimal(s, t) << endl;
}