#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://www.geeksforgeeks.org/problems/largest-bst/1

class NodeValue
{
public:
    int maxSize, maxNode, minNode;

    NodeValue(int maxSize, int maxNode, int minNode)
    {
        this->maxSize = maxSize;
        this->maxNode = maxNode;
        this->minNode = minNode;
    }
};

NodeValue traverse(Node *root)
{
    // Largest of left subtree should be smaller than node
    // Smallest of right subtree should be greater than node
    if (!root)
        return {0, INT_MIN, INT_MAX};

    NodeValue l = traverse(root->left);
    NodeValue r = traverse(root->right);

    if (l.maxNode < root->data && root->data < r.minNode)
        return {l.maxSize + r.maxSize + 1, max(root->data, r.maxNode), min(root->data, l.minNode)};
    else
        return {max(l.maxSize, r.maxSize), INT_MAX, INT_MIN};
    // TC: O(n)
    // SC: O(h)
}

int main()
{
    struct Node *root = new Node(6);
    root->left = new Node(7);
    root->right = new Node(3);
    root->left->right = new Node(2);
    root->right->left = new Node(2);
    root->right->right = new Node(4);

    NodeValue res = traverse(root);
    cout << res.maxSize << endl;
}