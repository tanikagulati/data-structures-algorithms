#include <bits/stdc++.h>
using namespace std;

// Find how many times array has been rotated

int rotation(vector<int> &v)
{
    int n = v.size();
    int mini = 0;

    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);

        // Full sorted
        if (v[low] <= v[high])
        {
            if (v[low] < v[mini])
            {
                return low;
                break;
            }
        }
        // Left sorted
        if (v[low] <= v[mid])
        {
            if (v[low] < v[mini])
            {
                mini = low;
            }
            low = mid + 1;
        }
        // Right sorted
        else
        {
            if (v[mid] < v[mini])
            {
                mini = mid;
            }
            high = mid - 1;
        }
    }

    return mini;
}

int main()
{
    vector<int> v = {7, 8, 1, 2, 3, 4, 5};

    cout << rotation(v) << endl;
}