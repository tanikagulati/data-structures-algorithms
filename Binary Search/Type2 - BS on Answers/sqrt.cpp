#include <bits/stdc++.h>
using namespace std;

// Floor of sqrt of n OR
// Max integer <= sqrt of n

int findSqrt(int n)
{
    int ans;

    for (int i = 1; i < n; i++)
    {
        if (i * i <= n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }

    return ans;

    // TC: O(sqrt n)
    // SC: O(1)
}

int findSqrtBS(int n)
{
    int low = 1, high = n, mid; // high = n/2 also valid
    long long temp;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        temp = mid * mid;
        if (temp <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;

    // TC: O(logn) much better than O(sqrt n)
    // SC: O(1)
}

int main()
{
    int n = 13;

    // Brute iteration
    cout << findSqrt(n) << endl;

    // Optimal: Using binary search
    cout << findSqrtBS(n) << endl;
}