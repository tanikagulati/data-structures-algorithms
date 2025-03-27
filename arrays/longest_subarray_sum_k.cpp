#include <bits/stdc++.h>
using namespace std;

int longestSubArrayWithSumK(vector<int> &v, int k)
{
    int n = v.size();
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + v[j];
            if (sum == k)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
    // TC: O(n^2)
    // SC: O(1)
}

int longestSubArrayWithSumK2(vector<int> &v, int k)
{
    int n = v.size();
    unordered_map<long long, int> hash;
    int maxLength = 0;
    long long prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += v[i];
        if (prefixSum == k)
        {
            maxLength = max(maxLength, i + 1);
        }
        if (!hash[prefixSum - k])
        {
            hash[prefixSum] = i;
        }

        if (hash[prefixSum - k])
        {
            maxLength = max(maxLength, i - hash[prefixSum - k]);
        }
    }
    return maxLength;
}

int main()
{
    // Find length of longest subarray with sum k (considering only positive numbers)
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;

    // Brute
    cout << longestSubArrayWithSumK(v, k) << endl;

    // Better using hashing
    cout << longestSubArrayWithSumK2(v, k) << endl;
}