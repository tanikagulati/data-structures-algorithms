#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

bool rootToNodePath(Node *root, Node *target, vector<int> &res)
{
    if (!root)
        return false;

    res.push_back(root->data);
    if (root == target)
        return true;

    if (rootToNodePath(root->left, target, res) || rootToNodePath(root->right, target, res))
        return true;

    res.pop_back();
    return false;
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *target = root->right->left;
    vector<int> res;

    rootToNodePath(root, target, res);

    for (auto i : res)
        cout << i << " ";
}