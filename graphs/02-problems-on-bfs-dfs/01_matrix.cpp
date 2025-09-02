#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/01-matrix/description/

vector<vector<int>> bfs(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> res(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q; // {{row, col}, steps}

    int delR[] = {-1, 0, 1, 0};
    int delC[] = {0, 1, 0, -1};

    // push all sources in the queue (0's)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    // traverse neighbours and mark steps
    while (!q.empty())
    {
        auto [r, c] = q.front().first;
        int steps = q.front().second;
        q.pop();
        res[r][c] = steps;
        for (int k = 0; k < 4; k++)
        {
            int nRow = r + delR[k];
            int nCol = c + delC[k];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol])
            {
                q.push({{nRow, nCol}, steps + 1});
                vis[nRow][nCol] = 1;
            }
        }
    }

    return res;
    // TC: O(nm + 4nm)
    // SC: O(3nm)
}

void print(vector<vector<int>> &res)
{
    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

    vector<vector<int>> res = bfs(mat);

    print(res);
}