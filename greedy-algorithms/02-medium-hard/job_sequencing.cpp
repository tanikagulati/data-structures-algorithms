#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

bool comp(pair<int, int> val1, pair<int, int> val2)
{
    return val1.second > val2.second;
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
{
    {
        int n = deadline.size();
        vector<pair<int, int>> data(n);

        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
        {
            data[i] = {deadline[i], profit[i]};
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        sort(data.begin(), data.end(), comp);

        bool hash[maxDeadline + 1] = {0};
        int cnt = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; i++)
        {
            // TODO: This inner loop can be replaced by using DSU (try later)
            for (int j = data[i].first; j > 0; j--)
            {
                if (hash[j] == 0)
                {
                    hash[j] = 1;
                    cnt++;
                    totalProfit += data[i].second;
                    break;
                }
            }
        }
        return {cnt, totalProfit};
        // TC: O(n + nlogn + n*maxDeadline)
        // SC: O(2n + maxDeadline)
    }
}

int main()
{
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};

    vector<int> ans = jobSequencing(deadline, profit);
    cout << ans[0] << " " << ans[1] << endl;
}