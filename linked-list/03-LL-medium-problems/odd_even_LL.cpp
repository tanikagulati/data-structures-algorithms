#include <bits/stdc++.h>
using namespace std;

// Segregate and group together odd and even indices in the LL

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

Node *oddEvenLLBrute(Node *head)
{
    // Store data in arr in the reqd sequence, then replace in the original LL
    Node *temp = head;
    vector<int> v;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next ? temp->next->next : nullptr;
    }
    temp = head->next;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next ? temp->next->next : nullptr;
    }
    temp = head;
    int i = 0;
    while (temp)
    {
        temp->data = v[i];
        temp = temp->next;
        i++;
    }
    return head;
    // TC: O(2n)
    // SC: O(n)
}

Node *oddEvenLLOptimal(Node *head)
{
    if (head->next == NULL)
        return head;
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;
    while (even && even->next) // Odd is always before even so no check reqd
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
    // TC: (O(n/2)*2) = O(n) -> Because each node is visited once -> Imp
    // SC: O(1)
}

int main()
{
    int n = 5;
    int arr[n] = {2, 7, 5, 1, 4};
    Node *head = createLL(arr, n);
    printLL(head);

    // Brute:
    // head = oddEvenLLBrute(head);
    // printLL(head);

    // Optimal:
    head = oddEvenLLOptimal(head);
    printLL(head);
}