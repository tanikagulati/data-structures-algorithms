#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    queue<Node *> q;
    q.push(root);
    int leftToRight = 1;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v(size);
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            int index = leftToRight ? i : i - size - 1;
            v[index] = temp->data;
        }
        res.push_back(v);
        leftToRight = !leftToRight;
    }
    return res;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> res;

    res = zigzagLevelOrder(root);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
    }
    cout << endl;
}