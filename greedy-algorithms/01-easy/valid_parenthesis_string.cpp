#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parenthesis-string/description/

bool checkValidStringBrute(string &s, int cnt, int ind)
{
    if (cnt < 0)
        return false;
    if (ind == s.size())
        return cnt == 0;

    if (s[ind] == '(')
        return checkValidStringBrute(s, cnt + 1, ind + 1);

    if (s[ind] == ')')
        return checkValidStringBrute(s, cnt - 1, ind + 1);

    return (checkValidStringBrute(s, cnt + 1, ind + 1) || checkValidStringBrute(s, cnt - 1, ind + 1) || checkValidStringBrute(s, cnt, ind + 1));
    // TC: O(3^n)
    // SC: O(n)
}

bool checkValidStringOptimal(string &s)
{
    // Track range instead of count
    int min = 0, max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            min++, max++;
        }
        else if (s[i] == ')')
        {
            min--, max--;
        }
        else
        {
            min--, max++;
        }
        // we must never consider '*' as ')' if min = 0 (i.e, no opening bracket left until this index)
        if (min < 0)
            min = 0;
        if (max < 0)
            return false;
    }
    return min == 0;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    string s = "(**(";

    cout << checkValidStringBrute(s, 0, 0) << endl;

    cout << checkValidStringOptimal(s) << endl;

    // Try using stack
}