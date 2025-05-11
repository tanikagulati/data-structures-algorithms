#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &v)
{
    int n = v.size();
    int element = v[0];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            element = v[i];
            count = 1;
        }
        else if (v[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    // Current value at 'element' after the above iteration may/may not be the majority element
    // The below verification can be skipped, given there always exist a majority element

    // Verify if value at element is majority
    int totalCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == element)
        {
            totalCount++;
        }
    }
    if (totalCount > n / 2)
    {
        return element;
    }
    return -1;
    // TC: O(2n)
    // SC: O(n)
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // Brute: Iterate array for each element
    // TC: O(n^2)
    // SC: O(1)

    // Better: Hashing
    // TC: O(nlogn + n) -> map / O(2n) -> unordered map
    // SC: O(n)

    // Optimal: Moore's voting algorithm
    cout << majorityElement(v) << endl;
}