#include <bits/stdc++.h>
using namespace std;

// Elements that appear > n/3 times

int main()
{
    vector<int> v = {3, 1, 3, 3, 1, 5, 1, 1, 3};
    int n = v.size();

    // Brute: Iterate and check for each element
    // Better: Hashing

    // Optimal: Moore's voting algo intuition
    // Observation: At most 2 elements can appear > n/3 times
    int n1, n2;
    int count1 = 0, count2 = 0;

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && v[i] != n2)
        {
            n1 = v[i];
            count1 = 1;
        }
        else if (count2 == 0 && v[i] != n1)
        {
            n2 = v[i];
            count2 = 1;
        }
        else if (v[i] == n1)
        {
            count1++;
        }
        else if (v[i] == n2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0, count2 = 0;

    // Verify if the two potential elements qualify
    for (int i = 0; i < n; i++)
    {
        if (v[i] == n1)
            count1++;
        else if (v[i] == n2)
            count2++;
    }

    if (count1 > n / 3)
        res.push_back(n1);
    if (count2 > n / 3)
        res.push_back(n2);

    for (auto i : res)
        cout << i << " ";

    // TC: O(n)
    // SC: O(1)
}