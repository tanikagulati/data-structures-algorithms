#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// USP -> SC: O(1)

vector<int> inorder(Node *root)
{
    vector<int> inorder;
    Node *cur = root;
    while (cur)
    {
        if (!cur->left)
        {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            // Find left-subtree's rightmost node
            Node *temp = cur->left;
            while (temp->right && temp->right != cur)
            {
                temp = temp->right;
            }
            if (!temp->right)
            {
                // Create a thread to cur
                temp->right = cur;
                cur = cur->left;
            }
            else
            {
                // Remove thread, add cur to result, move right
                temp->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
    // TC: O(2n)
    // SC: O(1)
}

vector<int> preorder(Node *root)
{
    vector<int> preorder;
    Node *cur = root;
    while (cur)
    {
        if (!cur->left)
        {
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            Node *temp = cur->left;
            while (temp->right && temp->right != cur)
            {
                temp = temp->right;
            }
            if (!temp->right)
            {
                temp->right = cur;
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else
            {
                temp->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> res = inorder(root);
    for (auto i : res)
        cout << i << " ";

    cout << endl;

    res = preorder(root);
    for (auto i : res)
        cout << i << " ";
}