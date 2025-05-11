#include <bits/stdc++.h>
using namespace std;

void printResult(vector<vector<int>> &res)
{
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> threeSumBrute(vector<int> &v)
{
    int n = v.size();

    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (v[i] + v[j] + v[k] == 0)
                {
                    vector<int> temp = {v[i], v[j], v[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> res(st.begin(), st.end());
    return res;

    // TC: O(n^3)
    // SC: O(2* no of triplets)
}

vector<vector<int>> threeSumBetter(vector<int> &v)
{
    // Hash instead of third loop
    int n = v.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        unordered_set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(v[i] + v[j]);
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {v[i], v[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(v[j]);
        }
    }

    vector<vector<int>> res(st.begin(), st.end());
    return res;

    // TC: O(n^2)
    // SC: O(n) for hash and O(2* no of triplets) for st and res
}

vector<vector<int>> threeSumOptimal(vector<int> v)
{
    int n = v.size();
    vector<vector<int>> res;

    sort(v.begin(), v.end());

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && v[i - 1] == v[i])
            continue;

        int j = i + 1, k = n - 1;

        while (j < k)
        {
            sum = v[i] + v[j] + v[k];
            if (sum == 0)
            {
                res.push_back({v[i], v[j], v[k]});
                j++;
                k--;
                while (j < k && v[j - 1] == v[j])
                    j++;
                while (j < k && v[k + 1] == v[k])
                    k--;
            }
            else if (sum > 0)
            {
                k--;
                while (j < k && v[k + 1] == v[k])
                    k--;
            }
            else if (sum < 0)
            {
                j++;
                while (j < k && v[j - 1] == v[j])
                    j++;
            }
        }
    }
    return res;

    // TC: O(nlogn + n^2)
    // SC: O(no of triplets)
}

int main()
{
    vector<int> v = {1, -1, 3, 2, 1, -2};

    vector<vector<int>> res;

    res = threeSumBrute(v);
    printResult(res);

    res = threeSumBetter(v);
    printResult(res);

    res = threeSumOptimal(v);
    printResult(res);
}