#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/1724915812/
// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/1724916619/
// https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/1724976114/

vector<int> preorder(Node *root)
{
    vector<int> preorder;
    if (root == NULL)
        return preorder;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if (root->right)
            st.push(root->right);
        if (root->left)
            st.push(root->left);
    }
    return preorder;
    // TC: O(n)
    // SC: O(n)
}

vector<int> inorder(Node *root)
{
    vector<int> inorder;
    stack<Node *> st;
    Node *node = root;

    while (true)
    {
        if (node)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
    // TC: O(n)
    // Sc: O(n)
}

vector<int> postorder2Stacks(Node *root)
{
    vector<int> postorder;
    if (root == NULL)
        return postorder;
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left)
            st1.push(root->left);
        if (root->right)
            st1.push(root->right);
    }

    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
    // TC: O(3n)
    // SC: O(2n)
}

vector<int> postorder1Stack(Node *root)
{
    // Postorder Simulation
    vector<int> postorder;
    stack<Node *> st;
    Node *curr = root; // Leftwards
    Node *temp;        // Rightwards
    while (curr != NULL || !st.empty())
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && st.top()->right == temp)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return postorder;
    // TC: O(2n)
    // SC: O(n)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res;

    res = preorder(root);
    for (auto i : res)
        cout << i << " ";
    cout << endl;

    res = inorder(root);
    for (auto i : res)
        cout << i << " ";
    cout << endl;

    res = postorder2Stacks(root);
    for (auto i : res)
        cout << i << " ";
    cout << endl;

    // Revisit
    res = postorder1Stack(root);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
}