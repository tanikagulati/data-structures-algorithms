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

Node *removeNthFromEndBrute(Node *head, int n)
{
    if (head == NULL)
        return head;
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    if (cnt == n)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
    int prevOfTargetIndex = cnt - n;
    temp = head;
    while (temp)
    {
        prevOfTargetIndex--;
        if (prevOfTargetIndex == 0)
            break;
        temp = temp->next;
    }
    Node *toBedeleted = temp->next;
    temp->next = temp->next->next;
    delete toBedeleted;
    return head;
    // TC: O(2n)
    // SC: O(1)
}

Node *removeNthFromEndOptimal(Node *head, int n)
{
    Node *fast = head;
    Node *slow = head;
    // Move fastptr n times
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    // If fast reached null, then n = len of LL -> head is to be deleted
    if (fast == NULL)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
    // Move fast and slow together until fast is not null
    // Eventually slow will end up at prev of target index
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *toBeDeleted = slow->next;
    slow->next = slow->next->next;
    delete toBeDeleted;
    return head;
    // O(n)
    // O(1)
}

int main()
{
    int n = 6;
    int arr[n] = {2, 4, 3, 7, 1, 6};
    Node *head = createLL(arr, n);
    printLL(head);

    // Brute:
    head = removeNthFromEndBrute(head, 1);
    printLL(head);

    // Optimal:
    head = removeNthFromEndOptimal(head, 3);
    printLL(head);
}