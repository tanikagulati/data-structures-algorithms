#include <bits/stdc++.h>
using namespace std;

int kthElementOfTwoSortedArrays(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n2 < n1)
    {
        return kthElementOfTwoSortedArrays(nums2, nums1, k);
    }
    int n = n1 + n2;
    int low = max(k - n2, 0), high = min(k, n1);
    int mid1, mid2;
    int elementsInLeft = k;
    int l1, l2, r1, r2;

    while (low <= high)
    {
        l1 = INT_MIN, l2 = INT_MIN;
        r1 = INT_MAX, r2 = INT_MAX;

        mid1 = low + ((high - low) / 2);
        mid2 = elementsInLeft - mid1;

        if (mid1 > 0)
            l1 = nums1[mid1 - 1];
        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 > 0)
            l2 = nums2[mid2 - 1];
        if (mid2 < n2)
            r2 = nums2[mid2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else if (l2 > r1)
        {
            low = mid1 + 1;
        }
    }
    return -1;
    // TC: O(log(min(n1,n2)))
    // SC: O(1)
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << kthElementOfTwoSortedArrays(a, b, k) << endl;
}