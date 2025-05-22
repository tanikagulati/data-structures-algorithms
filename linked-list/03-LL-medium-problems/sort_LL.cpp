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

void merge2SortedArrays(vector<int> &v, int low, int mid, int high)
{
    int left = low, right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (v[left] < v[right])
        {
            temp.push_back(v[left]);
            left++;
        }
        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(v[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(v[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        v[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &v, int low, int high)
{
    if (low == high)
        return;
    int mid = (low + high) / 2;
    mergeSort(v, 0, mid);
    mergeSort(v, mid + 1, high);
    merge2SortedArrays(v, low, mid, high);
}

Node *sortLLBrute(Node *head)
{
    // LL to array -> sort -> array to LL
    if (head == NULL || head->next == NULL)
        return head;
    vector<int> v;
    Node *temp = head;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    mergeSort(v, 0, v.size() - 1);
    temp = head;
    temp->data = v[0];
    Node *newHead = temp;
    temp = temp->next;
    for (int i = 1; i < v.size(); i++)
    {
        temp->data = v[i];
        temp = temp->next;
    }
    return newHead;
    // TC: O(2n + nlogn)
    // SC: O(n)
}

Node *findMidofLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head;
    // Take fast one step ahead, so that 1st mid is returned in case of even length LL
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge2SortedLL(Node *list1, Node *list2)
{
    Node *temp = new Node(-1, nullptr);
    Node *dummyHead = temp;
    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
    }
    if (list1)
        temp->next = list1;
    else
        temp->next = list2;
    return dummyHead->next;
}

Node *sortLLOptimal(Node *head)
{
    // Merge sort in LL
    if (head == NULL || head->next == NULL)
        return head;

    Node *mid = findMidofLL(head); // O(n/2)
    Node *left = head;
    Node *right = mid->next;
    mid->next = nullptr;

    left = sortLLOptimal(left);
    right = sortLLOptimal(right);
    return merge2SortedLL(left, right);
    // TC: O((n+n/2) * logn)
    // SC: O(logn) Recursive stack space
}

int main()
{
    int n = 6;
    int arr[n] = {1, 4, 3, 5, 2, 2};
    Node *head = createLL(arr, n);
    printLL(head);

    // Brute:
    // head = sortLLBrute(head);
    // printLL(head);

    // Optimal:
    head = sortLLOptimal(head);
    printLL(head);
}