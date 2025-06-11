#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int res = 0;
    int n = s.size();
    // Can also use switch case instead of map
    map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && mp[s[i]] < mp[s[i + 1]])
        {
            res -= mp[s[i]];
        }
        else
        {
            res += mp[s[i]];
        }
    }
    return res;
    // TC: O(n)
    // SC: O(1)
}

string intToRoman(int num)
{
    int normal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string res;
    for (int i = 0; i < 13; i++)
    {
        while (num >= normal[i])
        {
            res.append(roman[i]);
            num -= normal[i];
        }
    }
    return res;
    // TC: O(1)
    // SC: O(1)
}

int main()
{
    cout << romanToInt("MCMXCIV") << endl;

    cout << intToRoman(1994) << endl;
}