#include <iostream>
using namespace std;
int F[10]; //global array so that we can carry out memoization to reduce time complexity of our code
int better_fibo(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = better_fibo(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = better_fibo(n - 1);
        }
        F[n] = F[n - 1] + F[n - 2];
        return F[n - 1] + F[n - 2];
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }
    int num;
    cout << "Enter the number of terms ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << better_fibo(i) << " ";
    }
    return 0;
}