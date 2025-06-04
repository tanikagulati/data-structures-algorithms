#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix1(vector<string> &strs)
{
    if (strs.empty())
        return "";

    for (int i = 0; i < strs[0].size(); ++i)
    {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); ++j)
        {
            if (i >= strs[j].size() || strs[j][i] != c)
                return strs[0].substr(0, i);
        }
    }

    return strs[0];
    // TC: O(n*m)
    // SC: O(1)
}

string longestCommonPrefix2(vector<string> &strs)
{
    if (strs.empty())
        return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); ++i)
    {
        // 'find' returns the index where the prefix occurs in strs[i]
        while (strs[i].find(prefix) != 0)
        {
            prefix.pop_back(); // trim last character
            if (prefix.empty())
                return "";
        }
    }

    return prefix;
    // TC: O(n*m)
    // SC: O(1)
}

bool isCommonPrefix(vector<string> &strs, int len)
{
    string prefix = strs[0].substr(0, len);
    for (int i = 1; i < strs.size(); ++i)
    {
        if (strs[i].substr(0, len) != prefix)
            return false;
    }
    return true;
}

string longestCommonPrefixOptimal(vector<string> &strs)
{
    if (strs.empty())
        return "";
    int minLen = strs[0].size();
    for (const string &s : strs)
        minLen = min(minLen, (int)s.size());

    int low = 0, high = minLen;
    while (low < high)
    {
        int mid = (low + high + 1) / 2;
        if (isCommonPrefix(strs, mid))
            low = mid;
        else
            high = mid - 1;
    }

    return strs[0].substr(0, low);
    // TC: O(n * logm) -> n = no of strings, m = min length
    // SC: O(1)
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    // Brute1: Vertical scanning
    cout << longestCommonPrefix1(strs) << endl;

    // Brute2: Horizontal scanning
    cout << longestCommonPrefix2(strs) << endl;

    // Optimal: Binary search (Revisit)
    cout << longestCommonPrefixOptimal(strs) << endl;
}