#include <iostream>
using namespace std;
class Array
{
public:
    int *p;
    int size;
    int length;
    void display()
    {
        cout << "Elements of the array are " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    void insert(int index, int element)
    {
        if (index >= 0 && index <= length)
        {
            for (int i = length; i > index; i--)
            {
                p[i] = p[i - 1];
            }
            p[index] = element;
            length++;
            display();
        }
        else
        {
            cout << "Not a valid index";
        }
    }
};
int main()
{
    int size, num, index, ele;
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
    arr.display();
    cout << "Enter an element to insert and the index ";
    cin >> ele >> index;
    arr.insert(index, ele);
    return 0;
    delete[] arr.p;
}