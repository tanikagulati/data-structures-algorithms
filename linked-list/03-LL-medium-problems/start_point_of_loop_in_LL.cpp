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
    mover->next = head->next; // For cycle
    return head;
}

Node *startingPointOfLoopOptimal(Node *head)
{
    // Step1: Detection of loop (collision of slow and fast)
    // Step2: Find starting point
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    Node *head = createLL(arr, n);

    // Brute: Hashing visited nodes -> same as detecting loop problem

    // Optimal: TH method
    Node *loopStart = startingPointOfLoopOptimal(head);
    if (loopStart)
        cout << loopStart->data << endl;
    else
        cout << -1 << endl;
}