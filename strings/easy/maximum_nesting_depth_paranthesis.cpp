#include <bits/stdc++.h>
using namespace std;

// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

int maxDepth(string s)
{
    int maxi = 0, sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            sum++;
            maxi = max(maxi, sum);
        }
        else if (s[i] == ')')
        {
            sum--;
        }
    }
    return maxi;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    cout << maxDepth("(1+(2*3)+((8)/4))+1") << endl;
}