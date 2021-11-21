#include <iostream>
#include <algorithm>
using namespace std;
int Partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[l], arr[j]);
    return j;
}
void QuickSort(int arr[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = Partition(arr, l, h);
        QuickSort(arr, l, j);
        QuickSort(arr, j + 1, h);
    }
}
int main()
{
    int arr[] = {2, 42, 1, 32, 55, 5, INT_MAX};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, 6);
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}