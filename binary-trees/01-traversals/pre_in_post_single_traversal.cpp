#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// Less intuitive but easy

vector<vector<int>> preInPostOrderTraversal(Node *root)
{
    vector<int> preorder, inorder, postorder;
    stack<pair<Node *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right)
                st.push({it.first->right, 1});
        }
        else if (it.second == 3)
        {
            postorder.push_back(it.first->data);
        }
    }
    return {preorder, inorder, postorder};
    // TC: O(3n)
    // SC: O(4n)
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> res = preInPostOrderTraversal(root);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    // Try recursive way as well
}