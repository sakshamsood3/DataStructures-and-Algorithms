#include <iostream>
using namespace std;
class UpperTriangularMatrix
{
    int order;
    int *p;

public:
    UpperTriangularMatrix()
    {
        order = 2;
        p = new int[order * (order + 1) / 2];
    }
    UpperTriangularMatrix(int order)
    {
        this->order = order;
        p = new int[order * (order + 1) / 2];
    }
    ~UpperTriangularMatrix()
    {
        delete[] p;
    }
    void set(int i, int j, int element)
    {
        if (i <= j)
            p[((i - 1) * order - ((i - 1) * (i - 2) / 2)) + (j - i)] = element;
    }
    int get(int i, int j)
    {
        if (i <= j)
            return p[((i - 1) * order - ((i - 1) * (i - 2) / 2)) + (j - i)];
        else
            return 0;
    }
    void display()
    {
        for (int i = 1; i <= order; i++)
        {
            for (int j = 1; j <= order; j++)
            {
                if (i <= j)
                    cout << p[((i - 1) * order - ((i - 1) * (i - 2) / 2)) + (j - i)] << " ";
                else
                    cout << "0 ";
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
    UpperTriangularMatrix m1(order);
    int x;
    cout << "Enter all the elements " << endl;
    for (int i = 1; i <= order; i++)
    {
        for (int j = 1; j <= order; j++)
        {
            cin >> x;
            m1.set(i, j, x);
        }
    }
    m1.display(); //row major mapping
    //for column major mapping use j(j-1)/2 +(i-1)
    return 0;
}