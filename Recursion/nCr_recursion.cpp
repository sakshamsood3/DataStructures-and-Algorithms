#include <iostream>
using namespace std;
int C(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
        return C(n - 1, r) + C(n - 1, r - 1);
}
int main()
{
    int n, r;
    cout << "Enter values of n and r ";
    cin >> n >> r;
    cout << "nCr value is " << C(n, r);
    return 0;
}