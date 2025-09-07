#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-eventual-safe-states/description/

// DFS is better

vector<int> safeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> adjRev(n);
    vector<int> indegree(n);
    // reverse each node of graph
    for (int i = 0; i < n; i++)
    {
        for (auto j : graph[i])
        {
            adjRev[j].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> safe;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        safe.push_back(node);
        for (auto i : adjRev[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }

    sort(safe.begin(), safe.end());
    return safe;
    // TC: O(n+E + n + 2n+E + nlogn) ~ n+E+nlogn
    // SC: O(n+E + 2n) -> adjRev + indegree + queue ~ n+E
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    // Instead of thinking from this node, where can I go, flip it:
    // Build a reversed graph (reverse every edge)
    // In the reversed graph, safe nodes = nodes reachable from terminals

    vector<int> res = safeNodes(graph);

    for (auto i : res)
        cout << i << endl;
}