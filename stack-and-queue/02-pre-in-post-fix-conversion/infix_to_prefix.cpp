#include <bits/stdc++.h>
using namespace std;

// Infix to prefix expression conversion

// Reverse the expression -> Infix to postfix -> Reverse the ans
// (with some tweaks)

int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void reverseExp(string &exp)
{
    reverse(exp.begin(), exp.end());

    for (char &c : exp) // &c for in-place modification
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
}

string infixToPrefix(string &exp)
{
    reverseExp(exp);
    stack<char> st;
    string ans;
    for (int i = 0; i < exp.size(); i++)
    {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            ans += exp[i];
        }
        else
        {
            if (exp[i] == '(')
            {
                st.push(exp[i]);
            }
            else if (exp[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                if (exp[i] == '^')
                {
                    while (!st.empty() && priority(exp[i] <= priority(st.top())))
                    {
                        ans += st.top();
                        st.pop();
                    }
                }
                else
                {
                    while (!st.empty() && priority(exp[i]) < priority(st.top()))
                    {
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(exp[i]);
            }
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverseExp(ans);
    return ans;
    // TC: O(3n) -> considering while loops + reverse
    // SC: O(2n) -> stack + ans
}

int main()
{
    string exp = "a+b-c*(d/e+f)";
    cout << infixToPrefix(exp) << endl;
}