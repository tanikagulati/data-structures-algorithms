#include <bits/stdc++.h>
using namespace std;

// Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
// Primitive -> Valid paranthesis

string removeOuterParentheses(string s)
{
    string res = "";
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            if (sum > 0)
            {
                res += s[i];
            }
            sum++;
        }
        else
        {
            sum--;
            if (sum > 0)
            {
                res += s[i];
            }
        }
    }
    return res;
    // TC: O(n)
    // SC: O(n)
}

int main()
{
    cout << removeOuterParentheses("(()())(())") << endl;
}