#include <bits/stdc++.h>
using namespace std;

/*
Recursion -> A function that calls itself, until the specified condition (Base condition) is met
Whenever recursion calls are executed, they’re simultaneously stored in a recursion stack where they wait for the completion of the recursive function.
*/

void printName(int n, int count)
{
    if (count >= n)
        return;
    cout << "Tanika Gulati" << endl;
    printName(n, count + 1);
}

void counting(int n, int count)
{
    if (count > n)
        return;
    cout << count << " ";
    counting(n, count + 1);
}

void reverseCounting(int n, int count)
{
    if (count > n)
        return;
    reverseCounting(n, count + 1);
    cout << count << " ";
}

int main()
{
    int n;
    cin >> n;
    printName(n, 0);
    counting(n, 0);
    cout << endl;
    reverseCounting(n, 0);
}