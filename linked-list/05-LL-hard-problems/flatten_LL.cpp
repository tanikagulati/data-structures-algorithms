#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

public:
    Node(int data1)
    {
        data = data1;
        next = NULL;
        bottom = NULL;
    }
    Node(int data1, Node *next1, Node *bottom1)
    {
        data = data1;
        next = next1;
        bottom = bottom1;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
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
        mover->bottom = temp;
        mover = temp;
    }
    return head;
}

Node *flattenLLBrute(Node *head)
{
    // Store all elements into a single array
    // Sort the array
    // Form a new LL
    vector<int> v;
    Node *temp = head;
    Node *temp2 = nullptr;
    while (temp)
    {
        v.push_back(temp->data);
        temp2 = temp->bottom;
        while (temp2)
        {
            v.push_back(temp2->data);
            temp2 = temp2->bottom;
        }
        temp = temp->next;
    }

    sort(v.begin(), v.end());

    Node *result = new Node(v[0]);
    temp = result;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newNode = new Node(v[i]);
        temp->bottom = newNode;
        temp = temp->bottom;
    }
    return result;
    // TC: O(N + NlogN + N) -> N = n*m
    // SC: O(2N) -> N = n * m
}

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    Node *t1 = head1;
    Node *t2 = head2;

    while (t1 && t2)
    {
        if (t1->data < t2->data)
        {
            temp->bottom = t1;
            t1 = t1->bottom;
            temp = temp->bottom;
        }
        else
        {
            temp->bottom = t2;
            t2 = t2->bottom;
            temp = temp->bottom;
        }
    }

    if (t1)
        temp->bottom = t1;
    if (t2)
        temp->bottom = t2;

    return dummyNode->bottom;
    // TC: O(n1+n2)
    // SC: O(1)
}

Node *flattenLLOptimal(Node *head)
{
    Node *temp1 = head;
    Node *temp2 = temp1->next;
    while (temp2)
    {
        temp1 = mergeTwoSortedLL(temp1, temp2);
        temp2 = temp2->next;
    }
    return temp1;
    /*
    O(2M + 3M + 4M + ... + NM)
    = M * (2 + 3 + 4 + ... + N)
    = M * (N(N+1)/2 - 1)

    TC: O(N^2 * M)
    SC: O(1)
    */
}

Node *flattenLLRecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *merged = flattenLLRecursive(head->next);
    return mergeTwoSortedLL(merged, head);
    // TC: O(N^2 * M)
    // SC: O(n) -> Recursive stack space
}

int main()
{
    // Given: LL is sorted, both top to bottom and left to right
    // Flatten it into a single LL top to bottom

    int arr1[4] = {5, 7, 8, 30};
    Node *node1 = createLL(arr1, 4);
    printLL(node1);
    int arr2[2] = {10, 20};
    Node *node2 = createLL(arr2, 2);
    printLL(node2);
    int arr3[3] = {19, 22, 50};
    Node *node3 = createLL(arr3, 3);
    printLL(node3);

    node1->next = node2;
    node2->next = node3;

    // 5  10  19
    // 7  20  22
    // 8      50
    // 30

    Node *head = flattenLLBrute(node1);
    printLL(head);

    // head = flattenLLOptimal(node1);
    // printLL(head);

    head = flattenLLRecursive(node1);
    printLL(head);
}