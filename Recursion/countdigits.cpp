#include <iostream>
using namespace std;
int count_digits(int n)
{
    static int count = 0;
    if (n == 0)
        return 1;
    else
    {
        if (n != 0)
        {
            count++;
            count_digits(n / 10);
        }
        return count;
    }
}
int main()
{
    cout << "Enter a number ";
    int n;
    cin >> n;
    cout << count_digits(n);
    return 0;
}