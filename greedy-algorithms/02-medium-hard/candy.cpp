#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/candy/description/

int candyBrute(vector<int> &ratings)
{
    int n = ratings.size();
    int left[n], right[n];
    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;
    }
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            right[i] = right[i + 1] + 1;
        else
            right[i] = 1;
    }

    // Sum of max of left and right
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += max(left[i], right[i]);
    return sum;
    // TC: O(3n)
    // SC: O(2n)
}

int candyBetter(vector<int> &ratings)
{
    // Eliminate storing from right
    int n = ratings.size();
    int left[n];
    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;
    }
    int sum = max(1, left[n - 1]);
    int curr = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            curr++;
        else
            curr = 1;
        sum += max(curr, left[i]);
    }
    return sum;
    // TC: O(2n)
    // SC: O(n)
}

int candyOptimal(vector<int> &ratings)
{
    // Slope approach
    int n = ratings.size();
    int i = 1;
    int down;
    int peak = 1;
    int sum = 1;
    while (i < n)
    {
        while (i < n && ratings[i] == ratings[i - 1])
        {
            sum += 1;
            i++;
        }
        peak = 1;
        while (i < n && ratings[i] > ratings[i - 1])
        {
            peak++;
            sum += peak;
            i++;
        }
        down = 1;
        while (i < n && ratings[i] < ratings[i - 1])
        {
            sum += down;
            down++;
            i++;
        }
        if (down > peak)
        {
            sum += down - peak;
        }
    }
    return sum;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    vector<int> ratings = {1, 2, 2};

    cout << candyBrute(ratings) << endl;

    cout << candyBetter(ratings) << endl;

    cout << candyOptimal(ratings) << endl;
}