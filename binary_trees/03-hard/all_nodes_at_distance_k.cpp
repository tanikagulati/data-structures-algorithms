#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

void markParents(Node *root, unordered_map<Node *, Node *> &nodeParent)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
                nodeParent.insert({temp->left, temp});
            }
            if (temp->right)
            {
                q.push(temp->right);
                nodeParent.insert({temp->right, temp});
            }
        }
    }
}

vector<int> distanceK(Node *root, Node *target, int k)
{
    // Map nodes to its parents
    unordered_map<Node *, Node *> nodeParent;
    markParents(root, nodeParent);

    // Move out radially from target until distance k
    int dist = 0;
    queue<Node *> q;
    q.push(target);
    unordered_map<Node *, bool> visited;
    visited[target] = true;

    while (!q.empty() && dist < k)
    {
        int size = q.size();
        dist++;
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (nodeParent[curr] && !visited[nodeParent[curr]])
            {
                q.push(nodeParent[curr]);
                visited[nodeParent[curr]] = true;
            }
            if (curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if (curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right] = true;
            }
        }
    }
    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front()->data);
        q.pop();
    }
    return res;
    // TC: O(2n)
    // SC: O(3n)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    vector<int> res = distanceK(root, root->left, 2);

    for (auto i : res)
        cout << i << " ";
}