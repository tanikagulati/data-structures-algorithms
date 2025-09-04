#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/is-graph-bipartite/description/

bool bfs(int start, vector<vector<int>> &graph, vector<int> &vis)
{
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto i : graph[node])
        {
            if (vis[i] == -1)
            {
                q.push(i);
                vis[i] = !vis[node];
            }
            else if (vis[i] == vis[node])
                return false;
        }
    }
    return true;
}

bool isBipartiteBFS(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vis(n, -1); // -1 -> non-visited, 0/1 -> color

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
        {
            if (!bfs(i, graph, vis))
                return false;
        }
    }
    return true;
    // TC: O(n+n+2E)
    // SC: O(2n)
}

bool dfs(int node, int color, vector<vector<int>> &graph, vector<int> &vis)
{
    vis[node] = color;
    for (auto i : graph[node])
    {
        if (vis[i] == -1)
        {
            if (!dfs(i, !color, graph, vis))
                return false;
        }
        else if (vis[i] == color)
            return false;
    }
    return true;
}

bool isBipartiteDFS(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vis(n, -1); // -1 -> non-visited, 0/1 -> color

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
        {
            if (!dfs(i, 1, graph, vis))
                return false;
        }
    }
    return true;
    // TC: O(n+n+2E)
    // SC: O(2n)
}

int main()
{
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    // Observation:
    // A graph with no cycle or even length cycle -> Always bipartite
    // Odd length cycle -> Not bipartite

    cout << isBipartiteBFS(graph) << endl;

    cout << isBipartiteDFS(graph) << endl;
}