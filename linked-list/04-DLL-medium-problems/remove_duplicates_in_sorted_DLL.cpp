#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

void printDLL(Node *head)
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

Node *convertArrToDLL(int arr[], int n)
{
    Node *head = new Node(arr[0], nullptr, nullptr);
    Node *prev = head;
    for (int i = 1; i < n; i++)
    {
        Node *node = new Node(arr[i], nullptr, prev);
        prev->next = node;
        prev = prev->next;
    }
    return head;
    // TC: O(n)
}

Node *removeDuplicates(Node *head)
{
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *temp = head;
        while (temp && temp->next)
        {
            Node *next = temp->next;
            while (next != NULL && temp->data == next->data)
            {
                Node *duplicate = next;
                next = next->next;
                delete duplicate;
            }
            temp->next = next;
            if (next)
                next->prev = temp;

            temp = temp->next;
        }
        return head;
        // TC: O(n) (Each node is visited only once)
        // SC: O(1)
    }
}

int main()
{
    int n = 7;
    int arr[n] = {1, 1, 1, 2, 3, 3, 4};
    Node *head = convertArrToDLL(arr, n);
    printDLL(head);

    head = removeDuplicates(head);
    printDLL(head);
}