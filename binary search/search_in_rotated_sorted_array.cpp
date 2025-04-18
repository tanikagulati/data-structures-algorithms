#include <bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(vector<int> &v, int target)
{
    int n = v.size();
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (target == v[mid])
        {
            return mid;
        }
        // What next? Eliminate one half -> Identify sorted half of the array and check for target
        else
        {
            // Left sorted
            if (v[low] <= v[mid])
            {
                if (v[low] <= target && target < v[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // Right sorted
            else
            {
                if (v[mid] < target && target <= v[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
    }

    return -1;

    // TC: O(logn)
    // SC: O(1)
}

bool searchInRotatedSortedArray2(vector<int> &v, int target)
{
    int n = v.size();
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (target == v[mid])
        {
            return true;
        }

        // To handle an edge case where sorted half cannot be determined
        if (v[low] == v[mid] && v[mid] == v[high])
        {
            low++, high--;
            continue;
        }

        else
        {
            // Left sorted
            if (v[low] <= v[mid])
            {
                if (v[low] <= target && target < v[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // Right sorted
            else
            {
                if (v[mid] < target && target <= v[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
    }

    return false;

    // TC: O(logn), ~ O(n/2) in case of edge case (so many duplicates of same number)
    // SC: O(1)
}

int main()
{
    vector<int> v = {4, 5, 6, 6, 8, 0, 0, 0, 2, 2, 2};
    int target = 6;

    // Unique elements
    cout << searchInRotatedSortedArray(v, target) << endl;

    // With duplicates
    cout << searchInRotatedSortedArray2(v, target) << endl;
}
