#include <bits/stdc++.h>
using namespace std;

// Find least capacity to deliver all packages in d days

int findMax(vector<int> &weights)
{
    int n = weights.size();
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, weights[i]);
    }
    return maxi;
}

int findSum(vector<int> &weights)
{
    int n = weights.size();
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];
    }
    return sum;
}

int findDaysRequired(vector<int> &weights, int capacity)
{
    int n = weights.size();
    int load = 0, count = 1;
    for (int i = 0; i < n; i++)
    {
        if (load + weights[i] > capacity)
        {
            count++;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return count;
}

int findLeastCapacity(vector<int> &weights, int d)
{
    int n = weights.size();
    int low = findMax(weights);
    int high = findSum(weights);
    int mid;
    int daysRequired;

    while (low <= high)
    {
        mid = low + ((high - low)) / 2;
        daysRequired = findDaysRequired(weights, mid);
        if (daysRequired <= d)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int d = 5;

    cout << findLeastCapacity(weights, d) << endl;
}