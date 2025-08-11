#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

bool isLeaf(Node *node)
{
    if (!node->left && !node->right)
        return true;
    return false;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
    root = root->left;
    while (root)
    {
        if (!isLeaf(root))
            res.push_back(root->data);
        if (root->left)
            root = root->left;
        else
            root = root->right;
    }
}

void addLeafNodes(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeafNodes(root->left, res);
    if (root->right)
        addLeafNodes(root->right, res);
}

void addRightBoundary(Node *root, vector<int> &res)
{
    root = root->right;
    vector<int> temp;
    while (root)
    {
        if (!isLeaf(root))
            temp.push_back(root->data);
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}

// Anti-clockwise
vector<int> boundaryTraversal(Node *root)
{
    vector<int> res;
    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    // Left boundary (excluding leaf nodes)
    addLeftBoundary(root, res);
    // Leaf nodes
    addLeafNodes(root, res);
    // Right boundary in reverse
    addRightBoundary(root, res);
    return res;
    // TC: O(2*h) + O(n)
    // SC: O(h) -> for temp
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = boundaryTraversal(root);

    for (auto i : res)
        cout << i << " ";
}