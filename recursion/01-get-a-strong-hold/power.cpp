#include <bits/stdc++.h>
using namespace std;

double powerBrute(double x, int n, double res)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return res;
    else if (n == -1)
        return 1 / res;

    res = res * x;
    if (n > 0)
        n--;
    else if (n < 0)
        n++;
    return powerBrute(x, n, res);
    // TC: O(n)
    // SC: O(n)
}

double powerOptimal(double x, int n)
{
    // 2^10 = (2*2)^5
    // 4^5 = 4*(4^4)
    // 4^4 = (4*4)^2
    if (n == 0)
        return 1;
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

int main()
{
    double x = 2;
    int n = 4;
    // Brute:
    cout << powerBrute(x, n, x) << endl;

    // Optimal: Binary exponentiation
    cout << powerOptimal(x, n) << endl;
}