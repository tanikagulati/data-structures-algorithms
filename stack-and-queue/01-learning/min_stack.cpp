#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/min-stack/description/

class StackImpl
{
    stack<pair<int, int>> st;

public:
    void push(int x)
    {
        if (st.empty())
        {
            st.push({x, x});
        }
        else
        {
            int mini = min(x, st.top().second);
            st.push({x, mini});
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        st.pop();
    }

    int top()
    {
        if (st.empty())
            return -1;
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
    // TC: O(1) -> all operations
    // SC: O(2n)
};

// Optimal
class StackImpl2
{
    stack<int> st;
    int mini = INT_MAX;

public:
    void push(int x)
    {
        if (st.empty())
        {
            st.push(x);
            mini = x;
        }
        else
        {
            if (x < mini)
            {
                st.push(2 * x - mini);
                mini = x;
            }
            else
            {
                st.push(x);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        if (st.top() < mini)
        {
            mini = 2 * mini - st.top();
        }
        st.pop();
    }

    int top()
    {
        if (st.empty())
            return -1;
        if (st.top() < mini)
        {
            return mini;
        }
        return st.top();
    }

    int getMin()
    {
        return mini;
    }
    // TC: O(1) -> all operations
    // SC: O(n)
};

int main()
{
    StackImpl st;
    st.push(12);
    st.push(15);
    st.push(10);
    cout << st.getMin() << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.getMin() << endl;
    cout << st.top() << endl;

    cout << endl;

    StackImpl st2;
    st2.push(12);
    st2.push(15);
    st2.push(10);
    cout << st2.getMin() << endl;
    cout << st2.top() << endl;
    st2.pop();
    cout << st2.getMin() << endl;
    cout << st2.top() << endl;
}