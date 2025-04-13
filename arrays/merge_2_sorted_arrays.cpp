#include <bits/stdc++.h>
using namespace std;

void printResult(vector<int> &res)
{
    for (auto i : res)
    {
        cout << i << " ";
    }
}

void merge2SortedArraysBrute(vector<int> v1, vector<int> v2)
{
    // Using extra array
    int n1 = v1.size();
    int n2 = v2.size();

    vector<int> res;
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            res.push_back(v1[i]);
            i++;
        }
        else
        {
            res.push_back(v2[j]);
            j++;
        }
    }

    while (i < n1)
    {
        res.push_back(v1[i]);
        i++;
    }
    while (j < n2)
    {
        res.push_back(v2[j]);
        j++;
    }

    printResult(res);
    cout << endl;

    // TC: O(n+m)
    // SC: O(m+n)
}

void merge2SortedArraysOptimal1(vector<int> v1, vector<int> v2)
{
    // Inplace
    int n1 = v1.size();
    int n2 = v2.size();

    int i = n1 - 1;
    int j = 0;

    while (i >= 0 && j < n2)
    {
        if (v1[i] > v2[j])
        {
            swap(v1[i], v2[j]);
            i--, j++;
        }
        else
        {
            break;
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    printResult(v1);
    printResult(v2);
    cout << endl;

    // TC: O(min(n1,n2) + n1logn1 + n2logn2)
    // SC: O(1)
}

void swapIfGreater(vector<int> &v1, vector<int> &v2, int ind1, int ind2)
{
    if (v1[ind1] > v2[ind2])
    {
        swap(v1[ind1], v2[ind2]);
    }
}

void merge2SortedArraysOptimal2(vector<int> v1, vector<int> v2)
{
    // Inplace
    // Using gap method from shell sort technique

    int n1 = v1.size();
    int n2 = v2.size();
    int totalLen = n1 + n2;

    int gap = (totalLen / 2) + (totalLen % 2); // ceil value of half of sum of lengths

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < totalLen)
        {
            // left in v1 and right in v2
            if (left < n1 && right >= n1)
            {
                swapIfGreater(v1, v2, left, right - n1);
            }
            // both in v2
            else if (left >= n1)
            {
                swapIfGreater(v2, v2, left - n1, right - n1);
            }
            // both in v1
            else
            {
                swapIfGreater(v1, v1, left, right);
            }
            left++, right++;
        }

        if (gap == 1)
            break;

        gap = (gap / 2) + (gap % 2);
    }

    printResult(v1);
    printResult(v2);

    // TC: O(log(n1+n2)) * O(n1+n2)
    // SC: O(1)
}

int main()
{
    vector<int> v1 = {1, 4};
    vector<int> v2 = {1, 5, 6, 7, 9};

    merge2SortedArraysBrute(v1, v2);

    merge2SortedArraysOptimal1(v1, v2);

    // Not that important
    merge2SortedArraysOptimal2(v1, v2);
}