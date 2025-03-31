#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &v)
{
    int n = v.size();
    int sum = 0;
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            if (sum > max)
            {
                max = sum;
            }
        }
    }
    return max;
    // TC: O(n^2)
    // SC: O(1)
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // Brute: Check each subarray
    cout << maxSubarraySum(v) << endl;
}