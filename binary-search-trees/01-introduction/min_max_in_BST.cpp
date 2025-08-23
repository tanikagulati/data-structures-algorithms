#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// Find minimum/maximum element in a BST

int findMin(Node *root)
{
    if (!root)
        return -1;
    while (root->left)
        root = root->left;
    return root->data;
    // TC: O(h)
    // SC: O(1)
}

int findMax(Node *root)
{
    if (!root)
        return -1;
    while (root->right)
        root = root->right;
    return root->data;
    // TC: O(h)
    // SC: O(1)
}

int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->left->left->left = new Node(1);

    cout << findMin(root) << endl;
    cout << findMax(root) << endl;
}