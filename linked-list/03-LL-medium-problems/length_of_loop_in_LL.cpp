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
    mover->next = head->next; // For cycle
    return head;
}

int lengthOfLoopBrute(Node *head)
{
    map<Node *, int> mp;
    int currIndex = 1;
    Node *temp = head;
    while (temp)
    {
        if (mp.find(temp) != mp.end())
        {
            return currIndex - mp[temp];
        }
        mp[temp] = currIndex;
        currIndex++;
        temp = temp->next;
    }
    return 0;
    // TC: O(n * 2 * logn)
    // SC: O(n)
}

int lengthOfLoopOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            fast = fast->next;
            int cnt = 1;
            while (slow != fast)
            {
                fast = fast->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    Node *head = createLL(arr, n);

    // Brute: Hashing
    cout << lengthOfLoopBrute(head) << endl;

    // Optimal: TH method
    cout << lengthOfLoopOptimal(head) << endl;
}