#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-ladder-ii/description/

// Revisit

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
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

int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit", endWord = "cog";

    vector<vector<string>> res = findLadders(beginWord, endWord, wordList);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}