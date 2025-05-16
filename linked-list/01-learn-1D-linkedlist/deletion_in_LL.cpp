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

Node *createLL()
{
    int n = 8;
    int arr[n] = {2, 5, 6, 7, 9, 10, 12, 15};
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

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL)
        return head;

    Node *temp = head;

    if (temp->next == nullptr) // If there is only one element
    {
        free(temp);
        return nullptr;
    }

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node *deleteKthElement(Node *head, int k)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    // For LL algorithms, always think of edge cases first
    // Removal of head needs to be handled separately since there is no prev in this case
    if (k == 1)
    {
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 1;
    Node *prev = head;
    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteElement(Node *head, int k)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    if (head->data == k)
    {
        head = head->next;
        free(temp);
        return head;
    }
    Node *prev = head;
    while (temp)
    {
        if (temp->data == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    Node *head = createLL();
    printLL(head);

    Node *newHead = deleteHead(head);
    printLL(newHead);

    newHead = deleteTail(newHead);
    printLL(newHead);

    // Delete by position (1-based)
    newHead = deleteKthElement(newHead, 2);
    printLL(newHead);

    // Delete by value
    newHead = deleteElement(newHead, 10);
    printLL(newHead);
}
