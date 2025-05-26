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

vector<pair<int, int>> findPairsWithGivenSumBrute(Node *head, int sum)
{
    vector<pair<int, int>> ans;
    if (head == NULL)
        return ans;
    Node *temp1 = head;
    while (temp1->next)
    {
        Node *temp2 = temp1->next;
        while (temp2 && temp1->data + temp2->data <= sum)
        {
            if (temp1->data + temp2->data == sum)
            {
                ans.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
    // TC: ~O(n1*n2)
    // SC: O(1)
}

Node *findTail(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    return temp;
}

vector<pair<int, int>> findPairsWithGivenSumOptimal(Node *head, int sum)
{
    // Two pointers
    vector<pair<int, int>> ans;
    if (head == NULL)
        return ans;
    Node *left = head;
    Node *right = findTail(head); // O(n)

    while (left->data < right->data)
    {
        if (left->data + right->data == sum)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < sum)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return ans;
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 9};
    Node *head = convertArrToDLL(arr, n);
    printDLL(head);

    // Given: LL is sorted and has distinct numbers

    vector<pair<int, int>> ans = findPairsWithGivenSumBrute(head, 5);
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;

    ans = findPairsWithGivenSumOptimal(head, 5);
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
}