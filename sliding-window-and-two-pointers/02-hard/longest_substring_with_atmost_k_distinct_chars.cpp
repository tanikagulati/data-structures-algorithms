#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/ (Premium)

// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1 (Similar)

int longestSubstringBetter(string &s, int k)
{
    int l = 0, r = 0;
    int maxLen = 0;
    map<char, int> mp;
    while (r < s.size())
    {
        mp[s[r]]++;
        while (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
    // TC: O(2n)
    // SC: O(1)
}

int longestSubstringOptimal(string &s, int k)
{
    int l = 0, r = 0;
    int maxLen = 0;
    map<char, int> mp;
    while (r < s.size())
    {
        mp[s[r]]++;
        if (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }
        if (mp.size() <= k)
            maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    string s = "aaabbccd";
    int k = 2;

    // Brute: Generate all substrings
    // Better:
    cout << longestSubstringBetter(s, k) << endl;
    // Optimal:
    cout << longestSubstringOptimal(s, k) << endl;
}