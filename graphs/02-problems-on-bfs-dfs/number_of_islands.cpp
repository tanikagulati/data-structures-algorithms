#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-islands/description/

void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    while (!q.empty())
    {
        row = q.front().first;
        col = q.front().second;
        q.pop();

        // traverse neighbours

        // if diagonals are considered as part of island
        // for (int delRow = -1; delRow <= 1; delRow++)
        // {
        //     for (int delCol = -1; delCol <= 1; delCol++)
        //     {
        //         int nborRow = row + delRow;
        //         int nborCol = col + delCol;
        //         // check index validity, is land, is not visited
        //         if (nborRow >= 0 && nborRow < n && nborCol >= 0 && nborCol < m && grid[nborRow][nborCol] == '1' && !vis[nborRow][nborCol])
        //         {
        //             q.push({nborRow, nborCol});
        //             vis[nborRow][nborCol] = 1;
        //         }
        //     }
        // }

        // else
        int delR[] = {-1, 0, 1, 0};
        int delC[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int nborRow = row + delR[k];
            int nborCol = col + delC[k];
            // check index validity, is land, is not visited
            if (nborRow >= 0 && nborRow < n && nborCol >= 0 && nborCol < m && grid[nborRow][nborCol] == '1' && !vis[nborRow][nborCol])
            {
                q.push({nborRow, nborCol});
                vis[nborRow][nborCol] = 1;
            }
        }
    }
}

int numberOfIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;

    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !vis[i][j])
            {
                cnt++;
                bfs(i, j, grid, vis);
            }
        }
    }

    return cnt;
    // TC: O(n^2 + 9*(n^2)) ~ n^2
    // SC: O(n^2 + n^2) -> vis + queue
}

int main()
{
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};

    cout << numberOfIslands(grid) << endl;
}