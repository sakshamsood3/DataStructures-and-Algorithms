#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    for (; i <= mid; i++)
    {
        B[k++] = A[i];
    }
    for (; j <= h; j++)
    {
        B[k++] = A[j];
    }
    for (int i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}
void RMergeSort(int arr[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        RMergeSort(arr, l, mid);
        RMergeSort(arr, mid + 1, h);
        Merge(arr, l, mid, h);
    }
}
int main()
{
    int arr[] = {2, 42, 1, 32, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    RMergeSort(arr, 0, 4);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}