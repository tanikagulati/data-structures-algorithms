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

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    Node *dummyNode = new Node(-1, nullptr);
    Node *temp = dummyNode;
    Node *t1 = head1;
    Node *t2 = head2;

    while (t1 && t2)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            t1 = t1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = t2;
            t2 = t2->next;
            temp = temp->next;
        }
    }

    if (t1)
        temp->next = t1;
    if (t2)
        temp->next = t2;

    return dummyNode->next;
    // TC: O(n1+n2)
    // SC: O(1)
}

int main()
{
    int n1 = 4;
    int n2 = 7;
    int arr1[n1] = {1, 4, 6, 7};
    int arr2[n2] = {2, 2, 5, 7, 8, 9, 10};

    Node *head1 = createLL(arr1, n1);
    printLL(head1);
    Node *head2 = createLL(arr2, n2);
    printLL(head2);

    Node *head = mergeTwoSortedLL(head1, head2);
    printLL(head);
}