#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int n, vector<int> adj[])
{
    queue<int> q;
    // push the initial starting node
    q.push(0);
    vector<bool> vis(n, 0);
    vis[0] = 1;
    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        // traverse for all its neighbours
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return bfs;
    // TC: O(n + 2E)
    // SC: O(3n)
}

int main()
{
    vector<int> adj[5] = {{1, 4}, {0, 2, 3}, {1}, {1}, {0}};

    vector<int> res = bfsOfGraph(5, adj);

    for (auto i : res)
        cout << i << " ";
}