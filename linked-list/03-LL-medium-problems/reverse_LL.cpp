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

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *createLL(int arr[], int n)
{
    Node *head = new Node(arr[0], nullptr);
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *reverseLLBetter(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
    // TC: O(n)
    // SC: O(1)
}

Node *reverseLLRecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = reverseLLRecursive(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
    // TC: O(n)
    // SC: O(n) -> Recursive stack space
}

int main()
{
    int n = 4;
    int arr[n] = {1, 2, 3, 4};
    Node *head = createLL(arr, n);
    printLL(head);

    // Brute: Data replacement using stack
    // TC: O(2n)
    // SC: O(n)

    // Better: Changing pointers
    // head = reverseLLBetter(head);
    // printLL(head);

    head = reverseLLRecursive(head);
    printLL(head);
}