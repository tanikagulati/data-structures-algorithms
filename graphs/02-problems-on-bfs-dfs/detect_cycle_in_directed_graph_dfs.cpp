#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
        // already visited on same path
        else if (pathVis[i])
            return true;
    }
    pathVis[node] = 0;
    return false;
}

bool detectCycleDFS(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
    // TC: O(n+n+E)
    // SC: O(3n)
}

int main()
{
    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};

    // create adj list
    vector<int> adjLs[n];
    for (auto i : edges)
        adjLs[i[0]].push_back(i[1]);

    cout << detectCycleDFS(n, adjLs) << endl;

    // can use single array for visit and pathVisit -> mark visit as 1, pathVisit as 2
}
