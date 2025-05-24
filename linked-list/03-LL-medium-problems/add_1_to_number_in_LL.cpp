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

Node *reverseLL(Node *head)
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

Node *addOneToLLBrute(Node *head)
{
    head = reverseLL(head);
    int carry = 1;
    Node *temp = head;
    while (temp)
    {
        int num = temp->data + carry;
        temp->data = num % 10;
        carry = num / 10;
        if (carry == 0) // Addition is done
            break;
        temp = temp->next;
    }
    head = reverseLL(head);
    if (carry == 1)
    {
        return new Node(1, head);
    }
    return head;
    // TC: O(3n)
    // SC: O(1)
}

int main()
{
    int n = 4;
    int arr[n] = {9, 9, 9, 9};
    Node *head = createLL(arr, n);
    printLL(head);

    head = addOneToLLBrute(head);
    printLL(head);
}