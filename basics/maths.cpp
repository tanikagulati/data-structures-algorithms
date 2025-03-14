#include <bits/stdc++.h>
using namespace std;

void extractAndCountDigits(int n)
{

    cout << (int)(log10(n) + 1) << endl; // Gives count

    // Digits and count
    int count = 0;
    // Reverse the number
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

    /*
    TC: n = n / 10 -> O(log10(n))
    If division by 2 -> O(log2(n)) , division by 5 -> O(log5(n))

    Applications:
    Armstrong number: If number is equal to sum of its own digits each raised to the power of the number of digits (153 = 1^3 + 5^3 + 3^3)
    */
}

void printAllDivisors(int n)
{
    vector<int> divisors;

    // Divisors start repeating after square root of n
    // If n = 12 -> 1*12=12, 2*6=12, 3*4=12, 4*3=12, 6*2=12, 12*1=12
    for (int i = 1; i * i <= n; i++) // Imp -> i = 1
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if ((n / i) != i)
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());

    for (auto i : divisors)
        cout << i << " ";
    cout << endl;
}

bool checkPrime(int n)
{
    // Each composite number has at least one prime factor, so check divisibility only by (potential) prime numbers
    // All prime numbers (except 2 & 3) can be expressed in the form of (6k ± 1)

    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6) // i will always be 6k - 1
    {
        if (n % i == 0 || n % (i + 2) == 0) // check for divisibility by 6k - 1 and 6k + 1
            return false;
    }
    return true;

    // Case 1: Iterate all till √N -> O(√N)
    // Case 2: Logic above -> O(√N/3) approx. ~ O(√N) -> but faster than case 1
}

void findGcd(int n1, int n2)
{
    int gcd = 1;
    for (int i = 1; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }
    cout << gcd << endl;
}

void euclideanTheorem(int n1, int n2)
{
    /*
    The GCD of two numbers remains unchanged if larger number is replaced by its remainder when divided by the smaller number
    gcd(a, b) = gcd(b, a mod b)
    This process repeats until b = 0, at which point, a is the GCD
    TC: O(log(min(a, b)))
    */

    while (n1 != 0 && n2 != 0)
    {
        if (n1 < n2)
            n2 = n2 % n1;
        else
            n1 = n1 % n2;
    }
    cout << (n1 == 0 ? n2 : n1) << endl;
    // -- OR --
    while (n1 != 0)
    {
        n2 = n2 % n1;
        swap(n1, n2);
    }
    cout << n2 << endl;
}

int main()
{
    extractAndCountDigits(73600);
    printAllDivisors(36);
    cout << checkPrime(37) << endl;
    findGcd(20, 40);
    euclideanTheorem(20, 40);
}

// small mod big = small
// num mod 0 = undefined
// 0 mod num = 0