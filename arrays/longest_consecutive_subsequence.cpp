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

int main()
{
    vector<int> v = {1, 1, 4, 4, 2, 4};

    cout << longestConsecutiveSubseqBrute(v) << endl;
}
