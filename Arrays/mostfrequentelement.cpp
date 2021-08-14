#include <iostream>
#include <algorithm>
using namespace std;
void most_frequent(int arr[], int n)
{
    sort(arr, arr + n);
    int max_count = 1, curr_count = 1, res = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else
        {
            if (curr_count > max_count)
            {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }
    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }
    cout << "Element " << res << " occurs most times that is " << max_count << " times" << endl;
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the " << n << " elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    most_frequent(arr, n);
    cout << 6 % 5 << endl;
    return 0;
}