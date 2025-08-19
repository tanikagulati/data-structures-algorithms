#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

// Revisit

void flattenRecursive(Node *root, Node *&prev)
{
    if (!root)
        return;

    flattenRecursive(root->right, prev);
    flattenRecursive(root->left, prev);

    root->right = prev;
    root->left = NULL;

    prev = root;
    // TC: O(n)
    // SC: O(n)
}

void flattenIterative(Node *root)
{
    if (!root)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *cur = st.top();
        st.pop();
        if (cur->right)
            st.push(cur->right);
        if (cur->left)
            st.push(cur->left);

        if (!st.empty())
            cur->right = st.top();
        cur->left = NULL;
    }
    // TC: O(n)
    // SC: O(n)
}

void flattenOptimal(Node *root)
{
    Node *cur = root;
    while (cur)
    {
        if (cur->left)
        {
            Node *temp = cur->left;
            while (temp->right)
                temp = temp->right;
            temp->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    // Brute:
    Node *prev = NULL;
    Node *temp = root;
    flattenRecursive(temp, prev);
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;

    temp = root;
    flattenIterative(temp);
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;

    // Optimal: Using Morris traversal
    temp = root;
    flattenOptimal(temp);
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}