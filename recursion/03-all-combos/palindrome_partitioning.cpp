#include <bits/stdc++.h>
using namespace std;

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

bool checkPalindrome(string &s, int low, int high)
{
    while (low <= high)
    {
        if (s[low++] != s[high--])
        {
            return false;
        }
    }
    return true;
}

void palindromePartitioning(string &s, int index, vector<string> &temp, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(temp);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (checkPalindrome(s, index, i))
        {
            temp.push_back(s.substr(index, i - index + 1));
            palindromePartitioning(s, i + 1, temp, res);
            temp.pop_back();
        }
    }
    // TC: O(n*2^n)
    // SC: O(n*2^n) For res + O(n) Recursion stack space
}

int main()
{
    string s = "aabb";
    vector<string> temp;
    vector<vector<string>> res;

    palindromePartitioning(s, 0, temp, res);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}