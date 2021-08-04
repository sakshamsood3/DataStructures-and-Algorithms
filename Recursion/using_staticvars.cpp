#include <iostream>
using namespace std;
int func(int n)
{
    static int x = 0; //we can use a global var as well it works in the same way as a static variable
    if (n > 0)
    {
        x++;
        return func(n - 1) + x;
    }
    return 0;
}
int main()
{
    int x = 5;
    cout << func(x);
    return 0;
}