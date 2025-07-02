#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &maze, int n, int row, int col, string temp, vector<vector<int>> &vis, vector<string> &res)
{
    if (row == n - 1 && col == n - 1)
    {
        res.push_back(temp);
        return;
    }

    vis[row][col] = 1;

    // Down
    if ((row + 1) < n && !vis[row + 1][col] && maze[row + 1][col] != 0)
    {
        solve(maze, n, row + 1, col, temp + 'D', vis, res);
    }
    // Left
    if ((col - 1) >= 0 && !vis[row][col - 1] && maze[row][col - 1] != 0)
    {
        solve(maze, n, row, col - 1, temp + 'L', vis, res);
    }
    // Right
    if ((col + 1) < n && !vis[row][col + 1] && maze[row][col + 1] != 0)
    {
        solve(maze, n, row, col + 1, temp + 'R', vis, res);
    }
    // Up
    if ((row - 1) >= 0 && !vis[row - 1][col] && maze[row - 1][col] != 0)
    {
        solve(maze, n, row - 1, col, temp + 'U', vis, res);
    }

    vis[row][col] = 0;
    // TC: O(k * 4^k) -> k = no of open (not blocked) cells
    // SC: O(k * 4^k) For res + O(n^2) For visited + O(k) Rec stack space
}

void solve2(vector<vector<int>> &maze, int n, int row, int col, string temp, vector<vector<int>> &vis, vector<string> &res, vector<int> &r, vector<int> &c)
{
    if (row == n - 1 && col == n - 1)
    {
        res.push_back(temp);
        return;
    }
    string dlru = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nextRow = row + r[ind];
        int nextCol = col + c[ind];

        if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && !vis[nextRow][nextCol] && maze[nextRow][nextCol] != 0)
        {
            vis[row][col] = 1;
            solve2(maze, n, nextRow, nextCol, temp + dlru[ind], vis, res, r, c);
            vis[row][col] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> maze = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    string temp = "";
    vector<string> res;

    int n = maze.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[0][0] = 1;

    solve(maze, n, 0, 0, temp, visited, res);

    // Just another way
    // DLRU
    vector<int> r = {1, 0, 0, -1};
    vector<int> c = {0, -1, 1, 0};
    // solve2(maze, n, 0, 0, temp, visited, res, r, c);

    for (auto i : res)
    {
        cout << i << endl;
    }
}

// Note: temp as pass by reference is good for performance, pass by value is just good for readability