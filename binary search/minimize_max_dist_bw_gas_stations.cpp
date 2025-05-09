#include <bits/stdc++.h>
using namespace std;

// Place k more stations and minimize the maximum distance between gas stations

double minimizeMaxDistanceBrute(vector<int> &stations, int k)
{
    int n = stations.size();
    vector<int> sections(n - 1);
    double maxDist = -1;
    int maxDistInd = -1;

    // Placing station 1 by 1
    for (int i = 0; i < k; i++)
    {
        maxDist = -1;
        maxDistInd = -1;
        // Find max difference to minimize
        for (int j = 0; j < n - 1; j++)
        {
            double diff = double(stations[j + 1] - stations[j]) / double(sections[j] + 1);
            if (diff > maxDist)
            {
                maxDist = diff;
                maxDistInd = j;
            }
        }
        // Place the station in required section
        sections[maxDistInd]++;
    }

    maxDist = -1;
    // Find max distance for final answer
    for (int j = 0; j < n - 1; j++)
    {
        double diff = double(stations[j + 1] - stations[j]) / double(sections[j] + 1);
        maxDist = max(maxDist, diff);
    }

    return maxDist;
    // TC: O((k*n)+n)
    // SC: O(1)
}

double minimizeMaxDistanceOptimal(vector<int> &stations, int k)
{
    int n = stations.size();
    vector<int> sections(n - 1);

    priority_queue<int> pq;

    // Store the differences in pq
    for (int i = 0; i < n; i++)
    {
        double diff = double(stations[i + 1] - stations[i]);
        pq.push(diff);
    }
}

int main()
{
    vector<int> stations = {1, 13, 17, 23};
    int k = 5;

    cout << minimizeMaxDistanceBrute(stations, k) << endl;

    // cout << minimizeMaxDistanceOptimal(stations, k) << endl;
}