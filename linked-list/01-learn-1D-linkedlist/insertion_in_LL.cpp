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
    // TC: O(n)
}

Node *createLL()
{
    int n = 4;
    int arr[n] = {2, 5, 6, 7};
    Node *head = new Node(arr[0], nullptr);
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
    // TC: O(n)
}

Node *insertAtHead(Node *head, int element)
{
    Node *newNode = new Node(element, head);
    return newNode;
    // TC: O(1)
}

Node *insertAtTail(Node *head, int element)
{
    Node *newNode = new Node(element, nullptr);
    if (head == NULL)
        return newNode;
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
    // TC: O(n)
}

Node *insertAtPosition(Node *head, int element, int position)
{
    if (head == NULL)
        return head;
    if (position == 1)
        return new Node(element, head);

    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == position - 1)
        {
            Node *newNode = new Node(element, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
    // TC: O(n)
}

Node *insertAtValue(Node *head, int element, int value)
{
    if (head == NULL)
        return head;
    if (head->data == value)
        return new Node(element, head);

    Node *temp = head;
    while (temp->next)
    {
        if (temp->next->data == value)
        {
            Node *newNode = new Node(element, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
    // TC: O(n)
}

int main()
{
    Node *head = createLL();
    printLL(head);

    Node *newHead = insertAtHead(head, 1);
    printLL(newHead);

    newHead = insertAtTail(newHead, 10);
    printLL(newHead);

    newHead = insertAtPosition(newHead, 8, 3);
    printLL(newHead);

    // Insert element right before given value
    newHead = insertAtValue(newHead, 15, 10);
    printLL(newHead);
}