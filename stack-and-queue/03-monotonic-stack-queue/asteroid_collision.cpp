#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/asteroid-collision/description/

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> st; // Vector used as stack to avoid reversing it later for final result
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (asteroids[i] > 0)
        {
            st.push_back(asteroids[i]);
        }
        else
        {
            while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i]))
            {
                st.pop_back();
            }
            if (!st.empty() && abs(asteroids[i]) == st.back())
            {
                st.pop_back();
            }
            else if (st.empty() || st.back() < 0)
            {
                st.push_back(asteroids[i]);
            }
        }
    }
    return st;
    // TC: O(2n)
    // SC: O(n)
}

int main()
{
    vector<int> asteroids = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
    vector<int> res = asteroidCollision(asteroids);

    for (auto i : res)
    {
        cout << i << " ";
    }
}