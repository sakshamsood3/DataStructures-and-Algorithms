#include <iostream>
using namespace std;
int FindMax(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void CountSort(int arr[], int n)
{
    int max;
    max = FindMax(arr, n);
    int *c;
    c = new int[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        c[arr[i]]++;
    }
    int i = 0, j = 0;
    while (i < max + 1)
    {
        if (c[i] > 0)
        {
            arr[j++] = i;
            c[i]--;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int arr[] = {2, 42, 1, 32, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    CountSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}