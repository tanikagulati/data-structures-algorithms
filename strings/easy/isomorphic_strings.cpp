#include <bits/stdc++.h>
using namespace std;

/*
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.
*/

bool isIsomorphic(string &s, string &t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, char> s_to_t;
    unordered_map<char, char> t_to_s;

    for (int i = 0; i < s.length(); ++i)
    {
        char cs = s[i];
        char ct = t[i];

        if (s_to_t.count(cs) && s_to_t[cs] != ct)
            return false;

        if (t_to_s.count(ct) && t_to_s[ct] != cs)
            return false;

        s_to_t[cs] = ct;
        t_to_s[ct] = cs;
    }

    return true;
    // TC: O(n)
    // SC: O(1) -> Because, map size here depends on the size of character set, not input size.
    // Even if the strings are 10,000 characters long, we will store at most 256 key-value pairs in each map.
}

vector<int> getPattern(string &str)
{
    vector<int> pattern;
    unordered_map<char, int> mp;
    int index = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (!mp.count(str[i]))
        {
            mp.insert({str[i], index});
            index++;
        }
        pattern.push_back(mp[str[i]]);
    }
    return pattern;
}

bool isIsomorphic2(string &s, string &t)
{
    return getPattern(s) == getPattern(t);
    // TC: O(2n)
    // SC: O(2n)
}

int main()
{
    string s = "egg", t = "add";
    // Using hashmaps (Optimal)
    cout << isIsomorphic(s, t) << endl;

    // Pattern encoding
    cout << isIsomorphic2(s, t) << endl;
}