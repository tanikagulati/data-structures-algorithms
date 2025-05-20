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

Node *middleOfLLBrute(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    int mid = (cnt / 2) + 1;
    temp = head;
    while (--mid)
    {
        temp = temp->next;
    }
    return temp;
    // TC: O(n + n/2)
    // SC: O(1)
}

Node *middleOfLLOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    // TC: O(n/2)
    // SC: O(1)
}

int main()
{
    int n = 5;
    int arr[n] = {2, 6, 3, 9, 1};
    Node *head = createLL(arr, n);
    printLL(head);

    Node *mid = middleOfLLBrute(head);
    cout << mid->data << endl;

    // Optimal: Tortoise & hare method (Slow & fast pointers)
    mid = middleOfLLOptimal(head);
    cout << mid->data << endl;
}