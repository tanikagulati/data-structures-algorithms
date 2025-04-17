#include <bits/stdc++.h>
using namespace std;

int binarySearchIterative(vector<int> &v, int target)
{
    int n = v.size();
    int low = 0, high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (target > v[mid])
            low = mid + 1;
        else if (target < v[mid])
            high = mid - 1;
        else
            return mid;
    }

    return -1;

    // TC: O(logn)
    // SC: O(1)
}

int binarySearchRecursive(vector<int> &v, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + ((high - low) / 2);

    if (target == v[mid])
        return mid;

    if (target > v[mid])
        return binarySearchRecursive(v, target, mid + 1, high);
    else
        return binarySearchRecursive(v, target, low, mid - 1);

    // TC: O(logn)
    // SC: O(1)
}

int main()
{
    vector<int> v = {2, 4, 6, 8, 9};
    int target = 7;
    cout << binarySearchIterative(v, target) << endl;

    cout << binarySearchRecursive(v, target, 0, v.size() - 1) << endl;
}