#include <iostream>
using namespace std;
class Array
{
    int size;
    int length;
    int *p;

public:
    Array()
    {
        size = 10;
        length = 0;
    }
    Array(int size)
    {
        this->size = size;
        length = 0;
    }
    ~Array()
    {
        delete[] p;
    }
    void create_array()
    {
        int len;
        p = new int[size];
        cout << "Enter number of elements in the array initially" << endl;
        cin >> len;
        this->length = len;
        cout << "Enter the " << length << " no. of elements of the array " << endl;
        for (int i = 0; i < length; i++)
        {
            cin >> p[i];
        }
    }
    void display_array()
    {
        cout << "displaying the current array " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    void insert_element(int index, int ele)
    {
        if (index >= 0 && index < length)
        {
            for (int i = length; i > index; i--)
            {
                p[i] = p[i - 1];
            }
            p[index] = ele;
            length++;
            display_array();
        }
        else
        {
            cout << "cant insert at this index " << endl;
        }
    }
    void delete_element(int index)
    {
        int x = p[index];
        if (index >= 0 && index < length)
        {

            for (int i = index; i < length - 1; i++)
            {
                p[i] = p[i + 1];
            }
            length--;
            cout << "Element " << x << " was deleted" << endl;
            display_array();
        }
        else
        {
            cout << "Not a valid index " << endl;
            display_array();
        }
    }
    int linear_search(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (p[i] == key)
            {
                return i;
            }
        }
        return -1;
    }
    int binarysearch(int key)
    {
        int s = 0;
        int e = length - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (p[mid] == key)
            {
                return mid;
            }
            else if (p[mid] > key)
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
    int Rbinarysearch(int s, int e, int key)
    {
        if (s <= e)
        {
            int mid = (s + e) / 2;
            if (key == p[mid])
            {
                return mid;
            }
            else if (key < p[mid])
            {
                return Rbinarysearch(s, mid - 1, key);
            }
            else
            {
                return Rbinarysearch(mid + 1, e, key);
            }
        }
        return -1;
    }
    bool isSorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (p[i] > p[i + 1])
                return false;
        }
        return true;
    }
    int get(int index)
    {
        if (index >= 0 && index < length)
            return p[index];
    }
    void set(int index, int element)
    {
        if (index >= 0 && index < length)
            p[index] = element;
    }
    int max_array()
    {
        int max = p[0];
        for (int i = 0; i < length; i++)
        {
            if (p[i] > max)
                max = p[i];
        }
        return max;
    }
    int min_array()
    {
        int min = p[0];
        for (int i = 0; i < length; i++)
        {
            if (p[i] < min)
                min = p[i];
        }
        return min;
    }
    int sum_array()
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += p[i];
        }
        return sum;
    }
    double avg_array()
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += p[i];
        }
        return (double)sum / length;
    }
    void insert_sortedarray(int ele)
    {
        int l = length - 1;
        int i;
        for (i = l; p[i] > ele; i--)
        {
            p[i] = p[i - 1];
        }
        p[i + 1] = ele;
    }
    void merge_array(int arr2[], int m)
    {
        int i = 0, j = 0, k = 0;
        int arr3[(m + length)];
        while ((i < length) && (j < m))
        {
            if (p[i] < arr2[j])
                arr3[k++] = p[i++];
            else
                arr3[k++] = arr2[j++];
        }
        for (; i < length; i++)
        {
            arr3[k++] = p[i];
        }
        for (; j < m; j++)
        {
            arr3[k++] = arr2[j];
        }
        for (int a = 0; a < (m + length); a++)
        {
            cout << arr3[a] << " ";
        }
    }
    void rev_array()
    {
        int arr2[length];
        for (int i = length - 1, j = 0; i >= 0; i--, j++)
        {
            arr2[j] = p[i];
        }
        for (int i = 0; i < length; i++)
        {
            p[i] = arr2[i];
        }
    }
    void rev_arraybetter()
    {
        for (int i = 0, j = length - 1; i <= j; i++, j--)
        {
            p[i] = p[i] + p[j];
            p[j] = p[i] - p[j];
            p[i] = p[i] - p[j];
        }
    }
    void exit()
    {
        cout << "Exiting the program " << endl;
        display_array();
    }
};
int main()
{
    int size, len;
    cout << "Enter the size of the array " << endl;
    cin >> size;
    Array arr(size);
    char ch;
    do
    {
        cout << "Welcome to the array menu " << endl;
        cout << "1. Create array" << endl;
        cout << "2. Display array" << endl;
        cout << "3. Insert in array" << endl;
        cout << "4. Delete in array" << endl;
        cout << "5. Search in array" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter a choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            arr.create_array();
            break;
        }
        case 2:
        {
            arr.display_array();
            break;
        }
        case 3:
        {
            int index, ele;
            cout << "Enter the index and element to be inserted " << endl;
            cin >> index >> ele;
            arr.insert_element(index, ele);
            break;
        }
        case 4:
        {
            int index;
            cout << "Enter index of the element to be deleted" << endl;
            cin >> index;
            arr.delete_element(index);
            break;
        }
        case 5:
        {
            int ele;
            cout << "Enter element to be searched for " << endl;
            cin >> ele;
            if (arr.linear_search(ele) == -1)
            {
                cout << "Element not found " << endl;
            }
            else
            {
                cout << "Element found at index " << arr.linear_search(ele) << endl;
            }
            break;
        }
        case 6:
        {
            arr.exit();
            break;
        }
        }
        cout << "Do you want to continue y/n?" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
//many more operations can be inplemented in the same way
//we can use templates to provide better flexibility of datatypes