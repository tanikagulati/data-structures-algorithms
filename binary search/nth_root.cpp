#include <bits/stdc++.h>
using namespace std;

int power(int mid, int n, int m)
{
    // Custom power fn to prevent overflows
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (ans * mid == m)
        {
            return 1;
        }
        else if (ans * mid > m)
        {
            return 2;
        }
        else
        {
            ans = ans * mid;
        }
    }
    return 0;

    // TC: O(n) -> Can be done in O(log n) using binary exponentiation
    // SC: O(1)
}

// TODO:
// binaryExponentiation(){
// }

int nthRoot(int m, int n)
{
    int low = 1, high = m, mid;
    long long val;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        val = power(mid, n, m);
        if (val == 1)
        {
            return mid;
        }
        else if (val == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;

    // TC: O(n log m)
    // SC: O(1)
}

int main()
{
    int m = 81;
    int n = 4;

    cout << nthRoot(m, n) << endl;
}