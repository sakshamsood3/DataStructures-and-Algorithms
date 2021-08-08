#include <iostream>
using namespace std;
int hcf(int a, int b)
{
    if (a >= b)
    {
        if (a % b == 0)
            return b;
        else
            return hcf(b, a % b);
    }
    else
    {
        if (b % a == 0)
            return a;
        else
            return hcf(a, b % a);
    }
}
int lcm(int a, int b, int hcf)
{
    return (a * b) / hcf;
}
int main()
{
    int a, b;
    cout << "Enter two numbers ";
    cin >> a >> b;
    cout << "Hcf of the numbers is " << hcf(a, b) << endl;
    cout << "Lcm of the numbers is " << lcm(a, b, hcf(a, b));
    return 0;
}