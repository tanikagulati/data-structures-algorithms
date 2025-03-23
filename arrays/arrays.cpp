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

int removeDuplicates(int arr[], int n)
{
    // Returns number of unique elements
    int i = 0, j = 1;
    while (j < n)
    {
        if (arr[i] != arr[j])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    return i + 1;
}

void rotate(int nums[], int size, int k)
{
    // Handle if k > size
    int steps = k % size;
    // Partition on the basis of k and reverse
    int pIndex = size - steps;
    for (int i = 0; i < pIndex / 2; i++)
    {
        swap(nums[i], nums[pIndex - 1 - i]);
    }
    for (int i = 0; i < steps / 2; i++)
    {
        swap(nums[pIndex + i], nums[size - 1 - i]);
    }
    for (int i = 0; i < size / 2; i++)
    {
        swap(nums[i], nums[size - 1 - i]);
    }
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

    // Remove duplicates from sorted array
    cout << removeDuplicates(arr, n) << endl;

    int k;
    cin >> k;

    // Rotate the array by k steps (inplace)
    rotate(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}