#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// Similar: https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

Node *inorderSuccessor(Node *root, int val)
{
    Node *successor = NULL;
    while (root)
    {
        if (root->data > val)
        {
            successor = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return successor;
    // TC: O(h)
    // SC: O(1)
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);

    // Brute: Store inorder, apply BS on it to find successor
    // TC: O(n + logn)
    // SC: O(n)

    // Better: Do inorder traversal (Morris), find successor
    // TC: O(n)
    // SC: O(1)

    // Optimal:
    cout << inorderSuccessor(root, 3)->data << endl;

    // Similarly, predecessor can be found
}