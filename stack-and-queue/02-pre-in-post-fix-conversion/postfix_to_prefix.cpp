#include <bits/stdc++.h>
using namespace std;

// Postfix to prefix expression conversion

string postfixToPrefix(string &exp)
{
    stack<string> st;
    for (int i = 0; i < exp.size(); i++)
    {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            st.push(string(1, exp[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(exp[i] + t2 + t1);
        }
    }
    return st.top();
    // TC: O(2n) -> traversal + string additions
    // SC: O(n)
}

int main()
{
    string exp = "ab-de+f*/";
    cout << postfixToPrefix(exp) << endl;
}