#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/diameter-of-binary-tree/description/

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root. (Imp)

int heightOfBT(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = heightOfBT(root->left);
    int rh = heightOfBT(root->right);

    return 1 + max(lh, rh);
    // TC: O(n)
    // SC: O(h)
}

int diameterBrute(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = heightOfBT(root->left);
    int rh = heightOfBT(root->right);

    maxi = max(maxi, lh + rh);
    diameterBrute(root->left, maxi);
    diameterBrute(root->right, maxi);

    return maxi;
    // TC: O(n^2)
    // SC: O(h)
}

int diameterOptimal(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = diameterOptimal(root->left, maxi);
    int rh = diameterOptimal(root->right, maxi);

    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
    // TC: O(n)
    // SC: O(h)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right = new Node(7);

    int maxi = 0;

    cout << diameterBrute(root, maxi) << endl;

    cout << diameterOptimal(root, maxi) << endl;
}