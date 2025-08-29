#include <bits/stdc++.h>
using namespace std;

/*
Nodes or Vertices store the data
Two nodes connected by a horizontal line is called Edge, which can be directed or undirected

Undirected Graph: Bidirectional (undirected edges) ->  (u,v) & (v,u) is same edge
Directed Graph: (u,v) & (v,u) are two different edges

Cyclic
Acyclic

Path: Contains a lot of nodes and each of them is reachable

Degree:
In undirected graph, for a node -> The number of edges attached to that node
In directed graphs, for a node -> Indegree(incoming edges) and Outdegree(outgoing edges)
Total degree of graph = 2*E (since each edge is connected to two nodes)

Edge weight: A graph may have weights assigned on its edges, also referred to as cost of the edge

Representation: Adjacency matrix or adjacency list

Connected components: Parts of a single graph (Connected components can be traversed as a single graph using visited array)
*/

void storeUsingAdjMatrix()
{
    int n, m; // n -> nodes, m -> edges
    cin >> n >> m;

    // 2D matrix (n+1, n+1) -> if 1-based indexing of nodes
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // remove in case of directed graph
    }
    return;
    // TC: O(m)
    // SC: O(n^2)
}

void storeUsingAdjList()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove in case of directed graph
    }
    return;
    // TC: O(m)
    // SC: O(2m)
    // SC: O(m) -> for directed graph
}

int main()
{
    storeUsingAdjMatrix();
    storeUsingAdjList();

    // For weighted graphs:
    // Adj matrix: Just store wt instead of 1 in the matrix
    // Adj list: Instead of storing a list of integers in each index, store pairs (node, edge weight) in it.
}