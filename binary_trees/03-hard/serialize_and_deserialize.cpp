#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

// Use any traversal

string serialize(Node *root)
{
    string data = "";
    if (!root)
        return data;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr == NULL)
                data.append("#,");
            else
            {
                data.append(to_string(curr->data) + ',');
                q.push(curr->left);
                q.push(curr->right);
            }
        }
    }
    return data;
    // TC: O(n)
    // SC: O(2n)
}

Node *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node *root = new Node(stoi(str));
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")
                curr->left == NULL;
            else
            {
                curr->left = new Node(stoi(str));
                q.push(curr->left);
            }

            getline(s, str, ',');
            if (str == "#")
                curr->right == NULL;
            else
            {
                curr->right = new Node(stoi(str));
                q.push(curr->right);
            }
        }
    }
    return root;
    // TC: O(n)
    // SC: O(2n)
}

void traverse(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    traverse(root->left);
    traverse(root->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    string data = serialize(root);
    cout << data << endl;

    root = deserialize(data);
    traverse(root);
}