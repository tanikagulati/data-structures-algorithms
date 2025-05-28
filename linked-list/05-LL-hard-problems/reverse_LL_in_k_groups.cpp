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

Node *findKthNode(Node *head, int k)
{
    Node *temp = head;
    while (temp != NULL && --k)
    {
        temp = temp->next;
    }
    return temp;
}

Node *reverseLL(Node *head)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {
        Node *next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

Node *reverseLLInKGroups(Node *head, int k)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {
        Node *kthNode = findKthNode(temp, k);
        if (kthNode == NULL)
        {
            if (prev)
                prev->next = temp;
            break;
        }

        Node *nextNode = kthNode->next;
        kthNode->next = nullptr;
        Node *newHead = reverseLL(temp);

        if (temp == head)
            head = newHead;
        else
            prev->next = newHead;

        prev = temp;
        temp = nextNode;
    }
    return head;
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    int n = 10;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *head = createLL(arr, n);
    printLL(head);

    head = reverseLLInKGroups(head, 3);
    printLL(head);
}