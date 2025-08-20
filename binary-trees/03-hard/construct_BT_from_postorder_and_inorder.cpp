#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

Node *construct(vector<int> &postorder, unordered_map<int, int> &hash, int postSt, int postEnd, int inSt, int inEnd)
{
    if (postSt > postEnd || inSt < inEnd)
        return NULL;

    Node *root = new Node(postorder[postEnd]);

    int inRoot = hash[postorder[postEnd]];
    int numsLeft = inRoot - inSt;

    root->left = construct(postorder, hash, postSt, postSt + numsLeft - 1, inSt, inRoot - 1);

    root->right = construct(postorder, hash, postSt + numsLeft, postEnd - 1, inRoot + 1, inEnd);

    return root;
}

Node *buildTree(vector<int> &postorder, vector<int> &inorder)
{
    int n = inorder.size();
    unordered_map<int, int> inorderHash;
    for (int i = 0; i < n; i++)
    {
        inorderHash[inorder[i]] = i;
    }
    return construct(postorder, inorderHash, 0, n - 1, 0, n - 1);
    // TC: O(n)
    // SC: O(n)
}

void traverse(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    traverse(root->left);
    traverse(root->right);
}

int main()
{
    vector<int> inorder = {9, 13, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Node *root = buildTree(postorder, inorder);
    traverse(root);
}