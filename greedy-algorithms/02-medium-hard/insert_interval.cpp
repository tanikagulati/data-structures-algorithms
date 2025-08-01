#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/insert-interval/description/

vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    if (n == 0)
        return {newInterval};
    vector<vector<int>> res;

    int i = 0;
    while (i < n)
    {
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }
    }
    return res;
    // TC: O(n)
    // SC: O(n)
}

int main()
{
    vector<vector<int>> intervals = {};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> res = insertInterval(intervals, newInterval);
    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}