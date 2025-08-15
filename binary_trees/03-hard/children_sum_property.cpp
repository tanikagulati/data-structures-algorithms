#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://www.geeksforgeeks.org/problems/children-sum-parent/1

int childrenSumProperty(Node *root)
{
    if (!root || (!root->left && !root->right))
        return 1;

    int left = root->left ? root->left->data : 0;
    int right = root->right ? root->right->data : 0;

    if (root->data != left + right)
        return 0;
    return (childrenSumProperty(root->left) && childrenSumProperty(root->right));
    // TC: O(n)
    // SC: O(h)
}

void convertTree(Node *root)
{
    if (!root || (!root->left && !root->right))
        return;
    int children = 0;
    if (root->left)
        children += root->left->data;
    if (root->right)
        children += root->right->data;

    if (children < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    else // This else part is not really required
        root->data = children;

    convertTree(root->left);
    convertTree(root->right);

    children = 0;
    if (root->left)
        children += root->left->data;
    if (root->right)
        children += root->right->data;
    root->data = children;
    // TC: O(n)
    // SC: O(h)
}

void traverse(Node *root)
{
    // Root Left Right
    if (root == NULL)
        return;
    cout << root->data << " ";
    traverse(root->left);
    traverse(root->right);
}

int main()
{
    struct Node *root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    // Problem1: Determine whether the tree follows children sum property
    cout << childrenSumProperty(root) << endl;

    // Problem 2: Convert a tree (by incrementing node data) such that it follows children sum property (Imp)
    convertTree(root);
    traverse(root); // To verify
}