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

int maxSubarraySum2(vector<int> &v)
{
    int n = v.size();
    long long sum = 0;
    int max = LONG_MIN;
    int a = 0, b = 0; // Indexes of result subarray
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            temp = i; // Potential result start index
        }
        sum += v[i];
        if (sum > max)
        {
            max = sum;
            // Update indexes only while updating max
            b = i;
            a = temp;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << a << " " << b << endl;
    return max;
    // TC: O(n)
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
    // cout << maxSubarraySum(v) << endl;

    // Optimal: Kadane's algo
    cout << maxSubarraySum2(v) << endl;

    // Follow up: Try with divide and conquer
}