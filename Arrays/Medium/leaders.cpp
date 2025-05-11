#include <bits/stdc++.h>
using namespace std;

// Can skip revision

void leaders(vector<int> &v)
{
    int n = v.size();
    vector<int> res;
    res.push_back(v[n - 1]);

    int max = v[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] >= max)
        {
            res.push_back(v[i]);
            max = v[i];
        }
    }

    reverse(res.begin(), res.end());

    for (auto i : res)
    {
        cout << i << " ";
    }
    // TC: O(n)
    // SC: O(n)
}

int main()
{
    vector<int> v = {16, 17, 4, 3, 5, 2};

    // Brute: Iterate and check for each element
    // TC: O(n^2)

    // Optimal:
    leaders(v);
}