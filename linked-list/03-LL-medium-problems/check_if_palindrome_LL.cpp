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

bool checkIfPalindromeBrute(Node *head)
{
    Node *temp = head;
    stack<int> st;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (temp->data != st.top())
        {
            return false;
        }
        temp = temp->next;
        st.pop();
    }
    return true;
    // TC: O(2n)
    // SC: O(n)
}

Node *reverseLL(Node *head)
{ // 1 2 3
    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {
        Node *next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    printLL(prev);
    return prev;
}

bool checkIfPalindromeOptimal(Node *head)
{
    // 1-> Find middle (TH method) O(n/2)
    // 2-> Reverse second half O(n/2)
    // 3-> Compare both halves O(n/2)
    // 4-> Reverse second half again (for orig LL to remain same) O(n/2)
    if (head == NULL || head->next == NULL)
        return true;
    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = reverseLL(slow->next);
    Node *firstHalfHead = head;
    Node *secondHalfHead = newHead;
    while (secondHalfHead)
    {
        if (firstHalfHead->data != secondHalfHead->data)
        {
            reverseLL(newHead);
            return false;
        }
        firstHalfHead = firstHalfHead->next;
        secondHalfHead = secondHalfHead->next;
    }
    reverseLL(newHead);
    return true;
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 3, 2, 1};
    Node *head = createLL(arr, n);
    printLL(head);

    // Brute: Using stack
    cout << checkIfPalindromeBrute(head) << endl;

    // Optimal:
    cout << checkIfPalindromeOptimal(head) << endl;
}