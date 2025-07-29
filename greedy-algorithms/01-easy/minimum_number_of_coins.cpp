#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

vector<int> minNumberOfCoins(int n)
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
    vector<int> ans;
    int size = coins.size();

    for (int i = size - 1; i >= 0; i--)
    {
        while (n >= coins[i])
        {
            ans.push_back(coins[i]);
            n -= coins[i];
        }
    }

    return ans;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    int n = 43;

    vector<int> ans = minNumberOfCoins(n);

    for (auto i : ans)
        cout << i << " ";
}

// Note: Greedy approach here is possible because in the given denomination (coins), sum of two coins is always <= next coin
// If coins were randomly given in input, this approach would fail