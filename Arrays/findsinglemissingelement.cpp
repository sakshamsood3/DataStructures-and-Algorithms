#include <iostream>
using namespace std;
void find_missing(int arr[], int n)
{
    int l = arr[0];
    int h = arr[n - 1];
    int diff = l;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] - i) != diff)
        {
            cout << "Missing element is " << (diff + i) << endl;
            break;
        }
    }
}
void find_missing2(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if ((arr[i + 1] - arr[i]) != 1)
        {
            cout << "Missing element is " << arr[i] + 1 << endl;
            break;
        }
    }
}
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 6}; //sorted array
    int n = sizeof(arr) / sizeof(int);
    find_missing(arr, n);
    find_missing2(arr, n);
    return 0;
}