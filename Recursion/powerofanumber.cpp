#include <iostream>
using namespace std;
int power_func(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        return power_func(m * m, n / 2);
    }
    else
        return m * power_func(m * m, (n - 1) / 2);
}
int main()
{
    int num, pow;
    cout << "Enter the number and the power you want it to be raised to ";
    cin >> num >> pow;
    cout << num << " raised to power " << pow << " is " << power_func(num, pow);
    return 0;
}