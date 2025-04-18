#include <bits/stdc++.h>
using namespace std;

int minInRotatedSortedArray(vector<int> &v)
{
    int n = v.size();
    int low = 0, high = n - 1, mid;
    int mini = INT_MAX;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);

        // Full sorted
        if (v[low] <= v[high])
        {
            mini = min(mini, v[low]);
            break;
        }

        // Left sorted
        if (v[low] <= v[mid])
        {
            mini = min(mini, v[low]);
            low = mid + 1;
        }

        // Right sorted
        else
        {
            mini = min(mini, v[mid]);
            high = mid - 1;
        }
    }

    return mini;

    // TC: O(logn)
    // SC: O(1)
}

int minInRotatedSortedArray2(vector<int> &v)
{
    int n = v.size();
    int low = 0, high = n - 1, mid;
    int mini = INT_MAX;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);

        // Edge case -> eg. (8,0,8,8,8,8)
        if (v[low] == v[mid] && v[mid] == v[high])
        {
            mini = min(mini, v[low]);
            low++, high--;
            continue;
        }

        // Left sorted
        if (v[low] <= v[mid])
        {
            mini = min(mini, v[low]);
            low = mid + 1;
        }

        // Right sorted
        else
        {
            mini = min(mini, v[mid]);
            high = mid - 1;
        }
    }

    return mini;

    // TC: O(logn), ~ O(n/2) in case of edge case (so many duplicates of same number)
    // SC: O(1)
}

int main()
{
    vector<int> v1 = {4, 5, 1, 2, 3};
    vector<int> v2 = {4, 6, 6, 0, 0, 1, 1, 2, 3, 3, 4, 4, 4};

    // Unique elements
    cout << minInRotatedSortedArray(v1) << endl;

    // With duplicates
    cout << minInRotatedSortedArray2(v2) << endl;
}