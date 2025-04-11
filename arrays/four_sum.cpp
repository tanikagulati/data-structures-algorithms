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

void fourSumBrute(vector<int> &v, int target)
{
    int n = v.size();
    set<vector<int>> st;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    // For bigger integers, adding at once might exceed intmax & cause overflow
                    sum = v[i] + v[j];
                    sum += v[k];
                    sum += v[l];
                    if (sum == target)
                    {
                        vector<int> temp = {v[i], v[j], v[k], v[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> res(st.begin(), st.end());
    printResult(res);

    // TC: O(n^4)
    // SC: O(2m) -> m = no of quads
}

void fourSumBetter(vector<int> &v, int target)
{
    int n = v.size();
    set<vector<int>> st;
    long long sum = 0;
    long long fourth;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashSet;
            for (int k = j + 1; k < n; k++)
            {
                sum = v[i] + v[j];
                sum += v[k];
                fourth = (long long)target - sum;
                if (hashSet.find(fourth) != hashSet.end())
                {
                    vector<int> temp = {v[i], v[j], v[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(v[k]);
            }
        }
    }

    vector<vector<int>> res(st.begin(), st.end());
    printResult(res);

    // TC: O(n^3 * logn)
    // SC: O(n) for hashset + O(2m) -> m = no of quads
}

void fourSumOptimal(vector<int> v, int target)
{
    int n = v.size();
    long long sum = 0;
    vector<vector<int>> res;

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && v[i] == v[i - 1]) // Skip duplicate ith element
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && v[j] == v[j - 1]) // Skip duplicate jth element
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                sum = v[i] + v[j];
                sum += v[k];
                sum += v[l];
                if (sum == target)
                {
                    res.push_back({v[i], v[j], v[k], v[l]});
                    k++;
                    l--;
                    while (k < l && v[k] == v[k - 1])
                        k++;
                    while (k < l && v[l] == v[l + 1])
                        l--;
                }
                else if (sum < target)
                {
                    k++;
                    while (k < l && v[k] == v[k - 1])
                        k++;
                }
                else if (sum > target)
                {
                    l--;
                    while (k < l && v[l] == v[l + 1])
                        l--;
                }
            }
        }
    }

    printResult(res);

    // TC: O(n^3)
    // SC: O(m) -> m = no of squads
}

int main()
{
    vector<int> v = {1, 4, 6, 0, -1, 8, 2, -3, -1, -6, -2, 7, -1, -2};

    int k = -2;

    fourSumBrute(v, k);

    fourSumBetter(v, k);

    fourSumOptimal(v, k);
}