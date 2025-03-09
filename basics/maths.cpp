#include <bits/stdc++.h>
using namespace std;

void extractAndCountDigits(int n)
{

    cout << (int)(log10(n) + 1) << endl; // Gives count

    // Digits and count
    int count = 0;
    // Reverse  the number
    int reverse = 0;

    while (n > 0)
    {
        int digit = n % 10;
        cout << digit << " ";
        reverse = (reverse * 10) + digit;
        n = n / 10;
        count++;
    }
    cout << endl;
    cout << count << endl;
    cout << reverse << endl;

    // TC: n = n / 10 -> O(log10(n))
    // If division by 2 -> O(log2(n)) , division by 5 -> O(log5(n))
}

int main()
{
    extractAndCountDigits(73600);
}