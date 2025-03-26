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
}