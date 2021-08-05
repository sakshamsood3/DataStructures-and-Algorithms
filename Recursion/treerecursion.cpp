#include <iostream>
using namespace std;
void tree_rec(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        tree_rec(n - 1);
        tree_rec(n - 1);
    }
}
int main()
{
    int x;
    cout << "Enter a number";
    cin >> x;
    tree_rec(x);
    return 0;
}