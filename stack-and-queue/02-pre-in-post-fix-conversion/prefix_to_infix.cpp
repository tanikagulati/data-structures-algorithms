#include <bits/stdc++.h>
using namespace std;

// Prefix to infix expression conversion

string prefixToInfix(string &exp)
{
    stack<string> st;
    int n = exp.size();
    for (int i = n - 1; i >= 0; i--)
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
            st.push("(" + t1 + exp[i] + t2 + ")");
        }
    }
    return st.top();
    // TC: O(2n) -> traversal + string additions
    // SC: O(n)
}

int main()
{
    string exp = "*+pq-mn";
    cout << prefixToInfix(exp) << endl;
}