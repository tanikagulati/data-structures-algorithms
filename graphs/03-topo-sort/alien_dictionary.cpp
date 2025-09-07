#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/alien-dictionary/1

vector<int> topoSort(vector<vector<int>> &adj, vector<int> &indegree, vector<bool> &present)
{
    queue<int> q;
    // push into the queue if present and indegree = 0
    for (int i = 0; i < 26; i++)
        if (present[i] && indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto i : adj[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return topo;
}

string findOrder(vector<string> &words)
{
    int n = words.size();
    vector<bool> present(26, 0);

    // mark all present characters
    for (auto &word : words) // avoid copying strings using &
        for (char c : word)
            present[c - 'a'] = 1;

    // create adj list and compute indegree
    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    for (int i = 0; i < n - 1; i++)
    {
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min(s1.size(), s2.size());
        bool found = 0;
        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                indegree[s2[j] - 'a']++;
                found = 1;
                break;
            }
        }
        // this won't happen, since input is in lexicographical order of alien's dictionary
        // but if not so, this is how an edge case can be handled (eg. ["abcd", "abc"])
        if (!found && s1.size() > s2.size())
            return "";
    }

    vector<int> topo = topoSort(adj, indegree, present);

    // count nodes in graph
    int nodes = 0;
    for (int i = 0; i < 26; i++)
        if (present[i])
            nodes++;

    if (topo.size() != nodes)
        return "";

    string res = "";
    for (auto i : topo)
        res.push_back(i + 'a');
    return res;
    // TC: O(l + n+E)
    // SC: O(l + n+E) where l = summation of length of all given words
}

int main()
{
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

    cout << findOrder(words) << endl;
}