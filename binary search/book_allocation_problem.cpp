#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &pages)
{
    int n = pages.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, pages[i]);
    }
    return maxi;
}

long long findSum(vector<int> &pages)
{
    int n = pages.size();
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pages[i];
    }
    return sum;
}

int findStudentCnt(vector<int> &pages, int max)
{
    int n = pages.size();
    long long assignedPages = 0;
    int studentCnt = 1;

    for (int i = 0; i < n; i++)
    {
        if (assignedPages + pages[i] <= max)
        {
            assignedPages += pages[i];
        }
        else
        {
            studentCnt++;
            assignedPages = pages[i];
        }
    }

    return studentCnt;
}

int bookAllocationBrute(vector<int> &pages, int k)
{
    int n = pages.size();

    // Not possible to allocate books to all students
    if (n < k)
        return -1;

    // Possible result range
    int maxi = findMax(pages);
    long long sum = findSum(pages);

    long long assignedPages = pages[0];
    int studentCnt;

    for (int i = maxi; i < sum; i++)
    {
        studentCnt = findStudentCnt(pages, i);
        if (studentCnt == k)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> pages = {25, 46, 28, 49, 24};
    int k = 4;

    cout << bookAllocationBrute(pages, k) << endl;
}