#include <iostream>
using namespace std;
double taylor_series(int x, int n)
{
    static double p = 1, f = 1, r;
    if (n == 0)
        return 1;
    else
    {
        r = taylor_series(x, n - 1);
        p *= x;
        f *= n;
        return r + (p / f);
    }
}
int main()
{
    cout << taylor_series(4, 15);
    return 0;
}