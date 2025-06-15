#include <bits/stdc++.h>
using namespace std;

// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
// Given a string s, return the sum of beauty of all of its substrings.
// s consists of only lowercase English letters.

int beautySum(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // Can also use array over map for better complexity (just ignore 0 freqs)
        unordered_map<char, int> mp;
        for (int j = i; j < s.size(); j++)
        {
            mp[s[j]]++;
            int maxFreq = INT_MIN;
            int minFreq = INT_MAX;
            for (auto i : mp)
            {
                maxFreq = max(maxFreq, i.second);
                minFreq = min(minFreq, i.second);
            }
            sum += maxFreq - minFreq;
        }
    }
    return sum;
    // TC: O(n^2 * m) ~ O(n^2) -> m = no of unique chars in the string (26 max)
    // SC: O(m) ~ O(1)
}

int main()
{
    cout << beautySum("aabcbaa") << endl;
}