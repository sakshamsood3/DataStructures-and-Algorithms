// for sorted array only
#include <iostream>
using namespace std;
void findandcount_duplicates(int arr[], int n) //sorted array
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            int cnt = i + 1;
            while (arr[cnt] == arr[i])
                cnt++;
            cout << "Element " << arr[i] << " appears " << cnt - i << " times " << endl;
            i = cnt - 1;
        }
    }
}
void findandcount_duplicates2(int arr[], int n) //sorted array and unsorted as well
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int arr2[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        arr2[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        if (arr2[i] > 1)
        {
            cout << "Element " << i << " occurs " << arr2[i] << " times " << endl;
        }
    }
}
void findandcount_duplicatesunsorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        if (arr[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    cnt++;
                    arr[j] = -1;
                }
            }
            if (cnt > 1)
            {
                cout << "Element " << arr[i] << " occurs " << cnt << " times " << endl;
            }
        }
    }
}
int main()
{
    int arr[] = {3, 1, 2, 2, 3, 4, 5, 6, 7, 7, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    findandcount_duplicates2(arr, n);
    return 0;
}