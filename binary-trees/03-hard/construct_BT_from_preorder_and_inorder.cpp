#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

// Revisit

Node *construct(vector<int> &preorder, unordered_map<int, int> &inHash,
                int inStart, int inEnd, int preStart, int preEnd)
{
    if (inStart > inEnd || preStart > preEnd)
        return NULL;

    Node *root = new Node(preorder[preStart]);

    int inRoot = inHash[preorder[preStart]];
    int numsLeft = inRoot - inStart;

    root->left = construct(preorder, inHash, inStart, inRoot - 1, preStart + 1, preStart + numsLeft);

    root->right = construct(preorder, inHash, inRoot + 1, inEnd, preStart + numsLeft + 1, preEnd);

    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inHash;
    int n = inorder.size();
    for (int i = 0; i < n; i++)
    {
        inHash[inorder[i]] = i;
    }
    return construct(preorder, inHash, 0, inorder.size() - 1, 0, preorder.size() - 1);
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
    vector<int> preorder = {1, 2, 4, 5, 3, 6};
    vector<int> inorder = {4, 2, 5, 1, 6, 3};

    Node *root = buildTree(preorder, inorder);
    traverse(root); // To verify
}