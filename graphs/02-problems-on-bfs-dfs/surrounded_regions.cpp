#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/surrounded-regions/description/

// can use bfs as well

static constexpr int delR[] = {-1, 0, 1, 0};
static constexpr int delC[] = {0, 1, 0, -1};

void dfs(int r, int c, vector<vector<char>> &board, vector<vector<bool>> &vis)
{
    int n = board.size();
    int m = board[0].size();
    vis[r][c] = 1;

    for (int k = 0; k < 4; k++)
    {
        int nRow = r + delR[k];
        int nCol = c + delC[k];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && board[nRow][nCol] == 'O')
        {
            dfs(nRow, nCol, board, vis);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    // from boundary find O's, traverse and mark all O's connected to it
    // first and last row
    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j] && board[0][j] == 'O')
            dfs(0, j, board, vis);

        if (!vis[n - 1][j] && board[n - 1][j] == 'O')
            dfs(n - 1, j, board, vis);
    }

    // first and last column
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && board[i][0] == 'O')
            dfs(i, 0, board, vis);

        if (!vis[i][m - 1] && board[i][m - 1] == 'O')
            dfs(i, m - 1, board, vis);
    }

    // convert non visited O's to X
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O' && !vis[i][j])
                board[i][j] = 'X';
        }
    }
    // TC: O(2m+2n + nm+4nm + nm)
    // SC: O(2nm)
}

void print(vector<vector<char>> &res)
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
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};

    solve(board);
    print(board);
}