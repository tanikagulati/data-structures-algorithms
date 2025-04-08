#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {3, -3, 1, 1, 1};
    int k = 3;

    // Brute: Genearte all subarrays and check sum

    // Optimal: Using prefix sum

    int n = v.size();
    long long sum = 0;
    unordered_map<long, int> prefixSum;
    int count = 0;

    prefixSum[0]++; // Imp

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        count += prefixSum[sum - k];
        prefixSum[sum]++;
    }

    cout << count << endl;
    // TC: O(n)
    // SC: O(n)
}