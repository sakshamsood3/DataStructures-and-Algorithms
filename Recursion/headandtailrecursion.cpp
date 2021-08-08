#include <iostream>
using namespace std;
void tail_rec(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        tail_rec(n - 1);
    }
}
void head_rec(int n)
{
    if (n > 0)
    {
        head_rec(n - 1);
        cout << n << " ";
    }
}
int main()
{
    int x;
    cout << "Enter a number ";
    cin >> x;
    tail_rec(x);
    cout << endl;
    head_rec(x);
    return 0;
}