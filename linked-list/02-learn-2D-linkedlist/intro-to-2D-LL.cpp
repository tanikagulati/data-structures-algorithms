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

Node *convertArrToDLL()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
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

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
    // TC: O(1)
}

Node *deleteTail(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    temp->prev = nullptr;
    return head;
    // TC: O(n)
}

Node *deleteKthElement(Node *head, int position)
{
    if (head == NULL)
        return NULL;

    if (position == 1)
    {
        Node *prev = head;
        head = head->next;
        head->prev = nullptr;
        prev->next = nullptr;
        delete prev;
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        if (cnt == position)
        {
            Node *prev = temp->prev;
            Node *next = temp->next;

            prev->next = next;
            if (next)
            {
                next->prev = prev;
            }

            prev = nullptr;
            next = nullptr;
            delete temp;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *deleteElement(Node *head, int element)
{
    if (head == NULL)
        return NULL;

    if (head->data == element)
    {
        Node *prev = head;
        head = head->next;
        head->prev = nullptr;
        prev->next = nullptr;
        delete prev;
        return head;
    }
    Node *temp = head;
    while (temp)
    {
        if (temp->data == element)
        {
            Node *prev = temp->prev;
            Node *next = temp->next;

            prev->next = next;
            if (next)
            {
                next->prev = prev;
            }

            prev = nullptr;
            next = nullptr;
            delete temp;
            break;
        }
        temp = temp->next;
    }
    return head;
    // TC:O(n)
}

void deleteNode(Node *temp)
{
    Node *front = temp->next;
    Node *back = temp->prev;
    if (front == NULL)
    {
        back->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }
    back->next = front;
    front->prev = back;
    delete temp;
    // TC: O(1)
}

Node *insertAtHead(Node *head, int element)
{
    if (head == NULL)
        return new Node(element, nullptr, nullptr);

    Node *newNode = new Node(element, head, nullptr);
    head->prev = newNode;
    return newNode;
    // TC: O(1)
}

Node *insertAtTail(Node *head, int element)
{
    if (head == NULL)
        return new Node(element, nullptr, nullptr);
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(element, nullptr, temp);
    temp->next = newNode;
    return head;
    // TC: O(n)
}

Node *insertAtPosition(Node *head, int element, int position)
{
    if (head == NULL)
        return new Node(element, nullptr, nullptr);
    if (position == 1)
    {
        Node *newNode = new Node(element, head, nullptr);
        head->prev = newNode;
        return newNode;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        if (cnt == position)
            break;
        temp = temp->next;
    }
    Node *newNode = new Node(element, temp, temp->prev);
    temp->prev->next = newNode;
    temp->prev = newNode;

    return head;
    // TC: O(n)
}

void insertBeforeNode(Node *temp, int element)
{
    Node *newNode = new Node(element, temp, temp->prev);
    temp->prev->next = newNode;
    temp->prev = newNode;
    // TC: O(1)
}

int main()
{
    Node *head = convertArrToDLL();
    printDLL(head);

    head = deleteHead(head);
    printDLL(head);

    head = deleteTail(head);
    printDLL(head);

    head = deleteKthElement(head, 2);
    printDLL(head);

    head = deleteElement(head, 4);
    printDLL(head);

    deleteNode(head->next); // Except the head
    printDLL(head);

    head = insertAtHead(head, 1);
    printDLL(head);

    head = insertAtTail(head, 7);
    printDLL(head);

    head = insertAtPosition(head, 6, 3);
    printDLL(head);

    insertBeforeNode(head->next->next, 8); // Except the head
    printDLL(head);
}