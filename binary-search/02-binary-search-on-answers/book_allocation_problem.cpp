#include <bits/stdc++.h>
using namespace std;

// Make sure maximum pages alloted to a student is minimum
// Allotment should be contiguous

int findMax(vector<int> &pages)
{
    int n = pages.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, pages[i]);
    }
    return maxi;
}

int findStudentCnt(vector<int> &pages, int maxPagesAllowed)
{
    int n = pages.size();
    long long assignedPages = 0;
    int studentCnt = 1;

    for (int i = 0; i < n; i++)
    {
        if (assignedPages + pages[i] <= maxPagesAllowed)
        {
            assignedPages += pages[i];
        }
        else
        {
            studentCnt++;
            assignedPages = pages[i];
        }
    }

    return studentCnt;
}

int bookAllocationBrute(vector<int> &pages, int k)
{
    int n = pages.size();

    // Not possible to allocate books to all students
    if (n < k)
        return -1;

    // Possible result range
    int maxi = *max_element(pages.begin(), pages.end());
    long long sum = accumulate(pages.begin(), pages.end(), 0);

    for (int i = maxi; i < sum; i++)
    {
        // Books will be allocated to how many students if i is the max no of pages allowed to one
        int studentCnt = findStudentCnt(pages, i);
        // First number in the range (i.e, min) which lets allotment to <= k students will be the ans
        // Less than is imp (consider case {15, 10, 19, 10, 5, 18, 7}, k=5)
        if (studentCnt <= k)
        {
            return i;
        }
    }

    return -1;
    // TC: O((sum-max+1) * n)
    // SC: O(1)
}

int bookAllocationOptimal(vector<int> &pages, int k)
{
    int n = pages.size();
    if (n < k)
        return -1;

    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);
    int mid;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        int studentCnt = findStudentCnt(pages, mid);
        if (studentCnt > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
    // TC: O(log(sum-max+1) * n)
    // SC: O(1)
}

int main()
{
    vector<int> pages = {15, 10, 19, 10, 5, 18, 7};
    int k = 5;

    // LS
    cout << bookAllocationBrute(pages, k) << endl;

    // BS
    cout << bookAllocationOptimal(pages, k) << endl;
}