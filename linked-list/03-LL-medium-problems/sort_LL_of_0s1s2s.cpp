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

Node *sort012sLL(Node *head)
{
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *dummyHeadFor0 = new Node(-1, nullptr), *zero = dummyHeadFor0;
        Node *dummyHeadFor1 = new Node(-1, nullptr), *one = dummyHeadFor1;
        Node *dummyHeadFor2 = new Node(-1, nullptr), *two = dummyHeadFor2;

        Node *temp = head;
        while (temp)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = temp;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = temp;
            }
            else
            {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        zero->next = dummyHeadFor1->next ? dummyHeadFor1->next : dummyHeadFor2->next;
        one->next = dummyHeadFor2->next;
        two->next = nullptr;

        delete dummyHeadFor1, dummyHeadFor2, zero, one, two, temp;
        return dummyHeadFor0->next;
        // TC: O(n)
        // SC: O(1)
    }
}

int main()
{
    int n = 6;
    int arr[n] = {0, 2, 2, 0, 2, 0};
    Node *head = createLL(arr, n);
    printLL(head);

    // Brute: Data replacement -> store the no of 0,1,2, then replace data in LL acc to counts
    // TC: O(2n)

    // Optimal: Changing pointers
    head = sort012sLL(head);
    printLL(head);
}