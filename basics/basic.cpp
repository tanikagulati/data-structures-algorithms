// #include <iostream>
#include <bits/stdc++.h> // ALL the libraries
using namespace std;

void pairs()
{
    pair<int, int> p = {1, 2};
    cout << p.first << ' ' << p.second << endl;

    // Nested pair
    pair<int, pair<int, int>> p1 = {1, {2, 3}};
    cout << p1.first << ' ' << p1.second.first << ' ' << p1.second.second << endl;

    // Array of pair
    pair<int, int> arr[2] = {{1, 2}, {3, 4}};
    cout << arr[1].first << endl;
}

void vectors()
// Size can be changed dynamically
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2); // Faster than push_back

    vector<pair<int, int>> vec;
    vec.push_back({3, 4});
    vec.emplace_back(3, 4); // Syntax difference

    vector<int> v1(3, 10); // {10,10,10}

    vector<int> v2(v1); // A copy of v1 into v2

    vector<int>::iterator it = v.begin(); // Begin points to memory address of first element in the vector
    cout << *it << endl;
    vector<int>::iterator it2 = v.end(); // End points to memory address of next to last element
    cout << *(--it2) << endl;

    vector<int>::reverse_iterator itx = v.rend(); // Reverse iterators are rarely used
    vector<int>::reverse_iterator itx2 = v.rbegin();

    cout << v.back() << endl; // Back points to last element

    // Printing using iterator
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    for (auto it = v.begin(); it != v.end(); it++) // Shortcut
    {
        cout << *it << " ";
    }

    // Using for each
    for (auto i : v) // typeof i -> type of vector v
    {
        cout << i << " ";
    }

    // Deletion
    v.erase(v.begin() + 1); // Deletes 2nd element
    // v.erase(v1.begin() + 1, v1.begin() + 3); // Deletes 2nd and 3rd element -> (end of range not inclusive)
}

int main()
{
    cout << "Hello cpp" << '\n';

    /*
    Without namespace -> std::cout
    \n is faster than endl
    Datatypes: int, long, long long, float, double (see ranges and bits)
    Char -> ' ', string -> " "
    String type variable inputs only single word (anything before space)
    For sentence -> getline(cin, st) (anything before line break)
    String is characters in sequence, can access index based characters
    For, while, do while loops
    Types of functions: void, return, parameterized, non-parameterized
    Pass by value (copy is passed), Pass by Ref (&)
    (only) Arrays are always pass by reference default (even without & operator)
    */

    // Standard Template Library (STL):
    // Containers
    pairs();
    vectors();
}
