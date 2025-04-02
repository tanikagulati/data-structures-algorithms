#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &v)
{
    int dip = -1;
    int n = v.size();

    // Find break index
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] < v[i + 1])
        {
            dip = i;
            break;
        }
    }

    // No dip -> i/p is last perm -> res will be first perm
    if (dip == -1)
    {
        reverse(v.begin(), v.end());
        return;
    }

    // Swap break index with next greater element after break index
    for (int i = n - 1; i > dip; i--)
    {
        if (v[i] > v[dip])
        {
            swap(v[i], v[dip]);
            break;
        }
    }

    // Sort the array after break index to achieve next permutation
    reverse(v.begin() + dip + 1, v.end());

    // TC: O(3n)
    // SC: O(1)
}

int main()
{
    vector<int> v = {2, 1, 5, 4, 3, 0, 0};
    nextPermutation(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
}