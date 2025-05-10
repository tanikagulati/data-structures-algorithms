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

double minimizeMaxDistanceBetter(vector<int> &stations, int k)
{
    int n = stations.size();
    vector<int> sections(n - 1);

    priority_queue<pair<double, int>> pq;

    // Store the initial differences with its index in pq
    for (int i = 0; i < n - 1; i++)
    {
        double diff = stations[i + 1] - stations[i];
        pq.push({diff, i});
    }

    int maxInd;
    double newSectionLength;

    for (int i = 0; i < k; i++)
    {
        maxInd = pq.top().second;
        pq.pop();
        sections[maxInd]++; // 2 0 1
        newSectionLength = double(stations[maxInd + 1] - stations[maxInd]) / double(sections[maxInd] + 1);
        pq.push({newSectionLength, maxInd});
    }

    return pq.top().first;
    // TC: O(nlogn + klogn)
    // SC: O(n-1)
}

int findRequiredStations(vector<int> &stations, long double mid)
{
    // TODO: Try some time later
}

double minimizeMaxDistanceOptimal(vector<int> &stations, int k)
{
    int n = stations.size();
    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++)
    {
        long double diff = stations[i + 1] - stations[i];
        high = max(high, diff);
    }
    long double mid;

    while (high - low < 10e-6)
    {
        mid = low + ((high - low) / 2);
        int reqdStations = findRequiredStations(stations, mid);
        if (reqdStations > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> stations = {1, 13, 17, 23};
    int k = 12;

    // Brute
    cout << minimizeMaxDistanceBrute(stations, k) << endl;

    // Better using PQ
    cout << minimizeMaxDistanceBetter(stations, k) << endl;

    // Optimal using BS
    // cout << minimizeMaxDistanceOptimal(stations, k) << endl;
}