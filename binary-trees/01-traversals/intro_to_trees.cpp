#include <bits/stdc++.h>
using namespace std;

/*
Types of binary trees:

Full Binary Tree: Every node has either zero or two children (also known as Strict Binary Tree)
Complete Binary Tree: All levels are filled completely except possibly the last level, which is filled from left to right
Perfect Binary Tree: All leaf nodes are at the same level
Balanced Binary Tree: Height of tree should be log2n at maximum, where n is the number of nodes, this ensures that the tree does not become heavily skewed or imbalanced
Degenerate Tree: Nodes are arranged in a single path leaning to the right or left (resembles to LL)

*/

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
}