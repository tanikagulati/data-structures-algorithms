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

Node *convertArrayToLL(int arr[], int n)
{
    Node *head = new Node(arr[0], nullptr);
    Node *mover = head; // Never tamper the head
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
    // TC: O(n)
}

int lengthOfLL(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
    // TC: O(n)
}

int checkIfPresent(Node *head, int target)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == target)
            return 1;
        temp = temp->next;
    }
    return 0;
    // TC: O(n)
}

int main()
{
    // Convert array to LL
    int arr[4] = {1, 2, 3, 4};
    Node *head = convertArrayToLL(arr, 4);

    // Traversal of LL -> O(n)
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Length of LL
    cout << lengthOfLL(head) << endl;

    // Search in LL
    cout << checkIfPresent(head, 3) << endl;
}

// NULL (old C style) and nullptr(introduced in C++11) can be used interchangeably in LL pointer stuff but nullptr is preferred.
// Because NULL can lead to ambiguous overload resolution in functions that take either an integer or a pointer; whereas nullptr clearly represents a pointer literal.