#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

int minimumPlatformsBrute(vector<int> &arr, vector<int> &dep)
{
    // On the basis of time intersections
    int n = arr.size();
    int cnt = 1;
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        cnt = 1;
        for (int j = i + 1; j < n; j++)
        {
            // Starts before and end after arrival of i OR Starts between arrival and departure of i
            if ((arr[j] <= arr[i] && dep[j] >= arr[i]) || (arr[j] >= arr[i] && arr[j] <= dep[i]))
                cnt++;
            maxi = max(cnt, maxi);
        }
    }
    return maxi;
    // TC: O(n^2)
    // SC: O(1)

    // TODO: Check WA for this TC:
    // 646 1812 1953 1859 46 1935 1624 617 1645 628
    // 805 2200 2106 2333 1554 2047 2020 1900 2048 2351
}

int minimumPlatformsOptimal(vector<int> &arr, vector<int> &dep)
{
    // Clock ticking: Event at each time
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int a = 0, d = 0;
    int cnt = 0, maxi = 0;

    while (a < n) // Arrival will always exhaust first
    {
        if (arr[a] <= dep[d])
            cnt++, a++;
        else
            cnt--, d++;
        maxi = max(maxi, cnt);
    }
    return maxi;
    // TC: O(2nlogn + 2n)
    // SC: O(1)
}

int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << minimumPlatformsBrute(arr, dep) << endl;

    cout << minimumPlatformsOptimal(arr, dep) << endl;
}