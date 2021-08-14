#include <iostream>
#include <algorithm>
using namespace std;
void union_arrays(int arr[], int arr2[], int m, int n)
{
    sort(arr, arr + m);
    sort(arr, arr + n);
    int arr3[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (arr[i] < arr2[j])
        {
            arr3[k++] = arr[i++];
        }
        else if (arr[i] > arr2[j])
        {
            arr3[k++] = arr2[j++];
        }
        else
        {
            arr3[k++] = arr[i++];
            j++;
        }
    }
    for (; i < m; i++)
    {
        arr3[k++] = arr[i];
    }
    for (; j < n; j++)
    {
        arr3[k++] = arr[j];
    }
    cout << "The union of two arrays is" << endl;
    for (size_t i = 0; i < k; i++)
    {
        cout << arr3[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 53, 24, 2, 3};
    int arr2[] = {2, 3, 4, 5, 6};
    int m = sizeof(arr) / sizeof(int);
    int n = sizeof(arr2) / sizeof(int);
    union_arrays(arr, arr2, m, n);
    return 0;
}