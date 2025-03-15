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
    cout << count << " "; // Backtrack
}

int sum1ToN(int n) // Functional recursion
{
    if (n == 1)
        return n;
    return n + sum1ToN(n - 1);
}

void sum1ToN(int n, int sum) // Parameterized recursion
{
    if (n < 1)
    {
        cout << sum << endl;
        return;
    }
    sum1ToN(n - 1, sum + n);
}

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void reverseArray(int arr[], int n, int l)
{
    if (l >= n / 2)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    swap(arr[l], arr[n - l - 1]);
    reverseArray(arr, n, l + 1);
}

bool palindrome(string &st, int n, int l)
{
    if (l >= n / 2)
        return true;

    if (st[l] != st[n - l - 1])
        return false;
    return palindrome(st, n, l + 1); // Don't forget 'return'
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    string st;
    cin >> st;

    printName(n, 0);
    counting(n, 0);
    cout << endl;
    reverseCounting(n, 0);
    cout << endl;
    cout << sum1ToN(n) << endl;
    sum1ToN(n, 0);
    cout << factorial(n) << endl;
    reverseArray(arr, n, 0);
    cout << palindrome(st, st.size(), 0) << endl;
}