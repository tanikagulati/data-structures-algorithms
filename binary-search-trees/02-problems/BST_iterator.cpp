#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/binary-search-tree-iterator/description/

// Concept: Inorder iterative traversal

class BSTIterator
{
    stack<Node *> st;

    void pushAll(Node *node)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(Node *root)
    {
        pushAll(root);
    }

    int next()
    {
        Node *temp = st.top();
        st.pop();
        if (temp->right)
            pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

int main()
{
    struct Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTIterator *it = new BSTIterator(root);
    cout << it->next() << endl;
    cout << it->hasNext() << endl;
    cout << it->next() << endl;
    cout << it->next() << endl;
    cout << it->next() << endl;
    cout << it->next() << endl;
    cout << it->hasNext() << endl;

    // A total of n nodes will be pushed in the stack, and if there are around n next calls, then (n/n = 1)
    // TC: O(1) on avg

    // The stack stores elements around height of BT at once
    // SC: O(h)
}