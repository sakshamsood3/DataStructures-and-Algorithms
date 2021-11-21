#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void SelectionSort(int arr[], int n)
{
    int j, k;
    for (int i = 0; i < n - 1; i++)
    {
        for (j = i, k = i; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(arr[i], arr[k]);
    }
}
int main()
{
    int arr[] = {2, 42, 1, 32, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
