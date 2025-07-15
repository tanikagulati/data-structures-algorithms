#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-k-digits/description/

string removeKDigits(string &num, int k)
{
    int n = num.size();
    if (k == n)
        return "0";
    string st;
    int i = 0;
    while (i < n)
    {
        if (st.empty())
            st.push_back(num[i]);
        else
        {
            while (!st.empty() && k > 0 && st.back() > num[i])
            {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        i++;
    }
    // If k has not vanished, remove k elements from last
    while (k > 0)
    {
        st.pop_back();
        k--;
    }
    // Handle leading zeros
    i = 0;
    while (i < n && st[i] == '0')
    {
        i++;
    }
    st = st.substr(i);

    return st.empty() ? "0" : st;
    // TC: O(3n + k)
    // SC: O(n)
}

int main()
{
    string num = "1432219";
    int k = 3;

    cout << removeKDigits(num, k);
}