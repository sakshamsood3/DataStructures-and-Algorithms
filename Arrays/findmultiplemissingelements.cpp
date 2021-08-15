#include <iostream>
using namespace std;
void find_multiplemissingelements(int arr[], int n)
{
    int l = arr[0];
    int diff = l;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] - i) != diff)
        {
            for (; diff < arr[i] - i; diff++)
            {
                cout << "Missing element is " << diff + i << endl;
            }
        }
    }
}
void find_multiplemissingelements2(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int arr2[max] = {0};
    for (int i = 0; i < n; i++)
    {
        arr2[arr[i]]++;
    }
    for (int i = 1; i < max; i++)
    {
        if (arr2[i] == 0)
        {
            cout << "Element " << i << " is missing" << endl;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 4, 10, 6, 9, 5};
    int n = sizeof(arr) / sizeof(int);
    //find_multiplemissingelements(arr, n);  //slower O(n^2) //takes less space
    find_multiplemissingelements2(arr, n); //faster O(n) //takes more space
    return 0;
}