#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (k == arr[i])
            return i;
    }
    return -1;
}

// array must be sorted for binary search
int binarySearch(int *arr, int n, int k)
{
    int s = 0, e = n - 1, mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (k < arr[mid])
            e = mid - 1;
        else if (k > arr[mid])
            s = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << binarySearch(arr, n, k);
}