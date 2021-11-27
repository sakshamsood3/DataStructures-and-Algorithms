#include <iostream>
using namespace std;
class Heap
{
public:
    int *H;
    int size;
    Heap()
    {
        size = 10;
        H = new int[10];
    }
    Heap(int size)
    {
        this->size = size;
        H = new int[size];
    }
    void getElements()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter Elements of Heap" << endl;
            cin >> H[i];
        }
    }
    void Insert(int n)
    {
        int i = n, temp;
        temp = H[i];
        while (i > 1 && temp > H[i / 2])
        {
            H[i] = H[i / 2];
            i = i / 2;
        }
        H[i] = temp;
    }
    int Delete(int n)
    {
        int i, j, x, val, temp;
        val = H[1];
        x = H[n];
        H[1] = H[n];
        H[n] = val;
        i = 1;
        j = 2 * i;
        while (j < n - 1)
        {
            if (H[j + 1] > H[j])
                j = j + 1;
            if (H[i] < H[j])
            {
                temp = H[i];
                H[i] = H[j];
                H[j] = temp;
                i = j;
                j = 2 * j;
            }
            else
                break;
        }
        return val;
    }
};
int main()
{
    int size;
    cout << "Enter Heap size" << endl;
    cin >> size;
    Heap h(size);
    h.getElements();
    int i;
    for (i = 2; i <= 7; i++)
    {
        h.Insert(i);
    }
    for (i = 7; i > 1; i--)
    {
        h.Delete(i);
    }
    for (int i = 1; i <= 7; i++)
    {
        cout << h.H[i] << " ";
    }
}