#include <iostream>
using namespace std;
class Element
{
public:
    int i;
    int j;
    int x;
};
class SparseMatrix
{
    int m;
    int n;
    int num;
    Element *p;

public:
    SparseMatrix()
    {
    }
    SparseMatrix(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        p = new Element[this->num];
    }
    ~SparseMatrix()
    {
        delete[] p;
    }
    void read()
    {
        cout << "Enter non zero element' s row no. col no. and the number" << endl;
        for (int a = 0; a < num; a++)
        {
            cin >> p[a].i >> p[a].j >> p[a].x;
        }
    }
    void display()
    {
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((p[k].i == i) && (p[k].j == j))
                {
                    cout << p[k++].x << " ";
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
    SparseMatrix s1(5, 5, 5);
    s1.read();
    s1.display();
    return 0;
}