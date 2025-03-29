#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &v)
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
    sort012(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}