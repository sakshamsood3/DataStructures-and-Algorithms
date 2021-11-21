#include <bits/stdc++.h>
using namespace std;
void InsertionSort(int arr[], int n)
{
    int j, x;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}
int main()
{
    int arr[] = {2, 42, 1, 32, 55, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}