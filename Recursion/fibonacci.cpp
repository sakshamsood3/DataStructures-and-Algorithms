#include <iostream>
using namespace std;
int fibo(int n)
{
    if (n == 1 || n == 0)
        return n;
    else
        return (fibo(n - 1) + fibo(n - 2));
}
int main()
{
    int num;
    cout << " Enter number of terms of the sequence you want ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << fibo(i) << " ";
    }
    return 0;
}