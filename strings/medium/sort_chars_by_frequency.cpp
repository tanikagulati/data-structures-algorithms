#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<char, int> p1, pair<char, int> p2)
{
    return p1.second > p2.second;
}

string sortCharactersByFrequency(string s)
{
    // Store the frequency of each character in map -> O(n)
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    // To sort based on frequency, use vector (since map doesn't support sorting by value)
    vector<pair<char, int>> frequency(mp.begin(), mp.end()); // O(k)
    sort(frequency.begin(), frequency.end(), cmp);           // O(k logk)

    // Form string -> O(n)
    string res = "";
    for (auto i : frequency)
    {
        for (int j = 0; j < i.second; j++)
        {
            res.push_back(i.first);
        }
    }
    return res;
    // TC: O(2n) -> since k is limited to ascii 256
    // SC: O(3n)
}

int main()
{
    cout << sortCharactersByFrequency("aaabbbbccdee") << endl;

    // Other ways:
    // PQ
    // Bucket sort
}