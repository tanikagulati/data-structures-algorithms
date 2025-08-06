#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

int heightOfBT(Node *root)
{
    // Recurrence relation: 1 + max(l, r)
    if (root == NULL)
        return 0;
    int lh = heightOfBT(root->left);
    int rh = heightOfBT(root->right);

    return 1 + max(lh, rh);
    // TC: O(n)
    // SC: O(h)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Two ways:
    // 1. Recursive -> SC: O(h) (h = height of tree) (in worst case: O(n)) (Skewed tree)
    // 2. Level order traversal -> SC: O(n) (worst case: Perfect binary tree)

    cout << heightOfBT(root) << endl;
}