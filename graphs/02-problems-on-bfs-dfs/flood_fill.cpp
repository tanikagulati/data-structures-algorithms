#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/flood-fill/description/

void dfs(vector<vector<int>> &image, vector<vector<int>> &res, int sr, int sc, int newColor)
{
    int n = image.size();
    int m = image[0].size();

    res[sr][sc] = newColor;
    int orig = image[sr][sc];
    int delR[] = {-1, 0, 1, 0};
    int delC[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++)
    {
        int nRow = sr + delR[k];
        int nCol = sc + delC[k];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == orig && res[nRow][nCol] != newColor)
        {
            dfs(image, res, nRow, nCol, newColor);
        }
    }
    // TC: O(nm + 4nm) -> visit and check neighbours
    // SC: O(2nm) -> res and rec stack space
}

vector<vector<int>> bfs(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> res(image);
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int orig = image[sr][sc];
    res[sr][sc] = newColor;

    int delR[] = {-1, 0, 1, 0};
    int delC[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nRow = r + delR[k];
            int nCol = c + delC[k];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == orig && res[nRow][nCol] != newColor)
            {
                q.push({nRow, nCol});
                res[nRow][nCol] = newColor;
            }
        }
    }

    return res;
    // TC: O(nm + 4nm)
    // SC: O(2nm) -> vis and queue
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
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1;
    int color = 2;

    // Using dfs
    vector<vector<int>> res(image);
    dfs(image, res, sr, sc, color);
    print(res);

    // Using bfs
    res = bfs(image, sr, sc, color);
    print(res);
}