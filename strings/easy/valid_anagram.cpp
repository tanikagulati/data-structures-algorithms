#include <bits/stdc++.h>
using namespace std;

// Given s and t consists of lowercase english letters

bool isAnagramBrute(string s, string t)
{
    if (s.length() != t.length())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            return false;
        }
    }
    return true;
    // TC: O(2nlogn + n) ~ O(nlogn)
    // SC: O(1)
}

bool isAnagramOptimal(string s, string t)
{
    if (s.length() != t.length())
        return false;
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }
    for (auto i : arr)
    {
        if (i != 0)
            return false;
    }
    return true;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    cout << isAnagramBrute("anagram", "nagaram") << endl;

    cout << isAnagramOptimal("anagram", "nagaram") << endl;
}