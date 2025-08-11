#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

int subTreeSum(Node *root)
{
    if (!root)
        return 0;
    int l = subTreeSum(root->left);
    int r = subTreeSum(root->right);
    return root->data + max(l, r);
}

void maxPathSumBrute(Node *root, int &maxi)
{
    int lSum = subTreeSum(root->left);
    int rSum = subTreeSum(root->right);

    maxi = max(maxi, lSum + rSum + root->data);

    if (root->left)
        maxPathSumBrute(root->left, maxi);
    if (root->right)
        maxPathSumBrute(root->right, maxi);
    // TC: O(n^2)
    // SC: O(h)
}

int maxPathSumOptimal(Node *root, int &maxi)
{
    if (!root)
        return 0;
    int lSum = max(0, maxPathSumOptimal(root->left, maxi));
    int rSum = max(0, maxPathSumOptimal(root->right, maxi));

    maxi = max(maxi, root->data + lSum + rSum);
    return root->data + max(lSum, rSum);
    // TC: O(n)
    // SC: O(h)
}

int main()
{
    struct Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    int maxi = INT_MIN;
    maxPathSumBrute(root, maxi);
    cout << maxi << endl;

    maxi = INT_MIN;
    maxPathSumOptimal(root, maxi);
    cout << maxi << endl;
}