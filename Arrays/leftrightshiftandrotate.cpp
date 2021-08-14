#include <iostream>
using namespace std;
void left_shift(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
}
void right_shift(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = arr[i - 1];
    }
}
void left_rotate(int arr[], int n)
{
    int ele = arr[0];
    int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[i - 1] = ele;
}
void right_rotate(int arr[], int n)
{
    int ele = arr[n - 1];
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[i + 1] = ele;
}
int main()
{
    int arr[] = {1, 3, 63, 64, 2};
    right_rotate(arr, 5);
    left_rotate(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}