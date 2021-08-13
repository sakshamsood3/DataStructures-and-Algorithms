#include <iostream>
using namespace std;
int get(int arr[], int index, int n)
{
    if (index >= 0 && index < n)
        return arr[index];
}
void set(int arr[], int index, int element, int n)
{
    if (index >= 0 && index < n)
        arr[index] = element;
}
int max_array(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int min_array(int arr[], int n)
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
int sum_array(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int Rsum_array(int arr[], int n) //here n is last index
{
    if (n < 0)
        return 0;
    else
        return arr[n] + Rsum_array(arr, n - 1);
}
double avg_array(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return (double)sum / n;
}
int main()
{
    int arr[] = {2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << get(arr, 1, n) << endl;
    set(arr, 2, 5, n);
    cout << max_array(arr, n) << endl;
    cout << min_array(arr, n) << endl;
    cout << sum_array(arr, n) << endl;
    cout << Rsum_array(arr, n - 1) << endl;
    cout << avg_array(arr, n) << endl;
    return 0;
}