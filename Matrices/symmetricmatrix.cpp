#include <iostream>
using namespace std;
class SymmetricMatrix
{
    int order;
    int *p;

public:
    SymmetricMatrix()
    {
        order = 2;
        p = new int[order * (order + 1) / 2];
    }
    SymmetricMatrix(int order)
    {
        this->order = order;
        p = new int[order * (order + 1) / 2];
    }
    ~SymmetricMatrix()
    {
        delete[] p;
    }
    void set(int i, int j, int element)
    {
        if (i >= j)
            p[(i * (i - 1) / 2) + (j - 1)] = element;
    }
    int get(int i, int j)
    {
        if (i >= j)
            return p[(i * (i - 1) / 2) + (j - 1)];
        else
            return p[j * (j - 1) / 2 + (i - 1)];
    }
    void display()
    {
        for (int i = 1; i <= order; i++)
        {
            for (int j = 1; j <= order; j++)
            {
                if (i >= j)
                    cout << p[(i * (i - 1) / 2) + (j - 1)] << " ";
                else
                    cout << p[j * (j - 1) / 2 + (i - 1)] << " ";
            }
            cout << endl;
        }
    }
    int getDimension()
    {
        return order;
    }
};
int main()
{
    int order;
    cout << "Enter order of the Matrix" << endl;
    cin >> order;
    SymmetricMatrix m1(order);
    int x;
    cout << "Enter the elements of either upper or lower diagonal elements" << endl;
    for (int i = 1; i <= order; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> x;
            m1.set(i, j, x);
        }
    }
    cout << "Displaying symmetric Matrix" << endl;
    m1.display();
}