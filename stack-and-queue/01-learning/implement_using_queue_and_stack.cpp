#include <bits/stdc++.h>
using namespace std;

// Stack using queue
class StackImpl
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        q.pop();
    }

    int top()
    {
        return q.front();
    }

    int size()
    {
        return q.size();
    }
};

// Queue using stacks
class QueueImpl
{
    // SC: O(2n)
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
        // TC: O(2n)
    }

    int pop()
    {
        int el = s1.top();
        s1.pop();
        return el;
        // TC: O(1)
    }

    int front()
    {
        return s1.top();
        // TC: O(1)
    }

    int size()
    {
        return s1.size();
        // TC: O(1)
    }
};

// // Queue using stacks (Optimal)
class QueueImpl2
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
        // TC: O(1)
    }

    void pop()
    {
        if (s2.empty())
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
        // TC: O(n) -> but occasionally
    }

    int front()
    {
        if (s2.empty())
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
        // TC: O(n) -> but occasionally
    }

    int size()
    {
        return s1.size() + s2.size();
        // TC: O(1)
    }
};

int main()
{
    StackImpl st;
    st.push(5);
    st.push(1);
    st.pop();
    cout << st.top() << endl;
    st.push(3);
    cout << st.top() << endl;
    cout << st.size() << endl;

    cout << endl;

    QueueImpl q;
    q.push(4);
    q.push(7);
    q.pop();
    cout << q.front() << endl;
    q.push(3);
    cout << q.front() << endl;
    cout << q.size() << endl;

    cout << endl;

    QueueImpl2 q2;
    q2.push(4);
    q2.push(7);
    q2.pop();
    cout << q2.front() << endl;
    q2.push(3);
    cout << q2.front() << endl;
    cout << q2.size() << endl;
}