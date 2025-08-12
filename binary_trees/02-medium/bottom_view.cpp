#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

vector<int> bottomView(Node *root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<pair<Node *, int>> q; // Node, col
    map<int, int> mp;           // col, Node data

    q.push({root, 0});
    Node *temp;
    int col;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            q.pop();
            temp = it.first;
            col = it.second;

            mp[col] = temp->data;

            if (temp->left)
                q.push({temp->left, col - 1});
            if (temp->right)
                q.push({temp->right, col + 1});
        }
    }

    for (auto i : mp)
        res.push_back(i.second);
    return res;
    // TC: O(nlogn)
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

    vector<int> res = bottomView(root);

    for (auto i : res)
        cout << i << " ";
}

// Other traversals are not preferred for this, since we'll need to keep the track of height as well then