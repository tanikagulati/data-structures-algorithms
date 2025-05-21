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

Node *deleteMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    slow->next = nullptr;
    delete slow;
    return head;
    // TC: O(n/2)
    // SC: O(1)
}

Node *deleteMiddle2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    // Skip 1 step of slow pointer
    fast = fast->next->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Now, slow points to pre middle
    Node *temp = slow->next;
    slow->next = slow->next->next;
    temp->next = nullptr;
    delete temp;
    return head;
    // TC: O(n/2)
    // SC: O(1)
}

int main()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    Node *head = createLL(arr, n);
    printLL(head);

    // Brute: Find length in 1 pass, reach pre-middle in 2nd pass and delete middle
    // TC: O(n+n/2), SC: O(1)

    // Optimal: Using third variable -> prev
    head = deleteMiddle(head);
    printLL(head);

    // Optimal2: Slight change in TH method
    head = deleteMiddle2(head);
    printLL(head);
}