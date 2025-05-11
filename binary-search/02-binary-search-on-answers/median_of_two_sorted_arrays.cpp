#include <bits/stdc++.h>
using namespace std;

double medianOf2SortedArraysBrute(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<int> merged;
    int x = 0, y = 0;

    while (x < n1 && y < n2)
    {
        if (nums1[x] <= nums2[y])
        {
            merged.push_back(nums1[x]);
            x++;
        }
        else
        {
            merged.push_back(nums2[y]);
            y++;
        }
    }
    while (x < n1)
    {
        merged.push_back(nums1[x]);
        x++;
    }
    while (y < n2)
    {
        merged.push_back(nums2[y]);
        y++;
    }

    int mid = (n1 + n2) / 2;

    if ((n1 + n2) % 2 == 0)
    {
        return double(merged[mid] + merged[mid - 1]) / 2.0;
    }
    else
    {
        return merged[mid];
    }
    // TC: O(n1+n2)
    // SC: O(n1+n2)
}

double medianOf2SortedArraysBetter(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;

    int x = 0, y = 0;
    int count = 0;
    int ind1 = (n / 2) - 1, ind2 = n / 2; // for median
    int ind1Ele = INT_MIN, ind2Ele = INT_MIN;

    while (x < n1 && y < n2)
    {
        if (nums1[x] <= nums2[y])
        {
            if (count == ind1)
                ind1Ele = nums1[x];
            if (count == ind2)
                ind2Ele = nums1[x];
            x++;
            count++;
        }
        else
        {
            if (count == ind1)
                ind1Ele = nums2[y];
            if (count == ind2)
                ind2Ele = nums2[y];
            y++;
            count++;
        }
    }
    while (x < n1)
    {
        if (count == ind1)
            ind1Ele = nums1[x];
        if (count == ind2)
            ind2Ele = nums1[x];
        x++;
        count++;
    }
    while (y < n2)
    {
        if (count == ind1)
            ind1Ele = nums2[y];
        if (count == ind2)
            ind2Ele = nums2[y];
        y++;
        count++;
    }

    if (n % 2 == 0)
        return double(ind2Ele + ind1Ele) / 2.0;

    return ind2Ele;
    // TC: O(n1+n2) -> can be optimized to ~half by breaking out if both ind1Ele and ind2Ele is found
    // SC: O(1)
}

double medianOf2SortedArraysOptimal(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n2 < n1)
    {
        // Perform BS on smaller array for better complexity
        return medianOf2SortedArraysOptimal(nums2, nums1);
    }
    int n = n1 + n2;
    int low = 0, high = n1;
    int mid1, mid2;
    int elementsInLeft = (n + 1) / 2;
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
            if (n % 2 == 0)
                return double(max(l1, l2) + min(r1, r2)) / 2.0;
            else
                return double(max(l1, l2));
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
    vector<int> nums1 = {2, 5, 6, 8, 9, 10, 12, 17, 19};
    vector<int> nums2 = {14, 17, 28};

    cout << medianOf2SortedArraysBrute(nums1, nums2) << endl;

    cout << medianOf2SortedArraysBetter(nums1, nums2) << endl;

    cout << medianOf2SortedArraysOptimal(nums1, nums2) << endl;
}