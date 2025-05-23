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

    vector<int> v1(2, 5); // {5, 5}

    vector<int> v2(v1); // A copy of v1 into v2

    vector<int>::iterator it = v.begin(); // Begin points to memory address of first element in the vector
    cout << *it << endl;
    vector<int>::iterator it2 = v.end(); // End points to memory address of next to last element
    cout << *(--it2) << endl;

    vector<int>::reverse_iterator itx = v.rend(); // Reverse iterators are rarely used
    vector<int>::reverse_iterator itx2 = v.rbegin();

    cout << v.front() << endl; // First element
    cout << v.back() << endl;  // Last element

    cout << v.size() << endl; // Size

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

    // Insertion
    v.insert(v.begin(), 10);                   // {10, 1, 2}
    v.insert(v.begin() + 1, 3, 30);            // {10, 30, 30, 30, 1, 2}
    v.insert(v.end(), {3, 4});                 // {10, 30, 30, 30, 1, 2, 3, 4}
    v.insert(v.begin(), v1.begin(), v1.end()); // {5, 5, 10, 30, 30, 30, 1, 2, 3, 4}

    v1.swap(v2); // Swap elements

    // Deletion
    v.pop_back();                          // Deletes last element
    v.erase(v.begin() + 1);                // Deletes 2nd element
    v.erase(v.begin() + 1, v.begin() + 3); // Deletes 2nd and 3rd element -> (end of range not inclusive) -> [first, last)
    v.clear();                             // Erases entire vector

    v.empty(); // Boolean
    cout << endl;
}

void lists()
{
    // Dynamic in nature
    // Insertion in vector is costly than list since a singly LL is maintained for vector, whereas doubly LL for list
    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(3);
    ls.emplace_front(4);

    ls.pop_back();
    ls.pop_front();

    ls.front();
    ls.back();

    // same functions as in vector like begin, end, rend, rbegin, insert, swap, size, clear
}

void deques()
{
    // same as list
}

void stacks()
{
    // LIFO
    // O(1) -> For all operations push, pop, top
    // No index based access (st[1] -> invalid)
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.emplace(4);

    st.top(); // 4
    st.pop();
    st.size();  // 3
    st.empty(); // false

    stack<int> st1, st2;
    st1.swap(st2);
}

void queues()
{
    // FIFO
    // O(1) -> All operations
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);

    q.back() += 5;
    cout << q.back() << endl; // 8

    q.pop();   // {2, 8}
    q.front(); // 2
}

void priorityQueues()
{
    // Internally uses tree data structure
    // Push / Pop -> O(logn), Top -> O(1)
    priority_queue<int> pq; // Max heap
    pq.push(2);
    pq.push(6);
    pq.emplace(1);

    cout << pq.top() << endl; // 6
    pq.pop();                 // {2, 1}

    priority_queue<int, vector<int>, greater<int>> pq1; // Min heap
    pq1.push(2);
    pq1.push(6);
    pq1.emplace(1);

    cout << pq1.top() << endl; // 1
}

void sets()
{
    // sorted and unique
    // Internally uses tree data structure
    // O(logn) -> All operations
    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(1);
    s.insert(4);
    s.insert(3); // {1, 3, 4, 5}

    cout << s.count(3) << endl; // 1 if present, 0 if not (count can never exceed 1, since unique elements)

    s.erase(1); // {3, 4, 5}

    auto it = s.find(4);   // Points to memory address of given element
    auto it2 = s.find(10); // Element not present? -> st.end() -> points to address of next to last element

    s.erase(it, it2); // {3}

    // Read: lower and upper bound
}

void multiSets()
{
    // sorted and can store duplicates
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);

    ms.count(1);

    ms.erase(2);          // Erases all 2's
    ms.erase(ms.find(1)); // Erases first 1
    ms.erase(ms.find(1), next(ms.find(1), 2));

    /*
    Tree based containers like set use Bidirectional iterators that do not support (it + n) because of no direct indexing
    unlike vector/array/deque that are contagious and use Random access iterators
    Therefore, it's equivalent -> next(it, n) is used instead (next works for linear as well)
    next(it, n) internally moves step-by-step using ++it. It traverses the tree by following internal parent and child pointers. Takes O(n)
    */
}

void unorderedSets()
{
    // Unique and randomized order
    // O(1) -> All operations
    // For a worst case scenario -> O(n) (rare)
    // Lower and upper bound functions doesn't work
    unordered_set<int> st;
}

void maps()
{
    // Unique keys in sorted order
    // O(logn) -> All operations
    map<int, int> mp;
    map<int, pair<int, int>> mp1;
    map<pair<int, int>, int> mp2;

    mp[1] = 10;
    mp.insert({7, 20});
    mp.emplace(3, 30);

    mp2[{4, 2}] = 10;

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mp[3] << endl; // 30
    cout << mp[9] << endl; // key not exist -> 0 / null

    auto it = mp.find(7);         // if not present -> mp.end()
    cout << (*it).second << endl; // or it -> first (preferred)

    // lower bound, upper bound

    // begin, end, erase, size, swap, empty ... same
}

void multiMaps()
{
    // Allows duplicate keys
    // same as map but mp[key] cannot be used
}

void unorderedMaps()
{
    // Unique keys, randomized order
    // O(1) -> All operations
    // O(n) -> rare worst case
    // same as set and unordered set difference
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    // Sort on the basis of 2nd element, in ascending order
    // If 2nd elements are equal, sort on the basis of 1st, but in descending order
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;

    if (p1.first > p2.first)
        return true;
    else
        return false;
}

void sorting()
{
    int a[4] = {5, 3, 6, 1};
    vector<int> v = {7, 3, 8};

    // TC: O(nlogn)
    sort(a, a + 4);
    sort(a, a + 4, greater<int>()); // Descending order

    sort(v.begin(), v.end());
    sort(v.begin() + 1, v.end());

    // Custom sort using comparator
    vector<pair<int, int>> vec = {{1, 2}, {4, 6}, {5, 2}};
    sort(vec.begin(), vec.end(), comp);
}

void misc()
{
    int num = 7;
    cout << __builtin_popcount(num) << endl; // 3 -> Returns no of signed bits (7 = 111)

    long long num2 = 35648297368;
    cout << __builtin_popcountll(num2) << endl; // For long long type

    string s = "123";
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end())); // Modifies 's' in-place

    // s should be always sorted first, to get all permutations

    vector<int> v = {7, 3, 8};
    cout << *max_element(v.begin(), v.end() - 1) << endl; // Imp -> *
    cout << *min_element(v.begin(), v.end()) << endl;
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
    // Containers and Iterators
    pairs();
    vectors();
    lists();
    deques();
    stacks();
    queues();
    priorityQueues();
    sets();
    multiSets();
    unorderedSets();
    maps();
    multiMaps();
    unorderedMaps();

    // Algos
    sorting();
    misc();
}
