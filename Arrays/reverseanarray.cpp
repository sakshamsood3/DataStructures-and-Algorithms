#include <iostream>
using namespace std;
void rev_array(int arr[], int n)
{
    int arr2[n];
    for (int i = n - 1, j = 0; i >= 0; i--, j++)
    {
        arr2[j] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr2[i];
    }
}
void rev_arraybetter(int a[], int n)
{
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        a[i] = a[i] + a[j];
        a[j] = a[i] - a[j];
        a[i] = a[i] - a[j];
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    rev_arraybetter(arr, 6); //both methods work we can use any one
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    rev_array(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}