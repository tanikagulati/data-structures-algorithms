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
    cout << arr[1].first;
}

void vector()
{
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

    // Standard Template Library (STL)
    pairs();
}
