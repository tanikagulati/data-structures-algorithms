#include <bits/stdc++.h>
using namespace std;

/*
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.
*/

bool isIsomorphic(string s, string t)
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
    // SC: O(1)
}

int main()
{
    cout << isIsomorphic("egg", "add") << endl;
}