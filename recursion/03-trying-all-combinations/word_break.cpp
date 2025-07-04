#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string &s, vector<string> &dict, string &temp)
{
    if (s == temp)
    {
        return true;
    }
    if (s.substr(0, temp.size()) != temp) // or s.find(temp) != 0
    {
        return false;
    }
    for (int i = 0; i < dict.size(); i++)
    {
        temp += dict[i];
        if (wordBreak(s, dict, temp))
        {
            return true;
        };
        // Erase from given index till end
        temp.erase(temp.size() - dict[i].size());
    }
    return false;
    // TC: O(m^n) -> m = dict length, n = length of s
    // SC: O(n) Rec stack space
}

int main()
{
    string s = "applepenapple";
    vector<string> dict = {"apple", "pen"};
    string temp = "";

    cout << wordBreak(s, dict, temp);
}