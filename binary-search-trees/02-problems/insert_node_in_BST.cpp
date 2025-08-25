#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    Node *cur = root;
    while (true)
    {
        if (cur->data < val)
        {
            if (cur->right)
                cur = cur->right;
            else
            {
                cur->right = new Node(val);
                break;
            }
        }
        else
        {
            if (cur->left)
                cur = cur->left;
            else
            {
                cur->left = new Node(val);
                break;
            }
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
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    traverse(insert(root, 5));
}