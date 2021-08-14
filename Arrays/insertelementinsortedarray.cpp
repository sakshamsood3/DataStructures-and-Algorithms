#include <iostream>
using namespace std;
void insert(int arr[], int ele, int n)
{
    int l = n - 1;
    int i;
    for (i = l; arr[i] > ele; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[i + 1] = ele;
}
int main()
{
    int arr[] = {1, 4, 7, 8, 19, 20, 0, 0, 0}; //extra 0's denote empty space for simplifying our code
    int n = sizeof(arr) / sizeof(int);
    insert(arr, 5, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}