#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/course-schedule/description/
// https://leetcode.com/problems/course-schedule-ii/description/

// DFS can also be used

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    // cannot finish if there is a cycle (question boils down to cycle detection)
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto i : prerequisites)
    {
        adj[i[1]].push_back(i[0]); // reversed dependencies
        indegree[i[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
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
    if (cnt != numCourses)
        return false;
    return true;
    // TC: O(2E + n + 2n+E)
    // SC: O(2n)
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto i : prerequisites)
    {
        adj[i[1]].push_back(i[0]); // reversed dependencies
        indegree[i[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0)
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

    if (topo.size() != numCourses)
        return {};
    return topo;
    // TC: O(2E + n + 2n+E)
    // SC: O(3n)
}

int main()
{
    int n = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    cout << canFinish(n, prerequisites) << endl;

    vector<int> res = findOrder(n, prerequisites);

    for (auto i : res)
        cout << i << " ";
}