#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
// https://www.geeksforgeeks.org/problems/floor-in-bst/1
// https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/

int ceil(Node *root, int k)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == k)
        {
            ceil = root->data;
            break;
        }
        else if (root->data > k)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ceil;
    // TC: O(h)
    // SC: O(1)
}

int floor(Node *root, int k)
{
    int floor = -1;
    while (root)
    {
        if (root->data == k)
        {
            floor = root->data;
            break;
        }
        else if (root->data < k)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
    // TC: O(h)
    // SC: O(1)
}

int main()
{
    struct Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(13);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(9);
    root->right->right = new Node(15);
    root->right->right->left = new Node(14);

    cout << ceil(root, 10) << endl;
    cout << floor(root, 10) << endl;
}