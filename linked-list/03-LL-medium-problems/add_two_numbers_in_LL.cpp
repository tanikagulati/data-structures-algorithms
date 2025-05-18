#include <bits/stdc++.h>
using namespace std;

// Add two numbers represented by 2 linked lists respectively (in reverse order)

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

Node *addTwoNums(Node *head1, Node *head2)
{
    Node *temp1 = head1, *temp2 = head2;
    Node *dummy = new Node(-1, nullptr);
    Node *mover = dummy;
    int sum = 0, carry = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        sum = carry;
        if (temp1)
            sum += temp1->data;
        if (temp2)
            sum += temp2->data;

        mover->next = new Node(sum % 10, nullptr);
        carry = sum / 10;

        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
        mover = mover->next;
    }
    if (carry == 1)
    {
        mover->next = new Node(1, nullptr);
    }
    return dummy->next;
    // TC: O(max(n1,n2))
    // SC: O(n) -> For result
}

int main()
{
    int n1 = 2;
    int n2 = 1;
    int arr1[n1] = {2, 5};
    int arr2[n2] = {8};
    Node *head1 = createLL(arr1, n1);
    Node *head2 = createLL(arr2, n2);
    printLL(head1); // This is num1 in reverse order
    printLL(head2); // This is num2 in reverse order

    Node *sum = addTwoNums(head1, head2);
    printLL(sum);
}