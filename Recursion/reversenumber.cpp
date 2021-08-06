#include <iostream>
using namespace std;
int reverse_number(int n)
{
    static int rev = 0;
    if (n == 0)
        return rev;
    else
    {
        rev = (rev * 10) + n % 10;
        reverse_number(n / 10);
    }
    return rev;
}
int main()
{
    cout << reverse_number(10237);
    return 0;
}