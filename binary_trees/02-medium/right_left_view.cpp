#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/binary-tree-right-side-view/description/

vector<int> rightViewIterative(Node *root)
{
    // Using level order traversal
    vector<int> res;
    if (!root)
        return res;
    queue<Node *> q;

    q.push(root);
    Node *temp;
    int rightmost;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            temp = q.front();
            q.pop();

            rightmost = temp->data;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        res.push_back(rightmost);
    }
    return res;
    // TC: O(n)
    // SC: O(n)
}

void rightViewRecursive(Node *root, int level, vector<int> &res)
{
    // Using reverse pre-order traversal
    if (!root)
        return;

    if (level == res.size())
        res.push_back(root->data);

    rightViewRecursive(root->right, level + 1, res);
    rightViewRecursive(root->left, level + 1, res);
    // TC: O(n)
    // SC: O(h)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> res = rightViewIterative(root);

    for (auto i : res)
        cout << i << " ";
    cout << endl;

    res.clear();
    rightViewRecursive(root, 0, res);

    for (auto i : res)
        cout << i << " ";
}