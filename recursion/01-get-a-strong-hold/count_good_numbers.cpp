#include <bits/stdc++.h>
using namespace std;

// A digit string is good if the digits (0-indexed) at even indices are even (0, 2, 4, 6, 8) and the digits at odd indices are prime (2, 3, 5, or 7).
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

const unsigned int M = 1000000007;

long long power(long long x, long long n)
{
    if (n == 0)
        return 1;

    long long half = power(x, n / 2);

    if (n % 2 == 0)
        return (half * half) % M;
    else
        return (half * half * x) % M;
}

int countGoodNumbers(long long n)
{
    long long res;
    // Using nCr
    if (n % 2 == 0)
    {
        res = (power(5, n / 2) * power(4, n / 2)) % M;
    }
    else
    {
        res = (power(5, (n / 2) + 1) * power(4, n / 2)) % M;
    }
    return res;
    // TC: O(2* log n) ~ O(log n)
}

int main()
{
    cout << countGoodNumbers(50) << endl;
}