#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

class StackImpl
{
    Node *topNode = NULL;
    int currSize = 0;

public:
    void push(int n)
    {
        Node *temp = new Node(n, topNode);
        topNode = temp;
        currSize++;
        // TC: O(1)
    }

    void pop()
    {
        if (currSize == 0)
            return;
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        currSize--;
        // TC: O(1)
    }

    int top()
    {
        if (topNode == NULL)
            return -1;
        return topNode->data;
        // TC: O(1)
    }

    int size()
    {
        return currSize;
        // TC: O(1)
    }
};

class QueueImpl
{
    Node *start = NULL;
    Node *end = NULL;
    int currSize = 0;

public:
    void push(int n)
    {
        Node *temp = new Node(n, NULL);
        if (start == NULL)
        {
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = end->next;
        }
        currSize++;
        // TC: O(1)
    }

    void pop()
    {
        if (start == NULL)
            return;
        Node *temp = start;
        start = start->next;
        if (start == NULL)
            end = NULL;
        delete temp;
        currSize--;
        // TC: O(1)
    }

    int front()
    {
        if (start == NULL)
            return -1;
        return start->data;
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