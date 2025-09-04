#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

static constexpr int delR[] = {-1, 0, 1, 0};
static constexpr int delC[] = {0, 1, 0, -1};

void dfs(int r, int c, int row0, int col0, vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &shape)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[r][c] = 1;
    shape.push_back({r - row0, c - col0});

    for (int k = 0; k < 4; k++)
    {
        int nRow = r + delR[k];
        int nCol = c + delC[k];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !vis[nRow][nCol])
        {
            dfs(nRow, nCol, row0, col0, grid, vis, shape);
        }
    }
}

int distinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    // to store the shape of island in the set (using co-ordinates)
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> shape;
                dfs(i, j, i, j, grid, vis, shape);
                st.insert(shape);
            }
        }
    }

    return st.size();
    // TC: O((nm * log nm) + 5nm)
    // SC: O(3nm)
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {1, 1, 0, 1, 0}};

    cout << distinctIslands(grid) << endl;
}