#include <iostream>
using namespace std;
int main()
{
    int r, c;
    cout << "Enter number of rows and columns ";
    cin >> r >> c;
    int A[r][c];
    int *p[r];
    int **q;
    q = new int *[r];
    for (int i = 0; i < c; i++)
    {
        p[i] = new int[c];
        q[i] = new int[c];
    }
    cout << "Enter elements of the array ";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> q[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << q[i][j] << " ";
            if (j == c - 1)
            {
                cout << endl;
            }
        }
    }
    return 0;
}