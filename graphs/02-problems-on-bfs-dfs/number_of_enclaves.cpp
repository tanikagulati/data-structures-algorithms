#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-enclaves/description/

// same as surrounded regions problem
// can use dfs as well

static constexpr int delR[] = {-1, 0, 1, 0};
static constexpr int delC[] = {0, 1, 0, -1};

int bfs(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    // push all sources in the queue
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // boundaries only
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nRow = r + delR[k];
            int nCol = c + delC[k];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
            {
                q.push({nRow, nCol});
                vis[nRow][nCol] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
                cnt++;
        }
    }
    return cnt;
    // TC: O(nm + 5nm + nm)
    // SC: O(2nm)
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};

    cout << bfs(grid) << endl;
}