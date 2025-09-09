#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

void topoSort(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        int v = i.first;
        if (!vis[v])
            topoSort(v, adj, vis, st);
    }
    st.push(node);
}

vector<int> shortestPath(int n, int e, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    // find topo sort -> O(n+e)
    vector<bool> vis(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            topoSort(i, adj, vis, st);
    }

    // relaxation of edges (find shortest path from source to each node) -> O(n+e)
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // if node not reachable from source, skip checking it's neighbors as well
        if (dist[node] != INT_MAX)
        {
            for (auto i : adj[node])
            {
                int v = i.first;
                int wt = i.second;
                if (dist[node] + wt < dist[v])
                    dist[v] = dist[node] + wt;
            }
        }
    }

    // unreachable node -> -1
    for (int i = 0; i < n; i++)
        if (dist[i] == INT_MAX)
            dist[i] = -1;

    return dist;
    // TC: O(n+e)
    // SC: O(3n)
}

int main()
{
    int n = 7, e = 7;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};

    vector<int> res = shortestPath(n, e, edges);

    for (auto i : res)
        cout << i << " ";
}

/*
Why topo sort?
It ensures that when we relax (u -> v), the distance to u is already finalized.

Relaxing an edge is checking if the currently known shortest distance to v can be improved by going through u,
or relaxing the constraint on dist[v] by updating it if we found a shorter path.
*/