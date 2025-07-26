#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-repeating-character-replacement/description/

int characterReplacement(string &s, int k)
{
    int n = s.size();
    int maxLen = 0;
    int changes;
    for (int i = 0; i < n; i++)
    {
        vector<int> hash(26, 0);
        int maxFreq = 0;
        for (int j = i; j < n; j++)
        {
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            changes = (j - i + 1) - maxFreq;
            if (changes <= k)
                maxLen = max(maxLen, j - i + 1);
            else
                break;
        }
    }
    return maxLen;
    // TC: O(n^2)
    // SC: O(1)
}

int characterReplacementOptimal(string &s, int k)
{
    int n = s.size();
    int maxLen = 0;
    int l = 0, r = 0;
    int maxFreq = 0, changes = 0;
    vector<int> hash(26, 0);
    while (r < n)
    {
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r] - 'A']);
        changes = (r - l + 1) - maxFreq;
        if (changes <= k)
            maxLen = max(maxLen, r - l + 1);
        else
        {
            hash[s[l] - 'A']--;
            // Updating maxFreq at this step is not reqd, because a lower maxFreq will never contribute to answer
            l++;
        }
        r++;
    }
    return maxLen;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k) << endl;

    cout << characterReplacementOptimal(s, k) << endl;
}