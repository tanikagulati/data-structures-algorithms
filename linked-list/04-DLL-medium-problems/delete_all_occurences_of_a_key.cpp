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

Node *deleteAllOcuurences(Node *head, int k)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = temp->next;
                temp->next = nullptr;
                delete temp;
                head->prev = nullptr;
                temp = head;
            }
            else if (temp->next == NULL)
            {
                temp->prev = nullptr;
                delete temp;
                prev->next = nullptr;
                return head;
            }
            else
            {
                temp->prev = nullptr;
                prev->next = temp->next;
                temp->next->prev = prev;
                temp->next = nullptr;
                delete temp;
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    int n = 3;
    int arr[n] = {3, 3, 3};
    Node *head = convertArrToDLL(arr, n);
    printDLL(head);

    head = deleteAllOcuurences(head, 3);
    printDLL(head);
}