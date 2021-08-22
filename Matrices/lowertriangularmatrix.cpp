#include <iostream>
using namespace std;
class LowerTriangularMatrix
{
    int order;
    int *p;

public:
    LowerTriangularMatrix()
    {
        order = 2;
        p = new int[order * (order + 1) / 2];
    }
    LowerTriangularMatrix(int order)
    {
        this->order = order;
        p = new int[order * (order + 1) / 2];
    }
    ~LowerTriangularMatrix()
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
            return 0;
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
    LowerTriangularMatrix m1(order);
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
    //for column major mapping use n(j-1)-(j-2)(j-1)/2 +(i-j)
    return 0;
}