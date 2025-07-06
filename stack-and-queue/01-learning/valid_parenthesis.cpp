#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/description/

bool isValid(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            char c = st.top();
            st.pop();
            if ((c == '(' && s[i] != ')') || (c == '{' && s[i] != '}') || (c == '[' && s[i] != ']'))
            {
                return false;
            }
        }
    }
    return st.empty();
    // TC: O(n)
    // SC: O(n)
}

int main()
{
    string s = "([)]";
    cout << isValid(s) << endl;
}