#include <bits/stdc++.h>
using namespace std;

int mergeSortedArrays(vector<int> &v, int low, int mid, int high)
{
    vector<int> res;
    int left = low;
    int right = mid + 1;
    int count = 0;

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
            count += mid - left + 1;
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

    return count;
}

int countInversions(vector<int> &v, int low, int high)
{
    int count = 0;
    if (low == high)
        return count;

    int mid = (low + high) / 2;
    count += countInversions(v, low, mid);
    count += countInversions(v, mid + 1, high);
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
    cout << countInversions(v, 0, n - 1) << endl;

    for (auto i : v)
    {
        cout << i << " ";
    }
}