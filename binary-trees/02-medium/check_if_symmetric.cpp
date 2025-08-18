#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/symmetric-tree/description/

bool isSymmetric(Node *left, Node *right)
{
    if (!left || !right)
        return left == right;

    if (left->data != right->data)
        return false;

    return (isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left));
    // TC: O(n)
    // SC: O(h)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << isSymmetric(root->left, root->right) << endl;
}

// TODO: Try iterative