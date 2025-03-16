#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    // Select the minimun and swap
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // TC: O(n^2)
}

void bubbleSort(int arr[], int n)
{
    // Push max to last by adjacent swaps
    for (int i = 0; i < n - 1; i++)
    {
        bool didSwap = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0) // Optimization for best case (if already sorted)
            break;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // TC: worst and avg -> O(n^2)
    // Best -> O(n)
}

void insertionSort(int arr[], int n)
{
    // Take an element and place in correct position
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // TC: worst and avg -> O(n^2)
    // Best -> O(n)
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
    selectionSort(arr, n);
    bubbleSort(arr, n);
    insertionSort(arr, n);
}