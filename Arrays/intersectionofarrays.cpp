#include <iostream>
#include <algorithm>
using namespace std;
void intersection_arrays(int arr[], int arr2[], int m, int n)
{
    sort(arr, arr + m);
    sort(arr2, arr2 + n);
    int i = 0, j = 0, k = 0;
    int size = m > n ? m : n;
    int arr3[size];
    while (i < m && j < n)
    {
        if (arr[i] < arr2[j])
        {
            i++;
        }
        else if (arr[i] > arr2[j])
        {

            j++;
        }
        else
        {
            arr3[k++] = arr[i++];
            j++;
        }
    }
    cout << "The intersection of two arrays is" << endl;
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
    intersection_arrays(arr, arr2, m, n);
    return 0;
}