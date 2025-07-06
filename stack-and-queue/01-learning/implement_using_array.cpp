#include <bits/stdc++.h>
using namespace std;

// Stack using arrays
class StackImpl
{
    // Fixed size needs to be specified for array
    // SC: O(n)
    static const int n = 10;
    int arr[n];
    int topIndex = -1;

public:
    void push(int x)
    {
        if (topIndex < n - 1)
        {
            topIndex++;
            arr[topIndex] = x;
        }
        // TC: O(1)
    }

    void pop()
    {
        if (topIndex >= 0)
        {
            topIndex--;
        }
        // TC: O(1)
    }

    int top()
    {
        if (topIndex >= 0)
            return arr[topIndex];
        else
            return -1;
        // TC: O(1)
    }

    int size()
    {
        return topIndex + 1;
        // TC: O(1)
    }
};

// Queue using arrays
class QueueImpl
{
    // SC: O(size)
    static const int n = 5;
    int arr[n];
    int start = -1;
    int end = -1;
    int currSize = 0;

public:
    void push(int x)
    {
        if (currSize == n)
            return;
        if (currSize == 0)
            start = end = 0;
        else
            end = (end + 1) % n;
        arr[end] = x;
        currSize++;
        // TC: O(1)
    }

    void pop()
    {
        if (currSize == 0)
            return;
        if (currSize == 1)
            start = end = -1;
        else
            start = (start + 1) % n;
        currSize--;
        // TC: O(1)
    }

    int front()
    {
        if (currSize == 0)
            return -1;
        else
            return arr[start];
        // TC: O(1)
    }

    int size()
    {
        return currSize;
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
}
