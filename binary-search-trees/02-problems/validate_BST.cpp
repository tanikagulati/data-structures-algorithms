#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/validate-binary-search-tree/description/

bool isValidBST(Node *root, long minVal, long maxVal)
{
    if (!root)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return (isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal));
    // TC: O(n)
    // SC: O(h)
}

int main()
{
    struct Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    cout << isValidBST(root, LONG_MIN, LONG_MAX) << endl;
}