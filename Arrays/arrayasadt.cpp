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
    void add(int x)
    {
        p[length] = x;
        length++;
        display();
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
            cout << "Not a valid index" << endl;
            display();
        }
    }
    void delete_element(int index)
    {
        int x = p[index];
        if (index >= 0 && index < length)
        {
            for (size_t i = index; i < length - 1; i++)
            {
                p[i] = p[i + 1];
            }
            length--;
            cout << "Element " << x << " was deleted" << endl;
            display();
        }
        else
        {
            cout << "Not a valid index " << endl;
            display();
        }
    }
};
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
    arr.display();
    cout << "Enter an element to add or append to the array ";
    int x;
    cin >> x;
    arr.add(x);
    int ele, index;
    cout << "Enter an element to insert and the index ";
    cin >> ele >> index;
    arr.insert(index, ele);
    cout << "Enter an element to delete ";
    cin >> ele;
    arr.delete_element(ele);
    delete[] arr.p;
    return 0;
}