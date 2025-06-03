#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num)
{
    int n = num.size();
    while (n > 0)
    {
        if ((num[n - 1] - '0') % 2 != 0)
        {
            return num.substr(0, n);
        }
        n--;
    }
    return "";
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    cout << largestOddNumber("245874") << endl;
}