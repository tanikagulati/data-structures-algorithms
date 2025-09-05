#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

bool detectCycleBFS(int n, vector<vector<int>> &edges)
{
    // create adj list and compute indegree -> O(2E)
    vector<int> adj[n];
    int indegree[n] = {0};
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        indegree[i[1]]++;
    }

    // push nodes with indegree 0 into the queue -> O(n)
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto i : adj[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    // Topo sort will fail if there is a cycle
    if (cnt != n)
        return true;
    return false;
    // TC: O(2E + n + 2n+E)
    // SC: O(2n)
}

int main()
{
    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};

    cout << detectCycleBFS(n, edges) << endl;
}