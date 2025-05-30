#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

public:
    Node(int data1, Node *next1, Node *random1)
    {
        data = data1;
        next = next1;
        random = random1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        random = nullptr;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        if (temp->random)
            cout << temp->random->data << endl;
        else
            cout << 'X' << endl;
        temp = temp->next;
    }
    cout << endl;
}

Node *createLL(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *cloneLLBrute(Node *head)
{
    // Hashmap storing original and copy node
    unordered_map<Node *, Node *> mp;
    // Create copy nodes and store along with corresponding original in hashmap
    Node *temp = head;
    while (temp)
    {
        Node *copy = new Node(temp->data);
        mp[temp] = copy;
        temp = temp->next;
    }
    // Assign pointers to copy nodes
    temp = head;
    while (temp)
    {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
    // TC: O(2n) -> Assuming hashmap takes O(1)
    // SC: O(2n) -> n for hashmap(extra), n for copy nodes(reqd as per question)
}

Node *cloneLLOptimal(Node *head)
{
    // Create new nodes in the middle
    // Assign random pointers
    // Assign next pointers
    Node *temp = head;
    while (temp)
    {
        Node *copy = new Node(temp->data);
        copy->next = temp->next;
        temp->next = copy;
        temp = temp->next->next;
    }

    temp = head;
    while (temp)
    {
        temp->next->random = temp->random ? temp->random->next : NULL;
        temp = temp->next->next;
    }

    temp = head;
    Node *dummyHead = new Node(-1);
    Node *mover = dummyHead;
    while (temp)
    {
        mover->next = temp->next;
        mover = mover->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyHead->next;
    // TC: O(3n)
    // SC: O(n)
}

int main()
{
    int n = 4;
    int arr[n] = {1, 2, 3, 4};

    Node *head = createLL(arr, n);

    // Random setup
    head->random = head->next->next;          // 1 -> 3
    head->next->random = head;                // 2 -> 1
    head->next->next->random = head->next;    // 3 -> 2
    head->next->next->next->random = nullptr; // 4 -> NULL

    printLL(head);

    head = cloneLLBrute(head);
    printLL(head);

    head = cloneLLOptimal(head);
    printLL(head);
}