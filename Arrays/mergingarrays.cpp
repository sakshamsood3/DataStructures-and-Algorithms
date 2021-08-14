#include <iostream>
using namespace std;
void merge_array(int arr[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = 0;
    int arr3[(m + n)];
    while ((i < n) && (j < m))
    {
        if (arr[i] < arr2[j])
            arr3[k++] = arr[i++];
        else
            arr3[k++] = arr2[j++];
    }
    for (; i < n; i++)
    {
        arr3[k++] = arr[i];
    }
    for (; j < m; j++)
    {
        arr3[k++] = arr2[j];
    }
    for (int a = 0; a < (m + n); a++)
    {
        cout << arr3[a] << " ";
    }
} //merging two sorted arrays in sorted order
int main()
{
    int arr[] = {1, 2, 4, 6, 8, 10};
    int arr2[] = {5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);
    merge_array(arr, arr2, n, m);
    return 0;
}