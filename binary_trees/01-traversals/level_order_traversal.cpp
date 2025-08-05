#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        Node *temp;
        for (int i = 0; i < size; i++)
        {
            temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
    // TC: O(n)
    // SC: O(n) (not considering ans space)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> ans = levelOrder(root);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}