#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

Node *construct(vector<int> &preorder, int &i, int ub)
{
    // Keep in check the upper bound for each node
    if (i >= preorder.size() || preorder[i] >= ub)
        return NULL;
    Node *root = new Node(preorder[i]);
    i++;
    root->left = construct(preorder, i, root->data);
    root->right = construct(preorder, i, ub);
    return root;
    // TC: O(3n)
    // SC: O(h)
}

void traverse(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    traverse(root->left);
    traverse(root->right);
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Brute: Place each node using L<N<R property of BST
    // TC: O(n*n)
    // SC: O(1)

    // Better: Sort preorder to get inorder, now construct BT using preorder and inorder
    // TC: O(nlogn + n)
    // SC: O(n)

    // Optimal:
    int i = 0;
    Node *root = construct(preorder, i, INT_MAX);
    traverse(root);
}