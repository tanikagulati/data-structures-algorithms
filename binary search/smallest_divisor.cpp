#include <bits/stdc++.h>
using namespace std;

// Find smallest divisor such that sum of (all numbers after dividing by divisor) <= threshold

int findMax(vector<int> &nums)
{
    int n = nums.size();
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, nums[i]);
    }
    return maxi;
}

long long sumAfterDivision(vector<int> &nums, int mid)
{
    int n = nums.size();
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)nums[i] / (double)mid);
    }
    return sum;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();

    if (threshold < n)
        return -1;

    int low = 1, high = findMax(nums), mid;
    long long val;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        val = sumAfterDivision(nums, mid);
        if (val <= threshold)
        {
            high = mid - 1; // To increase the sum and decrease the divisor
        }
        else
        {
            low = mid + 1; // To decrease the sum and increase the divisor
        }
    }

    return low;

    // TC: O(n * log(maxEl))
    // SC: O(1)
}

int main()
{
    vector<int> nums = {44, 22, 33, 11, 1};
    int threshold = 5;

    cout << smallestDivisor(nums, threshold) << endl;
}
