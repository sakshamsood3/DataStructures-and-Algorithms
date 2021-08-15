#include <iostream>
#include <algorithm>
using namespace std;
int removeDuplicates(int arr[], int n)
{

    if (n == 0 || n == 1)
        return n;

    int temp[n];

    int j = 0;
    for (int i = 0; i < n - 1; i++)

        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];

    temp[j++] = arr[n - 1];

    for (int i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}
int removeDuplicates2(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;
    sort(arr, arr + n);
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
            arr[j++] = arr[i];
    }
    arr[j++] = arr[n - 1];
    return j;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int arr2[] = {1, 2, 2, 3, 4, 4, 6, 6, 5, 5};
    int m = sizeof(arr2) / sizeof(arr2[0]);

    // removeDuplicates() returns new size of
    // array.
    int k = removeDuplicates(arr, n);
    int l = removeDuplicates2(arr2, m);

    // Print updated array
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
    cout << endl;
    for (int i = 0; i < l; i++)
        cout << arr2[i] << " ";
    return 0;
}
