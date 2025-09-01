#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotting-oranges/description/

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // {{row, col}, time}
    queue<pair<pair<int, int>, int>> q;
    int vis[n][m];
    int freshCnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
                vis[i][j] = 0;

            if (grid[i][j] == 1)
                freshCnt++;
        }
    }

    int time = 0;
    int cnt = 0;

    int delR[] = {-1, 0, 1, 0};
    int delC[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        q.pop();

        time = max(time, t);
        for (int k = 0; k < 4; k++)
        {
            int nRow = row + delR[k];
            int nCol = col + delC[k];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0)
            {
                q.push({{nRow, nCol}, t + 1});
                vis[nRow][nCol] = 2;
                cnt++;
            }
        }
    }
    if (cnt != freshCnt)
        return -1;
    return time;
    // TC: O(n*m + 4*n*m)
    // SC: O(2*n*m)
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    cout << orangesRotting(grid) << endl;
}