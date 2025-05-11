#include <bits/stdc++.h>
using namespace std;

void missingAndRepeating(vector<int> &v)
{
    int n = v.size();

    long long sumOfN = (n * (n + 1)) / 2;
    long long sum = 0;

    long long sumOfSquaresOfN = (n * (n + 1) * (2 * n + 1)) / 6;
    long long sumOfSquares = 0;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        sumOfSquares += (long long)v[i] * (long long)v[i];
    }

    long long val1 = sumOfN - sum; // x-y

    long long val2 = (sumOfSquaresOfN - sumOfSquares) / val1; // x+y

    long long x = (val1 + val2) / 2; // missing

    long long y = x - val1; // repeating

    cout << x << " " << y << endl;

    // TC: O(n)
    // SC: O(1)
}

void missingAndRepeating2(vector<int> &v)
{
}

int main()
{
    vector<int> v = {4, 3, 2, 6, 1, 3};

    // Brute: Iterate for each element
    // TC: O(n^2), SC: O(1)

    // Better: Hasharray
    // TC: O(2n), SC: O(n)

    // Optimal:
    // Maths
    missingAndRepeating(v);

    // XOR: TODO
    missingAndRepeating2(v);
}