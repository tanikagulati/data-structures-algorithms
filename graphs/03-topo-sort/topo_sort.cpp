#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/topological-sort/1

// Only for Directed Acyclic Graphs (DAG)
// Node u will always appear before node v, if there is a directed edge from node u towards node v(u -> v)
// A graph may have multiple topological sortings

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
            dfs(i, adj, vis, st);
    }
    st.push(node);
}

vector<int> topoSort(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis, st);
    }

    vector<int> res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
    // TC: O(n+n+E + n)
    // SC: O(2n)
}

int main()
{
    int n = 4;
    vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};

    // create adj list
    vector<int> adjLs[n];
    for (auto i : edges)
        adjLs[i[0]].push_back(i[1]);

    vector<int> res = topoSort(n, adjLs);

    for (auto i : res)
        cout << i << endl;
}