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
            hash[s[i] - 'A']++;
            maxFreq = max(maxFreq, hash[s[i]]);
            changes = (j - i + 1) - maxLen;
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

int main()
{
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k) << endl;
}