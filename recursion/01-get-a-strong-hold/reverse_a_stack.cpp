#include <bits/stdc++.h>
using namespace std;

void pushIntoStack(stack<int> &s, int element)
{
    if (s.empty())
    {
        s.push(element);
        return;
    }
    int top = s.top();
    s.pop();
    pushIntoStack(s, element);
    s.push(top);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;

    int top = s.top();
    s.pop();

    reverseStack(s);
    pushIntoStack(s, top);
    // TC: O(n^2)
    // SC: O(n) Recursion stack space
}

int main()
{
    stack<int> s;
    s.push(11);
    s.push(6);
    s.push(8);
    s.push(17);

    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}