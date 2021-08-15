#include <iostream>
using namespace std;
int main()
{
    int arr[] = {5, 7, 2, 43, 200};
    int n = sizeof(arr) / sizeof(int);
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }
    cout << "Maximum element is " << max << endl;
    cout << "Minimum element is " << min << endl;
    return 0;
}