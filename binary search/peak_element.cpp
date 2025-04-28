#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &v)
{
    int n = v.size();
    int low = 1, high = n - 2, mid;
    int peak = -1;

    if (n == 1)
        return 0;

    // Given v[-1] and v[n] are -(infinity)
    if (v[0] > v[1])
        return 0;
    if (v[n - 1] > v[n - 2])
        return n - 1;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
        {
            return mid;
        }
        else if (v[mid + 1] > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return peak;

    // TC: O(logn)
    // SC: O(1)
}

int main()
{
    vector<int> v = {1, 2, 1, 3, 5, 6, 4};

    // Brute: Linear search

    // Optimal
    cout << peakElement(v) << endl;
}