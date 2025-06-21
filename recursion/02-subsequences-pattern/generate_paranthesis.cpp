#include <bits/stdc++.h>
using namespace std;

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

void generateParenthesis(int n, vector<string> &res, string &s, int openCount, int closedCount)
{
    if (s.size() == n * 2)
    {
        res.push_back(s);
        return;
    }
    if (openCount < n)
    {
        s.push_back('(');
        generateParenthesis(n, res, s, openCount + 1, closedCount);
        s.pop_back();
    }
    if (closedCount < n && openCount > closedCount)
    {
        s.push_back(')');
        generateParenthesis(n, res, s, openCount, closedCount + 1);
        s.pop_back();
    }
    // TC: O(2n * C_n) -> C_n = Catalan number
    // SC: O(2n * C_n)
}

int main()
{
    vector<string> res = {};
    string s = "";
    generateParenthesis(3, res, s, 0, 0);

    for (auto i : res)
    {
        cout << i << endl;
    }
}

/*
TODO: Read more
Catalan numbers form a famous sequence in combinatorics that counts the number of ways to solve various types of problems involving recursive structures and balanced things, like:
Valid parentheses expressions, Binary tree structures, Ways to triangulate polygons, Stack permutations, Dyck words

Formula: C_n = (2n)! / ((n+1)! * n!)

n	C(n)
0	1
1	1
2	2
3	5
4   14

*/