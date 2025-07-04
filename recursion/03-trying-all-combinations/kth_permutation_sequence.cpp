#include <bits/stdc++.h>
using namespace std;

// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, return the kth permutation sequence.

// Revisit

string kthPermutationSequence(int n, int k)
{
    string temp = "";
    k = k - 1;
    int fact = 1;
    vector<int> nums;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        nums.push_back(i);
    }
    nums.push_back(n);

    while (true)
    {
        temp = temp + to_string(nums[k / fact]);
        nums.erase(nums.begin() + k / fact);
        if (nums.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / nums.size();
    }
    return temp;
    // TC: O(n^2)
    // SC: O(n)
}

int main()
{
    int n = 3, k = 3;

    // Brute: Generate all permutations and return kth (TC: n! * n)

    // Optimal:
    cout << kthPermutationSequence(n, k) << endl;
}