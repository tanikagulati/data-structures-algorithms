#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

// a vis array can also be used, that limits visiting a node to once
// (for unit weights) path will always be shortest during first visit, no need to update dist -> classic BFS

vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    {
        int n = adj.size();
        queue<int> q;
        q.push(src);
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto i : adj[node])
            {
                if (dist[node] + 1 < dist[i])
                {
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (dist[i] == INT_MAX)
                dist[i] = -1;

        return dist;
        // TC: O(n+2E)
        // SC: O(2n)
    }
}

int main()
{
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};
    int src = 0;

    vector<int> res = shortestPath(adj, src);

    for (auto i : res)
        cout << i << " ";
}