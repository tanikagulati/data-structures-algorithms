#include <bits/stdc++.h>
using namespace std;

double powerBrute(double x, int n)
{
    // This will not work for large values of n (recursion stack will overflow)
    // so, iterative is better
    if (n == 0)
        return 1;
    if (n < 0)
        return 1.0 / powerBrute(x, -n);

    return x * powerBrute(x, n - 1);
    // TC: O(n)
    // SC: O(n)
}

double powerOptimal(double x, int n)
{
    if (n == 0)
        return 1;
    // This will not work if n == INT_MIN, since positive version of INT_MIN is out of int range
    // Either handle this explicitly or take n as long long
    if (n < 0)
        return 1.0 / powerOptimal(x, -n);

    double half = powerOptimal(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
    // TC: O(log n)
    // SC: O(log n)
}

double powerIterative(double x, int n)
{
    long long N = n;
    if (N < 0)
    {
        N = -N;
        x = 1 / x;
    }
    double res = 1.0;
    while (N > 0)
    {
        if (N % 2 == 1)
        {
            res *= x;
        }
        N /= 2;
        x *= x;
    }
    return res;
    // TC: O(log n)
    // SC: O(1)
}

int main()
{
    double x = 2;
    int n = -4;
    // Brute:
    cout << powerBrute(x, n) << endl;

    // Optimal: Binary exponentiation
    cout << powerOptimal(x, n) << endl;

    // n as long long to avoid out of int range case
    cout << powerIterative(x, n) << endl;
}

// Intuition:
// 2^10 = (2*2)^5
// 4^5 = 4*(4^4)
// 4^4 = (4*4)^2