#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

vector<vector<int>> verticalOrderTraversal(Node *root)
{
    // Using level order traversal (any traversal can be used)
    map<int, map<int, multiset<int>>> nodes; // col, row, []
    queue<pair<Node *, pair<int, int>>> q;   // Node, col, row

    q.push({root, {0, 0}});
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto temp = q.front();
            q.pop();

            int x = temp.second.first;
            int y = temp.second.second;
            nodes[x][y].insert(temp.first->data);

            if (temp.first->left)
                q.push({temp.first->left, {x - 1, y + 1}});
            if (temp.first->right)
                q.push({temp.first->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> res;
    for (auto vertical : nodes)
    {
        vector<int> col;
        for (auto level : vertical.second)
        {
            col.insert(col.end(), level.second.begin(), level.second.end());
        }
        res.push_back(col);
    }

    return res;
    // TC: O(n*logn)
    // SC: O(2n)
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

    vector<vector<int>> res;
    res = verticalOrderTraversal(root);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

// TODO: Try with another traversal