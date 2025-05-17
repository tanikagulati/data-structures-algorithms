#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *convertArrToDLL()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    Node *head = new Node(arr[0], nullptr, nullptr);
    Node *prev = head;
    for (int i = 1; i < n; i++)
    {
        Node *node = new Node(arr[i], nullptr, prev);
        prev->next = node;
        prev = prev->next;
    }
    return head;
}

Node *reverseDLLBrute(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    stack<int> st;
    Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
    // TC: O(2n)
    // SC: O(n)
}

Node *reverseDLLOptimal(Node *head)
{
    // 1 2 3 4
    Node *back = nullptr;
    Node *curr = head;
    while (curr)
    {
        curr->prev = curr->next;
        curr->next = back;
        back = curr;
        curr = curr->prev;
    }
    return back;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    Node *head = convertArrToDLL();
    printDLL(head);

    // Brute:
    // head = reverseDLLBrute(head);
    // printDLL(head);

    // Optimal: Pointers swap
    head = reverseDLLOptimal(head);
    printDLL(head);
}