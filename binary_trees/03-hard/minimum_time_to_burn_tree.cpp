#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

Node *markParents(Node *root, unordered_map<Node *, Node *> &nodeParent, int start)
{
    // Mark parents and find target node
    queue<Node *> q;
    q.push(root);
    Node *target;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->data == start)
                target = temp;
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
    return target;
}

int amountOfTime(Node *root, int start)
{
    unordered_map<Node *, Node *> nodeParent;
    Node *target = markParents(root, nodeParent, start);

    int time = 0;
    queue<Node *> q;
    q.push(target);
    unordered_map<Node *, bool> visited;
    visited[target] = true;

    while (!q.empty())
    {
        int size = q.size();
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (nodeParent[temp] && !visited[nodeParent[temp]])
            {
                q.push(nodeParent[temp]);
                visited[nodeParent[temp]] = true;
                flag = 1;
            }
            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
                flag = 1;
            }
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
                flag = 1;
            }
        }
        // Increase the time only if actually something is burned in one radial cycle
        if (flag)
            time++;
    }
    return time;
    // TC: O(2n)
    // SC: O(3n)
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

    cout << amountOfTime(root, 3) << endl;
}