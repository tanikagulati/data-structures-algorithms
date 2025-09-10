#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-ladder/description/

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    // set to avoid re-visiting already visited word
    set<string> dict(wordList.begin(), wordList.end());

    queue<pair<string, int>> q; // {word, level}
    q.push({beginWord, 1});
    dict.erase(beginWord);

    int len = beginWord.size();
    while (!q.empty())
    {
        auto [word, level] = q.front();
        q.pop();

        // BFS ensures first time we reach the target is the shortest path
        if (word == endWord)
            return level;

        for (int i = 0; i < len; i++)
        {
            char orig = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (dict.find(word) != dict.end())
                {
                    q.push({word, level + 1});
                    dict.erase(word);
                }
            }
            word[i] = orig;
        }
    }

    return 0;
    // TC: O(n*len*26*logn)
    // SC: O(2n)
}

int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit", endWord = "cog";

    cout << ladderLength(beginWord, endWord, wordList) << endl;
}