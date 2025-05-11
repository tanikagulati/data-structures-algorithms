#include <bits/stdc++.h>
using namespace std;

void printResult(vector<vector<int>> &res)
{
    for (auto i : res)
    {
        cout << i[0] << " " << i[1];
        cout << endl;
    }
}

void mergeIntervals(vector<vector<int>> v)
{
    int n = v.size();
    sort(v.begin(), v.end());

    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
        if (res.empty() || v[i][0] > res.back()[1])
        {
            res.push_back(v[i]);
        }
        else
        {
            res.back()[1] = max(res.back()[1], v[i][1]);
        }
    }

    printResult(res);

    // TC: O(nlogn + n)
    // SC: O(n) for result
}

int main()
{
    vector<vector<int>> v = {{2, 6}, {5, 8}, {1, 3}, {10, 11}};
    mergeIntervals(v);
}