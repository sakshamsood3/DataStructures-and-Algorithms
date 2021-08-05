#include <iostream>
using namespace std;
double taylor_func(int x, int n)
{
    static double s;
    if (n == 0)
        return s;
    else
    {
        s = 1 + x * s / n;
        return taylor_func(x, n - 1);
    }
}
int main()
{
    cout << "Enter number and no. of terms ";
    int num, x;
    cin >> x >> num;
    cout << "The value of taylor series is " << taylor_func(x, num);
    return 0;
}