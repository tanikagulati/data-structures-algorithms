#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &v, int k)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] == k)
        {
            return true;
        }
    }
    return false;
}

int longestConsecutiveSubseqBrute(vector<int> &v)
{
    int n = v.size();
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int element = v[i];
        int count = 1;
        while (linearSearch(v, element + 1) == true)
        {
            count++;
            element++;
        }
        if (count > longest)
        {
            longest = count;
        }
    }
    return longest;

    // TC: O(n^2)
    // SC: O(1)

    // Linear search for next consec num until it exists
    // 5 4 3 2 1
    // TC per element: 5 -> n, 4 -> 2n, 3 -> 3n, 2 -> 4n, 1 - 5n = 15n = O(3n^2)
}

int longestConsecutiveSubseqBetter(vector<int> &v)
{
    int n = v.size();
    sort(v.begin(), v.end());

    int longest = 1;
    int count = 0;
    int prev = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (v[i] - prev == 1)
        {
            count++;
            prev = v[i];
            longest = max(longest, count);
        }
        else if (v[i] != prev)
        {
            prev = v[i];
            count = 1;
        }
    }
    return longest;
    // TC: O(nlogn + n)
    // SC: O(1)
}

int longestConsecutiveSubseqOptimal(vector<int> &v)
{
    unordered_set<int> st;
    for (auto i : v)
    {
        st.insert(i);
    }

    int count = 1;
    int longest = 1;

    for (auto i : st)
    {
        if (st.find(i - 1) == st.end()) // Potential start of ans sequence
        {
            count = 1;
            int t = i;
            while (st.find(t + 1) != st.end())
            {
                count++;
                t++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
    // TC: O(3n) Ignoring worst case of unordered set
    // SC: O(n)
}

int main()
{
    vector<int> v = {4, 1, 7, 5, 2, 8, 6, 1, 5, 2, 11, 12, 13, 14, 15, 16, 17};

    cout << longestConsecutiveSubseqBrute(v) << endl;

    // Sort and iterate
    cout << longestConsecutiveSubseqBetter(v) << endl;

    cout << longestConsecutiveSubseqOptimal(v) << endl;
}
