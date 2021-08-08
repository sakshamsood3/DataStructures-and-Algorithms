#include <iostream>
using namespace std;
int main()
{
    int *p, *q, n, newn;
    cout << "Enter the size of initial array ";
    cin >> n;
    p = new int[n];
    cout << "Enter the elements of the initial array ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "Enter the size of the array you now want ";
    cin >> newn;
    q = new int[newn];
    cout << "Addresses of p initially " << endl;
    for (int i = 0; i < n; i++)
    {
        q[i] = p[i];
        cout << &p[i] << " ";
    }
    cout << endl;
    delete[] p;
    p = q;
    q = NULL;
    cout << "Addresses of p later " << endl;
    for (int i = 0; i < newn; i++)
    {
        cout << &p[i] << " ";
    }
    delete[] q;
    return 0;
}