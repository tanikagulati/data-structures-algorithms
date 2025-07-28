#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    {
        int n = val.size();
        vector<pair<double, int>> valueperWeight;
        double totalVal = 0.0;

        // Calculate value per weight
        for (int i = 0; i < n; i++)
            valueperWeight.push_back({1.0 * val[i] / wt[i], i});

        // Sort in descending order
        sort(valueperWeight.begin(), valueperWeight.end(), greater<pair<double, int>>());

        for (int i = 0; i < n; i++)
        {
            int ind = valueperWeight[i].second;
            if (wt[ind] <= capacity)
            {
                totalVal += val[ind];
                capacity -= wt[ind];
            }
            else
            {
                totalVal += valueperWeight[i].first * capacity;
                break;
            }
        }
        return totalVal;
        // TC: O(2n + nlogn)
        // SC: O(n)
    }
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    cout << fractionalKnapsack(val, wt, capacity) << endl;
}