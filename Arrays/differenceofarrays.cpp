#include <iostream>
#include <algorithm>
using namespace std;
void difference_arrays(int arr[], int arr2[], int m, int n)
{
    sort(arr, arr + m);
    sort(arr2, arr2 + n);
    int i = 0, j = 0, k = 0;
    int arr3[m];
    while (i < m && j < n)
    {
        if (arr[i] < arr2[j])
        {
            arr3[k++] = arr[i++];
        }
        else if (arr[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (; i < m; i++)
    {
        arr3[k++] = arr[i];
    }
    cout << "The difference of two arrays is" << endl;
    for (size_t i = 0; i < k; i++)
    {
        cout << arr3[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 53, 24, 2, 3, 9, 12};
    int arr2[] = {2, 3, 4, 5, 6, 9, 11};
    int m = sizeof(arr) / sizeof(int);
    int n = sizeof(arr2) / sizeof(int);
    difference_arrays(arr, arr2, m, n);
    return 0;
    return 0;
}