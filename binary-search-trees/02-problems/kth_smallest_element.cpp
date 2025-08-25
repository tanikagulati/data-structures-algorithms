#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

int kthSmallest(Node *root, int k)
{
    // Use any traversal (recursive, iterative, morris) -> Morris most optimal
    // Maintain cnt variable to find kth smallest
    // Do not immediately return when ans is found, let the traversal get completed, as the tree may be corrupt due to threads

    int cnt = 0, ans = -1;
    Node *cur = root;
    while (cur)
    {
        if (!cur->left)
        {
            cnt++;
            if (cnt == k)
                ans = cur->data;
            cur = cur->right;
        }
        else
        {
            Node *temp = cur->left;
            while (temp->right && temp->right != cur)
                temp = temp->right;
            if (!temp->right)
            {
                temp->right = cur;
                cur = cur->left;
            }
            else
            {
                temp->right = NULL;
                cnt++;
                if (cnt == k)
                    ans = cur->data;
                cur = cur->right;
            }
        }
    }
    return ans;
    // TC: O(2n)
    // SC: O(1)
}

int main()
{
    struct Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->left->right = new Node(2);

    // Concept: Inorder traversal of BST is always sorted
    // Brute: Store inorder traversal in a vector, return kth element
    // TC: O(n), SC: O(n)

    // Optimal: without storing
    cout << kthSmallest(root, 1) << endl;

    // Find kth largest?
    // Approach 1: Traverse once to find n (no of nodes), then traverse to find (n-k+1)th smallest
    // Approach 2: Traverse in inverse of inorder -> R N L
}