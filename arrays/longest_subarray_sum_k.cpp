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
        if (!hash[prefixSum]) // This condition enforce a sum is only hashed once -> to handle zeros
        {
            hash[prefixSum] = i;
        }
        if (hash[prefixSum - k])
        {
            maxLength = max(maxLength, i - hash[prefixSum - k]);
        }
    }
    return maxLength;
    // TC: O(n) unordered map, O(nlog n) map
    // SC: O(n)
}

int longestSubArrayWithSumK3(vector<int> &v, int k)
{
    // Leveraging the fact that sum always increase moving forward
    // Only for positive elements
    int n = v.size();
    long long sum = v[0];
    int maxLen = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        while (i <= j && sum > k)
        {
            sum -= v[i];
            i++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, j - i + 1);
        }
        j++;
        if (j < n)
        {
            sum = sum + v[j];
        }
    }
    return maxLen;
    // TC: O(2n) -> Why? In worst case, every element is touched at most twice once by i and once by j
    // SC: O(1)
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

    // Optimal (only for positives)
    cout << longestSubArrayWithSumK3(v, k) << endl;
}