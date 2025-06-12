#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    bool positive = true;
    long res = 0;
    int i = 0;
    int n = s.size();
    while (i < n && s[i] == ' ')
    {
        i++;
    }
    if (i < n && s[i] == '-')
    {
        positive = false;
        i++;
    }
    else if (i < n && s[i] == '+')
    {
        i++;
    }
    while (i < n && s[i] == '0')
    {
        i++;
    }
    while (res < 0 <= s[i] - '0' && s[i] - '0' <= 9)
    {
        res = (res * 10) + s[i] - '0';
        if (positive && res > INT_MAX)
            return INT_MAX;
        if (!positive && -res < INT_MIN)
            return INT_MIN;
        i++;
    }
    if (!positive)
        res = -res;
    return (int)res;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    cout << myAtoi("-91283472332") << endl;
}

// 32-bit signed integer range
// INT_MAX = 2147483647 (2^31 - 1)
// INT_MIN = -2147483648 (-2^31)