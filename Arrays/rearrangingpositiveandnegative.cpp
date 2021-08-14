#include <iostream>
using namespace std;
void rearrange(int arr[], int n) //just rearranging not sorting
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        while (arr[i] < 0)
        {
            i++;
        }
        while (arr[j] > 0)
        {
            j--;
        }
        if (i < j)
        {
            arr[i] = arr[i] + arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
        }
    }
}
int main()
{
    int arr[] = {-5, 3, 54, -7, -8, 32, 24, -2, 1, 10};
    int n = sizeof(arr) / sizeof(int);
    rearrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}