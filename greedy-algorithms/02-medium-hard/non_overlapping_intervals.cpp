#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/non-overlapping-intervals/description/

// Inverse of the problem - N meetings in one room

bool comp(vector<int> val1, vector<int> val2)
{
    return val1[1] < val2[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), comp);
    int n = intervals.size();
    int cnt = 1;
    int lastEndTime = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] >= lastEndTime)
        {
            cnt++;
            lastEndTime = intervals[i][1];
        }
    }
    return n - cnt;
    // TC: O(n + nlogn)
    // SC: O(1)
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    cout << eraseOverlapIntervals(intervals) << endl;
}