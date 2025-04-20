#include <bits/stdc++.h>
using namespace std;

int findSimgleElement(vector<int> &v)
{
    int n = v.size();

    if (n == 1)
        return v[0];
    if (v[0] != v[1])
        return v[0];
    if (v[n - 1] != v[n - 2])
        return v[n - 1];

    int low = 1, high = n - 2, mid;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);

        if (v[mid] != v[mid - 1] && v[mid] != v[mid + 1])
            return v[mid];

        // we are on left half
        if ((mid % 2 == 0 && v[mid] == v[mid + 1]) || (mid % 2 == 1 && v[mid] == v[mid - 1]))
        {
            low = mid + 1;
        }

        // We are on right half
        else
        {
            high = mid - 1;
        }
    }

    return -1;

    // TC: O(logn)
    // SC: O(1)
}

int main()
{
    vector<int> v = {1, 1, 2, 2, 3, 4, 4};

    // Observation: Even odd indices
    cout << findSimgleElement(v) << endl;
}