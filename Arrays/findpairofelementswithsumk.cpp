#include <iostream>
#include <stdlib.h>
using namespace std;
int find_sumequaltok(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << "Pairs with sum k are " << endl;
                cout << arr[i] << " + " << arr[j] << " = " << k << endl;
            }
        }
    }
}
find_sumequaltokinsorted(int arr[], int n, int k) //for sorted only
{
    for (int i = 0, j = n - 1; i < j;)
    {
        if (arr[i] + arr[j] == k)
        {
            cout << "Pairs with sum k are " << endl;
            cout << arr[i] << " + " << arr[j] << " = " << k << endl;
            i++;
            j--;
        }
        else if (arr[i] + arr[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}
int find_sumequaltok2(int arr[], int n, int k) //some problem with this method willl update later
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int arr2[max + 1];
    for (int i = 0; i < n; i++)
    {

        if (arr2[k - arr[i]] != 0)
        {
            if (arr[i] != 0)
            {
                cout << "Pairs with sum k are " << endl;
                cout << arr[i] << " + " << k - arr[i] << " = " << k << endl;
            }
        }
        arr2[arr[i]]++;
    }
}
int main()
{
    int arr[] = {1, 5, 21, 3, 2, 8, 7, 34, 10};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 10;
    int n = sizeof(arr) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);
    find_sumequaltok2(arr, n, k);
    // find_sumequaltokinsorted(arr2, m, k);
    return 0;
}