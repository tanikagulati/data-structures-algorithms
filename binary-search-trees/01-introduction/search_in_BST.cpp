#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// BST: L < N < R (For each node)
// All nodes in left subtree should be smaller than node
// All nodes in right subtree should be greater than node

// https://leetcode.com/problems/search-in-a-binary-search-tree/description/

Node *searchBST(Node *root, int val)
{
    while (root && root->data != val)
        root = val < root->data ? root->left : root->right;
    return root;
    // TC: O(log n)
    // SC: O(log n)
}

int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    int val = 2;

    cout << searchBST(root, val)->data << endl;
}