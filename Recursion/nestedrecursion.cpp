#include <iostream>
using namespace std;
int nested_rec(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return nested_rec(nested_rec(n + 11));
    }
}
int main()
{
    int x;
    cout << "Enter a number greater than 90 for your ease ";
    cin >> x;
    cout << nested_rec(x);
    return 0;
}