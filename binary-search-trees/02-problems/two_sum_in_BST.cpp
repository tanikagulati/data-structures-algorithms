#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

// Single class for iteration from the front and back of inorder of BST
class BSTIterator
{
    stack<Node *> st;
    bool reverse;
    // reverse -> false -> ascending
    // reverse -> true -> descending

    void pushAll(Node *node)
    {
        while (node)
        {
            st.push(node);
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

public:
    BSTIterator(Node *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        Node *temp = st.top();
        st.pop();
        if (reverse)
            pushAll(temp->left);
        else
            pushAll(temp->right);
        return temp->data;
    }
};

bool twoSum(Node *root, int k)
{
    BSTIterator l(root, false); // Stack allocation
    BSTIterator r(root, true);

    int i = l.next(); // first element
    int j = r.next(); // last element

    while (i != j)
    {
        if (i + j == k)
            return true;
        else if (i + j < k)
            i = l.next();
        else
            j = r.next();
    }

    return false;
    // TC: O(n)
    // SC: O(2h)
}

int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    // Brute: Store inorder of BST and apply two pointers
    // TC: O(2n)
    // SC: O(n)

    // Optimal: BST iterator
    cout << twoSum(root, 11);
}

// Note: Stack allocation is preferred over heap allocation. It is faster and avoids memory leaks.