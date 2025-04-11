#include <bits/stdc++.h>
using namespace std;

int countSubArraysWithXorKBrute(vector<int> &v, int target)
{
    int n = v.size();
    int xorr;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        xorr = 0;
        for (int j = i; j < n; j++)
        {
            xorr = xorr ^ v[j];
            if (xorr == target)
            {
                cnt++;
            }
        }
    }

    return cnt;
    // TC: O(n^2)
    // SC: O(1)
}

int countSubArraysWithXorKOptimal(vector<int> &v, int target)
{
    int n = v.size();
    unordered_map<int, int> mp;
    int xorr = 0;
    mp[0]++;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ v[i];
        int x = xorr ^ target;
        cnt += mp[x];
        mp[xorr]++;
    }

    return cnt;
    // TC: O(n)
    // SC: O(n)
}

int main()
{
    vector<int> v = {3, 5, 3, 7, 8, 2, 1};

    int target = 3;

    cout << countSubArraysWithXorKBrute(v, target) << endl;

    cout << countSubArraysWithXorKOptimal(v, target) << endl;
}