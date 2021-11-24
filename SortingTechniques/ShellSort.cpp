#include <bits/stdc++.h>
using namespace std;
void ShellSort(int arr[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            j = i - gap;
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + gap] = arr[j];
                j = j - gap;
            }
            arr[j + gap] = temp;
        }
    }
}
int main()
{
    int arr[] = {2, 42, 1, 32, 55, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    ShellSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}