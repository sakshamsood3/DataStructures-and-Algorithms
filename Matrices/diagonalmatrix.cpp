#include <iostream>
using namespace std;
class Matrix
{
    int order;
    int *p;

public:
    Matrix()
    {
        order = 10;
        p = new int[order];
    }
    Matrix(int order)
    {
        this->order = order;
        p = new int[order];
    }
    ~Matrix()
    {
        delete[] p;
    }
    void set(int i, int j, int element)
    {
        if (i == j)
            p[i - 1] = element;
    }
    int get(int i, int j)
    {
        if (i == j)
            return p[i - 1];
        else
            return 0;
    }
    void display()
    {
        for (int i = 1; i <= order; i++)
        {
            for (int j = 1; j <= order; j++)
            {
                if (i == j)
                    cout << p[i - 1] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Matrix m1(3);
    m1.set(1, 1, 2);
    m1.set(2, 2, 3);
    m1.set(3, 3, 4);
    m1.display();
    return 0;
}