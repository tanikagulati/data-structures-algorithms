#include <bits/stdc++.h>
using namespace std;

bool searchWord(vector<vector<char>> &board, string &word, int index, int row, int col)
{
    if (index == word.length())
    {
        return true;
    }

    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '0' || board[row][col] != word[index])
    {
        return false;
    }

    char c = board[row][col];
    board[row][col] = '0';

    // D
    bool down = searchWord(board, word, index + 1, row + 1, col);
    // L
    bool left = searchWord(board, word, index + 1, row, col - 1);
    // R
    bool right = searchWord(board, word, index + 1, row, col + 1);
    // U
    bool up = searchWord(board, word, index + 1, row - 1, col);

    board[row][col] = c;

    return down || left || right || up;
}

bool search(vector<vector<char>> &board, string &word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                if (searchWord(board, word, 0, i, j))
                {
                    return true;
                }
            }
        }
    }
    return false;
    // TC: O(m*n*4^k) -> k = length of word
    // SC: O(k) Rec stack space
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    cout << search(board, word) << endl;
}