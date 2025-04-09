#include <bits/stdc++.h>
using namespace std;

void pascalsTriangle(int n, int r)
{
    // nCr = n! / (r! * (n-r)!)
    // Simplified: 10C3 = 10*9*8 / (3*2*1)

    long long res = 1;
    int ans;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    cout << res << endl;

    // TC: O(r)
    // Sc: O(1)
}

void nthRowOfPascalsTriangle(int row)
{
    // Brute: Using nCr for each element of the row O(n^2)
    // Optimal:

    // For row=5: 4C0, 4C1, 4C2, 4C3, 4C4
    long long ans = 1;
    cout << 1 << " ";

    for (int i = 1; i < row; i++)
    {
        ans = ans * (row - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
    // TC: O(n)
    // SC: O(1)
}

void generatePascalsTriangle(int row)
{
    // Brute: Using nCr for each element -> O(n^3)

    // Optimal:
    for (int i = 1; i <= row; i++)
    {
        nthRowOfPascalsTriangle(i);
    }
    // TC: O(n^2)
    // SC: O(1)
}

int main()
{
    int row = 5, col = 3;
    //         1
    //       1   1
    //     1   2   1
    //   1   3   3   1
    // 1   4   6   4   1

    // Variation 1: Given row and column no, return the number at that position
    pascalsTriangle(row - 1, col - 1);

    // Variation 2: Given row no, return that row
    nthRowOfPascalsTriangle(row);

    // Variation 3: Given row no, generate the triangle till that row
    generatePascalsTriangle(row);
}