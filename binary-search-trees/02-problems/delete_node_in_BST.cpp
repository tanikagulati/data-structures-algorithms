#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/delete-node-in-a-bst/description/

Node *findRightMost(Node *root)
{
    while (root->right)
        root = root->right;
    return root;
}

Node *helper(Node *root)
{
    if (!root->left)
        return root->right;
    else if (!root->right)
        return root->left;
    Node *rightChild = root->right;
    Node *rightMostOnLeft = findRightMost(root->left);
    rightMostOnLeft->right = rightChild;
    return root->left;
}

Node *deleteNode(Node *root, int val)
{
    if (!root)
        return NULL;
    if (root->data == val)
        return helper(root);
    Node *cur = root;
    while (cur)
    {
        if (cur->data > val)
        {
            if (cur->left && cur->left->data == val)
            {
                cur->left = helper(cur->left);
                break;
            }
            else
                cur = cur->left;
        }
        else
        {
            if (cur->right && cur->right->data == val)
            {
                cur->right = helper(cur->right);
                break;
            }
            else
                cur = cur->right;
        }
    }
    return root;
    // TC: O(h)
    // SC: O(1)
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
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    traverse(deleteNode(root, 3));
}