#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, -1, 2, -2, 0, 7, -3, -2};

    // Brute: Genearte all subarrays and check

    // Optimal:
    int n = v.size();
    unordered_map<long long, int> mp;

    long long sum = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum == 0)
            maxi = max(maxi, i + 1);

        if (mp.find(sum) != mp.end())
        {
            maxi = max(maxi, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    cout << maxi << endl;

    // TC: O(n)
    // SC: O(n)
}