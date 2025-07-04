#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string &s, vector<string> &dict, string temp)
{
    if (s == temp)
    {
        return true;
    }
    if (s.find(temp) != 0 || temp.size() > s.size())
    {
        return false;
    }
    for (int i = 0; i < dict.size(); i++)
    {
        if (wordBreak(s, dict, temp + dict[i]))
        {
            return true;
        };
    }
    return false;
}

int main()
{
    string s = "applepenapple";
    vector<string> dict = {"apple", "pen"};
    string temp = "";

    cout << wordBreak(s, dict, temp);
}