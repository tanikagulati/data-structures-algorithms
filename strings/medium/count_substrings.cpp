#include <bits/stdc++.h>
using namespace std;

// Given a binary string S. The task is to count the number of substrings that starts and end with 1.
// Note: The starting and the ending 1s should be different.

int countSubstrings(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            cnt++;
        }
    }
    if (cnt == 0 || cnt == 1)
        return 0;
    // Sum of n natural nos = (n*(n+1))/2
    return ((cnt - 1) * cnt) / 2;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    cout << countSubstrings("101") << endl;
}

// No of 1s (n) -> substring count
// 1->0
// 2->1
// 3->3
// 4->6
// 5->10
// sum of n-1 natural numbers