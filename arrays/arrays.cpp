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

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    vector<int> res;
    int asize = a.size();
    int bsize = b.size();

    int i = 0, j = 0;

    while (i < asize && j < bsize)
    {
        if (a[i] <= b[j])
        {
            if (res.size() == 0 || res.back() != a[i])
            {
                res.push_back(a[i]);
            }
            i++;
        }
        else if (b[j] < a[i])
        {
            if (res.size() == 0 || res.back() != b[j])
            {
                res.push_back(b[j]);
            }
            j++;
        }
    }

    for (int x = i; x < asize; x++)
    {
        if (res.back() != a[x])
        {
            res.push_back(a[x]);
        }
    }
    for (int x = j; x < bsize; x++)
    {
        if (res.back() != b[x])
        {
            res.push_back(b[x]);
        }
    }
    return res;
    // TC: O(asize+bsize)
    // SC: O(asize+bsize)
}

vector<int> intersectionBruteF(vector<int> &v1, vector<int> &v2)
{
    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> res;
    vector<int> visited(n2, 0);

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (v1[i] == v2[j] && visited[j] == 0)
            {
                res.push_back(v1[i]);
                visited[j] = 1;
                break;
            }
            if (v2[j] > v1[i])
            {
                break;
            }
        }
    }
    return res;
    // TC: O(n1*n2)
    // SC: O(n2) or O(n1) based on impl
}

vector<int> intersectionOptimized(vector<int> &v1, vector<int> &v2)
{
}

int main()
{
    // Max array of size 10^5 can be initialized (10^8 if initialized globally)
    // Representing in powers of 10 but actual limit is not in powers of 10
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findSecondLargest(arr, n) << endl;

    // Remove duplicates from sorted array
    cout << removeDuplicates(arr, n) << endl;

    int k;
    cin >> k;

    // Rotate the array by k steps (inplace)
    rotate(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Union of two sorted arrays
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for (int i = 0; i < v1.size(); i++)
        cin >> v1[i];
    for (int i = 0; i < v2.size(); i++)
        cin >> v2[i];
    vector<int> res = findUnion(v1, v2);
    for (auto i : res)
        cout << i << " ";
    cout << endl;

    // Intersection of two sorted arrays (a number present in both arrays) (duplicates are also considered)
    vector<int> res2 = intersectionBruteF(v1, v2);
    for (auto i : res2)
        cout << i << " ";
    cout << endl;

    vector<int> res3 = intersectionOptimized(v1, v2);
    for (auto i : res3)
        cout << i << " ";
    cout << endl;
}