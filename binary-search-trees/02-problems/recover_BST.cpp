#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/recover-binary-search-tree/description/

Node *previous = NULL, *first = NULL, *mid = NULL, *last = NULL;

void recover(Node *root)
{
    if (!root)
        return;
    recover(root->left);
    if (previous && root->data < previous->data)
    {
        // First violation
        if (!first)
        {
            first = previous;
            mid = root;
            // why keep track of mid?
            // If the two violated nodes are adjacent, the second violation won't be captured later, so it needs to be stored
        }
        // Second violation
        else
            last = root;
    }
    previous = root;
    recover(root->right);
    // TC: O(n)
    // SC: O(h) -> Morris can be used for O(1) space
}

void traverse(Node *root)
{
    if (!root)
        return;
    traverse(root->left);
    cout << root->data << " ";
    traverse(root->right);
}

int main()
{
    struct Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);

    // Brute: Store inorder, sort it, traverse BST while matching from sorted inorder, and correct wrong values
    // TC: O(2n + nlogn)
    // SC: O(n)

    // Optimal:
    recover(root);

    if (first && last)
        swap(first->data, last->data);
    else
        swap(first->data, mid->data);

    traverse(root); // To verify
}