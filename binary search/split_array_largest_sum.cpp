#include <bits/stdc++.h>
using namespace std;

// Same as Book allocation problem
// Split array into k subarrays such that max subarray sum is minimum
// Also known as Painter's partition problem

int findSplits(vector<int> &nums, int maxSum)
{
    int n = nums.size();
    int splits = 1;
    long long sum = nums[0];
    for (int i = 1; i < n; i++)
    {
        sum += nums[i];
        if (sum > maxSum)
        {
            splits++;
            sum = nums[i];
        }
    }
    return splits;
}

int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0);
    int mid;

    long long sum = high;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        int splits = findSplits(nums, mid);
        if (splits > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
    // TC: O(log(sum-max+1) * n)
}

int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout << splitArray(nums, k) << endl;
}
