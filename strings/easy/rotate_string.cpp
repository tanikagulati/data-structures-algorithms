#include <bits/stdc++.h>
using namespace std;

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.

string rotate(string &s, int k)
{
    int len = s.size();
    if (k == len || k == 0)
        return s;
    string temp = "";
    int ind = 0;
    while (len--)
    {
        if (k == s.size())
        {
            k = 0;
        }
        temp.push_back(s[k]);
        ind++;
        k++;
    }
    return temp;
}

bool rotateString(string s, string goal)
{
    // Note: Checking if the lengths of both strings are different takes O(n)
    if (s.size() != goal.size())
        return false;

    if (s == goal)
        return true;

    for (int i = 1; i < s.size(); i++)
    {
        // Can also use stl for rotation
        if (rotate(s, i) == goal)
        {
            return true;
        }
    }
    return false;
    // TC: O(n^2)
    // SC: O(n)
}

bool rotateStringOptimal(string s, string goal)
{
    if (s.size() != goal.size())
        return false;

    if (s == goal)
        return true;

    // Concatenate s with itself
    // This new string contains all possible rotations of s within it
    string doubledString = s + s;

    return doubledString.find(goal) < doubledString.length();
    // TC: O(n)
    // SC: O(2n)
}

int main()
{
    cout << rotateString("abcde", "cdeab") << endl;

    cout << rotateStringOptimal("abcde", "cdeab") << endl;

    // TODO: Study Knuth-Morris-Pratt (KMP) algorithm
}