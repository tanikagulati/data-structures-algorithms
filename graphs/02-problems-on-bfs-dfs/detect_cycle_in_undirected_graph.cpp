#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

bool bfsCheck(int src, vector<int> adj[], vector<bool> &vis)
{
    queue<pair<int, int>> q; // {cur, parent}
    q.push({src, -1});
    vis[src] = 1;

    while (!q.empty())
    {
        int cur = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjNode : adj[cur])
        {
            if (!vis[adjNode])
            {
                q.push({adjNode, cur});
                vis[adjNode] = 1;
            }
            // if adjNode is already visited and is not equal to current's parent, there exists a cycle
            else if (adjNode != parent)
                return true;
        }
    }
    return false;
    // TC: O(n+2E)
    // SC: O(2n)
}

bool detectCycleBFS(int n, vector<int> adj[])
{
    vector<bool> vis(n, 0);
    // for multiple connected components
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (bfsCheck(i, adj, vis))
                return true;
        }
    }
    return false;
    // TC: O(n+n+2E)
    // SC: O(2n)
}

bool dfsCheck(int node, int parent, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = 1;
    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            if (dfsCheck(adjNode, node, adj, vis))
                return true;
        }
        // visited and non-parent -> cycle
        else if (adjNode != parent)
            return true;
    }
    return false;
    // TC: O(n+2E)
    // SC: O(2n)
}

bool detectCycleDFS(int n, vector<int> adj[])
{
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfsCheck(i, -1, adj, vis))
                return true;
        }
    }
    return false;
    // TC: O(n+n+2E)
    // SC: O(2n)
}

int main()
{
    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};

    // create adj list
    vector<int> adjLs[n];
    for (auto i : edges)
    {
        adjLs[i[0]].push_back(i[1]);
        adjLs[i[1]].push_back(i[0]);
    }

    cout << detectCycleBFS(n, adjLs) << endl;

    cout << detectCycleDFS(n, adjLs) << endl;
}