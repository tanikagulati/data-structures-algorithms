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

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    Node *dummyNode = new Node(-1, nullptr);
    Node *temp = dummyNode;
    Node *t1 = head1;
    Node *t2 = head2;

    while (t1 && t2)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            t1 = t1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = t2;
            t2 = t2->next;
            temp = temp->next;
        }
    }

    if (t1)
        temp->next = t1;
    if (t2)
        temp->next = t2;

    return dummyNode->next;
    // TC: O(n1+n2)
    // SC: O(1)
}

Node *mergeKSortedListsBrute(vector<Node *> listOfHeads)
{
    Node *head = listOfHeads[0];
    for (int i = 1; i < listOfHeads.size(); i++)
    {
        head = mergeTwoSortedLL(head, listOfHeads[i]);
    }
    return head;
    // TC: O(N^2 * M) ~ N^3
    // SC: O(1)
}

Node *mergeKSortedListsOptimal(vector<Node *> listOfHeads)
{
    // Minheap (using priority queue)
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;
    for (int i = 0; i < listOfHeads.size(); i++)
    {
        pq.push({listOfHeads[i]->data, listOfHeads[i]});
    }
    Node *dummyHead = new Node(-1, nullptr);
    Node *temp = dummyHead;
    while (!pq.empty())
    {
        temp->next = pq.top().second;
        pq.pop();
        temp = temp->next;
        if (temp->next)
        {
            pq.push({temp->next->data, temp->next});
        }
    }
    return dummyHead->next;
    // TC: O(klogk + (n*k)logk)
    // SC: O(k)
}

int main()
{
    int arr1[4] = {1, 4, 6, 7};
    int arr2[7] = {2, 2, 5, 7, 8, 9, 10};
    int arr3[5] = {3, 4, 7, 9, 11};

    Node *head1 = createLL(arr1, 4);
    printLL(head1);
    Node *head2 = createLL(arr2, 7);
    printLL(head2);
    Node *head3 = createLL(arr3, 5);
    printLL(head3);

    vector<Node *> listOfHeads = {head1, head2, head3};

    // Node *head = mergeKSortedListsBrute(listOfHeads);
    // printLL(head);

    Node *head = mergeKSortedListsOptimal(listOfHeads);
    printLL(head);
}