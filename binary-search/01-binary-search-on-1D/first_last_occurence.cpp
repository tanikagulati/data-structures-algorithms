#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &v, int target)
{
    int n = v.size();
    int low = 0, high = n - 1, mid;
    int first = -1;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (v[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (v[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return first;
}

int lastOccurence(vector<int> &v, int target)
{
    int n = v.size();
    int low = 0, high = n - 1, mid;
    int last = -1;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (v[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (v[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return last;
}

void firstLastOccurence(vector<int> &v, int target)
{
    int n = v.size();
    int low = 0, high = n - 1, mid;

    int first = firstOccurence(v, target);

    if (first == -1)
    {
        // If first is not present, last will also not be there
        cout << -1 << " " << -1;
        return;
    }

    int last = lastOccurence(v, target);

    cout << first << " " << last << endl;

    // TC: O(2logn), if target is not present -> O(logn)
    // SC: O(1)
}

int countOccurences(vector<int> &v, int target)
{
    int first = firstOccurence(v, target);

    if (first == -1)
        return 0;

    int last = lastOccurence(v, target);
    return last - first + 1;
}

int main()
{
    vector<int> v = {1, 3, 3, 6, 6, 6, 7, 9, 11};
    int target = 2;

    firstLastOccurence(v, target);
    // can also be solved by lower and upper bound
    // first = lowerBound, last = upperBound - 1 (but handle the cases where target not present)

    countOccurences(v, target);
}