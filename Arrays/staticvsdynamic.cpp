#include <iostream>
using namespace std;
int main()
{
    int A[5]; //static created inside stack
    int *p;
    p = new int[5]; //dynamic created inside heap
    for (int i = 0; i < 5; i++)
    {
        p[i] = i + 1;
        A[i] = i + 1;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << *(p + i) << " ";
    }
    delete[] p; //deleting dynamically allocated array otherwise can cause memory leak
    return 0;
}