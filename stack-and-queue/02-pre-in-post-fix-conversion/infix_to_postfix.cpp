#include <bits/stdc++.h>
using namespace std;

// Infix to postfix expression conversion

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

string infixToPostfix(string &exp)
{
    stack<char> s;
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
                s.push(exp[i]);
            }
            else if (exp[i] == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    ans += s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {
                while (!s.empty() && priority(exp[i]) <= priority(s.top()))
                {
                    ans += s.top();
                    s.pop();
                }
                s.push(exp[i]);
            }
        }
    }
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
    // TC: O(2n) -> considering while loops
    // SC: O(2n) -> stack + ans
}

int main()
{
    string exp = "a+b-c*(d/e+f)";
    cout << infixToPostfix(exp) << endl;
}