#include <bits/stdc++.h>
using namespace std;

// Find min days to wait to be able to make m bouqets
// k adjacent flowers required to make 1 bouquet
// ith flower will bloom in the bloomDay[i] (can be used only once)
// -1 if not possible

pair<int, int> findMinAndMax(vector<int> &bloomDay)
{
    int n = bloomDay.size();
    int maxi = 0, mini = 0;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }
    return {mini, maxi};
}

int numberOfBouquetsMade(vector<int> &bloomDay, int k, int mid)
{
    int n = bloomDay.size();
    int flowersCount = 0;
    int bouqetCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= mid)
        {
            flowersCount++;
        }
        else // Not adjacent case
        {
            bouqetCount += (flowersCount / k);
            flowersCount = 0;
        }
    }
    bouqetCount += (flowersCount / k);

    return bouqetCount;
}

int minDaysToMakeBouqets(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    pair<int, int> range = findMinAndMax(bloomDay);
    int low = range.first, high = range.second;
    int mid;
    int ans = -1;

    // Impossible to make reqd no of bouqets even if all flowers are bloomed
    long long val = m * 1LL * k * 1LL;
    if (n < val)
        return ans;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        int bouqetCount = numberOfBouquetsMade(bloomDay, k, mid);
        if (bouqetCount >= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;

    // TC: O(log(maxEl - minEl + 1)) * n
    // SC: O(1)
}

int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3; // no of bouqets reqd
    int k = 1; // adjacent flowers reqd

    cout << minDaysToMakeBouqets(bloomDay, m, k) << endl;
}