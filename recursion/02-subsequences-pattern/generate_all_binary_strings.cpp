#include <bits/stdc++.h>
using namespace std;

// Given an integer N , print all binary strings of size N which do not contain consecutive 1s.

void generateBinaryStrings(int n, vector<string> &res, string &s)
{
    if (s.size() == n)
    {
        res.push_back(s);
        return;
    }
    s.push_back('0');
    generateBinaryStrings(n, res, s);
    s.pop_back();
    if (s.empty() || s.back() == '0')
    {
        s.push_back('1');
        generateBinaryStrings(n, res, s);
        s.pop_back();
    }
    // TC: O(2^n)
    // SC: O(2^n) -> For res + O(n) -> Recursion stack space
}

void generateBinaryStrings2(int n, vector<string> &res, string s, char lastChar)
{
    if (s.size() == n)
    {
        res.push_back(s);
        return;
    }
    generateBinaryStrings2(n, res, s + '0', '0');
    if (s.empty() || lastChar == '0')
    {
        generateBinaryStrings2(n, res, s + '1', '1');
    }
    // TC: O(2^n)
    // SC: O(2^n) -> For res + O(n) -> Recursion stack space
}

int main()
{
    vector<string> res = {};
    string s = "";
    generateBinaryStrings(2, res, s);
    for (auto i : res)
    {
        cout << i << endl;
    }

    // res.clear();
    // Just another way to implement
    // generateBinaryStrings2(2, res, s, '0');
    // for (auto i : res)
    // {
    //     cout << i << endl;
    // }
}