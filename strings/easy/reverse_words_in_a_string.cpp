#include <bits/stdc++.h>
using namespace std;

// Remove leading, trailing or any extra spaces in between
// Reverse the order of words in the string

string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    int n = s.size();
    int left = 0;
    int right = 0;
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            break;
        while (i < n && s[i] != ' ')
        {
            s[right++] = s[i++];
        }
        reverse(s.begin() + left, s.begin() + right);
        s[right++] = ' ';
        left = right;
        i++;
    }
    s.resize(right - 1);
    return s;
    // TC: O(n)
    // SC: O(1)
}

void trimSpaces(string &s)
{
    int n = s.length();
    int i = 0, j = 0;

    // Skip leading spaces
    while (i < n && s[i] == ' ')
        i++;

    while (i < n)
    {
        if (s[i] != ' ')
        {
            s[j++] = s[i++];
        }
        else
        {
            // Reduce multiple spaces to 1
            s[j++] = ' ';
            while (i < n && s[i] == ' ')
                i++;
        }
    }
    // Remove trailing space, if any
    if (j > 0 && s[j - 1] == ' ')
        j--;
    s.resize(j);
}

string reverseWords2(string s)
{
    // Remove all unwanted spaces
    trimSpaces(s);
    // Reverse
    reverse(s.begin(), s.end());

    // Reverse words
    int n = s.length();
    int start = 0;
    for (int end = 0; end <= n; end++)
    {
        if (end == n || s[end] == ' ')
        {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }
    return s;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    // Brute:
    // Extract words and store them. Then, reverse and join.
    // TC: O(n) SC: O(n)

    // Optimal1:
    cout << reverseWords("  hello world ") << endl;

    // Optimal2:
    cout << reverseWords2("  the  sky is    blue ") << endl;
}