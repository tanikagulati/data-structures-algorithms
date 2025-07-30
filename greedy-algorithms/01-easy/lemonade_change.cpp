#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lemonade-change/description/

bool lemonadeChange(vector<int> &bills)
{
    int n = bills.size();
    int five = 0, ten = 0; // Counter of 20 has no significance
    for (int i = 0; i < n; i++)
    {
        if (bills[i] == 5)
            five++;
        else if (bills[i] == 10)
        {
            ten++;
            if (five)
                five--;
            else
                return false;
        }
        else if (bills[i] == 20)
        {
            if (ten && five)
                ten--, five--;
            else if (five >= 3)
                five -= 3;
            else
                return false;
        }
    }
    return true;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    vector<int> bills = {5, 5, 5, 10, 20};

    cout << lemonadeChange(bills) << endl;
}

// How is this greedy?
// We need to prioritize (10+5) as change for 20 instead of (5+5+5) in order to save 5(lower denomination) for future use.

// Consider we have: five = 3, ten = 1
// Now for a bill of 20, let's say we return 3 fives, and next bill is 10, we can't sell to them, instead if 10+5 was returned to the previous customer, we could sell it.