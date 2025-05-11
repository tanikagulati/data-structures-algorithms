#include <bits/stdc++.h>
using namespace std;

int findKthMissing(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;

    // TC: O(n)
}

int findKthMissingOptimal(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        int noOfMissingElements = nums[mid] - mid - 1;
        if (noOfMissingElements < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // After BS, high is at a position where no of missing elements is just less than k
    // ans = nums[high] + more
    // ans = nums[high] + k-(no of missing el)
    // ans = nums[high] + k - nums[high] + high + 1
    // ans = high + k + 1 = low + k

    return high + k + 1;

    // TC: O(logn)
}

int main()
{
    vector<int> nums = {2, 3, 6, 7, 11};
    int k = 12;

    // Brute: Maths
    cout << findKthMissing(nums, k) << endl;

    // Optimal: Maths + BS
    cout << findKthMissingOptimal(nums, k) << endl;
}