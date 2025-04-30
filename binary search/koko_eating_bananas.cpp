#include <bits/stdc++.h>
using namespace std;

// Find minimun integer k such that koko can eat all bananas in <= given no of hours
// k = bananas/hr

int findGreatestPile(vector<int> &piles)
{
    int n = piles.size();
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}

long long findTimeTaken(vector<int> &piles, int mid)
{
    long long totalHrs = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        totalHrs += ceil((double)piles[i] / (double)mid);
    }
    return totalHrs;
}

int minEatingSpeed(vector<int> &piles, int hours)
{
    int low = 1;
    int high = findGreatestPile(piles);
    int mid;
    long long timeTaken;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        timeTaken = findTimeTaken(piles, mid);
        if (timeTaken <= hours)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;

    // TC: O(log(maxElement)) * O(n)
    // SC: O(1)
}

int main()
{
    vector<int> piles = {3, 6, 7, 11}; // 1 2 3 4 5 6 7 8 9 10 11
    int hours = 8;

    cout << minEatingSpeed(piles, hours) << endl;
}
