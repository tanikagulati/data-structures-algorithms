#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> v, int x)
{
    int n = v.size();
    int low = 0, high = n - 1;
    int mid;
    int minIndex = n;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (v[mid] >= x)
        {
            minIndex = mid; // Probable answer
            high = mid - 1; // Keep checking in the left to find smallest index
        }
        else
        {
            low = mid + 1;
        }
    }

    return minIndex;
    // TC: O(logn)
    // SC: O(1)
}

int upperBound(vector<int> &v, int x)
{
    int n = v.size();
    int low = 0, high = n - 1;
    int mid;
    int minIndex = n;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (v[mid] > x)
        {
            minIndex = mid; // Probable answer
            high = mid - 1; // Keep checking in left
        }
        else
        {
            low = mid + 1;
        }
    }

    return minIndex;
    // TC: O(logn)
    // SC: O(1)
}

int searchInsertPosition(vector<int> &v, int x)
{
    // smallest number greater than x
    return upperBound(v, x); // even lower bound will also work
}

int floor(vector<int> &v, int x)
{
    int n = v.size();
    int low = 0, high = n - 1;
    int mid;
    int ans = -1;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (v[mid] <= x)
        {
            ans = v[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int ceil(vector<int> &v, int x)
{
    return v[lowerBound(v, x)];
}

int main()
{
    vector<int> v = {2, 5, 5, 6, 8, 8, 9, 9};
    int x = 7;

    // index of (smallest number >= x)
    cout << lowerBound(v, x) << endl;

    // index of (smallest number > x)
    cout << upperBound(v, x) << endl;

    cout << searchInsertPosition(v, x) << endl;

    // largest number <= x (not index)
    cout << floor(v, x) << endl;

    // smallest number >= x (not index)
    cout << ceil(v, x) << endl;
}