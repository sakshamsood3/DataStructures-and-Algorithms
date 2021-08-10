#include <iostream>
using namespace std;
int linear_search(int arr[], int key, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}
int transposition_linearsearch(int arr[], int key, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            return i - 1;
        }
    }
    return -1;
}
int movetohead_linearsearch(int arr[], int key, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            return 0;
        }
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; //initialised for simplicity
    int n = (sizeof(arr) / sizeof(int));
    cout << "Element found at index " << linear_search(arr, 3, n) << endl;
    cout << "Element found at index " << transposition_linearsearch(arr, 3, n) << endl;
    cout << "Element found at index " << movetohead_linearsearch(arr, 2, n);
    return 0;
}