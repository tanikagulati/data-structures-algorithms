#include <bits/stdc++.h>
using namespace std;

int mergeSortedArrays(vector<int> &v, int low, int mid, int high)
{
    vector<int> res;
    int low1 = low;
    int low2 = mid + 1;
    int count = 0;

    while (low1 <= mid && low2 <= high)
    {
        if (v[low1] <= v[low2])
        {
            res.push_back(v[low1]);
            low1++;
        }
        else
        {
            res.push_back(v[low2]);
            low2++;
            count += mid - low1 + 1;
        }
    }

    while (low1 <= mid)
    {
        res.push_back(v[low1]);
        low1++;
    }

    while (low2 <= high)
    {
        res.push_back(v[low2]);
        low2++;
    }

    for (int i = low; i <= high; i++)
    {
        v[i] = res[i - low];
    }

    return count;
}

int mergeSort(vector<int> &v, int low, int high)
{
    int count = 0;
    if (low == high)
        return count;

    int mid = (low + high) / 2;
    count += mergeSort(v, low, mid);
    count += mergeSort(v, mid + 1, high);
    count += mergeSortedArrays(v, low, mid, high);
    return count;

    // TC: O(nlogn)
    // SC: O(n)
}

int main()
{
    // Brute: Iterate for each element and check

    // Optimal: Using merge sort

    vector<int> v = {5, 3, 2, 1, 4};
    int n = v.size();
    cout << mergeSort(v, 0, n - 1) << endl;

    for (auto i : v)
    {
        cout << i << " ";
    }
}