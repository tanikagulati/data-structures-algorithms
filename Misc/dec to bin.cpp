#include <iostream>
#include <math.h>
using namespace std;

long powerFunction(int a, int b){
    long res = 1;
    while(b--){
        res *= a;
    }
    return res;
}

long int dec_to_bin(long n)
{
    long c = 0;
    long r = 0;
    while (n != 0)
    {
        r = (powerFunction(10, c) * (n % 2)) + r;
        c++;
        n = n / 2;
    }
    return r;
}

int dec_to_octal(int n)
{
    int c = 0, r = 0;
    while (n != 0)
    {
        r = powerFunction(10, c) * (n % 8) + r;
        c++;
        n = n / 8;
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    cout << "Binary number: " << dec_to_bin(n) << endl;
    cout << "Octal number: " << dec_to_octal(n) << endl;
    return 0;
}

