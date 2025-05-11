#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &v, int low, int mid, int high)
{
    vector<int> res;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (v[left] <= v[right])
        {
            res.push_back(v[left]);
            left++;
        }
        else
        {
            res.push_back(v[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        res.push_back(v[left]);
        left++;
    }

    while (right <= high)
    {
        res.push_back(v[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        v[i] = res[i - low];
    }
}

int countPairs(vector<int> &v, int low, int mid, int high)
{
    int count = 0;
    int right = mid + 1;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && v[i] > 2 * v[right])
        {
            right++;
        }
        count += right - (mid + 1);
    }
    return count;
}

int reversePairs(vector<int> &v, int low, int high)
{
    int count = 0;
    if (low == high)
        return count;

    int mid = (low + high) / 2;
    count += reversePairs(v, low, mid);
    count += reversePairs(v, mid + 1, high);
    count += countPairs(v, low, mid, high);
    mergeSortedArrays(v, low, mid, high);
    return count;

    // TC: O(2nlogn)
    // SC: O(n)
}

int main()
{
    // i<j & a[i] > 2*a[j]

    // Brute: Generate all pairs and check -> O(n^2)

    // Optimal: Using merge sort

    vector<int> v = {1, 3, 2, 3, 1};
    int n = v.size();
    cout << reversePairs(v, 0, n - 1) << endl;

    for (auto i : v)
    {
        cout << i << " ";
    }
}