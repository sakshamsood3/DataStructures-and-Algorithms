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
    friend istream &operator>>(istream &is, SparseMatrix &s);
    friend ostream &operator<<(ostream &os, SparseMatrix &s);
    SparseMatrix operator+(SparseMatrix &s)
    {
        int i = 0, j = 0, k = 0;
        if ((m != s.m) || (n != s.n))
            return *this;
        SparseMatrix *sum = new SparseMatrix(m, n, num + s.num);
        while (i < num && j < s.num)
        {
            if (p[i].i < s.p[j].i)
            {
                sum->p[k++] = p[i++];
            }
            else if (p[i].i > s.p[j].i)
            {
                sum->p[k++] = s.p[j++];
            }
            else
            {
                if (p[i].j < s.p[j].j)
                {
                    sum->p[k++] = p[i++];
                }
                else if (p[i].j > s.p[j].j)
                {
                    sum->p[k++] = s.p[j++];
                }
                else
                {
                    sum->p[k] = p[i];
                    sum->p[k++].x = s.p[j++].x + p[i++].x;
                }
            }
        }
        for (i; i < num; i++)
        {
            sum->p[k++] = p[i];
        }
        for (j; j < s.num; j++)
        {
            sum->p[k++] = s.p[j];
        }
        sum->num = k;
        return *sum;
    }
};
istream &operator>>(istream &is, SparseMatrix &s)
{
    cout << "Enter non zero element' s row no. col no. and the number" << endl;
    for (int a = 0; a < s.num; a++)
    {
        cin >> s.p[a].i >> s.p[a].j >> s.p[a].x;
    }
    return is;
}
ostream &operator<<(ostream &os, SparseMatrix &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if ((s.p[k].i == i) && (s.p[k].j == j))
            {
                cout << s.p[k++].x << " ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return os;
}
int main()
{
    SparseMatrix s1(5, 5, 5);
    SparseMatrix s2(5, 5, 5);
    cin >> s1;
    cin >> s2;
    SparseMatrix sum = s1 + s2;
    cout << "First Matrix " << endl;
    cout << s1 << endl;
    cout << "Second Matrix" << endl;
    cout << s2 << endl;
    cout << "Sum of two Matrices" << endl;
    cout << sum;
    return 0;
}