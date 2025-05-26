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
    // TC: O(n)
}

Node *convertArrToDLL(int arr[], int n)
{
    Node *head = new Node(arr[0], nullptr, nullptr);
    Node *prev = head;
    for (int i = 1; i < n; i++)
    {
        Node *node = new Node(arr[i], nullptr, prev);
        prev->next = node;
        prev = prev->next;
    }
    return head;
    // TC: O(n)
}

Node *deleteAllOccurences(Node *head, int k)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    while (temp)
    {
        Node *next = temp->next;
        Node *prev = temp->prev;
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = next;
            }
            if (prev)
                prev->next = next;
            if (next)
                next->prev = prev;
            delete temp;
            temp = next;
        }
        else
            temp = temp->next;
    }
    return head;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    int n = 3;
    int arr[n] = {2, 3, 3};
    Node *head = convertArrToDLL(arr, n);
    printDLL(head);

    head = deleteAllOccurences(head, 3);
    printDLL(head);
}