#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

int longestSubstring(string s)
{
    int l = 0, r = 0;
    int len = 0, maxLen = 0;
    vector<int> hash(256, -1);

    while (r < s.size())
    {
        if (hash[s[r]] >= l)
        {
            l = hash[s[r]] + 1;
        }
        hash[s[r]] = r;
        len = r - l + 1;
        maxLen = max(maxLen, len);
        r++;
    }
    return maxLen;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    string s = "cadbzabcd";

    // Brute: Generate all subarrays

    // Optimal:
    cout << longestSubstring(s) << endl;
}