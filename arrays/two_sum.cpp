#include <bits/stdc++.h>
using namespace std;

// Return the indexes of two elements whose sum equals k

pair<int, int> twoSum(vector<int> v, int k)
{
    int n = v.size();
    unordered_map<int, int> hash;
    int more;
    for (int i = 0; i < n; i++)
    {
        more = k - v[i];
        if (hash.find(more) != hash.end())
        {
            return {hash[more], i};
        }
        hash[v[i]] = i;
    }
    return {-1, -1};
    // TC: O(n) for unordered map, O(nlogn) for map
    // SC: O(n)
}

string twoSum2(vector<int> v, int k)
{
    int n = v.size();
    int i = 0, j = n - 1;
    sort(v.begin(), v.end());
    while (i < j)
    {
        if (v[i] + v[j] > k)
        {
            j--;
        }
        else if (v[i] + v[j] < k)
        {
            i++;
        }
        else
        {
            return "Yes";
        }
    }
    return "No";
    // TC: O(n+nlogn)
    // SC: O(1)
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;

    // Brute: Iterate through the array check with every other element O(n^2)

    // Better using hashing
    pair<int, int> res;
    res = twoSum(v, k);
    cout << res.first << " " << res.second << endl;

    // Optimal if only need to check and not return the index
    // Using two pointers
    // Distorts the input array or take extra space
    cout << twoSum2(v, k);
}