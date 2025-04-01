#include <bits/stdc++.h>
using namespace std;

void rearrangeByAlternativeSignsBrute(vector<int> v)
{
    int n = v.size();

    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {
        if (v[i] >= 0)
        {
            pos.push_back(v[i]);
        }
        else
        {
            neg.push_back(v[i]);
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        v[2 * i] = pos[i];
        v[(2 * i) + 1] = neg[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    // TC: O(n + n/2)
    // SC: O(n)
}

void rearrangeByAlternativeSignsOptimal(vector<int> &v)
{
    int n = v.size();
    vector<int> res(n);

    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < n; i++)
    {
        if (v[i] >= 0)
        {
            res[posIndex] = v[i];
            posIndex += 2;
        }
        else
        {
            res[negIndex] = v[i];
            negIndex += 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    // TC: O(n)
    // SC: O(n)
}

void rearrange(vector<int> v)
{
    int n = v.size();

    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {
        if (v[i] >= 0)
        {
            pos.push_back(v[i]);
        }
        else
        {
            neg.push_back(v[i]);
        }
    }

    int mini = min(pos.size(), neg.size());

    for (int i = 0; i < mini; i++)
    {
        v[2 * i] = pos[i];
        v[(2 * i) + 1] = neg[i];
    }

    if (pos.size() > neg.size())
    {
        int index = 2 * neg.size();
        for (int i = mini; i < pos.size(); i++)
        {
            v[index] = pos[i];
            index++;
        }
    }
    else
    {
        int index = 2 * pos.size();
        for (int i = mini; i < neg.size(); i++)
        {
            v[index] = neg[i];
            index++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    // TC: O(2n)
    // SC: O(n)
}

int main()
{
    vector<int> v = {3, 1, -2, 5, 2, -4};
    // Case 1: Equal no of negatives and positives
    rearrangeByAlternativeSignsBrute(v);

    // Slightly better
    rearrangeByAlternativeSignsOptimal(v);

    // Case 2: If non equal no of positives and negatives
    rearrange(v);
}