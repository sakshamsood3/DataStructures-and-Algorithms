#include <iostream>
using namespace std;
class ToeplitzMatrix
{
    int order;
    int *p;

public:
    ToeplitzMatrix()
    {
        order = 5;
        p = new int[(order * 2) - 1];
    }
    ToeplitzMatrix(int order)
    {
        this->order = order;
        p = new int[(order * 2) - 1];
    }
    ~ToeplitzMatrix()
    {
        delete[] p;
    }
    void set(int i, int j, int element)
    {

        if (i <= j)
            p[j - i] = element;
        else
            p[order - 1 + i - j] = element;
    }
    int get(int i, int j)
    {
        if (i <= j)
            return p[j - i];
        else
            return p[order - 1 + i - j];
    }
    void display()
    {
        for (int i = 1; i <= order; i++)
        {
            for (int j = 1; j <= order; j++)
            {
                if (i <= j)
                    cout << p[j - i] << " ";
                else
                    cout << p[order - 1 + i - j] << " ";
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
    ToeplitzMatrix m1(order);
    for (int i = 1; i <= order; i++)
    {
        for (int j = 1; j <= order; j++)
        {
            cin >> x;
            m1.set(i, j, x);
        }
    }
    cout << "Displaying the Toeplitz Matrix " << endl;
    m1.display();
    return 0;
}
