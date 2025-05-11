#include <bits/stdc++.h>
using namespace std;

void sort012Better(vector<int> &v)
{
    int n = v.size();
    int hash[3] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[v[i]]++;
    }
    int i = 0;
    while (hash[0]--)
    {
        v[i] = 0;
        i++;
    }
    while (hash[1]--)
    {
        v[i] = 1;
        i++;
    }
    while (hash[2]--)
    {
        v[i] = 2;
        i++;
    }
    // TC: O(2n)
    // SC: O(1)
}

void sort012Optimal(vector<int> &v)
{
    int n = v.size();
    int l = 0, m = 0, h = n - 1;
    while (m <= h)
    {
        if (v[m] == 0)
        {
            swap(v[l], v[m]);
            l++;
            m++;
        }
        else if (v[m] == 1)
        {
            m++;
        }
        else if (v[m] == 2)
        {
            swap(v[h], v[m]);
            h--;
        }
    }
    // TC: O(n)
    // SC: O(1)
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

    // Brute -> Sorting algo

    // Better
    sort012Better(v);

    // Optimal: Dutch national flag algorithm
    sort012Optimal(v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}