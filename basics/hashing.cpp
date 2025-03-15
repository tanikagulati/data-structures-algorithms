#include <bits/stdc++.h>
using namespace std;

void arrayHashing()
{
    int n;
    cin >> n;
    int arr[n];

    // Hash array -> Size determined by max possible value in input array
    // Size limit for array initialization inside main -> 10^5 (globally -> 10^7)

    int hash[100000] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // Pre-compute (store frequency of each element)
        hash[arr[i]]++;
    }

    int q;
    cin >> q;
    int queries[q];
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }

    // Fetch
    for (int i = 0; i < q; i++)
    {
        cout << hash[queries[i]] << endl;
    }
}

void characterHashing()
{
    string s;
    cin >> s;

    int hash[26] = {0}; // 256 size if input string can have any character

    // Pre-compute
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 97]++; // ASCII
    }

    int q;
    cin >> q;
    char queries[q];
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }

    for (int i = 0; i < q; i++)
    {
        cout << hash[queries[i] - 97] << endl;
    }
}

void usingMap()
{
    // Because array hash can't be used for bigger numbers, say 10^9 or more
    map<int, int> hash;
    map<char, int> hash2;
    // Can use any data type as key
    // value? it's frequency in this scenario, so int

    // For all best, avg, worst cases, Store/Fetch is O(log n) due to sorted order, so unordered map for hashing
}

void usingUnorderedMap()
{
    // For best and avg, Store/Fetch -> O(1), for rare worst (due to collision) -> O(n)
    unordered_map<int, int> hash;
    // Data types are limited to int, char, float, etc.

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // Pre-compute
        hash[arr[i]]++;
    }

    int q;
    cin >> q;
    int queries[q];
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }

    // Iterate
    for (auto i : hash)
    {
        cout << i.first << "->" << i.second << endl;
    }

    // Fetch
    for (int i = 0; i < q; i++)
    {
        cout << hash[queries[i]] << endl; // Keys that do not exist will automatically give 0 in cpp (null in Java)
    }
}

int main()
{
    // Why hashing?
    // To identify frequency of q given elements in an input size of n, brute force would take O(q*n)

    // Array Hashing
    arrayHashing();

    // Character Hashing
    characterHashing();

    // Map
    usingMap();

    // Unordered map
    usingUnorderedMap(); // Hashmap in Java

    /* Collision (Rare worst of unordered map):
    Division method -> One of the ways maps are internally implemented (Folding and mid-square -> some other methods)
    Reduce the array elements by using modulo on actual values and apply array hashing
    Multiple values resulting in same remainder are resolved by linear chaining
    Linear chaining -> Multiple numbers on same hash index in sorted order

    Whatever method the map is using, if all the elements go to the same hash index -> case of collision
    This would give TLE, which if happens, fallback to use map instead of unordered map
    */
}