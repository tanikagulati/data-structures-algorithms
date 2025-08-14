#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

// Max width = max distance b/w two nodes at any level

int maxWidth(Node *root)
{
    if (!root)
        return 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    int maxi = 0;
    while (!q.empty())
    {
        int size = q.size();
        int mini = q.front().second; // Min index of that level
        int minIdx, maxIdx;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front().first;
            int idx = q.front().second - mini; // To prevent overflow
            q.pop();

            if (i == 0)
                minIdx = idx;
            if (i == size - 1)
                maxIdx = idx;

            if (temp->left)
                q.push({temp->left, idx * 2LL + 1});
            if (temp->right)
                q.push({temp->right, idx * 2LL + 2});
        }
        maxi = max(maxi, maxIdx - minIdx + 1);
    }
    return maxi;
    // TC: O(n)
    // SC: O(n)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    cout << maxWidth(root) << endl;
}