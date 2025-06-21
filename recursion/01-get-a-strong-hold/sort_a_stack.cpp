#include <bits/stdc++.h>
using namespace std;

// Note: Traversing directly in a stack (without modification) is not possible, since we can only access the top element
// Can be done by making a copy of stack

void sortedInsert(stack<int> &s, int element)
{
    if (s.empty() || element > s.top())
    {
        s.push(element);
        return;
    }
    int top = s.top();
    s.pop();
    sortedInsert(s, element);
    s.push(top);
}

void sortStack(stack<int> &s)
{
    // Recursively pop all elements until stack is empty
    // Insert each popped element back into the sorted stack in its correct position
    if (s.empty())
        return;

    int top = s.top();
    s.pop();

    sortStack(s);
    // Sorted insertion while backtracking
    sortedInsert(s, top);
    // TC: O(n^2)
    // SC: O(n) -> Recursion stack space
}

int main()
{
    stack<int> s;

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}