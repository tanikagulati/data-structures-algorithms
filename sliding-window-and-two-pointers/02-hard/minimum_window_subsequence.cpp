#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

string minimumWindowSubsequence(string &s1, string &s2)
{
    int minLen = INT_MAX;
    int stIndex = -1;
    int size1 = s1.size(), size2 = s2.size();
    int l = 0, r = 0;
    int s2Ind = 0;
    while (r < size1)
    {
        if (s1[r] == s2[s2Ind])
        {
            s2Ind++;
        }
        if (s2Ind == size2)
        {
            l = r;
            while (s2Ind > 0)
            {
                if (s1[l] == s2[s2Ind - 1])
                {
                    s2Ind--;
                }
                l--;
            }
            l++;
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                stIndex = l;
            }
            r = l;
        }
        r++;
    }
    return stIndex == -1 ? "" : s1.substr(stIndex, minLen);
    // TC: O(n + n + m+n) ~ O(n)
    // SC: O(1)
}

int main()
{
    string s1 = "abcdebdde";
    string s2 = "bde";

    cout << minimumWindowSubsequence(s1, s2) << endl;
}