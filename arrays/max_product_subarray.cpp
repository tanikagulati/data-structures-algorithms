#include <bits/stdc++.h>
using namespace std;

long long maxProductSubarrayBrute(vector<int> &v)
{
    long long maxProduct = INT_MIN;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        long long product = 1;
        for (int j = i; j < n; j++)
        {
            product = product * v[j];
            maxProduct = max(maxProduct, product);
        }
    }
    return maxProduct;

    // TC: O(n^2)
    // SC: O(1)
}

long long maxProductSubarrayOptimal(vector<int> v)
{
    long long maxProduct = INT_MIN;
    long long prefixProduct = 1;
    long long suffixProduct = 1;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (prefixProduct == 0)
        {
            prefixProduct = 1;
        }
        if (suffixProduct == 0)
        {
            suffixProduct = 1;
        }

        prefixProduct *= v[i];
        suffixProduct *= v[n - 1 - i];
        maxProduct = max(maxProduct, max(prefixProduct, suffixProduct));
    }
    return maxProduct;

    // TC: O(n)
    // SC: O(1)
}

int main()
{
    vector<int> v = {2, 0, -2, 4, 0, -3, 5, 2};

    // Brute: Generate all subarrays and check
    cout << maxProductSubarrayBrute(v) << endl;

    // Optimal: Based on observations

    // All positives -> Full array product is ans
    // Even no of negatives -> Full array product is ans
    // Odd no of negatives -> Ignoring one negative, either its prefix or suffix will give ans
    // Handle zeros -> set product = 1

    cout << maxProductSubarrayOptimal(v) << endl;
}