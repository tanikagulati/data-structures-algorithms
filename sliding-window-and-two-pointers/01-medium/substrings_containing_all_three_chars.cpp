#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

int countSubstrings(string &s)
{
    int n = s.size();
    int lastSeen[3] = {-1, -1, -1};
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        lastSeen[s[i] - 'a'] = i;
        // Below if check is not required (kept for readability)
        // Since 1 + (-1) = 0 will be added to cnt in that case
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            cnt += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        }
    }
    return cnt;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    string s = "abcabc";

    // Brute: Generate all substrings
    // Better: No. of substrings with LTE 3 chars (i.e, all possible substrings) - No. of substrings with LTE 2 chars
    // Optimal:
    cout << countSubstrings(s) << endl;
}