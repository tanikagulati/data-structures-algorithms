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
    // mover->next = head->next; // -> For cycle
    return head;
}

bool detectCycleBrute(Node *head)
{
    Node *temp = head;
    map<Node *, int> mp;
    while (temp)
    {
        if (mp[temp] == 1)
            return true;
        mp[temp] = 1;
        temp = temp->next;
    }
    return false;
    // TC: O(n * 2 * logn)
    // SC: O(n)
}

bool detectCycleOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // Bound to meet if cycle exists
        {
            return true;
        }
    }
    return false;
    // TC: ~O(n)
    // SC: O(1)
}

int main()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    Node *head = createLL(arr, n);
    // printLL(head); // Can't print if cycle exists (endless LL)

    // Brute: Hashing visited node
    cout << detectCycleBrute(head) << endl;

    // Optimal: TH method
    cout << detectCycleOptimal(head) << endl;
}