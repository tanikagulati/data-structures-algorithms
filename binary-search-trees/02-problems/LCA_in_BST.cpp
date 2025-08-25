#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

Node *lcaIterative(Node *root, Node *p, Node *q)
{
    while (root)
    {
        int val = root->data;
        if (val > p->data && val > q->data)
            root = root->left;
        else if (val < p->data && val < q->data)
            root = root->right;
        else
            break;
    }
    return root;
    // TC: O(h)
    // Sc: O(1)
}

Node *lcaRecursive(Node *root, Node *p, Node *q)
{
    if (!root)
        return NULL;
    int val = root->data;
    if (val > p->data && val > q->data)
        return lcaRecursive(root->left, p, q);

    else if (val < p->data && val < q->data)
        return lcaRecursive(root->right, p, q);

    return root;
    // TC: O(h)
    // SC: O(h)
}

int main()
{
    struct Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    Node *p = root->left;
    Node *q = root->left->right;

    cout << lcaIterative(root, p, q)->data << endl;

    cout << lcaRecursive(root, p, q)->data << endl;
}