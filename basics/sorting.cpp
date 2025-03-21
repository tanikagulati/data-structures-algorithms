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

void mergeTwoSortedArrays(int arr[], int l, int mid, int r)
{
    int left = l;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= r)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= r)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
    // TC: O(nlogn)
    // SC: O(n) (Due to temp vector)
}

void mergeSort(int arr[], int l, int r)
{
    // Divide and conquer
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, 0, mid);
    mergeSort(arr, mid + 1, r);
    mergeTwoSortedArrays(arr, l, mid, r);
}

int placePivotAtCorrectPosition(int arr[], int l, int h)
{
    int i = l;
    int j = h;
    while (i <= j)
    {
        while (i <= j && arr[i] <= arr[l])
        {
            i++;
        }
        while (i <= j && arr[j] > arr[l])
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h)
{
    // Divide and conquer
    // Pick a pivot at place at correct position
    // Smaller on left, greater on the right
    if (l >= h)
        return;

    int partionIndex = placePivotAtCorrectPosition(arr, l, h);

    quickSort(arr, l, partionIndex - 1);
    quickSort(arr, partionIndex + 1, h);
    // TC: O(nlogn)
    // SC: O(1) (Recursion stack space is not considered)
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

    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}