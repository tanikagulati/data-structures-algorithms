#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/fruit-into-baskets/description/

int fruitIntoBasketsBrute(vector<int> &nums)
{
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i; j < n; j++)
        {
            st.insert(nums[j]);
            if (st.size() <= 2)
                maxLen = max(maxLen, j - i + 1);
            else
                break;
        }
    }
    return maxLen;
    // TC: O(n^2)
    // SC: O(1)
}

int fruitIntoBasketsBetter(vector<int> &nums)
{
    int n = nums.size();
    int maxLen = 0;
    int l = 0, r = 0;
    map<int, int> mp; // Number frequency map
    while (r < n)
    {
        mp[nums[r]]++;
        while (mp.size() > 2)
        {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
    // TC: O(2n)
    // SC: O(1)
}

int fruitIntoBasketsOptimal(vector<int> &nums)
{
    int n = nums.size();
    int maxLen = 0;
    int l = 0, r = 0;
    map<int, int> mp; // Number frequency map
    while (r < n)
    {
        mp[nums[r]]++;
        if (mp.size() > 2)
        {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);
            l++;
        }
        if (mp.size() <= 2)
            maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
    // TC: O(n)
    // SC: O(1)
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 1, 2, 3};

    cout << fruitIntoBasketsBrute(nums) << endl;

    cout << fruitIntoBasketsBetter(nums) << endl;

    cout << fruitIntoBasketsOptimal(nums) << endl;
}