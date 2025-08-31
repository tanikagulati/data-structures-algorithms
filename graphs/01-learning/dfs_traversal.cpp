#include <bits/stdc++.h>
using namespace std;

void dfsOfGraph(int node, vector<int> adj[], vector<bool> &vis, vector<int> &dfs)
{
    vis[node] = 1;
    dfs.push_back(node);
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfsOfGraph(i, adj, vis, dfs);
        }
    }
    // TC: O(n + 2E)
    // SC: O(3n)
}

int main()
{
    vector<int> adj[5] = {{1, 4}, {0, 2, 3}, {1}, {1}, {0}};
    vector<int> dfs;
    vector<bool> vis(5, 0);

    dfsOfGraph(0, adj, vis, dfs);

    for (auto i : dfs)
        cout << i << " ";
}