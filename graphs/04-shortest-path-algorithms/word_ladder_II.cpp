#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-ladder-ii/description/

// Revisit

vector<vector<string>> findLadders1(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    int level = 0;
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    vector<vector<string>> ans;
    int len = beginWord.size();
    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();

        if (vec.size() > level)
        {
            level++;
            for (auto i : usedOnLevel)
                dict.erase(i);
            usedOnLevel.clear();
        }

        string word = vec.back();
        if (word == endWord)
        {
            if (ans.size() == 0)
                ans.push_back(vec);
            else if (ans[0].size() == vec.size())
                ans.push_back(vec);
        }

        for (int i = 0; i < len; i++)
        {
            char orig = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (dict.find(word) != dict.end())
                {
                    vec.push_back(word);
                    usedOnLevel.push_back(word);
                    q.push(vec);
                    vec.pop_back();
                }
            }
            word[i] = orig;
        }
    }
    return ans;
    // TC varies on input, can't say
}

map<string, int> findOneShortestPath(string beginWord, string endWord, vector<string> &wordList)
{
    // same as Word ladder - I
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    dict.erase(beginWord);

    map<string, int> path;
    path.insert({beginWord, 1});

    int n = beginWord.length();
    while (!q.empty())
    {
        auto [word, lvl] = q.front();
        q.pop();

        if (word == endWord)
            break;

        for (int i = 0; i < n; i++)
        {
            char orig = word[i];
            for (int ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (dict.count(word))
                {
                    q.push({word, lvl + 1});
                    path.insert({word, lvl + 1});
                    dict.erase(word);
                }
            }
            word[i] = orig;
        }
    }

    return path;
}

void backtrack(string &word, int lvl, string &beginWord, map<string, int> &path, vector<string> &seq, vector<vector<string>> &res)
{
    if (word == beginWord)
    {
        reverse(seq.begin(), seq.end());
        res.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }

    for (int i = 0; i < word.length(); i++)
    {
        char orig = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            word[i] = ch;
            if (path[word] == lvl - 1)
            {
                seq.push_back(word);
                backtrack(word, lvl - 1, beginWord, path, seq, res);
                seq.pop_back();
            }
        }
        word[i] = orig;
    }
}

vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string> &wordList)
{
    // Find one shortest path and then backtrack from end to find other paths
    map<string, int> path = findOneShortestPath(beginWord, endWord, wordList);
    vector<vector<string>> res;
    vector<string> seq;
    seq.push_back(endWord);
    backtrack(endWord, path[endWord], beginWord, path, seq, res);
    return res;
}

void print(vector<vector<string>> &res)
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
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit", endWord = "cog";

    // Gives TLE on LC, but this approach is recommended for interviews
    vector<vector<string>> res = findLadders1(beginWord, endWord, wordList);
    print(res);

    // Optimized for LC
    res = findLadders2(beginWord, endWord, wordList);
    print(res);
}

/*
Note for findLadders1():
Erase a word from the dictionary only after finishing the entire level
Reason: Multiple paths at the same depth may reach the same word
eg. Path1: [hit, pot, lot], Path2: [hit hot, lot]
If 'lot' is erased immediately after being used in the first path, the second valid path would be blocked
*/