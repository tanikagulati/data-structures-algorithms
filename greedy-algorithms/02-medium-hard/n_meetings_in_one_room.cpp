#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// Similar: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/

class Data
{
public:
    int start;
    int end;
    int pos; // in case positions of chosen meetings is asked
};

bool comp(Data d1, Data d2)
{
    return d1.end < d2.end;
    // <= is not valid in comparators, since it fails the property: if comp(val1, val2) is true then comp(val2, val1) should be false
}

int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    Data arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1; // 1 based index
    }
    sort(arr, arr + n, comp);

    int cnt = 1;
    int prevEnd = arr[0].end;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].start > prevEnd)
        {
            cnt++;
            prevEnd = arr[i].end;
        }
    }
    return cnt;
    // TC: O(2n + nlogn)
    // SC: O(3n)
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << maxMeetings(start, end) << endl;
}