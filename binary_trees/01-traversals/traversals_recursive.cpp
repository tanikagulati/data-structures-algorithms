#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

void preorder(Node *root)
{
    // Root Left Right
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    // Left Root Right
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    // Left Right Root
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    // TC: O(n)
    // SC: O(n)
}