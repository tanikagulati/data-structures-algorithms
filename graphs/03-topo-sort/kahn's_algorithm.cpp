#include <bits/stdc++.h>
using namespace std;

// Topo sort using BFS

vector<int> topoSortBFS(int n, vector<int> adj[])
{
    // compute indegree -> O(n+E)
    int indegree[n] = {0};
    for (int i = 0; i < n; i++)
        for (auto j : adj[i])
            indegree[j]++;

    // push nodes with indegree 0 into the queue -> O(n)
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // traverse all outgoing nodes
        for (auto i : adj[node])
        {
            // reduce the indegree of adj node
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return topo;
    // TC: O(n+E + n + 2n+E)
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

    vector<int> res = topoSortBFS(n, adjLs);

    for (auto i : res)
        cout << i << endl;
}

/*
 - Visited array was not required here,
 since we are only pushing into the queue when indegree is 0, which will happen only once

 - No need to run separately for each connected component,
 since each component will have at least one node with indegree = 0,
 which will be initially pushed into the queue
*/