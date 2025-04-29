#include <bits/stdc++.h>
using namespace std;

int nthRoot(int m, int n)
{
    int low = 1, high = m, mid;
    long long val;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        val = pow(mid, n);
        if (val == m)
        {
            return mid;
        }
        if (val < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;

    // TC: O(log m) for BS + O(log n) for power func
    // SC:O(1)
}

int main()
{
    int m = 82;
    int n = 4;

    cout << nthRoot(m, n) << endl;
}