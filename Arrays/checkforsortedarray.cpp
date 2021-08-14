#include <iostream>
using namespace std;
bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 10, 1, 24, 6};
    if (isSorted(arr2, 5)) //if we try it with arr it returns array is sorted
    {
        cout << "Array is sorted";
    }
    else
    {
        cout << "Array not sorted ";
    }
    return 0;
}