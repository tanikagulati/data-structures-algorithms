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

Node *findIntersectionBrute(Node *head1, Node *head2)
{
    // Hashing nodes of one of the LL and then compare with nodes of second LL
    if (head1 == NULL || head2 == NULL)
        return NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;
    map<Node *, int> mp;
    while (temp1)
    {
        mp[temp1] = 1;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        if (mp.find(temp2) != mp.end())
        {
            return temp2;
        }
        temp2 = temp2->next;
    }
    return NULL;
    // TC: O(n1logn1 + n2logn2)
    // SC: O(n1)
}

Node *intersection(Node *t1, Node *t2, int cnt1, int cnt2)
{
    int diff = cnt2 - cnt1;
    while (t2)
    {
        if (diff == 0)
            break;
        diff--;
        t2 = t2->next;
    }
    while (t1 && t2)
    {
        if (t1 == t2)
            return t1;
        t1 = t1->next;
        t2 = t2->next;
    }
    return NULL;
}

Node *findIntersectionBetter(Node *head1, Node *head2)
{
    // Find length of both, cover up the diff distance in longer LL
    // Now, since the lengths have become equal, compare and find intersection
    if (head1 == NULL || head2 == NULL)
        return NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;
    int cnt1 = 0, cnt2 = 0;
    while (temp1)
    {
        cnt1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        cnt2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if (cnt1 < cnt2)
        return intersection(temp1, temp2, cnt1, cnt2);
    else
        return intersection(temp2, temp1, cnt2, cnt1);
    return NULL;
    // TC: O(n1+n2+n2) ~ O(n1 + 2*n2)
    // SC: O(1)
}

Node *findIntersectionOptimal(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
            return temp1;
        if (temp1 == NULL)
            temp1 = head2;
        if (temp2 == NULL)
            temp2 = head1;
    }
    return temp1;
    // TC: O(n1+n2)
    // SC: O(1)
}

int main()
{
    int n1 = 5;
    int n2 = 2;
    int arr1[n1] = {3, 2, 7, 4, 1};
    int arr2[n2] = {5, 9};
    Node *head1 = createLL(arr1, n1);
    Node *head2 = createLL(arr2, n2);
    head2->next->next = head1->next; // For intersection

    Node *ans = findIntersectionBrute(head1, head2);
    cout << ans->data << endl;

    ans = findIntersectionBetter(head1, head2);
    cout << ans->data << endl;

    // Revisit
    ans = findIntersectionOptimal(head1, head2);
    cout << ans->data << endl;
}