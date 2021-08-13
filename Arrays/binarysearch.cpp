#include <iostream>
using namespace std;
int binarysearch(int arr[], int key, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
            break;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
int Rbinarysearch(int arr[], int s, int e, int key)
{
    if (s <= e)
    {
        int mid = (s + e) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            return Rbinarysearch(arr, s, mid - 1, key);
        }
        else
        {
            return Rbinarysearch(arr, mid + 1, e, key);
        }
    }
    return -1;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; //for ease taken a sorted array will implement sort later
    int n = sizeof(arr) / sizeof(int);
    int ele;
    int s = 0;
    int e = n - 1;
    cout << "Enter number to search for" << endl;
    cin >> ele;
    /* if (binarysearch(arr, ele, n) == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at index " << binarysearch(arr, ele, n);
    }
    */
    // we can use both the functions for our purpose
    if (Rbinarysearch(arr, s, e, ele) == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at index " << Rbinarysearch(arr, s, e, ele);
    }
    return 0;
    //iterative version is better as recursion involves stack
}