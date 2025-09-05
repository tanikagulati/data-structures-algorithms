#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-eventual-safe-states/description/

bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis)
{
    vis[node] = 2;
    for (auto i : graph[node])
    {
        if (!vis[i])
        {
            if (dfs(i, graph, vis))
                return true;
        }
        // already visited on same path
        else if (vis[i] == 2)
            return true;
    }
    // node is safe
    vis[node] = 1; // remove path visited mark
    return false;
}

vector<int> safeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    // optimized to use single array for vis and pathVis, but not recommended for interviews
    vector<int> vis(n, 0); // 0 -> not visited, 1 -> visited, 2 -> path visited
    vector<int> safe;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, graph, vis);
    }

    // not path visited -> safe
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 1)
            safe.push_back(i);
    }
    return safe;
    // TC: O(n+n+E + n)
    // SC: O(2n)
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    // Observation:
    // A node part of cycle -> not safe
    // Leading to a cycle -> not safe
    // Else -> safe

    vector<int> res = safeNodes(graph);

    for (auto i : res)
        cout << i << endl;
}
