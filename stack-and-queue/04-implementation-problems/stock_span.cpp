#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/online-stock-span/description/

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int ind;

    StockSpanner()
    {
        ind = -1;
        while (!st.empty())
            st.pop();
    }

    int next(int price)
    {
        // pge concept
        ind++;
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        int span = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        return span;
    }
    // TC: O(2n)
    // SC: O(n)
};

int main()
{
    StockSpanner ss;
    cout << ss.next(100) << endl;
    cout << ss.next(80) << endl;
    cout << ss.next(60) << endl;
    cout << ss.next(70) << endl;
    cout << ss.next(60) << endl;
    cout << ss.next(75) << endl;
    cout << ss.next(85) << endl;
}