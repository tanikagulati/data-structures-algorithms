#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-provinces/description/

void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
        }
    }
    // TC: O(n + 2E)
    // SC: O(2n)
}

int numberOfProvinces(vector<vector<int>> &adjMat)
{
    // convert adjMat to adjLis
    int n = adjMat.size();
    vector<int> adjLs[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMat[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    vector<bool> vis(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i, adjLs, vis);
        }
    }

    return cnt;
    // TC: O(n + n + 2E)
    // - ignoring conversion to adjLs, as it is almost always given
    // - n for for loop, n+2E for dfs (across the for loop, it is a single dfs over entire graph)

    // SC: O(2n) -> vis + rec stack space
}

int main()
{
    vector<vector<int>> adjMat = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    cout << numberOfProvinces(adjMat) << endl;
}