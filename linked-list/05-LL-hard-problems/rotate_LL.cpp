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

int findLengthOfLL(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node *rotateLL(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    int n = findLengthOfLL(head);
    if (k % n == 0)
        return head;
    k = k % n;

    Node *temp = head;
    int cnt = 0;
    Node *newHead = nullptr;
    while (temp->next)
    {
        cnt++;
        if (cnt == n - k)
        {
            newHead = temp->next;
            temp->next = nullptr;
            temp = newHead;
        }
        else
        {
            temp = temp->next;
        }
    }
    temp->next = head;
    return newHead;
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    Node *head = createLL(arr, n);
    printLL(head);

    head = rotateLL(head, 9);
    printLL(head);
}