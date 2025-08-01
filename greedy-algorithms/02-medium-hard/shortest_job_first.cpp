#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-job-first/1

long long shortestJobFirst(vector<int> &taskTime)
{
    int n = taskTime.size();
    sort(taskTime.begin(), taskTime.end());
    int timer = 0;
    int waitTime = 0;
    for (int i = 0; i < n; i++)
    {
        waitTime += timer;
        timer += taskTime[i];
    }
    return waitTime / n;
    // TC: O(n + nlogn)
    // SC: O(1)
}

int main()
{
    vector<int> taskTime = {4, 3, 7, 1, 2};

    cout << shortestJobFirst(taskTime) << endl;
}