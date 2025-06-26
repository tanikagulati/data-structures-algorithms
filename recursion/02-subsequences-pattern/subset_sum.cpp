#include <bits/stdc++.h>
using namespace std;

// Given a array arr of integers, return the sums of all subsets in the list. Return the sums in any order.

void subsetSum(vector<int> &v, int index, int sum, vector<int> &res)
{
    if (index == v.size())
    {
        res.push_back(sum);
        return;
    }
    subsetSum(v, index + 1, sum + v[index], res);
    subsetSum(v, index + 1, sum, res);
    // TC: O(2^n)
    // SC: O(2^n) For result + O(n) Recursion stack space
}

int main()
{
    vector<int> res;
    vector<int> v = {5, 6, 7};

    // Brute: Power set (2^n * n)

    // Optimal:
    subsetSum(v, 0, 0, res);

    for (auto i : res)
    {
        cout << i << " ";
        cout << endl;
    }
}