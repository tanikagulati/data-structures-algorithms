#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/count-complete-tree-nodes/description/

int leftHeight(Node *root)
{
    int lh = 0;
    while (root)
    {
        lh++;
        root = root->left;
    }
    return lh;
    // O(log n)
}

int rightHeight(Node *root)
{
    int rh = 0;
    while (root)
    {
        rh++;
        root = root->right;
    }
    return rh;
    // O(log n)
}

int count(Node *root)
{
    if (!root)
        return 0;
    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh)
        return (1 << lh) - 1; // (2 ^ lh) - 1

    return 1 + count(root->left) + count(root->right);
    // TC: O((logn)^2) -> logn (traversal) * logn (finding height)
    // SC: O(log n)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    // Brute: Any traversal with cnt variable

    // Optimal:
    cout << count(root) << endl;
}