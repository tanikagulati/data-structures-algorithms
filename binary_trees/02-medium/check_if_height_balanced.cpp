#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/balanced-binary-tree/description/

// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

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

bool checkBrute(Node *root)
{
    if (root == NULL)
        return true;
    int lh = heightOfBT(root->left);
    int rh = heightOfBT(root->right);

    if (abs(lh - rh) > 1)
        return false;

    bool l = checkBrute(root->left);
    bool r = checkBrute(root->right);

    if (!l || !r)
        return false;

    return true;
    // TC: O(n^2)
    // SC: O(h)
}

int check(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = check(root->left);
    if (lh == -1)
        return -1;
    int rh = check(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

bool checkOptimal(Node *root)
{
    return check(root) != -1;
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

    cout << checkBrute(root) << endl;

    cout << checkOptimal(root) << endl;
}