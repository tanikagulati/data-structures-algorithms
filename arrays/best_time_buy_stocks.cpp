#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    int mini = prices[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        profit = max(profit, prices[i] - mini);
        mini = min(mini, prices[i]);
    }
    cout << profit << endl;
    // TC: O(n)
    // SC: O(1)
}