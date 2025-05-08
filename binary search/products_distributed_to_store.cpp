#include <bits/stdc++.h>
using namespace std;

// Minimize the maximum number of products that are given to any store

int findDistributedAmong(vector<int> &quantities, int maxAllowed, int stores)
{
    int n = quantities.size();
    int storeCnt = 0;
    for (int i = 0; i < n; i++)
    {
        storeCnt += ceil((double)quantities[i] / (double)maxAllowed);
        if (storeCnt > stores)
        {
            break;
        }
    }
    return storeCnt;
}

int minimizedMaximum(vector<int> &quantities, int stores)
{
    int n = quantities.size();
    int low = 1, high = *max_element(quantities.begin(), quantities.end());
    int mid;
    if (stores == n)
        return high;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        int storeCnt = findDistributedAmong(quantities, mid, stores);
        if (storeCnt > stores)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;

    // TC: O(log(max) * n)
}

int main()
{
    vector<int> quantities = {11, 6};
    int stores = 6;

    cout << minimizedMaximum(quantities, stores);
}