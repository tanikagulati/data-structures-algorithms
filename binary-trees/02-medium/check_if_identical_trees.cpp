#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/same-tree/description/

bool isSameTree(Node *p, Node *q)
{
    // Use any traversal, compare each node data
    if (p == NULL || q == NULL)
        return p == q;

    return (p->data == q->data && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    // TC: O(n)
    // SC: O(n)
}

int main()
{
    struct Node *p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);
    p->left->left = new Node(4);
    p->left->right = new Node(5);

    struct Node *q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);
    q->left->left = new Node(4);
    q->left->right = new Node(5);

    cout << isSameTree(p, q) << endl;
}