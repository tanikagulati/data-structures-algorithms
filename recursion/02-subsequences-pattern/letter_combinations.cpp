#include <bits/stdc++.h>
using namespace std;

// Given a string containing digits from 2-9, return all possible letter combinations that the number could represent.

void letterCombinations(string &digits, vector<string> &letters, int index, string &temp, vector<string> &res)
{
    if (index == digits.size())
    {
        res.push_back(temp);
        return;
    }
    int digit = digits[index] - '0';
    for (int i = 0; i < letters[digit].size(); i++)
    {
        temp.push_back(letters[digit][i]);
        letterCombinations(digits, letters, index + 1, temp, res);
        temp.pop_back();
    }
    // TC: O(4^n * n)
    // SC: O(4^n * n) For res + O(n) Recursion stack space
}

int main()
{
    string digits = "23";
    string temp = "";
    vector<string> res;

    vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    letterCombinations(digits, letters, 0, temp, res);

    for (auto i : res)
    {
        cout << i << endl;
    }
}