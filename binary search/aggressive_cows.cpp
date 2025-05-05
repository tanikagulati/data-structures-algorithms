#include <bits/stdc++.h>
using namespace std;

// Assign stalls to k cows such that the minimum distance between any two of them is the maximum possible

bool possibleToPlace(vector<int> &stalls, int cows, int minDist)
{
    int n = stalls.size();
    int cowsPlaced = 1;
    int lastPosition = stalls[0];

    for (int i = 0; i < n; i++)
    {
        if ((stalls[i] - lastPosition) >= minDist)
        {
            cowsPlaced++;
            lastPosition = stalls[i];
        }
        if (cowsPlaced >= cows)
        {
            return true;
        }
    }

    return false;
}

int aggressiveCowsBrute(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int limit = stalls[n - 1] - stalls[0];

    // Max distance between 2 cows possible is maxEl-minEl
    for (int i = 1; i <= limit; i++)
    {
        if (!possibleToPlace(stalls, k, i))
        {
            return i - 1;
        }
    }

    return limit;

    // TC: O((maxEl-minEl) * n)
}

int aggressiveCowsOptimal(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0], mid;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (possibleToPlace(stalls, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;

    // TC: O(log(maxEl-minEl) * n)
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    cout << aggressiveCowsBrute(stalls, k) << endl;

    cout << aggressiveCowsOptimal(stalls, k) << endl;
}