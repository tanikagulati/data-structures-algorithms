#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(int arr[], int n)
{
    // If array contains negatives, initialize with INT_MIN
    int slargest = -1;
    int largest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > slargest && arr[i] != largest) // arr[i] != largest handles duplicates
        {
            slargest = arr[i];
        }
    }
    return slargest;
}

int main()
{
    // Max array of size 10^5 can be initialized (10^8 if initialized globally)
    // Representing in powers of 10 but actual limit is not in powers of 10
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << findSecondLargest(arr, n) << endl;
}