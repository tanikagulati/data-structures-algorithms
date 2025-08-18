#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

Node *lca(Node *root, Node *p, Node *q)
{
    if (root == NULL || root == p || root == q)
        return root;

    Node *left = lca(root->left, p, q);
    Node *right = lca(root->right, p, q);

    if (left && right)
        return root;
    return left ? left : right;
    // O(n)
    // O(h)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *p = root->left->right;
    Node *q = root->right->left;

    // Brute:
    // Find root to node path for both p and q, the common node from end will be lca
    // If path of p = 1->2->5, q = 1->3->6, LCA = 1

    // Optimal: Single traversal
    cout << lca(root, p, q)->data << endl;
}