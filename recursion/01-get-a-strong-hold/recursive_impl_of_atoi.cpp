#include <bits/stdc++.h>
using namespace std;

// String to Integer (atoi) (Recursive)

int findNumber(string &s, int i, bool negative, int res)
{
    if (i >= s.size() || s[i] < '0' || s[i] > '9')
    {
        return negative ? -res : res;
    }

    res = (res * 10) + s[i] - '0';
    if (negative && -res < INT_MIN)
        return INT_MIN;
    if (!negative && res > INT_MAX)
        return INT_MAX;

    return findNumber(s, i + 1, negative, res);
}

int myAtoi(string s)
{
    int n = s.size();
    int i = 0;
    // Handle leading spaces
    while (i < n && s[i] == ' ')
    {
        i++;
    }
    // Handle sign
    bool negative = false;
    if (i < n && (s[i] == '-' || s[i] == '+'))
    {
        if (s[i] == '-')
        {
            negative = true;
        }
        i++;
    }
    // Find number
    return findNumber(s, i, negative, 0);
    // TC: O(n)
    // SC: O(n) -> Rec stack space
}

int main()
{
    cout << myAtoi("  +234") << endl;
}