#include <iostream>
using namespace std;
class Array
{
public:
    int *p;
    int size;
    int length;
};
void display(Array arr)
{
    cout << "Elements of the array are " << endl;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.p[i] << " ";
    }
}
int main()
{
    int size, num;
    Array arr;
    cout << "Enter size of array ";
    cin >> size;
    arr.p = new int[size];
    arr.length = 0;
    cout << "Enter number of elements to insert in the empty array ";
    cin >> num;
    cout << "Enter the " << num << " No. of elements ";
    for (int i = 0; i < num; i++)
    {
        cin >> arr.p[i];
    }
    arr.length = num;
    display(arr);
    return 0;
}