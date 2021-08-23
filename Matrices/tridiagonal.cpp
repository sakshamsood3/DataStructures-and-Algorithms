#include <iostream>
using namespace std;
class TriDiagonalMatrix
{
    int order;
    int *p;

public:
    TriDiagonalMatrix()
    {
        order = 5;
        p = new int[(order * 3) - 2];
    }
    TriDiagonalMatrix(int order)
    {
        this->order = order;
        p = new int[(order * 3) - 2];
    }
    ~TriDiagonalMatrix()
    {
        delete[] p;
    }
    void set(int i, int j, int element)
    {
        if ((i - j) == 1)
        {
            p[i - 2] = element;
        }
        else if ((i - j) == 0)
        {
            p[order - 1 + i - 1] = element;
        }
        else if ((i - j) == -1)
        {
            p[2 * order - 1 + i - 1] = element;
        }
    }
    int get(int i, int j)
    {
        if ((i - j) == 1)
        {
            return p[i - 2];
        }
        else if ((i - j) == 0)
        {
            return p[order - 1 + i - 1];
        }
        else if ((i - j) == -1)
        {
            return p[2 * order - 1 + i - 1];
        }
        else
            return 0;
    }
    void display()
    {
        for (int i = 1; i <= order; i++)
        {
            for (int j = 1; j <= order; j++)
            {
                if ((i - j) == 1)
                {
                    cout << p[i - 2] << " ";
                }
                else if ((i - j) == 0)
                {
                    cout << p[order - 1 + i - 1] << " ";
                }
                else if ((i - j) == -1)
                {
                    cout << p[2 * order - 1 + i - 1] << " ";
                }
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int order, x;
    cout << "Enter order of the Matrix" << endl;
    cin >> order;
    TriDiagonalMatrix m1(order);
    for (int i = 1; i <= order; i++)
    {
        for (int j = 1; j <= order; j++)
        {
            cin >> x;
            m1.set(i, j, x);
        }
    }
    cout << "Displaying the TriDiagonal Matrix" << endl;
    m1.display();
    return 0;
}